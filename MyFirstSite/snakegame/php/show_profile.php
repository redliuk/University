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
  <?php
    require_once('connection.php');  
    require_once('database.php');
     
    $result = mysqli_query($mysqli , "SELECT * FROM users WHERE email='".$session_user."' ");
    $row = mysqli_fetch_assoc($result);
    $firstname = htmlspecialchars( $row["firstname"]);
    $lastname = htmlspecialchars( $row["lastname"]);
    $note = htmlspecialchars( $row["note"]);
    $email = htmlspecialchars( $row["email"]);
    mysqli_close($mysqli);
  ?>

  <div class=lamp>
    <form method="post" action="update_profile.php" >
      <div class="nes-field">
        <label for="name_field">Email</label>
        <input type="text" name="email" id="email" class="nes-input" value="<?php echo $email; ?>" required>
      </div>
      <div class="nes-field">
        <label for="name_field">Firstname</label>
        <input type="text" name="firstname" id="name_field" class="nes-input" value="<?php echo $firstname; ?>" required>
      </div>
      <div class="nes-field">
        <label for="name_field">Lastname</label>
        <input type="text" name="lastname" id="name_field" class="nes-input" value="<?php echo $lastname; ?>" required>
      </div>
      <div class="nes-field">
        <label for="name_field">Add or modify a note about you</label>
        <input type="text" name="note" id="name_field" class="nes-input" value="<?php echo $note; ?>">
      </div>
      
      <center>
      <div>
          <button type="submit" name="submit" class="nes-input">Confirm</button>
      </div>
      <a href="changepass.php">Change password</a>
      <a href="logout.php">Log out</a>
      </center>
    </form>
  </div>
</body>
</html>