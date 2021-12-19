// const buf1 = Buffer.alloc(10, 'Hi Welcome');
// const buf2 = Buffer.alloc(17, 'to PES University');

// // var buf = new Buffer(10)
// // buf.write()
// // alloc() does the above 2 steps

// console.log(buf1.toString());
// var buf = Buffer.concat([buf1, buf2], buf1.length + buf2.length);

// console.log(buf.toString());

var fs = require("fs");
var rstr = fs.createReadStream("data.txt", "utf-8");
var fdata = '';
rstr.on('data', (chunk) => {
    fdata += chunk;
})

rstr.on('err', (err) => {
    console.log(err.stack);
})

rstr.on('end', () => {
    console.log(fdata)
})

var wstr = fs.createWriteStream("data1.txt", "utf-8");
// wstr.setDefaultEncoding('utf-8');
wstr.write("This is a write to the stream");
wstr.end();