/* 
 * File:   zmqcpp.h
 * Author: erupter
 *
 * Created on December 14, 2012, 6:32 PM
 */

#ifndef ZMQCPP_H
#define	ZMQCPP_H
extern "C" {
    #include <zmq.h>
    #include <zhelpers.h>
}
#include <string>
#include <sstream>
#include <iostream>
#define ZMQCPP_BIND 0
#define ZMQCPP_CONNECT 1

namespace Zmqcpp
{

  
    class Context
    {
        public:
            Context();
            Context(int threads);
            virtual ~Context();
            Context* getPtr();
            
        protected:
            friend class Socket;
            void* _zmq_context_ptr;
            
    };
    
    class Socket
    {
        public:
            Socket(Context* context, int skt_type);
            Socket(Context* context, int skt_type, std::string* ip_str, int conn);
            Socket(Context* context, int skt_type, const char* ip_addr, int conn);
            virtual ~Socket();
            Socket* getPtr();
            int getsockopt (void *socket, int option_name, void *option_value, size_t *option_len);
            int setsockopt(int option, const void *optval,size_t optvallen);
            int connect();
            int connect(std::string ip_addr);
            int bind();
            int bind(std::string ip_addr);
            int SendMore(std::string msg);
            int Send(std::string msg);
            char* Receive();
            
        protected:
            void *_zmq_socket_ptr;
            std::string _ip_addr;
    };
    
    class generic
    {
        public:
            int getSocketOption (void *socket, int option_name, void *option_value, size_t *option_len);
            int setSocketOption(int option, const void *optval,size_t optvallen);
            int setIdentity(std::string ident);
            int setIdentityRnd(void);
        protected:
            Zmqcpp::Context* _zmq_context;
            Zmqcpp::Socket* _socket;
    };
    
    class Publisher: public generic
    {
        
        public:
            Publisher(Context* context);
            Publisher(Context* context, std::string* ip_str, int conn);
            Publisher(Context* context, const char * ip_str, int conn);
            virtual ~Publisher();
            void PubMsg(int count, ...);
        
        private:
            unsigned int _counter;
    };
    
    class Subscriber: public generic
    {
        public:
            Subscriber(Context* context);
            Subscriber(Context* context, std::string* ip_str, int conn);
            Subscriber(Context* context, const char * ip_str, int conn);
            virtual ~Subscriber();
            int SubscribeTopic(std::string topic);
            std::string RecvMsg();

    };
    
    class Request: public generic
    {
        public:
            Request(Context* context);
            Request(Context* context, std::string* ip_str, int conn);
            Request(Context* context, const char * ip_str, int conn);
            virtual ~Request();            
            void SendMsg(int count, ...);
            std::string RecvMsg();

    };
    
    class Reply: public generic
    {
        public:
            Reply(Context* context);
            Reply(Context* context, std::string* ip_str, int conn);
            Reply(Context* context, const char * ip_str, int conn);
            virtual ~Reply();
            void SendMsg(int count, ...);
            std::string RecvMsg();            
    };
    
    class Router: public generic
    {
        public:
            Router(Context* context);
            Router(Context* context, std::string* ip_str, int conn);
            Router(Context* context, const char * ip_str, int conn);
            virtual ~Router();
            void SendMsg(int count, ...);
            std::string RecvMsg();            
    };

}


#endif	/* ZMQCPP_H */

