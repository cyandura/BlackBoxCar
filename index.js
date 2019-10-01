
const SerialPort = require('serialport');

const path = require("path");
const express = require("express");

const app = express();
const port = 8090;

const http = require('http');

const sport = new SerialPort('/dev/ttyUSB0', {baudRate: 9600})

//Points to where all static files where the styling and assets are
app.use(express.static(path.join(__dirname, "/")));

app.get("/", (req, response) => {
    response.sendFile(path.join(__dirname + '/index.html'));
    sport.write('1\n')
});

app.listen(port, () => {
  console.log(`Listening to requests on http://localhost:8090`);
});

app.get('/up', function(request, response) {
	sport.write('1\n')
});

app.get('/down', function(request, response) {
	sport.write('1\n')
});

app.get('/left', function(request, response) {
	sport.write('1\n')
});

app.get('/right', function(request, response) {
	sport.write('1\n')
});