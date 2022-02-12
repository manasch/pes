exports.mealTime = () => {
    const today = new Date(2021, 12, 11, 12, 00, 0, 0);
    const breakfast = new Date(today.getFullYear(), today.getMonth(), today.getDate(), 7, 00, 0, 0);
    const lunch = new Date(today.getFullYear(), today.getMonth(), today.getDate(), 12, 30, 0, 0);
    const dinner = new Date(today.getFullYear(), today.getMonth(), today.getDate(), 20, 30, 0, 0);
    
    if (today < breakfast) {
        console.log("Breakfast Time");
    }
    else if (breakfast < today < lunch) {
        console.log("Lunch Time");
    }
    else if (lunch < today < dinner) {
        console.log("Dinner Time");
    }
    else {
        console.log("Sleep Time");
    }
}
