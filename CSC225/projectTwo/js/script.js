$(".card-hover").hover(
  function() {
    if($(this).siblings().length < 1) {
      $(this).parent(0).append("<a href='"+$(this).parent(0).attr('id')+".html' class='remove w-100 top-50 position-absolute align-middle btn btn-lg btn-primary'>See More</a>");
      $(this).css("opacity", 0.3)}
    },
  function() {
    $(".card").hover(
    function(){},
    function(){
      $('.remove').remove();
      $(this).children().css("opacity", 1);
    }
  )}
);
