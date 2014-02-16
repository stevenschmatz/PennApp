function split(c, sample_rate) {
	var result = [];
	if(c.length % sample_rate != 0) {
		c = c.slice(0, c.length - (c % sample_rate));
	}
	for(var i = 0; i < char.length; i+= c.length/sample_rate) {
		result.push(c[i]);
	}
	return result;
}

exports.split = split;