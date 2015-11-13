 <head>
		<!-- Custom styles for this template -->
	<link rel="stylesheet" type="text/css" href="res/style.css"> 
	<link rel="stylesheet" type="text/css" href="res/main.css"> 
		<!-- Scripts -->
	<script src="res/jquery.js"></script>
	<script src="res/smoothscroll.js"></script>
 </head>
<?php
    function ping($host,$port=80,$timeout=6)
    {
            $fsock = fsockopen($host, $port, $errno, $errstr, $timeout);
            if ( ! $fsock )
            { return "<pre>0</pre>"; }
            else
            { return "<pre>1</pre>";}
    }
	$ghost=$_GET["host"];
	$gport=$_GET["port"];
	$gtimeout=$_GET["timeout"];
	echo ping($ghost,$gport,$gtimeout);
?>