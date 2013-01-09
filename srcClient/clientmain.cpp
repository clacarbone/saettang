/*
* ----------------------------------------------------------
*
* File:   clientmain.cpp
* Copyright 2013 Erupter
* Created on December 15, 2012, 4:08 PM
*
* ----------------------------------------------------------
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
*/

#include <service.h>
#include <saetta.pb.h>
#include "cli_parser.h"

using namespace std;
//std::string _zmq_sub_skt_string;     

struct parameters{
    Zmqcpp::Context * zmqcont;
    void (*callback) (std::string);
    std::string ip;
    int conntype;
    std::list<std::string> topics;
};

void *th_subscriber (void * params);
void server_location_callback(std::string ip);
/*
 * 
 */
int main(int argc, char** argv) {

    int th_control = 1;
    struct parameters myparams;
    struct arguments arguments;
    outstream = stdout;
    arguments.M_DEBUG=&MAIN_DEBUG;
    arguments.Z_DEBUG=&ZMQ_DEBUG;
    strcpy( arguments.interf, "eth0" );
    strcpy(arguments.outfile, "");
    s_catch_signals();

    argp_parse(&argp, argc, argv, ARGP_NO_ERRS, 0, &arguments);

    if (strlen(arguments.outfile)>0)
        outstream = fopen (arguments.outfile, "w");

    fprintf(outstream, "Requested interface %s, attempting to fetch address...\n",arguments.interf);
    if (!get_iface_address(arguments.interf))
        return (EXIT_FAILURE);
    ss << "epgm://" << _local_ip_address << ";" << MULTICAST_ADDRESS << ":" << MULTICAST_PORT;// << std::endl;
    //_zmq_sub_skt_string = ss.str();
    myparams.ip = ss.str();
        
    //Saetta_Server::Server_Info serverinfomsg;

    Zmqcpp::Context* mycontext = new Zmqcpp::Context(1);
   
    //Zmqcpp::Subscriber *mysubber=new Zmqcpp::Subscriber(mycontext,_zmq_sub_skt_string.c_str(), ZMQCPP_CONNECT);
    //mysubber->SubscribeTopic("SERVER_INFO");
    //mysubber->setIdentityRnd();
    
    ss.str("");
    ss.str(HEADER_SERVER_INFO);
    myparams.topics.insert(myparams.topics.end(),ss.str());
    myparams.conntype = ZMQCPP_CONNECT;
    myparams.zmqcont=mycontext;
    myparams.callback=&server_location_callback;
    
    ss.str("");
    ss << THREAD_CONTROL_IPC;
    Zmqcpp::Publisher *ctrlpublisher = new Zmqcpp::Publisher(mycontext, THREAD_CONTROL_IPC, ZMQCPP_BIND);
    
    pthread_t th_hndl_subber;
    pthread_create(&th_hndl_subber, NULL, th_subscriber, (void *)&myparams);
    
    while(th_control)
    {
        if (s_interrupted == 1) {
            fprintf(outstream, "\n");
            if (MAIN_DEBUG)
                dbg_print(MAIN_PROC_NAME,"SIGINT interrupt received, killing node\n");
            else
                fprintf(outstream, "\n!!!!!    KILL NODE COMMAND RECEIVED    !!!!!\n\n");
            
            ctrlpublisher->PubMsg(2,HEADER_CTRL,"KILL");
            sleep(1);
            th_control = 0;
        }
        
        ctrlpublisher->PubMsg(2,HEADER_CTRL,"Test");
        sleep(1);
        /*cout << mysubber->RecvMsg() << std::endl;
        serverinfomsg.ParseFromString(mysubber->RecvMsg());
        cout << "Address: " << serverinfomsg.address() << std::endl;
        cout << "Time: " << serverinfomsg.time() << std::endl << std::endl;
        if (serverinfomsg.known_clients_size()>0)
            for (int i=0; i<serverinfomsg.known_clients_size();i++)
            {
                cout << "Known clients" << std::endl;        
                cout << "\t Address: " << serverinfomsg.known_clients(i).address() << std::endl;
                cout << "\t Name: " << serverinfomsg.known_clients(i).name() << std::endl;
                cout << "\t Status: " << serverinfomsg.known_clients(i).status() << std::endl;
            }*/
    }
    //mysubber->~Subscriber();
    ctrlpublisher->~Publisher();
    void *status;
    pthread_join(th_hndl_subber, &status);
    mycontext->~Context();
    return (EXIT_SUCCESS);
}

void *th_subscriber (void * params)
{
    int th_control = 1;
    std::string server_ip;
    std::stringstream ss;
    std::string msgtype;
    std::string msgmaster = HEADER_SERVER_INFO;
    std::string temp;
    struct parameters *myparams = (struct parameters *) params;
    Zmqcpp::Subscriber *msgsubber = new Zmqcpp::Subscriber(myparams->zmqcont,&(myparams->ip), myparams->conntype);
    for (std::list<std::string>::iterator it = myparams->topics.begin(); it != myparams->topics.end(); it++)
    {
        cout << "Subscribing to <" << *it <<">"<<std::endl;
        printf("Subscribing to: <%s>\n",it->c_str());
        msgsubber->SubscribeTopic(*it);
    }
    Saetta_Server::Server_Info serverinfomsg;
    ss.str("");
    ss << THREAD_CONTROL_IPC;
    Zmqcpp::Subscriber *ctrlsubber = new Zmqcpp::Subscriber(myparams->zmqcont,THREAD_CONTROL_IPC, ZMQCPP_CONNECT);
    ctrlsubber->SubscribeTopic(HEADER_CTRL);
    Zmqcpp::Poller *mypoller = new Zmqcpp::Poller();
    Zmqcpp::PollItem* mypollitems = new Zmqcpp::PollItem();
    
    mypollitems->addevent(msgsubber,ZMQ_POLLIN,0);
    mypollitems->addevent(ctrlsubber,ZMQ_POLLIN,0);
    
    sleep(1);
    while(th_control)
    {
        usleep(100000);
        int rc = mypoller->PollEvents(mypollitems,100);

        if (rc > 0)
        {
            if(mypollitems->item(0)->revents!= 0)
            {
                while(mypoller->PollEvents(mypollitems, 0, 100)>0)
                {
                    ss.str("");
                    msgtype.clear();
                    ss << msgsubber->RecvMsg();
                    msgtype = ss.str();

                    if (!msgtype.compare(msgmaster))
                    {
                        //cout << mysubber->RecvMsg() << std::endl;
                        serverinfomsg.ParseFromString(msgsubber->RecvMsg());
                        //cout << "Address: " << serverinfomsg.address() << std::endl;
                        if (strcmp(server_ip.c_str(),serverinfomsg.address().c_str()))
                        {
                            ss.str("");
                            server_ip.clear();
                            ss << serverinfomsg.address();
                            server_ip.assign(ss.str());
                            ss.str("");
                            cout << "Updated" << std::endl;
                            myparams->callback(server_ip.c_str());
                        }
                    }
                }
            }
            if(mypollitems->item(1)->revents!= 0)
            {
                while(mypoller->PollEvents(mypollitems, 1, 100)>0)
                {
                    ss.str("");
                    ss << ctrlsubber->RecvMsg();
                    msgtype.clear();
                    msgtype = ss.str();
                    if (!msgtype.compare(HEADER_CTRL))
                    {
                        ss.str("");            
                        ss << "Control message: " << ctrlsubber->RecvMsg();
                        temp.clear();
                        temp.assign(ss.str());
                        myparams->callback(temp.c_str());
                        if (temp.compare("Control message: KILL")==0)
                            th_control = 0;
                        
                    }
                }
            }
        }
    }
    
        
        
        
        
        /*cout << "Time: " << serverinfomsg.time() << std::endl << std::endl;
        if (serverinfomsg.known_clients_size()>0)
        {
            for (int i=0; i<serverinfomsg.known_clients_size();i++)
            {
                cout << "Known clients" << std::endl;        
                cout << "\t Address: " << serverinfomsg.known_clients(i).address() << std::endl;
                cout << "\t Name: " << serverinfomsg.known_clients(i).name() << std::endl;
                cout << "\t Status: " << serverinfomsg.known_clients(i).status() << std::endl;
            }
        }*/
    
    ctrlsubber->~Subscriber();
    msgsubber->~Subscriber();
    return(EXIT_SUCCESS);
    
}

void server_location_callback(std::string ip)
{
    
    cout << ip.c_str() <<  std::endl;    
}
