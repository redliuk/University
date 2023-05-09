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
    <link rel="stylesheet" type="text/css" href="\~S4865720\snakegame\css\style1.css" />
</head>


<body>


    <div id="navbar" class="sticky" >
        <button class="nes-btn is-primary" onclick="window.location.href='/~S4865720/snakegame/php/homepage2.php'"> Home</button>
        <button class="nes-btn is-primary" onclick="window.location.href='/~S4865720/snakegame/php/logout.php'"> Log-out</button>
        <button class="nes-btn is-success" onclick="window.location.href='/~S4865720/snakegame/php/show_profile.php'"> Profile</button>  
    </div>

  <div class=lamp>
        <h2>Leaderboard</h2>
        <table style="width:100%">
            <tr>
                <th>Ranking </th>
                <th>firstname </th>
                <th>lastname </th>
                <th>bestscore </th>
            </tr>
        
<?php
require_once('connection.php');  
require_once('database.php');

$result = mysqli_query($mysqli, "SELECT firstname, lastname, bestscore 
 FROM users ORDER BY bestscore DESC");
  
/* First rank will be 1 and 
    second be 2 and so on */
$ranking = 1;
  
/* Fetch Rows from the SQL query */
if (mysqli_num_rows($result)) {
    while ($row = mysqli_fetch_array($result)) {
        echo "<tr><td>{$ranking}</td>
        <td>{$row['firstname']}</td>
        <td>{$row['lastname']}</td>
        <td>{$row['bestscore']}</td>
        </tr>";
        $ranking++;
    }
}
?>

    </table>
  </div>
</body>
</html>