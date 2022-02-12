var h = document.querySelector('#sub');

function myfunc(){
    alert("you submitted the form!!");
    $('canvas').show()
    const canvas = document.querySelector("#canvas");
    const contex = canvas.getContext("2d");
    contex.font = '100px serif';
    contex.textAlign = "right";
    contex.textBaseline = "right";
    contex.fillText('🗿', canvas.width / 2, canvas.height / 2)

}

h.addEventListener('click',myfunc,true);

$(document).ready(function(){
    
    $("button:first").click(function(){
        $("form input").hide()
        $("body").append( $("<p>").html("I love JQuery!!!").css("color","red") )
        $("body").append( $("<button>").html("Click to remove JQuery and reveal form elements").click(function(){
            $("form input").show()
            $("p:last").remove()
            $("button:last").remove()
        }))
    })
    $("button:last").click(function(){
        $("h1:first").fadeToggle("slow")
    })
})

