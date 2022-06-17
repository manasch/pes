function displayTime(){
    const d1 = new Date();
    document.write("<p align = right>" + d1.getDate() + "/" + (d1.getMonth() - 0 + 1) + "/" + d1.getFullYear() + " " + d1.getHours() + ":" + d1.getMinutes() + "</p>")
}
displayTime()