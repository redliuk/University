<!DOCTYPE html>
<html lang="en">

<head>
    <title>SnakeGame</title>
    <meta http-equiv="content-type" content="text/html; charset-UTF-8" />
    <link href="https://fonts.googleapis.com/css?family=Press+Start+2P" rel="stylesheet">
    <link href="https://unpkg.com/nes.css/css/nes.css" rel="stylesheet" />
    <link rel="stylesheet" type="text/css" href="\~S4865720\snakegame\css\game.css" />
</head>

    <?php
        require_once('connection.php');  
        require_once('database.php');
 
        $result = mysqli_query($mysqli , "Select bestscore from users WHERE email='".$session_user."' ");
        $row = mysqli_fetch_array($result);
        $bestscore = $row["bestscore"];
    ?>

<body> 

    <div id="navbar" class="sticky">
        <button class="nes-btn is-primary" onclick="window.location.href='/~S4865720/snakegame/php/homepage2.php'"> Home</button>
        <button class="nes-btn is-success" onclick="window.location.href='/~S4865720/snakegame/php/show_profile.php'"> Profile</button>  
    </div>

    <div class="nes-container">
        <canvas id="gc" width="400" height="400"></canvas>
    </div>

    
    <div id=content>
        <h2>actual score: </h2>
        <h2 id="score"></h2>
        <h2>your best score: </h2>
        <h2 id="best"></h2>
    </div> 
    

    <form method="POST" action="setbestscore.php" >

        <input type="hidden" id="setscore" name="bestscore" />
        <center>
        <button class="hidden" id="submit" name="submit"> save new best score
        </center>
    </form>

    <script>
    
    window.onload=function() {
        canv=document.getElementById("gc");
        ctx=canv.getContext("2d");
        document.addEventListener("keydown",keyPush);
        setInterval(game,1000/15);
    }

    px=py=10;
    gs=tc=20;
    ax=ay=15;
    xv=yv=0;
    trail=[];
    tail=2;
    score=0;
    let best = '<?php echo $bestscore; ?>';
    document.getElementById('best').innerHTML = best;

    setTimeout(function() {
        alert("Press a direction key to start!");
    }, 250);

    function game() {

        px+=xv;
        py+=yv;
        if(px<0) {
            px= tc-1;
        }
        if(px>tc-1) {
            px= 0;
        }
        if(py<0) {
            py= tc-1;
        }
        if(py>tc-1) {
            py= 0;
        }
        ctx.fillStyle="black";
        ctx.fillRect(0,0,canv.width,canv.height);
    
        ctx.fillStyle="lime";

        for(var i=0;i<trail.length;i++) {
            ctx.fillRect(trail[i].x*gs,trail[i].y*gs,gs-2,gs-2);
            if(trail[i].x==px && trail[i].y==py) {
                tail = 2;
                if(score!=0 ){
                    if (score<best) {
                        location.reload();
                        alert("you lost :(") 
                    }
                    else{
                        document.getElementById('submit').click();
                        alert("you lost :(") 
                    }
                }
                score = 0;
                document.getElementById('score').innerHTML = score;
                
                    
                              
            }
        }
        trail.push({x:px,y:py});
        while(trail.length>tail) {
        trail.shift();
        }
    
        if(ax==px && ay==py) {
            tail++;
            score++;
            document.getElementById('score').innerHTML = score;
            if (score>best) {
                best=score;
                document.getElementById('best').innerHTML = best;
                document.getElementById('setscore').value = best; //update del bestscore nel database
            }
            
            ax=Math.floor(Math.random()*tc);
            ay=Math.floor(Math.random()*tc);
        }
        ctx.fillStyle="red";
        ctx.fillRect(ax*gs,ay*gs,gs-2,gs-2);

    }

    function keyPush(evt) {
        switch(evt.keyCode) {
            case 37:
                xv=-1;yv=0;
                break;
            case 38:
                xv=0;yv=-1;
                break;
            case 39:
                xv=1;yv=0;
                break;
            case 40:
                xv=0;yv=1;
                break;
        }
    }
    </script>
     
</body>
</html>
