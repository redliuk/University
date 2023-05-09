<?php
        session_start();
        if (isset($_SESSION['session_user'])) {
            $session_user = htmlspecialchars($_SESSION['session_user'], ENT_QUOTES, 'UTF-8');
            $session_id = htmlspecialchars($_SESSION['session_id']);
        }
        else{
            header('Location: index.php');
        }
?>