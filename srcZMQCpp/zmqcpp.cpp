/*
* ----------------------------------------------------------
*
* File:   zmqcpp.cpp
* Copyright 2013 Erupter
* Created on December 14, 2012, 6:32 PM
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

#include <zmq.h>

#include "zmqcpp.h"
namespace Zmqcpp {

    
    Context::Context()
    {
        this->_zmq_context_ptr = zmq_init(1);
        if (this->_zmq_context_ptr == NULL)
            throw error_t ();      
    }
    
    Context::Context(int threads)
    {
        this->_zmq_context_ptr = zmq_init(threads);
        if (this->_zmq_context_ptr == NULL)
            throw error_t ();           
    }
    
    Context::~Context()
    {
        zmq_ctx_destroy(this->_zmq_context_ptr);
    }
    
    Context* Context::getPtr()
    {
        return this;
    }
    
    Socket::Socket(Context* context, int skt_type)
    {
        this->_zmq_socket_ptr = 0;
        this->_zmq_socket_ptr = zmq_socket(context->_zmq_context_ptr, skt_type);    
        if (this->_zmq_socket_ptr == NULL)
            throw error_t ();
        s_set_id (this->_zmq_socket_ptr);
    }
    
    Socket::Socket(Context* context, int skt_type, std::string ip_addr, int conn)
    {
        this->_zmq_socket_ptr = 0;
        this->_zmq_socket_ptr = zmq_socket(context->_zmq_context_ptr, skt_type);    
        if (this->_zmq_socket_ptr == NULL)
            throw error_t ();
        if (conn == ZMQCPP_BIND)        
            zmq_bind(this->_zmq_socket_ptr, ip_addr.c_str());
        else
        {
            if (conn == ZMQCPP_CONNECT)
                zmq_connect(this->_zmq_socket_ptr, ip_addr.c_str());
            else
                throw error_t();
        }
        s_set_id (this->_zmq_socket_ptr);
    }
    
    Socket::~Socket()
    {
        zmq_close(this->_zmq_socket_ptr);
        //zmq_disconnect(this->_zmq_socket_ptr, this->_ip_addr);
    }
    
    Socket* Socket::getPtr()
    {
        return this;
    }
        
    int Socket::getsockopt (void *socket, int option_name, void *option_value, size_t *option_len)
    {
        return zmq_getsockopt(socket, option_name, option_value, option_len);
    }
    
    int Socket::setsockopt(int option, const void *optval,size_t optvallen)
    {
        return zmq_setsockopt(this->_zmq_socket_ptr,option, optval,optvallen);        
    }
    
    char* Socket::Receive()
    {
        return s_recv (this->_zmq_socket_ptr);
    }

    int Socket::Send(std::string msg)
    {
        return s_send(this->_zmq_socket_ptr,(char*)msg.c_str());
    }
    
    
    int Socket::SendMore(std::string msg)
    {
        return s_sendmore(this->_zmq_socket_ptr,(char*)msg.c_str());
    }
    
    int Socket::connect()
    {
        int rc = zmq_connect (this->_zmq_socket_ptr, "tcp://localhost:5678");
        if (rc != 0)
            throw error_t ();
        this->_ip_addr = "tcp://localhost:5678";
        return 0;
    }
    
    int Socket::connect(std::string ip_addr)
    {
        int rc = zmq_connect (this->_zmq_socket_ptr, ip_addr.c_str());
        if (rc != 0)
            throw error_t ();  
        this->_ip_addr = ip_addr;
        return 0;
    }    
    
    int Socket::bind()
    {
        int rc = zmq_bind (this->_zmq_socket_ptr, "tcp://*:5678");
        if (rc != 0)
            throw error_t ();           
        this->_ip_addr = "tcp://*:5678";
        return 0;
    }
           
    int Socket::bind(std::string ip_addr)
    {
        int rc = zmq_bind (this->_zmq_socket_ptr, ip_addr.c_str());
        if (rc != 0)
            throw error_t ();      
        this->_ip_addr = ip_addr;
        return 0;
    }
    
    int generic::getSocketOption (void *socket, int option_name, void *option_value, size_t *option_len)
    {
        return zmq_getsockopt(this->_socket, option_name, option_value, option_len);
    }
    int generic::setSocketOption(int option, const void *optval,size_t optvallen)
    {
        return zmq_setsockopt(this->_socket,option, optval, optvallen);
    }
    int generic::setIdentity(std::string ident)
    {
        return zmq_setsockopt (this->_socket, ZMQ_IDENTITY, ident.c_str(), ident.length());
    }
    int generic::setIdentityRnd(void)
    {
        s_set_id (this->_socket);
    }

    
    Publisher::Publisher(Context* context)
    {
        this->_counter=0;
        this->_socket=0;
        this->_zmq_context=0;
        this->_zmq_context=context;
        this->_socket = new Zmqcpp::Socket(this->_zmq_context,ZMQ_PUB);
        this->_socket->bind();
    }
    Publisher::Publisher(Context* context, std::string ip_str, int conn)
    {
        this->_counter=0;
        this->_socket=0;
        this->_zmq_context=0;
        this->_zmq_context=context;
        this->_socket = new Zmqcpp::Socket(this->_zmq_context,ZMQ_PUB, ip_str, conn);
        
    }
    Publisher::~Publisher()
    {
        this->_socket->~Socket();
    }

    void Publisher::PubMsg (int count, ...)
    {
        va_list argptr;

        va_start( argptr, count );      

        for( ; count > 1; count-- ) {
            //char *mystr = va_arg(argptr, char*);
            this->_socket->SendMore (va_arg(argptr, char*));
        }
        this->_socket->Send(va_arg(argptr, char*));

        va_end( argptr );          
    }
    

    Subscriber::Subscriber(Context* context)
    {
        this->_socket=0;
        this->_zmq_context=0;
        this->_zmq_context=context;
        this->_socket = new Zmqcpp::Socket(this->_zmq_context,ZMQ_SUB);
    }

    Subscriber::Subscriber(Context* context, std::string ip_str, int conn)
    {
        this->_socket=0;
        this->_zmq_context=0;
        this->_zmq_context=context;
        this->_socket = new Zmqcpp::Socket(this->_zmq_context,ZMQ_SUB, ip_str, conn);
    }

    Subscriber::~Subscriber()
    {
        this->_socket->~Socket();
    }

    int Subscriber::SubscribeTopic(std::string topic)
    {
        return (this->_socket->setsockopt(ZMQ_SUBSCRIBE, topic.c_str(), topic.length()));    
    }

    
    std::string Subscriber::RecvMsg()
    {        
        return this->_socket->Receive();
    }
    
    Request::Request(Context* context)
    {
        this->_socket=0;
        this->_zmq_context=0;
        this->_zmq_context=context;
        this->_socket = new Zmqcpp::Socket(this->_zmq_context,ZMQ_REQ);        
    }
    
    Request::Request(Context* context, std::string ip_str, int conn)
    {
        this->_socket=0;
        this->_zmq_context=0;
        this->_zmq_context=context;
        this->_socket = new Zmqcpp::Socket(this->_zmq_context,ZMQ_REQ, ip_str, conn);        
    }
    
    Request::~Request()
    {
        this->_socket->~Socket();
    }


    Reply::Reply(Context* context)
    {
        this->_socket=0;
        this->_zmq_context=0;
        this->_zmq_context=context;
        this->_socket = new Zmqcpp::Socket(this->_zmq_context,ZMQ_REP);            
    }
    
    Reply::Reply(Context* context, std::string ip_str, int conn)
    {
        this->_socket=0;
        this->_zmq_context=0;
        this->_zmq_context=context;
        this->_socket = new Zmqcpp::Socket(this->_zmq_context,ZMQ_REP, ip_str.c_str(), conn);            
    }
    
    Reply::~Reply()
    {
        this->_socket->~Socket();
    }
    
    void Reply::SendMsg(int count, ...)
    {
        va_list argptr;

        va_start( argptr, count );      

        for( ; count > 1; count-- ) {
            //char *mystr = va_arg(argptr, char*);
            this->_socket->SendMore (va_arg(argptr, char*));
        }
        this->_socket->Send(va_arg(argptr, char*));

        va_end( argptr );     
    }
    
    std::string Reply::RecvMsg()
    {        
        return this->_socket->Receive();
    }    
    
    Router::Router(Context* context)
    {
        this->_socket=0;
        this->_zmq_context=0;
        this->_zmq_context=context;
        this->_socket = new Zmqcpp::Socket(this->_zmq_context,ZMQ_REP);            
    }
    
    Router::Router(Context* context, std::string ip_str, int conn)
    {
        this->_socket=0;
        this->_zmq_context=0;
        this->_zmq_context=context;
        this->_socket = new Zmqcpp::Socket(this->_zmq_context,ZMQ_REP, ip_str.c_str(), conn);            
    }
    
    Router::~Router()
    {
        this->_socket->~Socket();    
    }
    
    void Router::SendMsg(int count, ...)
    {
        va_list argptr;

        va_start( argptr, count );      

        for( ; count > 1; count-- ) {
            //char *mystr = va_arg(argptr, char*);
            this->_socket->SendMore (va_arg(argptr, char*));
        }
        this->_socket->Send(va_arg(argptr, char*));

        va_end( argptr );             
    }
    
    std::string Router::RecvMsg()
    {        
        return this->_socket->Receive();
    }
}
