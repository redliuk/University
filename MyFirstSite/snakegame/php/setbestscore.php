<?php
  require_once('connection.php');  
  require_once('database.php');

    $bscore = htmlspecialchars($_POST['bestscore']);
    $query= "UPDATE users SET bestscore='".$bscore."' WHERE email='".$session_user."'";
    $s=mysqli_query($mysqli,$query);
    mysqli_close($mysqli);
    header('Location: play.php');
?>