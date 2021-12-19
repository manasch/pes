const express = require("express");
const path = require("path");
const MongoClient = require("mongodb").MongoClient;

const uri = "mongodb://localhost:27017/books";
const app = express();

app.use(express.json());
app.use(express.urlencoded({ extended: true }));

app.get("/", (req, res) => {
    res.sendFile(path.join(__dirname, "watch.html"));
})

app.post("/insert", (req, res) => {
  const data = req.body;

  const main_1 = async () => {
    MongoClient.connect(uri, async (err, client) => {
      if (err) throw err;
      const check = await client
        .db("watches")
        .collection("watch")
        .findOne(data);
      if (check == null) {
        await client.db("watches").collection("watch").insertOne(data);
        client.close();
        res.send(`
          <h1> Watch data inserted details</h1>
          <h2> Model No : ${req.body.model_no} </h2>
          <h2> Model Name : ${req.body.model_name} </h2>
          <h2> Model Price : ${req.body.model_price} </h2>
          <h2> Model Company : ${req.body.model_company} </h2>
        `);
        } 
        else {
          res.send(`<h1>Data is already present in the database</h1>`);
        }
      });
    };
    main_1();
});

app.post("/login/update", (req, res) => {
  const data = {
    model_name: req.body.model_name,
    model_name : req.body.model_name
  };
  const update = {
    model_price: req.body.model_price,
  };

  const main2 = async () => {
    MongoClient.connect(uri, async (err, client) => {
        if (err) throw err;
      const check = await client.db("watches").collection("watch").findOne(data);
      if (check == null) {
        res.send(`<h1>Data is not present in the database</h1>`);
      } 
      else {
        await client.db("watches").collection("watch").updateOne(data, {
          $set: update,
        });
        client.close();
        res.send(`
        <h1> Watch details updated </h1>
        <h2> Model No : ${req.body.model_no} </h2>
        <h2> Model Name : ${req.body.model_name} </h2>
        <h2> Model Price : ${req.body.model_price} </h2>
        `);
      }
    });
  };
  main2();
});

app.listen(3000, () => {
    console.log("Listening to port 3000 (http://localhost:3000)");
})
