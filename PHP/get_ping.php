<?php
    function ping($host,$port=80,$timeout=6)
    {
            $fsock = fsockopen($host, $port, $errno, $errstr, $timeout);
            if ( ! $fsock )
            { return "0"; }
            else
            { return "1";}
    }
	
	$ghost=$_GET["host"];
	$gport=$_GET["port"];
	$gtimeout=$_GET["timeout"];
	echo ping($ghost,$gport,$gtimeout);
?>