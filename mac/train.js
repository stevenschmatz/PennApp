var sample = require('./sample');
var neuralNetwork = require('./NeuralNetwork');

var current_char_index = 0;
var chars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890.!?';
var current_char_training_set = [];

process.stdin.on('data', function(input_text) {
	var currentCharacter = chars[current_char_index];
	var current_pair = {};
	if(input_text.indexOf('CHANGE') == -1) {
		var first_index = input_text.indexOf(':');
	  var var_index = input_text.indexOf(':', first_index+1)-1;
	  var variable_name = input_text.charAt(var_index);
	  var value_end_index = input_text.indexOf('\n');
		var value = input_text.substring(var_index+2,value_end_index);
		if(variable_name == 'x') {
				current_pair['x'] = parseInt(value);
			}
			else {
				current_pair['y'] = parseInt(value);
				current_char_training_set.push(current_pair);
				current_pair = {};
			}
		}
		else {
			var sampledData = sample.split(current_char_training_set, 5);
			var result = neuralNetwork.train(sampledData, currentChar);
			current_char_training_set = [];
		}
});

process.stderr.on('data', function(data) {
	console.log(data.toString('ascii'));
});

process.on('exit', function(code) {
	var nets = neuralNetwork.nets();
	for(int i = 0; i < nets.length(); i++) {
		var netjson = nets[i].toJSON();
		require('fs').writeFile("~/pennapp/mac/training/net"+i);
	}
});