/**
 * \file test_wsquery.c
 * Unit test for wsquery module.
 */


#include <string.h>
#include <stdio.h>
#include "wsquery.h"


/** String to test */
#define QUERY "timestamp=1484862407&lat=41.3&lon=1.45"


/**
 * Unit test.
 * \return 0 in case of success
 */
int main(int argc, char **argv) {

    char *value;
    int err = 0;

    value = parse_query(QUERY, "lat");

    if(strcmp(value, "41.3")) {
        fprintf(stderr, "Bad read value for lat (!=41.3) : .%s.\n", value);
        err = 1;
    } else {
        fprintf(stdout, "Read value for lat OK\n");
    }

    return err;
}
