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
  <div class=lamp>
  <div id="navbar" class="sticky">
    <button type="button"  id="button" class="nes-btn is-disabled">Home</button>
    <button class="nes-btn is-primary"  id="button" onclick="window.location.href='/~S4865720/snakegame/login.html'"> Log-in</button>
    <button class="nes-btn is-primary"  id="button" onclick="window.location.href='/~S4865720/snakegame/register.html'"> Sign-up </button>
  </div>
  
  <div class="content" style="padding-top: 230px;">
      
    <section class="nes-container" style=" background-color: turquoise;">
      <section class="message-list">
        <section class="message -left">
          <div class="nes-balloon from-left">
            <p>Benvenuto!!!</p>
          </div>
        </section>
    
        <section class="message -right">
          <!-- Balloon -->
          <div class="nes-balloon from-right">
            <p>Registrati o Accedi al tuo account per inziare a giocare a snake ;)</p>
          </div>
        </section>
      </section>
    </section>


    <div class="nes-container with-title" style=" background-color: turquoise;">
        <span class="title">Our Social</span>
        <i class="nes-icon twitter is-large"></i>
        <i class="nes-icon facebook  is-large" onclick="window.location.href='https://it-it.facebook.com/'"></i>
        <i class="nes-icon instagram  is-large"></i>
        <i class="nes-icon trophy is-large" ></i>
        <i class="nes-icon twitch is-large"></i>
        <i class="nes-icon youtube is-large"></i>
        <i class="nes-icon google is-large"></i>
    </div>

    <div id="styleswitch" class="lamp">
        <center>
          <ul>
          <center><p class="lampdark"><center><a class="lampdark" href="javascript:setStyle('default');"><img  style=" width: 80px; height: 80px; border-radius: 50%;" src="\~S4865720\snakegame\img\off.png"/></a></center></p></center>
          <center><p class="lamplight"><center><a class="lamplight" href="javascript:setStyle('light')"><img style=" width: 80px; height: 80px; border-radius: 50%;" src="\~S4865720\snakegame\img\on.png"/></a></center></p></center>
          </ul> 
        </center>
    </div>
  </div>
  </div>
</body>
</html>

