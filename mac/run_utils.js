var util = require('util');
var spawn = require('child_process').spawn;

function mean(list) {
    var result = 0;
    for(var i = 0; i < list.length; i++){
       result += list[i]/list.length;
    }
    return result;
}

function x_stable_condition(x_queue, curr, tolerance) {
    //Returns true if |curr-mean(q)| < tolerance.
    return Math.abs(curr - mean(x_queue)) < tolerance;
}

function y_stable_condition(y_queue, curr, tolerance) {
    return Math.abs(curr - mean(y_queue)) < tolerance;
}

function iterate_x_queue(x_queue, curr, tolerance) {
    if(x_stable_condition(x_queue, curr, tolerance)) {
        x_queue.push(curr);
				console.log('current value ' + curr + ' is within ' + tolerance + ' of ' + mean(x_queue));
				console.log('length: ' + x_queue.length);
        if (x_queue.length == 4){
            return 0;
        }
    }
    else {
        x_queue = null;
    }
    return x_queue;
}

function iterate_y_queue(y_queue, curr, tolerance) {
    if(y_stable_condition(y_queue, curr, tolerance)) {
        y_queue.push(curr);
        if (y_queue.length == 4){
            return 0;
        }
    }
    else {
        y_queue = null;
    }
    return y_queue;
}

exports.iterate_x_queue = iterate_x_queue;
exports.iterate_y_queue = iterate_y_queue;
exports.x_stable_condition = x_stable_condition;
exports.y_stable_condition = y_stable_condition;
exports.mean = mean;