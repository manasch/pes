// n = 1;

// function print() {
//     console.log("This is " + n);
//     n++;
//     if (n == 10)
//         clearTimeout(t)
// }

// t = setInterval(print, 10)

// var fs = require("fs");
var mymod = require("./mymodule.js");

// var data = fs.readFileSync("data.txt", "utf-8");
console.log(mymod.myadd(10, mymod.MYCONST));

// setTimeout(() => {
//     console.log("timer stopped");
// }, 2000);
// console.log(("timer started"));