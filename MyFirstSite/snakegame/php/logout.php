<?php
require_once('connection.php');  

unset($_SESSION['session_id']);
unset($_SESSION['session_user']);
unset($_SESSION['msg']);

$_SESSION = array();
setcookie(session_name(),'',time() - 42000); //Cancello cookie di sessione
session_destroy();

header('Location: index.php');
