var net = require('host');

var server = net.createServer(function(socket) {
	var currentChar = [];
	socket.on('accelData', function(buffer) {
		var accel = JSON.parse(buffer.toString('ascii'));
		currentChar.push(accelData);
	});
	socket.on('accelDone', function(buffer) {
		var sampledData = sample.split(currentChar, 5);
		var result = neuralNetwork.accept(sampledData);
		socket.write(new Buffer(result, 'utf-8'));
	});
});

server.listen(1997, '158.130.160.226')