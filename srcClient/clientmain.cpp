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
#define MULTICAST_ADDRESS "239.192.1.1"
#define MULTICAST_PORT 5678
using namespace std;
std::string _zmq_pub_skt_string;


void printscreen (std::string str)
{
    if (str.compare("we would like to see"))
        cout << "Evviva!";
}

int sum( int num, ... ) {
  int answer = 0;
  va_list argptr;            
 
  va_start( argptr, num );            
 
  for( ; num > 0; num-- ) {
    answer += va_arg( argptr, int );
  }           
 
  va_end( argptr );           
 
  return( answer );
}             

struct parameters{
    void * zmqobj;
    void (*callback) (std::string);
};

void *th_subscriber (void * params);
void server_location_callback(std::string ip);
/*
 * 
 */
int main(int argc, char** argv) {

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
    ss << "epgm://" << _local_ip_address << ";" << MULTICAST_ADDRESS << ":" << MULTICAST_PORT << std::endl;
    _zmq_pub_skt_string = ss.str();
        
    Saetta_Server::Server_Info serverinfomsg;

    Zmqcpp::Context* mycontext = new Zmqcpp::Context(1);
   
    Zmqcpp::Subscriber *mysubber=new Zmqcpp::Subscriber(mycontext,_zmq_pub_skt_string.c_str(), ZMQCPP_CONNECT);
    mysubber->SubscribeTopic("SERVER_INFO");
    mysubber->setIdentityRnd();
    struct parameters myparams;
    myparams.zmqobj=(void*)mysubber;
    myparams.callback=&server_location_callback;
    pthread_t th_hndl_subber;
    pthread_create(&th_hndl_subber, NULL, th_subscriber, (void *)&myparams);
    
    while(1)
    {
        if (s_interrupted == 1) {
            fprintf(outstream, "\n");
            if (MAIN_DEBUG)
                dbg_print(MAIN_PROC_NAME,"SIGINT interrupt received, killing node\n");
            else
                fprintf(outstream, "\n!!!!!    KILL NODE COMMAND RECEIVED    !!!!!\n\n");
            break;
        }
        
        /*cout << mysubber.RecvMsg() << std::endl;
        serverinfomsg.ParseFromString(mysubber.RecvMsg());
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
    mysubber->~Subscriber();
    mycontext->~Context();
    return (EXIT_SUCCESS);
}

void *th_subscriber (void * params)
{
    struct parameters *myparams = (struct parameters *) params;
    Zmqcpp::Subscriber *mysubber = (Zmqcpp::Subscriber*)(myparams->zmqobj);
    Saetta_Server::Server_Info serverinfomsg;
    std::string server_ip;
    std::stringstream ss;
    std::string msgtype;
    std::string msgmaster = "SERVER_INFO";
    
    while(1)
    {
        ss.str("");
        msgtype.clear();
        ss << mysubber->RecvMsg();
        msgtype = ss.str();
        
        if (!msgtype.compare(msgmaster))
        {
            //cout << mysubber->RecvMsg() << std::endl;
            serverinfomsg.ParseFromString(mysubber->RecvMsg());
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
    }
    return(EXIT_SUCCESS);
    
}

void server_location_callback(std::string ip)
{
    cout << "AAAAAAAAAA  Callback fired!  AAAAAAAAAA" << std::endl;
    cout << "AAAAAAAAAA  New server address: " << ip.c_str() << "  AAAAAAAAAA" << std::endl;    
}
