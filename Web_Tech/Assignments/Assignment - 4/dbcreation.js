const mongoClient = require("mongodb").MongoClient;
const murl = "mongodb://127.0.0.1:27017";
const topology = {
    useUnifiedTopology : true
}

exports.createDB = () => {
    mongoClient.connect(murl, topology, (err, client) => {
        if (err) throw err;
        console.log("Database created and connected");
        const dbase = client.db("healthcare");
        dbase.createCollection("hospital", (err, res) => {
            if (err) throw err;
            console.log("Collection created");
            client.close();
        })
    }) 
}
