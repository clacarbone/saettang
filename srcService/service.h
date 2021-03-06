/* 
 * File:   service.h
 * Author: erupter
 *
 * Created on October 25, 2012, 12:08 PM
 */

#ifndef SERVICE_H
#define	SERVICE_H
#include <globals.h>
#include <pthread.h>
#include <cstdlib>
#include <zmqcpp.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <list>
std::string _local_ip_address;
std::stringstream ss;

static inline bool get_iface_address(std::string interf)
{
    int s;
    struct ifreq ifr = {};
    s = socket(PF_INET, SOCK_DGRAM, 0);

    strncpy(ifr.ifr_name, interf.c_str(), sizeof(ifr.ifr_name));

    if (ioctl(s, SIOCGIFADDR, &ifr) >= 0)
    {        
        _local_ip_address = inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr);
        printf("Detected interface IP address is %s.\nCreating sockets on this address.\n", _local_ip_address.c_str());          
        return true;
    }    
    printf("Unable to get interface IP address: is the interface configured?\n");
    return false;
    
}

#ifdef	__cplusplus
extern "C" {
#endif

#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <globals.h>
FILE *outstream;
//#include <fcntl.h>>
#include <stdarg.h>
struct timeval plm_tv;
time_t plm_t;
struct tm plm_tm;
int MAIN_DEBUG;
int ZMQ_DEBUG;



#define PROC_STR(PROC_NAME) {plm_t=time(NULL); gettimeofday(&plm_tv, NULL); localtime_r(&plm_t,&plm_tm); fprintf(outstream,"[%02d:%02d:%02d.%06ld  %s] ", plm_tm.tm_hour,plm_tm.tm_min,plm_tm.tm_sec,plm_tv.tv_usec,PROC_NAME);}

#define DEF_SECOND 1000000

static void dbg_print(const char* proc_name, const char *format,...)
{
    PROC_STR(proc_name);
    va_list argptr;
    va_start (argptr, format);
    vfprintf (outstream, format, argptr);
    va_end (argptr);
}

volatile sig_atomic_t s_interrupted = 0;
volatile sig_atomic_t alarm_expired = 0;

static void s_signal_handler (int signal_value)
{
    if (signal_value == SIGTERM || signal_value == SIGSTOP || signal_value == SIGINT)
        s_interrupted = 1;
    if (signal_value == SIGALRM)
        //signal(SIGALRM,alarm_wakeup);
        alarm_expired = 1;
    if (signal_value == SIGTSTP)
    {
        printf("SIGTSTP received\n");
    }
}

static void s_catch_signals (void)
{
    struct sigaction action;
    action.sa_handler = s_signal_handler;
    action.sa_flags = 0;
    sigemptyset (&action.sa_mask);
    sigaction (SIGINT, &action, NULL);
    sigaction (SIGTERM, &action, NULL);
    sigaction (SIGALRM, &action, NULL);
    sigaction (SIGSTOP, &action, NULL);
    sigaction (SIGTSTP, &action, NULL);
}


#ifdef	__cplusplus
}
#endif

#endif	/* SERVICE_H */

