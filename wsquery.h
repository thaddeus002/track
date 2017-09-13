/**
 * \file wsquery.h
 * Parse a werservice query.
 */



/**
 * Find a parameter's value in a query string.
 * \param query the query string in the form param1=value1&param2=value2...
 * \param parameter the name of the parameter to look for
 * \return a pointer to a staticaly allocated string with the value of the
 * parameter, or an empty string if not found. DON'T free it.
 */
char *parse_query(char *query, char *parameter);
