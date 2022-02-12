const http = require("http");
const url = require("url");
const MongoClient = require("mongodb").MongoClient;
const murl = "mongodb://127.0.0.1:27017";
var mealtime = require("./mealtime");
var dbCreate = require("./dbcreation");

const topology = {
    useUnifiedTopology : true
}

dbCreate.createDB();

http.createServer(function(req, res) {
    
    if (req.url != '/favicon.ico') {
        
        if (req.method == "GET") {
            MongoClient.connect(murl, topology, (err, client) => {
                if (err) throw err;
                
                var mdb = client.db("healthcare");
                console.log("Connected to " + mdb.databaseName);
                
                mdb.collection("hospital").find({}, {projection : {_id : 0}}).limit(1).sort({"hsp_id" : "-1"}).toArray((err, data) => {
                    if (err) throw err;
                    console.log(data);
                    
                    client.close();
                    res.writeHead(200, {"Content-type" : "application/json"});
                    res.end(JSON.stringify(data));
                })
            })
        }
        else {
            let body = [];
            req.on("data", (chunk) => {
                body.push(chunk);
            });
            req.on("end", () => {
                body = Buffer.concat(body).toString();
            })
            
            MongoClient.connect(murl, topology, (err, client) => {
                if (err) throw err;
                
                var mdb = client.db("healthcare");
                console.log("Connected to " + mdb.databaseName);
                
                mdb.collection("hospital").insertOne(JSON.parse(body), (err, data) => {
                    if (err) throw err;
                    console.log(data);
                    
                    client.close();
                    res.writeHead(200, {"Content-type" : "application/json"});
                    res.end(JSON.stringify(data));
                })
            })
        }
    }
  
}).listen(8081);

console.log("Lisenting on http://localhost:8081");
mealtime.mealTime();
