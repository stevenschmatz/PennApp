var iterate_x_queue = require('./run_utils').iterate_x_queue;
var iterate_y_queue = require('./run_utils').iterate_y_queue;
var x_stable_condition = require('./run_utils').x_stable_condition;
var y_stable_condition = require('./run_utils').y_stable_condition;
var mean = require('./run_utils').mean;
var sample = require('./sample');
var neuralNetwork = require('./NeuralNetwork');

global.x_queue = [];
global.y_queue = [];

var current_char = [];

process.stdin.on('data', function(input_text) {
	var current_pair = {};
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
		if(!is_first) {
			is_first = true;
			global.x_queue.push(current_pair['x']);
			global.y_queue.push(current_pair['y']);
		}
		else {
			if(iterate_x_queue(global.x_queue, current_pair['x'], 50) == 0 || iterate_y_queue(global.y_queue, current_pair['y'], 50) == 0) {
				var sampledData = sample.split(current_char, 5);
				var result = neuralNetwork.accept(sampledData);
				current_char = [];
			}
		}
});

process.stderr.on('data', function(data) {
	console.log(data.toString('ascii'));
});