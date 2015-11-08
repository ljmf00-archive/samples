 <? $ip=$_SERVER['REMOTE_ADDR']; // Get ip address of user ?>
<!DOCTYPE html>
<html>
 <head>
		<!-- Custom styles for this template -->
	<link rel="stylesheet" type="text/css" href="res/style.css"> 
	<link rel="stylesheet" type="text/css" href="res/main.css"> 
		<!-- Scripts -->
	<script src="res/jquery.js"></script>
	<script src="res/smoothscroll.js"></script>
 </head>
  <body>  
		<!--TEXT -->
	<form action="get_geoip.php" method="get">
	IP: <input type="text" value="<?php echo $ip; ?>" name="ipbox"> <input type="submit" value="GET">
	</form>	
  </body>
</html>