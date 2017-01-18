# Track project

This is simple cgi program to store data on a web server. A client program is planned for the future.

## How track a cell phone ?

Here is a basic server side spec to follow the position of a cell phone :

A client program will make an HTTP GET request on http://my-server/track?timestamp=xxxxxxxxxx&lat=xx.xxx&lon=xx.xxx
The cgi program will read and store the values of timestamp, lat, and lon.
This data may be kept in a csv file or in a rrd database.

