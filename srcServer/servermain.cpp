/*
* ----------------------------------------------------------
*
* File:   servermain.cpp
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
std::string _zmq_pub_skt_string;
std::string _zmq_rou_skt_string;


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

/*
 * 
 */
int main(int argc, char** argv) {

    struct arguments arguments;
    outstream = stdout;
    arguments.M_DEBUG=&MAIN_DEBUG;
    arguments.Z_DEBUG=&ZMQ_DEBUG;
    strcpy( arguments.interf, "eth0" );
    strcpy( arguments.outfile, "");
    s_catch_signals();

    argp_parse(&argp, argc, argv, ARGP_NO_ERRS, 0, &arguments);

    if (strlen(arguments.outfile)>0)
        outstream = fopen (arguments.outfile, "w");

    fprintf(outstream,"Requested interface %s, attempting to fetch address...\n",arguments.interf);
    if (!get_iface_address(arguments.interf))
        return (EXIT_FAILURE);
    ss << "epgm://" << _local_ip_address << ";" << MULTICAST_ADDRESS << ":" << MULTICAST_PORT << std::endl;
    _zmq_pub_skt_string = ss.str();
 
    Zmqcpp::Context* mycontext = new Zmqcpp::Context();

    Zmqcpp::Publisher mypubber(mycontext, _zmq_pub_skt_string.c_str(), ZMQCPP_BIND);
    ss.str("");
    ss << "tcp://" << _local_ip_address << ":" << ROUTER_PORT << std::endl;
    _zmq_rou_skt_string = ss.str();
    Zmqcpp::Router myrouter(mycontext, _zmq_rou_skt_string.c_str(), ZMQCPP_BIND);

    int counter=0;
    
    Saetta_Server::Server_Info serverinfomsg;
    serverinfomsg.set_address(_zmq_rou_skt_string.c_str());
    time_t t = time(0);
    char mystrt[40];
    sprintf(mystrt,"%s",ctime(&t));
    serverinfomsg.set_time(mystrt);
    /*Saetta_Server::Server_Info_Client* lclclient = serverinfomsg.add_known_clients();
    lclclient->set_address("192.168.1.1");
    lclclient->set_name("Router");
    lclclient->set_status("Nominal");
    lclclient = serverinfomsg.add_known_clients();
    lclclient->set_address("192.168.1.2");
    lclclient->set_name("NAS/DNS");
    lclclient->set_status("Nominal");*/
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
        char mystr[3];
        sprintf(mystr,"%03d",counter);
        time_t t = time(0);
        sprintf(mystrt,"%s",ctime(&t));
        serverinfomsg.set_time(mystrt);
        mypubber.PubMsg(3,"A","We don't want to see this",mystr);
        mypubber.PubMsg(3,"B","We would like to see this",mystr);
        mypubber.PubMsg(2,"SERVER_INFO",serverinfomsg.SerializeAsString().c_str());
        printf("Cycle [%s]\n",mystr);
        counter++;
        
        usleep(1000000);
    }
    mypubber.~Publisher();
    myrouter.~Router();
    mycontext->~Context();
    return (EXIT_SUCCESS);
}

