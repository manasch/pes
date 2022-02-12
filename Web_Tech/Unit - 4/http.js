var http = require("http");
var url = require("url");
var fs = require("fs");
http.createServer(function(req, res) {
    // res.writeHead(200, {"Content-type": "text/html"});
    // res.write("<h2>Welcome to my page</h2>");
    // res.write("<h3>NO</h3>");
    // res.end();

    var myurl = url.parse(req.url);
    var pname = myurl.pathname;

    if (pname == '/')
            var fname = "index.html";
        else
            fname = pname.substr(1);

    if(req.method == "GET") {
        // if (pname == '/')
        //     var fname = "index.html";
        // else
        //     fname = pname.substr(1);
        
        fs.readFile(fname, "utf-8", function(err, data) {
            if(err) {
                res.writeHead(404, {"Content-type": "text/html"});
                res.write("<h2>File not found</h2>");
                res.end();
            }
            else {
                res.writeHead(200, {"Content-type": "text/html"});
                res.write(data);
                res.end()
            }
        })
    }
    if(req.method == "POST") {
        
        let body = [];

        req.on('data', (chunk) => {
            body.push(chunk);
        })
        req.on('end', () => {{
            var reqdata = Buffer.concat(body).toString();
            fs.appendFile(fname, reqdata, (err) => {
                if(err) {
                    res.writeHead(500, {"Content-type": "text/html"});
                    res.write("<h2>Internal server error</h2>"); // can be ignored as browser has an internal resonse for the error code
                    res.end();
                }
                else {
                    res.writeHead(200, {"Content-type": "text/html"});
                    res.write(("<h1>FILE PRESENT</h1>"));
                    res.end();
                }
            })
        }})
    }
}).listen(8080);

console.log("server running at http://localhost:8080");