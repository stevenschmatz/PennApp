function split(char, sample_rate) {
	var result = []
	for(var i = 0; i < char.length; i+= sample_rate) {
		result.push(char[i]);
	}
	return result;
}

exports.split = split;