<?php

  require_once('connection.php');  
  require_once('database.php');


  $query= "SELECT newsletter FROM users WHERE email='".$session_user."'";
  $check=mysqli_query($mysqli,$query);
  $row = mysqli_fetch_array($check);
  if ($row["newsletter"]) {
    $msg = 'Sei già iscritto alla nostra newsletter! ';
  }
  else{
  $query= "UPDATE users SET newsletter=1  WHERE email='".$session_user."'";
  $s=mysqli_query($mysqli,$query); 
    $msg = 'Registrazione avvenuta con successo! ';
  }

  $_SESSION['msg']=$msg;
  header('Location: errorcatcher.php');
?>


