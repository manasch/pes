var http = require("http")
var options = {
    host: "localhost",
    port: "3000",
    path: "/greeting",
    method: "post",
    headers: {'Content-type': 'application/x-www-form-urlencoded'}
}

var callback = (res) => {
    let body = []
    res.on("data", (chunk) => {
        body.push(chunk)
    })
    res.on("end", () => {
        console.log(Buffer.concat(body).toString());
    })
}

var req = http.request(options, callback);
// req.write(JSON.stringify({name: "abc", srn: "1234"}))
req.write('name=abcd&srn=12345')
req.end()
