$('form').on('submit', function(e){
    e.preventDefault();
    var billAmount = parseFloat($('#billAmount').val());
    var numberOfPeople = parseFloat($('#numberOfPeople').val()),
        tipPercentage = parseFloat($('#tipPercentage').val());

    var tipAmount = billAmount* tipPercentage/100;
    var fullTotal = (billAmount + tipAmount).toFixed(2);
    var totalPerPerson = fullTotal/numberOfPeople.toFixed(2);
    
    var html = '<p>Full total: $' + fullTotal + '</p>';
    html = html + '<p>Per person $' + totalPerPerson + '</p>';
    
    $('#result').html(html);
        
    
});