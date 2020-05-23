var maximum = Math.min(32, 45, 72, 3);
var power = Math.pow(2,4);
var ceil = Math.floor(1.7);

var number1 = "5";
var number2 = 6;
// alert(parseInt('ff0000',16)+number2);

// alert(isNaN("the"));
// alert(isNaN(false));

$('.button').on("click", function(){
    var input = $('#input').val();
    if(!input){
        alert('enter a number');
        return;
    }
    if(isNaN(input)){
        var type = typeof input;
        $('#result').html('is not a number, what you entered is a ' + type)
        // alert();
        return;
    }
    //alert("we've got a number");
    $('#result').html("we've got a number");
});