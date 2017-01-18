# Track project

This is simple cgi program to store data on a web server.

## Track my phone

This is a basic server side spec to follow the position of a cell phone.

A customer program will make an HTTP GET request on http://my-server/track?timestamp=xxxxxxxxxx&lat=xx.xxx&lon=xx.xxx

The cgi program will read and store the values of timestamp, lat, and lon.

This data may be kept in a csv file or in a rrd database.
