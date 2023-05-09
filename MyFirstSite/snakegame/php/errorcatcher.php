<!DOCTYPE html>
<html lang="en">
  <head> 
    <title>Profile</title>
    <link href="https://fonts.googleapis.com/css?family=Press+Start+2P" rel="stylesheet">
    <link href="https://unpkg.com/nes.css/css/nes.css" rel="stylesheet" />
    <link rel="stylesheet" type="text/css" href="\~S4865720\snakegame\css\default.css" title="default">
    <link rel="alternate stylesheet" type="text/css" href="\~S4865720\snakegame\css\light.css" title="light">
    <script type="text/javascript" src="\~S4865720\snakegame\js\cookie.js"></script>
    <link rel="stylesheet" type="text/css" href="\~S4865720\snakegame\css\style3.css" />
  </head>

  <?php
    session_start();
  ?>

<script>
    var timeleft = 5;
    setTimeout(myFunction, 3000);
    var downloadTimer = setInterval(
        function(){
            if(timeleft <= 0)   clearInterval(downloadTimer);
            document.getElementById("progressBar").value = 6 - timeleft;
            timeleft -= 2;
            },  
        1000);
        function myFunction() {
            window.location.href = 'homepage2.php'; }
</script>

<body>
  <div class=lamp>
    <section class="nes-container">
    <center>
          <span id="text" class="nes-text is-primary"><?php echo $_SESSION['msg']; ?></span>
          <span id="text" class="nes-text is-primary">Redirecting to homepage</span>
          <progress value="0" max="5" id="progressBar"></progress>
    </center>
    </section>
  </div>
</body>
</html>
