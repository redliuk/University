<!DOCTYPE html>
<html lang="en">
<head>
	<title>admin area</title>
	<link href="https://fonts.googleapis.com/css?family=Press+Start+2P" rel="stylesheet">
    <link href="https://unpkg.com/nes.css/css/nes.css" rel="stylesheet" />
    <link rel="stylesheet" type="text/css" href="\~S4865720\snakegame\css\default.css" title="default">
    <link rel="alternate stylesheet" type="text/css" href="\~S4865720\snakegame\css\light.css" title="light">
    <script type="text/javascript" src="\~S4865720\snakegame\js\cookie.js"></script>
    <link rel="stylesheet" type="text/css" href="\~S4865720\snakegame\css\style3.css" />
</head>

<body>
<div class=lamp>
    <center>
    <?php
        if(isset($_POST['sendmail'])) {
            //Import PHPMailer classes into the global namespace
            require 'mailer/PHPMailerAutoload.php';
            
            //Create an instance; passing `true` enables exceptions
            $mail = new PHPMailer(true);

            try {
                //Server settings
                $mail->SMTPDebug = SMTP::DEBUG_SERVER;                      //Enable verbose debug output
                $mail->isSMTP();                                            //Send using SMTP
                $mail->Host       = 'smtp.gmail.com';                       //Set the SMTP server to send through
                $mail->SMTPAuth   = true;                                   //Enable SMTP authentication
                $mail->Username   = 'snakegame641@gmail.com';               //SMTP username
                $mail->Password   = 'lollolollo';                           //SMTP password
                $mail->SMTPSecure = 'tls';                                  //Enable implicit TLS encryption
                $mail->Port       = 587;                                    //TCP port to connect to; use 587 if you have set `SMTPSecure = PHPMailer::ENCRYPTION_STARTTLS`

                //Recipients
                $mail->setFrom('snakegame641@gmail.com', 'Snakegame.com');
                $mail->addAddress($_POST['email']);                         //Add a recipient
                //$mail->addAddress('ellen@example.com');                   //Name is optional
                $mail->addReplyTo('snakegame641@gmail.com');

                //Attachments
                //$mail->addAttachment('/var/tmp/file.tar.gz');             //Add attachments
                //$mail->addAttachment('/tmp/image.jpg', 'new.jpg');        //Optional name

                //Content
                $mail->isHTML(true);                                        //Set email format to HTML
                $mail->Subject = $_POST['subject'];
                $mail->Body    = $_POST['message'];
                //$mail->AltBody = 'This is the HTML message body <b>in bold!</b>';
                //aggiungere nel messaggio la possibilità di disiscriversi


                $mail->send();
                echo 'Message has been sent';
            } 
        
            catch (Exception $e) {
                echo "Message could not be sent. Mailer Error: {$mail->ErrorInfo}";
            }
        }
      
    ?>

    <div class="col-md-9 col-md-offset-2">
        
        <form role="form" method="post" enctype="multipart/form-data">
            <div class="row">
                <div class="col-sm-9 form-group">
                    <label for="email">To Email:</label>
                    <input type="email" class="form-control" id="email" name="email" placeholder="Enter a email" maxlength="50" required>
                </div>
            </div>

            <div class="row">
                <div class="col-sm-9 form-group">
                    <label for="subject">Subject:</label>
                    <input type="text" class="form-control" id="subject" name="subject" value="---- Test Mail ----" maxlength="50">
                </div>
            </div>
            
            <div class="row">
                <div class="col-sm-9 form-group">
                    <label for="name">Message:</label>
                    <textarea class="form-control" type="textarea" id="message" name="message" placeholder="Your Message Here" maxlength="6000" rows="4">Test mail using PHPMailer</textarea>
                </div>
            </div>

            <div class="row">
                <div class="col-sm-9 form-group">
                    <button type="submit" name="sendmail" class="btn btn-lg btn-success btn-block">Send</button>
                </div>
            </div>
        </form>  
    </div>
    <table  style="margin-top:40px; text-align:center;">
    <tr>
    <th>email that accepted the newsletter </th>
    </tr>
    <?php
    require_once('database.php');
    $result = mysqli_query($mysqli, "SELECT email 
    FROM users WHERE newsletter=true ");

    if (mysqli_num_rows($result)) {
        while ($row = mysqli_fetch_array($result)) {
            echo "<tr> <td>{$row['email']}</td> </tr>";
        }
    }
    ?>
    </table>
    </center>
    
</div>
</body>
</html>



 