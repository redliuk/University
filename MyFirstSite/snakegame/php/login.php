<?php
session_start();
require_once('database.php');

if (isset($_POST['submit'])) {

    $email = trim($_POST["email"]);
    $password = trim($_POST["pass"]);
    
    if (empty($email) || empty($password)) {
        $msg = 'Inserisci username e password non inseriti %s';
    } 
    else {
        $stmt = mysqli_prepare($mysqli, "SELECT * FROM users WHERE email=?");
        mysqli_stmt_bind_param($stmt, 's', $email);
        
        if (!mysqli_stmt_execute($stmt)) {
            $msg = "Errore, riprova più tardi";
        }
        else {

            $result = mysqli_stmt_get_result($stmt);
            $row = mysqli_fetch_assoc($result);
            
            if (password_verify($password, htmlspecialchars($row["password"]))) {
                $_SESSION['session_id'] = session_id();
                $_SESSION['session_user'] = $row['email'];
                $msg = "Welcome " . htmlspecialchars($row['firstname']) . " !";
            } 
            else {
                $msg = "Email o password errati";
            }
            mysqli_stmt_close($stmt);
        }
    }
}
    
mysqli_close($mysqli);
$_SESSION['msg']=$msg;
header('Location: errorcatcher.php');

