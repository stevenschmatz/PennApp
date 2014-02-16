var util = require('util');
var spawn = require('child_process').spawn;

process.stdin.on('data', function(input_text) {
		var current_char = [];
		var current_pair, accel = {};
		if(input_text.indexOf('STOP') == -1) {
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
				current_char.push(current_pair);
				current_pair = {};
			}
		}
		else {
			var sampledData = sample.split(currentChar, 5);
			var result = neuralNetwork.accept(sampledData);
			current_char = [];
		}
});

process.stderr.on('data', function(data) {
	console.log(data.toString('ascii'));
});