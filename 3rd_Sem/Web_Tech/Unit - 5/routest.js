var express =  require("express");
var router = express.Router();

router.get("/:from/:to", function (req, res) {
    console.log(req.params.from, req.params.to);
    res.end();
})

module.exports = router;