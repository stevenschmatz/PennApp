var util = require('util');
var spawn = require('child_process').spawn;

var x_queue = [];
var y_queue = [];

function mean(list) {
    var result = 0;
    for(var i = 0; i < list.length; i++){
       result += list[i]/list.length;
    }
    return result;
}

function x_stable_condition(curr, tolerance) {
    //Returns true if |curr-mean(q)| < tolerance.
    return Math.abs(curr - mean(x_queue)) < tolerance;
}

function y_stable_condition(curr, tolerance) {
    //Returns true if |curr-mean(q)| < tolerance.
    return Math.abs(curr - mean(y_queue)) < tolerance;
}

function iterate_x_queue(curr, tolerance) {
    if(x_stable_condition(curr, tolerance)) {
        x_queue.push(curr);
        if (x_queue.length == 4){
            return true;
        }
    }
    else {
        x_queue = null;
    }
    return false;
}

function iterate_y_queue(curr, tolerance) {
    if(y_stable_condition(curr, tolerance)) {
        y_queue.push(curr);
        if (y_queue.length == 4){
            return true;
        }
    }
    else {
        y_queue = null;
    }
    return false;
}

var current_char = [];

process.stdin.on('data', function(input_text) {
			var current_pair, accel = {};
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
			// 
		if(iterate_x_queue(current_pair['x'], 50) && iterate_y_queue(current_pair['y'], 50)) {
			var sampledData = sample.split(currentChar, 5);
			require('fs').writeFile('stuff.txt', sampledData);
			var result = neuralNetwork.accept(sampledData);
			current_char = [];
		}
});

process.stderr.on('data', function(data) {
	console.log(data.toString('ascii'));
});