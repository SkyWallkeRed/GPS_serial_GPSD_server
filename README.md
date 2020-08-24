# GPS_serial_GPSD_server
#

<p>
 <img src="https://github.com/SkyWallkeRed/SkyWallkeRed/blob/master/Screen%20Shot%202020-08-24%20at%2011.44.19.png" width="200">
 <img src="https://github.com/SkyWallkeRed/GPS_serial_GPSD_server/blob/master/Screen%20Shot%202020-08-24%20at%2018.43.09.png">
</p>


This is a raw working draft of an: Arduino serial GPS module => node serial => gps.js(parser) => to GPSD local server that 3rd party software can connect to.

(implemented on mac) => PC user need to change some port connection from tty... to COM... (//TODO: config file)

#### whats in?:
* arduino promini + GPS Module(NEO-6m) working code .ino file
* index.js to start local GPSD server (there is a timeout after 1 min change as needed)
* gps.js modified for connections.

#### I used QGPS as GUI, after map download works offline.

#### its not a plug and play ! there are some config files needed to change (//TODO: config file )



start GPS dashboard  
 `node node_modules/gps/examples/dashboard/server.js`  
start GPSD server  
 `node index.js` 
 server will be on:
 `localhost:2947`
 
 // upload hardware schema 
 // device led indicator schema
