this.onmessage = (event)=>{
    console.log(event.data);
    if(typeof(event.data == "number"))
    {
        d = event.data;
        fact = 1;
        while(d){
            fact *= d;
            d--;
        }
        this.postMessage(fact);
    }
}