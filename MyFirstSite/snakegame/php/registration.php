
<?php
if (isset($_POST['submit'])) {
    session_start();
    if ($_POST['firstname'] == "" || $_POST['lastname'] == "" || $_POST['email'] == "" || $_POST['pass'] == "" || $_POST['confirm'] == "" ) {
        $msg = "errore nell'update, i campi inseriti non possono essere vuoti";
    } 
    else {
        
        require_once('database.php');
        $firstname = trim($_POST["firstname"]);
        $lastname = trim($_POST["lastname"]);
        $password = trim($_POST["pass"]);
        $confirm = trim($_POST["confirm"]);
        $email = trim($_POST["email"]);

        $isFirstnameValid = filter_var(
            $firstname,
            FILTER_VALIDATE_REGEXP, [
                "options" => [
                    "regexp" => "/^[a-z\d]{3,20}$/i"
                ]
            ]
        );

        $isLastnameValid = filter_var(
            $lastname,
            FILTER_VALIDATE_REGEXP, [
                "options" => [
                    "regexp" => "/^[a-z\d]{3,20}$/i"
                ]
            ]
        );

        $isEmailValid = filter_var(
            $email,
            FILTER_VALIDATE_REGEXP, [
                "options" => [
                    "regexp" => "/^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,3})$/"
                ]
            ]
        );

        $pwdLenght = mb_strlen($password);
        
        if (!($password === $confirm)) {
            $msg = 'Password di conferma diversa';
        } elseif (false === $isFirstnameValid || false === $isLastnameValid) {
            $msg = 'Nome o cognome non valido. Sono ammessi solamente caratteri 
                    alfanumerici. Lunghezza minina 3 caratteri.
                    Lunghezza massima 20 caratteri';
        } elseif ($pwdLenght < 8 || $pwdLenght > 20) {
            $msg = 'Lunghezza minima della password 8 caratteri.
                    Lunghezza massima 20 caratteri';
        } elseif (false === $isEmailValid) {
            $msg = 'E-mail non valida';
        }
        else {
            $password_hash = password_hash($password, PASSWORD_BCRYPT);

            $stmt = mysqli_prepare($mysqli, "INSERT INTO users (firstname, lastname, email, password) VALUES (?, ?, ?, ?)");
            mysqli_stmt_bind_param($stmt, 'ssss', $firstname, $lastname, $email, $password_hash);
            if (mysqli_stmt_execute($stmt)) {
                $msg = 'Registrazione eseguita con successo';
            } 
            else {
                $msg = 'Problemi con l\'inserimento dei dati';
            }
            mysqli_stmt_close($stmt);
        }
        mysqli_close($mysqli);
    }
    $_SESSION['msg']=$msg;
    header('Location: errorcatcher.php');
}
?>