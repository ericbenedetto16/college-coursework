var n = 0;

$('#addTask').on("click", createTask);

$('#input').on("keypress", function(e) {
  if(e.which == 13) {
    createTask();
  }
});

function createTask() {
  var task = $('#input').val();
  if(task == "" || task === null){
    $('.form-group').prepend('<div class="alert alert-danger alert-dissmissable fade show" role="alert"> Please Enter A Task! <button type="button" class="close" data-dismiss="alert" aria-label="Close"><span aria-hidden="true">&times;</span></button></div>');
    return;
  }
  n++;
  $('#tasks').append('<p id="task-' + n + '" class="col-12 col-md-8 col-xl-6 align-self-middle">' + task + ' <button id="remove" title="Remove Item" onclick="removeTask($(this))" class="close task-'+ n +'">&times;</button> </p>');
  $('#input').val("");
}

function removeTask(e) {
  $('p#' + e.attr('class').split(' ')[1]).remove()
}
