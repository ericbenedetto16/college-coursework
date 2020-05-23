// $(document).ready(function(){
//     let apiBase = "https://statenweb.mockable.io/books/"
//     axios.get(apiBase)
//     .then(response => {
//         let bookHTML = response.data.map(book => {
//             return $('<p>').addClass('book').data('id', book.id).html(book.id + '. ' + book.title)
//         })
//         $('#books').html(bookHTML)
//         $('.book').on('click', function() {
//             $('#current-book').html("LOADING...")
//             let id = $(this).data('id')
//             let url = apiBase + id
//             axios.get(url)
//             .then(response => {
//                 let title = response.data.title
//                 let author = response.data.author
//                 let genre = response.data.genre
//                 let publisher = response.data.publisher
        
//                 let $title = $('<h2>').html(title)
//                 let $author = $('<h3>').html(author)
//                 let $genre = $('<h4>').html(genre)
//                 let $publisher = $('<h5>').html('Publisher' + publisher)
        
//                 $('#current-book').html([$title, $author, $genre, $publisher])
//             })
//             .catch(error => console.log(error))
//         })
//     })
//     .catch(error => console.log(error))
// })
let userInput = "Superfreakonomics"
$(document).ready(function(){
    let apiBase = "https://statenweb.mockable.io/books/"
    axios.get(apiBase)
    .then(response => {
    let found = false;
        var book = response.data.forEach(book => {
          //  debugger;
            if(book.title === userInput) {
                let $bookHTML = $('<p>').addClass('book').data('id', book.id).html(book.id + '. ' + book.title)
                $('#books').html($bookHTML);
               return;
            }
        })

        // if(!found) {
        //     $('body').html('No Match Found')
        // }

        $('.book').on('click', function() {
            $('body').html("LOADING...")
            let id = $(this).data('id')
            let url = apiBase + id
            axios.get(url)
            .then(response => {
                let title = response.data.title
                let author = response.data.author
                let genre = response.data.genre
                let publisher = response.data.publisher
        
                let $title = $('<h2>').html(title)
                let $author = $('<h3>').html(author)
                let $genre = $('<h4>').html(genre)
                let $publisher = $('<h5>').html('Publisher' + publisher)
        
                $('#current-book').html([$title, $author, $genre, $publisher])
            })
            .catch(error => console.log(error))
        })
    })
    .catch(error => console.log(error))
    $('#books').html("LOADING...")
})
