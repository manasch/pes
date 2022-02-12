const express = require("express");
const app = express();
const path = require("path");
const { MongoClient } = require("mongodb");
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

const uri = "mongodb://localhost:27017/Books";

app.get("/", (req, res) => {
  res.sendFile(path.join(__dirname, "watch.html"));
});

app.post("/insert", (req, res) => {
  const query1 = req.body;

    const main_1 = async () => {
        MongoClient.connect(uri, async (err, client) => {
            if (err) throw err;
          const check = await client
            .db("watches")
            .collection("watch")
            .findOne(query1);
          if (check == null) {
            await client.db("watches").collection("watch").insertOne(query1);
            client.close();
            res.send(`
                <h1> New Watch details</h1>
                <h2> book ID : ${req.body.model_no} </h2>
                <h2> book Name : ${req.body.model_name} </h2>
                <h2> book Price : ${req.body.model_price} </h2>
                <h2> book Author : ${req.body.model_company} </h2>
                `);
        
          } else {
            res.send(`
        <h1>Data is already present in the database</h1>
        `);
        
          }
        });
      };
      main_1();
});

app.post("/insert/update", (req, res) => {
  const query2 = {
    model_name: req.body.model_name};
  const update = {
    model_price: req.body.model_price,
  };

  const main2 = async () => {
    MongoClient.connect(uri, async (err, client) => {
        if (err) throw err;
      const check = await client.db("watches").collection("watch").findOne(query2);
      if (check == null) {
        res.send(`<h1>Data is not present in the database</h1>`);
      } 
      else {
        await client.db("watches").collection("watch").updateOne(query2, {
          $set: update,
        });
        client.close();
        res.send(`
        <h1> Watch updated details</h1>
        <h2> Model No : ${req.body.model_no} </h2>
        <h2> Model Name : ${req.body.model_name} </h2>
        <h2> Model Price : ${req.body.model_price} </h2>
        `);
      }
    });
  };
  main2();
});

app.get("/update", (req, res) => {
  res.sendFile(path.join(__dirname, "update.html"));
});

app.listen(3000, () => {
  console.log("Listening to port 3000 (http://localhost:3000)");
});
