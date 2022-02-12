var http = require("http");
var url = require('url');

http.createServer(function (request, response) {
    response.writeHead(200, {'Content-type': 'text/html'});
    response.end("PAIN");
}).listen(8080);
console.log("server running at http://localhost:8080");
