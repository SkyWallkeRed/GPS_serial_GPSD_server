const gpsd = require('node-gpsd');
const SerialPort = require('serialport');
const Readline = require('@serialport/parser-readline');
// const port = new SerialPort('/dev/ttyACM0', { baudRate: 9600 });
const port = new SerialPort('/dev/cu.usbmodem14101', {baudRate: 9600});
const parser = port.pipe(new Readline({delimiter: '\n'}));
// Read the port data
let Latitude = '';
let Longitude = '';
port.on("open", () => {
    console.log('serial port open');
});
const daemon = new gpsd.Daemon({
    program: '/usr/local/sbin/./gpsd',
    device: '/dev/cu.SLAB_USBtoUART',
    port: 2947,
    pid: '/tmp/gpsd.pid',
    readOnly: false,
    logger: {
        info: function () {
        },
        warn: console.warn,
        error: console.error
    }
});
daemon.start(function () {
    console.log('Started');
});

setTimeout(() => {
    daemon.stop(function () {
        console.log('Stopped');
    });
}, 120000); // 1 min
// pm2 delete all && pm2 start --name=logger packages/log-server/dist/main.js -i max --max-memory-restart 1G  && pm2 log
