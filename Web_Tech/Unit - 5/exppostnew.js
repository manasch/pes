var express = require("express");
var app = express()
var multer = require("multer");
var upload = multer();
var fileupload = require("express-fileupload")

// app.use(upload.array()
app.use(fileupload()) //req.files
// app.use(express.json()); // json message in request -> req.body
// app.use(express.urlencoded()); // name=abc&srn=1234 -> req.body

// app.post("/greeting", function(req, res) {
//     res.send("Got a POST request with -" + JSON.stringify(req.body))
// })

app.post("/upload", function(req, res) {
    if(!req.files || Object.keys(req.files).lenght == 0) {
        res.status(400).send("No files sent for upload");
        return;
    }
    var file = req.files.assignment;
    files.mv("files/" + file.name, function(err) {
        if(err){
            res.status(500).send(err)
            return;
        }
        res.send("File Uploaded Successfully");
    })
})

app.get("/form", function(req, res) {
    // res.send("<form action='/greeting' method='post'>Name:<input
    //  name='name'/><br/>SRN:<input name='srn'/><br/><button 
    //  type='submit'>Submit</button></form>")
    // can use multiple res.write and then res.end
    
    res.send("<form action='/upload' encType='multipart/form-data' method='post'>File:<input type='file' name='assignment'/><br/><button type='submit'>Submit</button></form>")
})

app.listen(3000)
