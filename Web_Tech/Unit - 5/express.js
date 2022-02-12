var express = require("express");
var bodyparser = require("body-parser");
var app = express();

var router = require("./greeting.js")
app.use(express.json())

app.use("/greeting", router)
app.post("/greeting", function(req, res) {
    res.send("Got a POST request with " + JSON.stringify(req.body))
})

// app.get("/greeting", function(req, res) {
//     res.send("<h2>Hello there</h2>")
// })

//http://localhost:3000/greeting/1
// app.get("/greeting/:gid", function(req, res) {
//     var msgs = ['', 'Hello There', 'Good Morning', 'Hey there']
//     res.send("<h2>" + msgs[req.params.gid] + '</h2>');
// })

// app.get("/greeting/:gid/:to", function(req, res) {
//     var msgs = ['', 'Hello There', 'Good Morning', 'Hey there']
//     res.send("<h2>" + msgs[req.params.gid] + req.params.to + '</h2>');
// })


// app.use("/greeting", function(req, res, next) {
//     console.log("My Func 1");
//     next()
// })

// app.use("/greeting", function(req, res, next) {
//     console.log("My Func 2");
//     next()
// })

// app.get("/greeting", function(req, res, next) {
//     res.send("This is the get request for greeting")
//     console.log("GET router for greeting");
//     next()
// })

// app.use("/greeting", function(req, res, next) {
//     console.log("My Func 3");
//     // res.send("New get request")
//     next()
// })

// app.use("/greeting", function(req, res) {
//     console.log("My Func 4");
// })

app.listen(3000);