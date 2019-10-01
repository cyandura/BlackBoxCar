const SerialPort = require('serialport');
const path = require("path");
const app = require('express');
const server = require('http').Server(app);
const io = require('socket.io')(server);

server.listen(8092);

const sp = new SerialPort('/dev/ttyUSB0', {baudRate: 9600})

io.on('connection', function (socket) {
	console.log("user connected");
	io.on('update', function(data) {
		socket.emit('updateData',{pollOneValue:data});
	});
	socket.on('buttonClk', function(data) {
		sp.write(data);
	});
	socket.on('textIn', function(data) {
		sp.write(data);
	});
});

const Readline = SerialPort.parsers.Readline;
const parser = sp.pipe(new Readline({delimiter: '\r\n'}));
sp.on('open', function() {
        setTimeout(() => {
        sp.write("GrizzHacks 4!\n", function(err, res) {
                if (err) console.log(err);
        });
        }, 3000);
});
parser.on('data', (data) => {
        console.log(data);
});

app.get("/", (req, response) => {
    response.sendFile(path.join(__dirname + '/index2.html'));
});

app.get('/up', function(request, response) {
	sp.write('1\n')
});

