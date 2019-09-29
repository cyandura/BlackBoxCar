const SerialPort = require('serialport');
const Readline = SerialPort.parsers.Readline;
const sp = new SerialPort('/dev/ttyUSB0', { baudRate: 9600 });
const parser = sp.pipe(new Readline({delimiter: '\r\n'}));
sp.on('open', function() {
	setTimeout(() => {
	sp.write("0\n", function(err, res) {
		if (err) console.log(err);
	});
	}, 3000);
});
parser.on('data', (data) => {
	console.log(data);
});
