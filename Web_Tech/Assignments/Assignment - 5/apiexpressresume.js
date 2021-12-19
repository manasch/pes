const express = require("express");
const app = express();
const path = require("path");
const {MongoClient} = require("mongodb");
app.use(express.json());
app.use(express.urlencoded({extended:true}));

const uri = "mongodb://localhost:27017/employee"

app.get("/",(req,res)=>{
    res.sendFile(path.join(__dirname,"resume.html"));
})


app.post("/login",(req,res)=>{

    const query1 = req.body;

    const main_1 = async () => {
        MongoClient.connect(uri, async (err, client) => {
            if (err) throw err;
          const check = await client.db("employee").collection("info").findOne(query1);
          if (check == null) {
            await client.db("employee").collection("info").insertOne(query1);
            client.close();
            res.send(`
                <h1> Employee inserted details</h1>
                <h2> Employee name : ${req.body.name} </h2>
                <h2> Employee date of birth : ${req.body.dob} </h2>
                <h2> Employee qualification : ${req.body.Qualification} </h2>
                <img src=${req.body.image}>Employee image</img>
                `);
        
          } else {
            res.send(`
        <h1>Data is already present in the database</h1>
        `);
        
          }
        });
      };
      main_1();
})

app.listen(4000,()=>{
    console.log("Listening to port 4000 (http://localhost:4000)");
})
