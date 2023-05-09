<!DOCTYPE html>
<html lang="en">
  <head> 
    <title>Profile</title>
    <link href="https://fonts.googleapis.com/css?family=Press+Start+2P" rel="stylesheet">
    <link href="https://unpkg.com/nes.css/css/nes.css" rel="stylesheet" />
    <link rel="stylesheet" type="text/css" href="\~S4865720\snakegame\css\default.css" title="default">
    <link rel="alternate stylesheet" type="text/css" href="\~S4865720\snakegame\css\light.css" title="light">
    <script type="text/javascript" src="\~S4865720\snakegame\js\cookie.js"></script>
    <link rel="stylesheet" type="text/css" href="\~S4865720\snakegame\css\style1.css" />
  </head>

<body>
  <div class=lamp>
    <form method="post" action="#" >

      <div class="nes-field" style="margin: 30px auto;">
        <label for="name_field">Old password</label>
        <input type="password" name="oldpsw" class="nes-input" required>
      </div>

      <div class="nes-field" style="margin: 30px auto;">
        <label for="name_field">New password</label>
        <input type="password" name="newpsw" class="nes-input" required>
      </div>

      <div style="margin: 30px auto;">
          <button type="submit" name="submit" class="nes-input">Confirm</button>
      </div>
      
    </form>  
  </div>

<?php
    require_once('connection.php');  
    require_once('database.php');
      
    if(isset($_POST['submit'])){

        $newpass = trim($_POST["newpsw"]);
        $newpass_hash = password_hash($newpass, PASSWORD_DEFAULT);
        $oldpass = trim($_POST["oldpsw"]);
        $pwdLenght = mb_strlen($newpass);

        if ($pwdLenght < 8 || $pwdLenght > 20) {
            $msg = 'Lunghezza minima password 8 caratteri.
                    Lunghezza massima 20 caratteri';
            $_SESSION['msg']=$msg;
            header('Location: errorcatcher.php');
        }

        $stmt = mysqli_prepare($mysqli, "SELECT password FROM users WHERE email = ?");
        mysqli_stmt_bind_param($stmt, 's', $session_user);

        if (!mysqli_stmt_execute($stmt)) {   
          $_SESSION['msg']='Errore nella lettura della vecchia password';
          header('Location: errorcatcher.php');
        }
        else {
          $result = mysqli_stmt_get_result($stmt);
          $row = mysqli_fetch_assoc($result);

          if (password_verify($oldpass,  htmlspecialchars($row['password']))) {
            $stmt = mysqli_prepare($mysqli, "UPDATE users SET password =? WHERE email=?");
            mysqli_stmt_bind_param($stmt, 'ss', $newpass_hash,  $session_user);
            if (mysqli_stmt_execute($stmt)) {
              $msg = 'Modifica effettuata con successo';
            } 
            else {
              $msg = 'Impossibile effettuare la modifica';
            }
          } 
          else{
            $msg ='Old password wrong';
          }
        }
        mysqli_stmt_close($stmt); 
        mysqli_close($mysqli);

        $_SESSION['msg']=$msg;
        header('Location: errorcatcher.php');
    }
?>
</body>
</html>