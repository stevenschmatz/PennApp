var net = new brain.NeuralNetwork();
var drive = require('./drive');

function accept(sampledData) {
	for(int i = 0; i < sampledData.length; i++) {
		var out = net.run(sampledData[i]);
		drive.write(out);
	}
}