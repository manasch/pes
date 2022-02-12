var events = require("events")

var em = new events.EventEmitter();

var listener1 = function listner1 () {
    console.log("lisntere1 was ccalled");
}

var listner2 = function listner2 () {
    console.log("2 was claled");
}

em.addListener("connection", listener1);
em.on("connection", listner2);

var nem = events.EventEmitter.listenerCount(em, "connection");
console.log("events listening: " + nem);

em.emit("connection");