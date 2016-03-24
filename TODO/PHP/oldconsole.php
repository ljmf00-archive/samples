<!-- 
Yb    dP 88  dP""b8 88 88      dP"Yb  
 Yb  dP  88 dP   `" 88 88     dP   Yb 
  YbdP   88 Yb  "88 88 88  .o Yb   dP 
   YP    88  YboodP 88 88ood8  YbodP  
-->
<?php 
		//Lib's
	require "../../../config/session.php";
	require_once("../../../config/cfg.php");

		//Objects
	$configDatabase = new configDatabase();
	$configLinks = new configLinks();
	$configID = new configID();
	$configPath = new configPath();

	if (!isset($_SESSION["s_usr"]) || !isset($_SESSION["s_pw"]))
	{
		header("Location: /login");
		exit;
	}
	else {
		$query = "SELECT * FROM users WHERE username='" . $_SESSION["s_usr"] . "' and password='".$_SESSION["s_pw"]."'";
		if(!(($configDatabase->db->query($query)->rowCount()) > 0))
		{
			header("Location: /logout");
			exit;
		}
	}
?>
<!DOCTYPE html>
	<html lang="en-US">
		<head>
		<meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
		<meta name="viewport" content="width=device-width, initial-scale=1">
		<script src="//oss.maxcdn.com/jquery/2.2.0/jquery.js"></script>
      	<script src="//code.jquery.com/jquery-1.10.2.js"></script>
			<style>
				/*
				Yb    dP 88  dP""b8 88 88      dP"Yb  
				 Yb  dP  88 dP   `" 88 88     dP   Yb 
				  YbdP   88 Yb  "88 88 88  .o Yb   dP 
				   YP    88  YboodP 88 88ood8  YbodP  
			 	  */
				
				html, body {
					background-color: #000000;
					color: #00FF00;
				}
				input[type="text"], textarea {
    				background-color : #000000;
				}
				#user-caption{
				}
				input, input:focus {
    				border:none;
    				/*width: 0px;*/
    				/*max-width: 1024px;*/
    				outline:none;
    				color:black;
				}
				pre {
					margin : 0;
					padding : 0;
				}
				p, pre {
    				font-family: Consolas, Menlo, Monaco, Lucida Console, Liberation Mono, DejaVu Sans Mono, Bitstream Vera Sans Mono, Courier New, monospace, serif;
    				font-size:14px;
				}
				.f, .fpre{
					color: #008000;
				}
				pre.inline {
				   display: inline;
				}
			</style>
			<script>
				/*
				Yb    dP 88  dP""b8 88 88      dP"Yb  
				 Yb  dP  88 dP   `" 88 88     dP   Yb 
				  YbdP   88 Yb  "88 88 88  .o Yb   dP  
				   YP    88  YboodP 88 88ood8  YbodP   
				*/
				$(document).ready(function() {
					$('#user-caption').focus();
					$(window).on('click', function(){
				    	interval = setInterval ('cursorAnimation()', 500);
				    	$('#user-caption').focus();
				   	});
				   	$(window).on('blur', function(){
				    	clearInterval(interval);
				   	});
					var interval;
   					interval = setInterval ('cursorAnimation()', 500);
					var data = new Date();
   					msg =  'Last login: '+data.toLocaleString()+ ' from 127.0.0.1';
   					writeMessage(msg);
   					
   					$('#user-caption').on('keydown', function(e){
				      caption = $('input#user-caption').val();
				      switch (e.keyCode) {
				         case 8:
				         	console.log("Backspace keydown!");
				            removeLastChar();
				            break;
				         case 46:
				         	console.log("Delete keydown!");
				            removeWithDelete();
				            break;
				         case 13: // Enter
				         	console.log("Enter keydown!");
				            checkOption();
				            break;
				         case 37: // Left
				         	console.log("Left keydown!");
				         	leftClick();
				         	break;
				         case 38: // Up
				         	console.log("Up keydown!");
				            $('input#user-caption').val(caption);
				            break;
				         case 39: // Right
				         	console.log("Right keydown!");
				         	rightClick();
				         	break;
				         case 40: // Down
				         	console.log("Down keydown!");
				            break;
				         default: console.log("Any keydown!"); type(String.fromCharCode(e.which));
				      }


				   });
				});
				function type(newStr) {
				   if( newStr ){
				      $('#caption').append( newStr );
				   } else {
				      captionEl.html(caption.substr(0, captionLength++));
				      if(captionLength < caption.length+1) {
				         setTimeout('type(null)', 50);
				      } else {
				         captionLength = 0;
				         caption = '';
				      }
				   }
				}
				function writeMessage(string)
				{
   					$pretag = $('<pre>' + string + '</pre>');
   					$('pre:last').after($pretag);
   					$("html, body").animate({ scrollTop: $(document).height()-$(window).height() }, 5);
				}
				function writeCommand(command)
				{
   					$pretag = $('<pre class="inline fpre">' + $('.f').html() + '</pre>' + '<pre class="inline" id="command">' + command +'</pre><pre></pre>');
   					$('pre:last').after($pretag);
   					$("html, body").animate({ scrollTop: $(document).height()-$(window).height() }, 5);
				}
				function removeLastChar()
				{
   					var str = $('#caption').html();
   					str = str.substring(0, str.length - 1);
   					$('#caption').html(str);
				}
				function removeWithDelete()
				{
   					var str = $('#after-caption').html();
   					if(str!=''){
   						str = str.substring(1, str.length);
   						$('#after-caption').html(str);
   					}
				}
				function leftClick()
				{
   					var str = $('#caption').html();
   					var strc = str.substring(0, str.length - 1);
   					var strac = str.substring(str.length - 1, str.length);
   					$('#caption').html(strc);
   					$('#after-caption').prepend(strac);
				}
				function rightClick()
				{
   					var str = $('#after-caption').html();
   					var strac = str.substring(1, str.length);
   					var strc = str.substring(0, 1);
   					$('#after-caption').html(strac);
   					$('#caption').append(strc);
				}
				function cursorAnimation() {
				   $('#cursor').animate({
				      opacity: 0
				   }, 'fast', 'swing').animate({
				      opacity: 1
				   }, 'fast', 'swing');
				}
				function checkOption()
				{
				   var str = $('#caption').html() + $('#after-caption').html();
				   writeCommand(str);
				   switch (str) {
				   	  case 'help':
				         msg = 'Coming Soon!';
				         writeMessage(msg);
				         break;
				      case 'la':
				         msg = 'ls -la: /: Permission denied';
				         writeMessage(msg);
				         break;
				      case '':
				      	 break;
				      case 'ls':
				         msg = 'ls: /: Permission denied'
				         writeMessage(msg);
				         break;
				      case 'su':
				         $('.f').html('$root@vigilo# ');
				         break;
				      case 'exit':
				         $('.f').html(<?php echo "'" . $_SESSION["s_usr"] . "'"; ?> + '@vigilo$ ' );
				         break;
				      case 'clear':
				         $('pre').hide();
				         break;
				      default:
				         msg = 'command not found: ' + str;
				         writeMessage(msg);
				         help = 'try \'help\'';
				         writeMessage(help);
				   }
				   $('#caption').html('');
				   $('#user-caption').val('');
				   $('#after-caption').html('');
				}
			</script>
		</head>
		<body>
			<pre id="term">
Yb    dP 88  dP""b8 88 88      dP"Yb  
 Yb  dP  88 dP   `" 88 88     dP   Yb 
  YbdP   88 Yb  "88 88 88  .o Yb   dP 
   YP    88  YboodP 88 88ood8  YbodP  
			</pre>
			<p class="commands">
           		<span class="f"><?php echo $_SESSION["s_usr"]; ?>@vigilo$ </span>
           		<span id="caption"></span>
           		<span id="cursor">|</span>
           		<span id="after-caption"></span>
        	</p>
        	<input type="text" id="user-caption" value=""/>
			<?php

			?>
		</body>
	</html>
