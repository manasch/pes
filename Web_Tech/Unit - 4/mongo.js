var mongoclient = require("mongodb").MongoClient;

mongoclient.connect("mongodb://127.0.0.1:27017",
    {
        useUnifiedTopology:true
    },
    function (err, client)
    {
        if (err) throw err;
        console.log("Connected...");
        var db = client.db("secB");
        db.collection("stud_info").insertOne(
        {
            "name" : "Vikram",
            "address" : "nowhere",
            "hobbies" : "online games"
        }, function (err, res)
        {
            if (err) throw err
            console.log(res.insertedCount + " document(s) inserted");
        });
        var myobjs = [
        {
            "name" : "Vikranti",
            "address" : "everywhere",
            "hobbies" : "online games"
        },
        {
            "name" : "Rahul",
            "address" : "somewhere",
            "hobbies" : "online games"
        }]
        db.collection("stud_info").insertMany(myobjs, function (err, res)
        {
            if (err) throw err;
            console.log(res.insertedCount+ " document(s) inserted");
        });
        db.collection("stud_info").find(
        {
            "hobbies" : "online games"
        }).toArray(function (err, resobjs)
        {
            if (err) throw err;
            console.log(JSON.stringify(resobjs))
        })
        db.collection("stud_info").findOne(
        {
            "address" : "nowhere"
        },
        function (err, resobjs)
        {
            if (err) throw err;
            console.log(JSON.stringify(resobjs))
        })
    })
