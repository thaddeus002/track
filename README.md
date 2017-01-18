# Track project

This is simple cgi program to store data on a web server. A client program is planned for the future.

## How track a cell phone ?

Here is a basic server side spec to follow the position of a cell phone :

A client program will make an HTTP GET request on http://my-server/track?timestamp=xxxxxxxxxx&lat=xx.xxx&lon=xx.xxx
The cgi program will read and store the values of timestamp, lat, and lon.
This data may be kept in a csv file or in a rrd database.

## Install the server side program

This require a functionnal web server

### Get the sources files

```bash
$ git clone https://github.com/thaddeus002/track.git
```

### Build the program

```bash
$ make
```

### Install the program

Copy the file `track` in a accessible directory of your web server, and configure the web server to consider this directory as à cgi directory.
This can be done with a `.htaccess` file.

