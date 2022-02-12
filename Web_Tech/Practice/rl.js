const readl = require("readline");
const fs = require('fs');

var rl = readl.createInterface({
    input: fs.createReadStream("test.html"),
    output: process.stdout,
    terminal: true
})

rl.on("line", (data) => {
    console.log(data);
})