import fetch from 'node-fetch';
var http = require("http")
var options = {
    host: "localhost",
    port: "8080",
    path: "/save.txt",
    method: "post",
    body: "This is the request data..."
}

var callback = (res) => {
    let body = [];
    res.on("data", (chunk) => {
        body.push(chunk)
    })
    res.on("end", (chunk) => {
        console.log(Buffer.concat(body).toString());
    })
}

var req = http.request(options, callback);
req.write(JSON.stringify({name: "abc", srn:"1234"}))
req.end()


fetch('http://localhost:8080/save.txt', {
    method: 'post',
    body: JSON.stringify({name:"abc", srn:"1234"})
})
.then(res => res.text())
.then(res => console.log(res))
