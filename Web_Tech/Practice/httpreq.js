var http = require("http");
var url = require("url");
var qs = require("querystring");
var fs = require("fs")
const { parse } = require("path");


const server = http.createServer(function (req, res) {
    var myUrl = url.parse(req.url, true);
    console.log(myUrl.query.op1);
    
    // if (req.method == "GET") {
    //     var result = parseInt(myUrl.op1) + parseInt(myUrl.op2);
    //     result = result.toString();
        

    // }

    var pname = myUrl.pathname;
    var fname = "";
    console.log(pname);

    if (pname == "/") {
        fname = "test.html"
    }
    else {
        fname = pname.substring(1);
    }

    if (req.method == "GET") {
        fs.readFile(fname, "utf-8", (err, fd) => {
            // if (err) console.log(err);

            res.writeHead(200, {"content-type" : "text/html"});
            res.write(fd);
            res.end();
        })
    }


    res.end();
}).listen(8080, () => {
    const { address, port } = server.address();
    console.log(address, port, server.address());
})
console.log("server running on http://localhost:8080");