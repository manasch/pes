var fetch = require("cross-fetch");

const url = "http://localhost:8081";


fetch(url, {
    method: "POST",
    headers: {"Content-type" : "application/json"},
    body: JSON.stringify({"hsp_id" : "3", "hsp_name" : "abd", "hosp_dept" : "abdd", "hsp_timings" : "9-9"})
})
.then(res => console.log(res))


fetch(url, {
    method: "POST",
    headers: {"Content-type" : "application/json"},
    body: JSON.stringify({"hsp_id" : "4", "hsp_name" : "abc", "hosp_dept" : "abdc", "hsp_timings" : "9-12"})
})
.then(res => console.log(res))


fetch(url, {
    method: "GET",
    headers: {"Content-type" : "application/json"}
})
.then(res => res.json())
.then(res => console.log(res))
