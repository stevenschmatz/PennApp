var googleapis = require('googleapis');
var readline = require('readline');

var CLIENT_ID = "986980652469-57r4d13dvbafj5u9uatj3v8mucatf4e5.apps.googleusercontent.com"
var CLIENT_SECRET = "qGalt18mkH-mM-fX-V5QMXyO"
var REDIRECT_URL = "urn:ietf:wg:oauth:2.0:oob"
var SCOPE = 'https://www.googleapis.com/auth/drive.file'

var auth = new googleapis.OAuth2Client(CLIENT_ID, CLIENT_SECRET, REDIRECT_URL);

googleapis.discover('drive', 'v2').execute(function(err, client) {
	var url = auth.generateAuthUrl({ scope: SCOPE });
	var getAccessToken = function(code) {
		auth.getToken(code, function(err, tokens) {
			if(err) {
				console.log(err);
			}
			auth.credentials = tokens;
		});
	}
});

function write(str) {
	client.drive.files.insert({ title: 'My PenApp File', mimeType: 'text/plain' }).withMedia('text/plain', str).withAuthClient(auth);
}