<?php
  require_once('connection.php');  
  require_once('database.php');

    if(isset($_POST['submit'])){

      if ($_POST['firstname'] == "" || $_POST['lastname'] == "" || $_POST['email'] == "") {
        $msg = "errore nell'update, i campi inseriti non possono essere vuoti";
      }
      else{
        $firstname = trim($_POST["firstname"]);
        $lastname = trim($_POST["lastname"]);
        $email = trim($_POST["email"]);
        $note = trim($_POST["note"]);

        $stmt = mysqli_prepare($mysqli, "UPDATE users SET firstname=?, lastname=?, email=?, note=? WHERE email=?");
        mysqli_stmt_bind_param($stmt, 'sssss', $firstname, $lastname, $email, $note, $session_user);
        
        if (mysqli_stmt_execute($stmt)) {
            $msg = 'Update effettuato';
            $_SESSION['session_user'] = $_POST['email'];
        } 
        else {
            $msg = 'Update non effettuato';
        }
        mysqli_stmt_close($stmt); 
        mysqli_close($mysqli);
      }
    $_SESSION['msg']=$msg;
    header('Location: errorcatcher.php');
    }
?>






