var SAMPLING_RATE = 16;
var nets = [];

for(var i = 0; i < SAMPLING_RATE; i++) {
	nets.push(new brain.NeuralNetwork());
}

var drive = require('./drive');

function train(sampledData, char) {
	for(var i = 0; i < SAMPLING_RATE; i++) {
		nets[i].train([{input: sampleData[i], output: char.charCodeAt(0)}]);
	}
}

function accept(sampledData) {
	for(int i = 0; i < SAMPLING_RATE; i++) {
		var out = nets[i].run(sampledData[i]);
	}
	return decide(nets);
}

