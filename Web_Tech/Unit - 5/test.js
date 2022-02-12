var express = require("express");
var app = express();

var router = require("./routest");

// app.get("/home/:from/:to", function (req, res) {
//     // console.log(req, res);
//     console.log(req.params.from, req.params.to);
//     res.end();
// })

app.use("/home", router);

app.listen(3000);