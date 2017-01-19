/**
 * file wsquery.c
 * parse a webservice query
 */

#include <string.h>

/** Max query string length */
#define BUFFER_SIZE 1024
/** Max number of parameters */
#define MAX_PARAM 15


static char BUFFER[BUFFER_SIZE];
static char *PARAMS[MAX_PARAM];
static char *VALUES[MAX_PARAM];
static int NB_PARAM;
static char *EMPTY_STRING = "";

typedef enum state {
    READING_PARAM,
    READING_VALUE
} state_t;


/**
 * Init the globals variables.
 * \param queryString the input string of form "Param1=Value1&Param2=value2&..."
 * \return the number of read parameters
 */
static int query_string_analyse(char *queryString) {

    state_t st = READING_PARAM;
    char *pos, *prec;
    int end = 0;

    strncpy(BUFFER, queryString, BUFFER_SIZE);
    BUFFER[BUFFER_SIZE-1] = '\0';

    NB_PARAM = 0;
    pos = BUFFER;
    prec = BUFFER;

    while(!end) {

        switch(*pos) {
        case '=':
            if(st!=READING_PARAM) {
                // Unrecoverable error
                end = 1;
            } else {
                PARAMS[NB_PARAM]=prec;
                *pos='\0';
                prec = ++pos;
                st=READING_VALUE;
            }
            break;
        case '&':
            if(st!=READING_VALUE) {
                // Unrecoverable error
                end = 1;
            } else {
                VALUES[NB_PARAM]=prec;
                *pos='\0';
                prec = ++pos;
                st=READING_PARAM;
                NB_PARAM++;
            }
            break;
        case '\0':
            if(st == READING_VALUE) {
                VALUES[NB_PARAM] = prec;
                NB_PARAM++;
            }
            end = 1;
            break;
        default:
            pos++;
        }

        if(NB_PARAM >= MAX_PARAM) end = 1;
    }

    return NB_PARAM;
}



static char *find_value(char *parameter){

    char *value = EMPTY_STRING;
    int i;

    for(i=0; i<NB_PARAM; i++) {

        if(!strcmp(PARAMS[i], parameter)) {
            value = VALUES[i];
            break;
        }
    }

    return value;
}


char *parse_query(char *query, char *parameter){

    query_string_analyse(query);

    return find_value(parameter);
}
