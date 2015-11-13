 <?php $ip=$_SERVER['REMOTE_ADDR']; // Get ip address of user
function get_isp($ip) { $details = json_decode(file_get_contents("http://ipinfo.io/{$ip}")); return $details->org; }
function get_hostname($ip) { $details = json_decode(file_get_contents("http://ipinfo.io/{$ip}")); return $details->hostname; }
function get_city($ip) { $details = json_decode(file_get_contents("http://ipinfo.io/{$ip}")); return $details->city; }
function get_country($ip) { $details = json_decode(file_get_contents("http://ipinfo.io/{$ip}")); return $details->country; }
function get_region($ip) { $details = json_decode(file_get_contents("http://ipinfo.io/{$ip}")); return $details->region; }
function get_coordenates($ip) { $details = json_decode(file_get_contents("http://ipinfo.io/{$ip}")); return $details->loc; }
function get_postal($ip) { $details = json_decode(file_get_contents("http://ipinfo.io/{$ip}")); return $details->postal; }
?><!DOCTYPE html>
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
	<form action="get_ip-address.php" method="get">
	IP: <input type="text" value="<?php echo $ip; ?>" name="ipbox"> <input type="submit" value="GET">
	</form>
	-----------------------------------------<br>
	HOSTNAME: <?php echo get_hostname($ip);?> <br>
	ISP: <?php echo get_isp($ip);?> <br>
	CITY: <?php echo get_city($ip);?> <br>
	REGION: <?php echo get_region($ip);?> <br>
	COUNTRY: <?php echo get_country($ip);?> <br>
	COORDENATES: <?php echo get_coordenates($ip);?> <br>
  </body>
</html>