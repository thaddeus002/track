/**
 * file track.c
 * Main cgi program for the "track my phone" project
 */


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "wsquery.h"

// store file
#define DATA_FILE "pos.csv"

// strings for the http get request
#define TIME_STRING "timestamp"
#define LAT_STRING "lat"
#define LON_STRING "lon"



static int store_data(int timestamp, float lat, float lon) {

    FILE *fd;
    // timestamp in seconds
    time_t now;

    //verify data validity

    now = time(NULL);
    if((time - timestamp > 1) || (timestamp - time > 60)) {
        fprintf(stderr, "Invalide time : %l\n", timestamp);
    }

    if((lat < -90) || (lat > 90)) {
        fprintf(stderr, "Latitude value out of bounds : %f\n", lat);
        return -1;
    }

    if((lon < -180) || (lon > 180)) {
        fprintf(stderr, "Latitude value out of bounds : %f\n", lat);
        return -1;
    }

    // store data

    fd = fopen(DATA_FILE, "a");

    if(fd == NULL) {
        fprintf(stderr, "Can't open file %s\n", DATA_FILE);
        return -1;
    }

    fprintf(fd, "%d, %2.5f, %3.6f\n", timestamp, lat, lon);

    fclose(fd);
    return 0;
}


/**
 * Send an empty response to the web client.
 */
static void empty_response() {

    fprintf(stdout, "Content-type: text/html\n\n");
}


int main(int argc, char **argv) {

    long timestamp;
    float lat, lon;

    char *queryString;

    queryString = getenv("QUERY_STRING");

    timestamp = atol(parse_query(queryString, TIME_STRING));
    lat = atof(parse_query(queryString, LAT_STRING));
    lon = atof(parse_query(queryString, LON_STRING));

    store_data(timestamp, lat, lon);

    empty_response();

    return 0;
}
