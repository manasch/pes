// function changeCase (str) {
//     output = "";
//     for (i in str) {
//         if (str[i].toLowerCase() != str[i]) {
//             output += str[i].toLowerCase();
//             continue;
//         }

//         if (str[i].toUpperCase() != str[i]) {
//             output += str[i].toUpperCase();
//             continue;
//         }
//     }

//     console.log(output);
// }

// changeCase("HeLlo");

// numbers = [2, 5, 1, 3, 32, 9, 92];
// numbers.sort((a, b) => {
//     console.log(a, b, a- b)
//     return a - b;
// });
// console.log(numbers);

// var myA = new Array(5);
// console.log(myA);
// myA[0] = 1;
// myA[4] = 3;
// console.log(myA);
// for (i in myA) {
//     console.log(myA[i]);
// }
// myA.reverse();
// console.log(myA);

// console.log("1" == 1, "1" === 1);

// myA.length = 9;
// console.log(myA, myA.length);

// for (i in myA) {
//     console.log(i + typeof(i) + typeof(myA[i]));
// }

// var key = (a, b) => {
//     return a * b;
// }

// console.log(key(5, 6));

// var test = function (...args) {
//     console.log(args);
//     console.log(arguments);
//     return args;
// }

// console.log(test(5, 3, "sdf"));

// var nr = [1, 2, 3, 4, 5];
// console.log(nr);
// var rm = nr.splice(2, 1);
// console.log(rm, nr);

// statusbar = "this is "

// document.write("Tis is a test");
// document.write(Math.abs(-15));

// setTimeout(() => {
//     document.write("this is after timeout");
// }, 2300)

// var i = 0;
// var t = setInterval(() => {
//     document.write(i);
//     if (i == 5) {
//         clearInterval(t);
//     }
//     i++;
// }, 200)

// function sayHi(phrase) {
//     document.write(phrase);
// }

// setTimeout(sayHi, 1000, "Hel", "W");

// let tid = setInterval(() => {
//     alert("test");
// }, 1000);

// setTimeout(() => {
//     clearInterval(tid);
//     alert("STopped");
// }, 5000);

// let dt = new Date();
// console.log('date: ', dt);
// console.log('date: ', dt.getDate());
// dt.setDate(dt.getDate() + 1);
// console.log(dt.getDate());

// var count = 0;
// function log() {
//     console.log(count);
//     count++;
//     if (count == 5) {
//         clearInterval(old_t);
//         console.log(11);
//     }
// }

// var old_t = setInterval(log, 500);

// var obj = new Object();

// obj.name = "testset";
// obj.age = 12;

// for (i in obj) {
//     console.log(i, obj[i]);
// }

// let lit = {
//     name: "rebok",
//     age: 4,
//     show() {
//         console.log(lit.name, lit.age, lit.a);
//     },
//     a: 5
// }

// lit.show();

// class Key {
//     constructor(door, lock) {
//         this.door = door;
//         this.lock = lock;
//     }

//     show() {
//         console.log(this.door, this.lock);
//     }
// }

// let k = new Key(1, 1212);
// k.show()
// let lit_item = {
//     name: "Reebok",
//     price: "Rs. 2000",
//     av_qty: 20
// };

// let item1 = Object.create(lit_item);
// console.log(item1, "tt");
// /* Inherited */
// let item2 = Object.create(lit_item, {
// name: {value: "Nike"},
// price: {value: "Rs. 2500"},
// desc: {value: 'Full desc'}
// });
// console.log(item2);




function init() {
    let sub = document.querySelectorAll("div");
    console.log(sub);

    var tab = document.querySelector(".h");
    console.log(tab);
    tab.addEventListener('click', display);

    var par = document.getElementById("par");
    par.addEventListener('click', (event) => {
        console.log(event.target.innerHTML);
    })

    let prog = document.getElementById("prog");
    console.log(prog.value);

    let t = setInterval(() => {
        prog.value += 1;
        console.log(prog.value);

        if (prog.value == 100) {
            clearInterval(t);
        }
    }, 10)

    // $('#bt1').hide()
}

function colorCell(cell) {

    console.log("inside color");
    if (parseInt(cell.innerHTML) % 2 == 0) {
        cell.style.backgroundColor = "green";
    }
    else {
        cell.style.backgroundColor = "red";
    }
}

function addrow() {
    console.log("received");

    let table = document.getElementById("table1");
    console.log(table);

    var row = document.createElement("tr");
    var ce1 = document.createElement("td");
    var ce2 = document.createElement("td");
    // var row = table.insertRow(0);
    // var ce1 = row.insertCell(0);
    // var ce2 = row.insertCell(1);

    ce1.innerHTML = Math.ceil(Math.random() * (201));
    ce2.innerHTML = Math.ceil(Math.random() * (201));

    ce1.setAttribute('onClick', 'fillDiv(this)');
    ce2.setAttribute('onClick', 'fillDiv(this)');

    table.appendChild(row);
    row.appendChild(ce1);
    row.appendChild(ce2);

    colorCell(ce1);
    colorCell(ce2);
}

function fillDiv(t) {
    let div = document.getElementById("display")
    console.log(t.innerHTML);
    div.innerHTML = t.innerHTML;
}

function display() {
    console.log("received");
    // alert("clicked");
}

function setCol(event) {
    event.preventDefault()
    console.log(event.target.value);
    let col = document.querySelector("#col");
    col.value = event.target.value;
}

function setText(event) {
    let text = document.getElementById("ctext");
    text.value = event.target.value;
}

function selectop(event) {
    console.log(event.target.value);
    let sel = document.getElementById("input1");

    console.log(sel.options[sel.selectedIndex].value);
}