/* 
 * File:   cli_parser.h
 * Author: erupter
 *
 * Created on August 22, 2012, 12:53 PM
 */

#ifndef CLI_PARSER_H
#define	CLI_PARSER_H

#define MAIN_PROGRAM_VERSION "Saetta Coordination Project - Server Side"

#define CONTACT_EMAIL "noaddr@email.com"

#define MAIN_PROC_NAME "Main"

#define ZMQ_PROC_NAME "0MQ Lib"

#ifdef	__cplusplus
extern "C" {
#endif

#include <argp.h>
#include <stdio.h>
const char *argp_program_version = MAIN_PROGRAM_VERSION;

const char *argp_program_bug_address = CONTACT_EMAIL;    
/* This structure is used by main to communicate with parse_opt. */
struct arguments
{
  int *Z_DEBUG, *M_DEBUG;
  char * interf;
  char *outfile;            /* Argument for -o */
};

/*
   OPTIONS.  Field 1 in ARGP.
   Order of fields: {NAME, KEY, ARG, FLAGS, DOC}.
*/
static struct argp_option options[] =
{

  {"ZMQDebug", 'Z', "n", 0, "Set debug level of the 0MQ Manager"},
  {"MAINDebug", 'M', "n", 0, "Set debug level of the main program"},
  {"output",  'o', "OUTFILE", 0, "Output to OUTFILE instead of to standard output"},
  {"interface", 'i', "char", 0, "Interface on which to bind the server"},
  //{"robot", 'r' , "n", 0, "Set robot index for multi robot environment"},
  {0}
};


/*
   PARSER. Field 2 in ARGP.
   Order of parameters: KEY, ARG, STATE.
*/
static error_t
parse_opt (char key, char *arg, struct argp_state *state)
{
  struct arguments *arguments = state->input;

  switch (key)
  {
    case 'Z':
        *(arguments->Z_DEBUG) = atoi(arg);
        break;
    case 'M':
        *(arguments->M_DEBUG) = atoi(arg);
        break;               
    case 'o':
        arguments->outfile = arg;
        break;
    case 'i':
        arguments->interf = arg;
        break;
        
    case ARGP_KEY_ARG:
    case ARGP_KEY_END:
        argp_usage(state);
        break;
    default:
      return ARGP_ERR_UNKNOWN;
    }
  return 0;
}

/*
   ARGS_DOC. Field 3 in ARGP.
   A description of the non-option command-line arguments
     that we accept.
*/
//static char args_doc[] = "ARG1 ARG2";

/*
  DOC.  Field 4 in ARGP.
  Program documentation.
*/
static char doc[] =
"Laboratorio di Robotica, Università degli Studi Roma TRE\n"
"Provides a coordinating node for all Saetta robots.\n"
"The server location is broadcasted on the local wireless network"
", client nodes (the robots) get the server address and connect."
"Upon connecting, the server starts coordinating the swarm according"
"to the given instructions.";

/*
   The ARGP structure itself.
*/
static struct argp argp = {options, parse_opt, 0, doc};


#ifdef	__cplusplus
}
#endif

#endif	/* CLI_PARSER_H */

