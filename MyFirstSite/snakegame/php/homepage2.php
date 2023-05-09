<!DOCTYPE html>
<html lang="en">
<head>
  <title>Homepage</title>
  <meta http-equiv="content-type" content="text/html; charset-UTF-8" />
  <link href="https://fonts.googleapis.com/css?family=Press+Start+2P" rel="stylesheet">
  <link href="https://unpkg.com/nes.css/css/nes.css" rel="stylesheet" />
  <link rel="stylesheet" type="text/css" href="\~S4865720\snakegame\css\default.css" title="default">
  <link rel="alternate stylesheet" type="text/css" href="\~S4865720\snakegame\css\light.css" title="light">
  <script type="text/javascript" src="\~S4865720\snakegame\js\cookie.js"></script>
  <link rel="stylesheet" type="text/css" href="\~S4865720\snakegame\css\style2.css" />
</head>

<body>
  <div id="styleswitch" class="lamp">
    <div id="navbar" class="sticky">
        <button type="button" id="button" class="nes-btn is-disabled">Home</button>
        <button class="nes-btn is-primary" id="button" onclick="window.location.href='/~S4865720/snakegame/php/logout.php'"> Log-out</button>
        <button class="nes-btn is-primary" id="button" onclick="window.location.href='/~S4865720/snakegame/php/leaderboard.php'"> Leaderboard</button>
        <button class="nes-btn is-success" id="button" onclick="window.location.href='/~S4865720/snakegame/php/show_profile.php'"> Profile</button>  
        <form action="search_profile.php" method="post" >
          <input type="text" name="email" class="nes-input" placeholder="Search email..">
          <button type="submit" class="nes-btn is-primary" style="background-color: #333;" name="submit" class="nes-input">Enter</button>

        </form>
    </div>

    <?php
      require_once('connection.php'); 
    ?>

    <div class="content" style="padding-top: 230px;">
      <section class="nes-container" style=" background-color: turquoise;">
        <section class="message-list">
          <section class="message -left">
            <div class="nes-balloon from-left">
              <p>Welcome <?php echo $session_user; ?> !!!</p>
            </div>
          </section>
        </section>
      </section>

      <div class="nes-container" style=" background-color: turquoise;">
        <center>
          <button class="nes-btn is-primary" onclick="window.location.href='/~S4865720/snakegame/php/play.php'"> --- start playing --- </button>
        </center>
      </div>
      <div class="nes-container" style=" background-color: turquoise;">
        <center>
          <button class="nes-btn is-primary" onclick="window.location.href='/~S4865720/snakegame/php/acceptnewsletter.php'"> --- iscriviti alla newsletter --- </button>
        </center>
      </div>

      <?php 
        require_once('database.php');  
        
        $query= " SELECT isadmin  FROM users WHERE email = '".$session_user."'
        ";
        $check= mysqli_query($mysqli, $query); 
        $row = mysqli_fetch_array($check);

        if ($row['isadmin']){   //se l'utente è admin può andare a eseguire questa operazione
          print(
            "<div class='nes-container' style=' background-color: turquoise;'>
              <center>
                <button class='nes-btn is-primary' onclick='redirect()'> --- admin area --- </button>
              </center>
            </div>"
          );
        }
        mysqli_close($mysqli);
      ?>

        <div id="styleswitch" class="lamp">
          <center>
            <ul>
            <center><p class="lampdark"><center><a class="lampdark" href="javascript:setStyle('default');"><img  style=" width: 80px; height: 80px; border-radius: 50%;" src="\~S4865720\snakegame\img\off.png"/></a></center></p></center>
            <center><p class="lamplight"><center><a class="lamplight" href="javascript:setStyle('light')"><img style=" width: 80px; height: 80px; border-radius: 50%;" src="\~S4865720\snakegame\img\on.png"/></a></center></p></center>
            </ul> 
          </center>
        </div>

      </div>
</body>
</html>

<script>
function redirect() {
  window.location.href= "/~S4865720/snakegame/php/newsletter.php";
}
</script>

