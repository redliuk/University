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

    <div id="navbar" class="sticky">
        <button class="nes-btn is-primary" onclick="window.location.href='/~S4865720/snakegame/php/homepage2.php'"> Home</button>
        <button class="nes-btn is-primary" onclick="window.location.href='/~S4865720/snakegame/php/logout.php'"> Log-out</button>
        <button class="nes-btn is-primary" onclick="window.location.href='/~S4865720/snakegame/php/leaderboard.php'"> Leaderboard</button>
        <button class="nes-btn is-success" onclick="window.location.href='/~S4865720/snakegame/php/show_profile.php'"> Profile</button>  
    </div>

  <?php

    require_once('connection.php');  
    require_once('database.php');

    if(isset($_POST['submit'])) {

        $searched = mysqli_real_escape_string($mysqli, trim( $_POST['email']));

        $result = mysqli_query($mysqli , "SELECT firstname, lastname, note, bestscore, count(*) as count FROM users WHERE email='".$searched."' ");
        $row = mysqli_fetch_array($result);
        
        if($row['count']==0){
          $msg = 'no profile found corrisponding to searched email';
          $_SESSION['msg']=$msg;
          header('Location: errorcatcher.php');
          exit();
        }

        $firstname = $row["firstname"];
        $lastname = $row["lastname"];
        $note = $row["note"];
        $bestscore = $row["bestscore"];
    }
  ?>

<body>
  <div class=lamp>
  <div id="box">
    <section class="nes-container with-title">
      <h1 class="title"><?php echo "$searched" ?></h1>
        <div class="nes-field">
          <span class="nes-text is-primary">Firstname</span>
          <a> <?php echo "$firstname"; ?> </a>
        </div>
        <div class="nes-field">
          <span class="nes-text is-primary">Lastname</span>
          <a> <?php echo "$lastname"; ?> </a>
        </div>
        <div class="nes-field">
          <span class="nes-text is-primary">Note</span>
          <a> <?php echo "$note"; ?> </a>
        </div>
        <div class="nes-field">
          <span class="nes-text is-primary">Bestscore</span>
          <a> <?php echo "$bestscore"; ?> </a>
        </div>
    </section>
  </div>
</body>   
</html> 