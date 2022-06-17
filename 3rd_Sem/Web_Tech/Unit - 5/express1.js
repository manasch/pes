var express = require("express");
var app = express();

app.use(function(err, req, res, next) {
    console.log(err.stack)
    res.status(500).send("Something went wrong")
})

app.get("/", function(req, res, next) {
    if (req.query.srn.indexOf("0000") == -1) {
        var err = new Error("Invalid SRN");
        next(err);
    }
})

app.use(function(req, res, next) {
    res.send("everything is fine")
})
app.listen(3000);