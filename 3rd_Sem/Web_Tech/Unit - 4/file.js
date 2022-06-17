var fs = require("fs");
var data = Buffer.alloc(200, 0);

fs.open("data.txt", "r", (err, fd) => {
    if (err) throw err

    fs.read(fd, data, 0, 200, 0, (err, bytes, buf) => {
        if (err) throw err
        console.log(bytes + " bytes read " + buf + data);

        fs.appendFile("data2.txt", buf, (err) => {
            if (err) throw err
        })
    })

    fs.close(fd, (err) => {
        if(err) throw err;
    });
})

// var data = fs.readFileSync("datanew.txt", "utf-8");

// var lines = data.split(/\r?\n/); // \r\n or \n

// lines.forEach((line) => {
//     console.log(line);
// })

var rl = require("readline");

var r = rl.createInterface({
    input: process.stdin, // fs.createReadStream("datanew.txt")
    output: process.stdout,
    terminal: true
})

r.on("line", (line) => {
    console.log(line);
})