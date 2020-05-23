$(document).ready(function(){

    $('button').on('click', function() {
        if($('#zip').val() != "" && $('#zip').val() != null) {
            console.log('hello')
            $zip = $('#zip').val()
                axios.get('https://api.openweathermap.org/data/2.5/weather?zip=' + $zip +'&appid=1769f945762d3d38c79827466213d723')
                    .then(res => {
                        let condition = res.data.weather[0]['main']
                        let sky = res.data.weather[0]['description']
                        let temp = ((res.data.main['temp']-273.15) * (9/5) + 32).toFixed(2) + ' °F'
                        let humidity = res.data.main['humidity']
                        let high = ((res.data.main['temp_min']-273.15) * (9/5) + 32).toFixed(2) + ' °F'
                        let low = ((res.data.main['temp_max']-273.15) * (9/5) + 32).toFixed(2) + ' °F'
                        let windSpeed = res.data.wind['speed'] + ' mph'
                        let windDeg = res.data.wind['deg'] + '°'

                        $('#area').html('Current Weather For ' + $zip)
                        $('#condition').html(condition)
                        $('#sky').html(sky)
                        $('#temp').html(temp)
                        $('#humidity').html(humidity)
                        $('#high').html(high)
                        $('#low').html(low)
                        $('#wind').html(windSpeed + ' @ ' + windDeg)
                    })
                    .catch(err => {
                        console.log(err)
                        $('body').prepend('<div class="alert alert-danger rounded-0 text-center" role="alert">Error: Zip Code Not Found!</div>')
                        window.setTimeout(function() {
                            location.reload()
                        }, 3000)
                    })
                        $('#condition').html('Loading...')
                        $('#sky').html('Loading...')
                        $('#temp').html('Loading...')
                        $('#humidity').html('Loading...')
                        $('#high').html('Loading...')
                        $('#low').html(low)
                        $('#wind').html('Loading...')
        }
    })
})