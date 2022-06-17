var express = require("express");
// var bodyparser = require("body-parser");
var router = express.Router();

// router.use(bodyparser.json())

// http://localhost:3000/greeting/gid/to
router.get("/:gid/:to", function(req, res) {
    var msgs = ['', 'Hello There', 'Good Morning', 'Hey there']
    res.send("<h2>" + msgs[req.params.gid] +  " " + req.params.to + '</h2>');
})

// http://localhost:3000/greeting?gid=1&to=Rajesh
router.get("/", function(req, res) {
    var msgs = ['', 'Hello There', 'Good Morning', 'Hey there']
    res.send("<h2>" + msgs[req.query.gid] + req.query.to + '</h2>');
})

console.log("test");
// router.post("/", function(req, res) {
//     res.send("Got a POST request with " + JSON.stringify(req.body))
// })
module.exports = router;
