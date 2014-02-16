var util = require('util');
var spawn = require('child_process').spawn;

var pebble_build = spawn('pebble', ['build']);
var pebble_install = spawn('pebble', ['install', '--phone', '158.130.164.180']);
var pebble_log = spawn('pebble', ['logs', '--phone', '158.130.164.180']);

pebble_log.stdout.on('data', function(data) {
	var buffer = '' // CHANGE LATER....
	var accel = JSON.parse(buffer.toString('ascii'));
	currentChar.push(accelData);
	
});