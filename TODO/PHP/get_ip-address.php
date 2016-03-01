 <head>
		<!-- Custom styles for this template -->
	<link rel="stylesheet" type="text/css" href="res/style.css"> 
	<link rel="stylesheet" type="text/css" href="res/main.css"> 
		<!-- Scripts -->
	<script src="res/jquery.js"></script>
	<script src="res/smoothscroll.js"></script>
 </head>
<?php $ip=$_GET["ipbox"]; // Get ip address of user
function get_isp($ip) { $details = json_decode(file_get_contents("http://ipinfo.io/{$ip}")); return $details->org; } //ISP GET
function get_hostname($ip) { $details = json_decode(file_get_contents("http://ipinfo.io/{$ip}")); return $details->hostname; } //HOSTNAME GET
function get_city($ip) { $details = json_decode(file_get_contents("http://ipinfo.io/{$ip}")); return $details->city; } //CITY GET
function get_country($ip) { $details = json_decode(file_get_contents("http://ipinfo.io/{$ip}")); return $details->country; } //COUNTRY GET
function get_region($ip) { $details = json_decode(file_get_contents("http://ipinfo.io/{$ip}")); return $details->region; } //REGION GET
function get_coordenates($ip) { $details = json_decode(file_get_contents("http://ipinfo.io/{$ip}")); return $details->loc; } //COORDENATES GET
function get_postal($ip) { $details = json_decode(file_get_contents("http://ipinfo.io/{$ip}")); return $details->postal; } //POSTAL CODE
?><pre>IP: <?php echo $ip;?><br>-----------------------------------------HOSTNAME: <?php echo get_hostname($ip);?> ISP: <?php echo get_isp($ip);?> CITY: <?php echo get_city($ip);?> REGION: <?php echo get_region($ip);?> COUNTRY: <?php echo get_country($ip);?> COORDENATES: <?php echo get_coordenates($ip);?> </pre>