$(document).ready(function(){
    $('button').on('click', function(){
        if($(this).parent().prev().find('.input').val() != '' || $(this).prev().val() === null) {
            let suffix = $(this).attr('id')
            let baseUrl = "https://statenweb.mockable.io/conversions/"
            axios.get(baseUrl)
                .then(res => {
                    let conversionRate;
                    switch(suffix) {
                        case 'centimetersInInch':
                            conversionRate = res.data.centimetersInInch
                            break
                        case 'inchesInCm':
                            conversionRate = res.data.inchesInCm
                            break  
                        default:
                            $('body').prepend('<div class="alert alert-danger fade show text-center rounded-0" role="alert">Error: Internal Error (Server Did Not Recognize Input Type) !</div>')
                            setTimeout(function(){$('.alert').alert('close')}, 2000)
                            break
                    }
                    $(this).parent().prev().find('.output').val((conversionRate * $(this).parent().prev().find('.input').val()).toFixed(2))
                })
            }else{
                $('body').prepend('<div class="alert alert-danger fade show text-center rounded-0" role="alert">Error: Invalid Input!</div>')
                setTimeout(function(){$('.alert').alert('close')}, 2000)
            }
        })
})