var neuralNetwork = require('./neuralNetwork');
var bluetooth = new(require('bluetooth-serial-port')).BluetoothSerialPort();

btSerial.on('found', function(address, name) {
	btSerial.findSerialPortChannel(address, function(channel) {
		btSerial.connect(address, channel, function() {
			btSerial.on('gestureData', function(buffer) {
				var gesture = JSON.parse(buffer.toString('ascii'));
				var sampledData = sample.split(buffer, 5);
				var result = neuralNetwork.accept(sampledData);
				btSerial.write(new Buffer(result, 'utf-8'));
			});
		});
	});
});