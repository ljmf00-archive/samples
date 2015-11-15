<?php
	function pingone($host,$port=80,$timeout=6) //Ping for .PT Server in port 80 with 6s timeout
	{
		$fsock = fsockopen($host, $port, $errno, $errstr, $timeout);
		if ( ! $fsock ) 
		{ 
			return '.PT [OFF]'; 
		}
		else 
		{ 
			return '.PT [ON]';
		}
	}
	function pingtwo($host,$port=80,$timeout=6) //Ping for Global Server in port 80 with 6s timeout
	{
		$fsock = fsockopen($host, $port, $errno, $errstr, $timeout);
		if ( ! $fsock ) 
		{ 
			return 'Global [OFF]'; 
		}
		else 
		{ 
			return 'Global [ON]';
		} 
	}
	$one=pingone('my.dominios.pt',80,6); //Run Function
	$two=pingtwo('api.hackertarget.com',80,6); // ...
?>
<html>
  <head>
		<!-- Custom styles for this template -->
	<link rel="stylesheet" type="text/css" href="/res/style.css"> 
	<link rel="stylesheet" type="text/css" href="/res/main.css"> 

		<!-- Scripts -->
	<script src="/res/jquery.js"></script>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>
    <script src="/bootstrap/js/bootstrap.min.js"></script>
	<script src="/res/smoothscroll.js"></script>
	
		<!-- Bootstrap -->
		<link href="/bootstrap/css/bootstrap.css" rel="stylesheet">
		<link href="/bootstrap/css/bootstrap.min.css" rel="stylesheet">
  </head>
  <body>
	<form class="form-horizontal" method="post">
		<fieldset>
		
				<!-- Text input-->
			<div class="form-group">
				<label class="col-md-4 control-label" for="textinput">DNS/IP:</label>  
				<div class="col-md-4">
					<input id="texbox" name="domain" placeholder="example.com" class="form-control input-md" type="text">
					<span class="help-block">Domain name / IP Address</span>  
				</div>
			</div>

				<!-- Multiple Radios -->
			<div class="form-group">
				<label class="col-md-4 control-label" for="selectbasic">Server:</label>
				<div class="col-md-4">
					<select id="selectbasic" name="server" class="form-control">
						<option value="1"> <?php echo $one; //Display one ?> </option>
						<option value="2"> <?php echo $two; //Display two ?> </option>
					</select>
				</div>
			</div>

				<!-- Button -->
			<div class="form-group">
				<label class="col-md-4 control-label" for="buttonsubmit">Submit:</label>
				<div class="col-md-4">
					<button id="buttonsubmit" class="btn btn-primary">Whois</button>
				</div>
			</div>
		</fieldset>
	</form>
	<?php
	
	if (isset($_POST['server'])) {
		switch ($_POST['server']) {
			case 1:
				one();
				break;
			case 2:
				two();
				break;
			default:
				zero();
		}
	}
	
	function one() 
		{
			$hdomain = 'https://my.dominios.pt/modules/registrars/dnspt/whois.php?dom=' . $_POST['domain'] ;
			echo utf8_decode(get_remote_data($hdomain));
		}
		
	function two() 
		{
			$hdomain = 'https://api.hackertarget.com/whois/?q=' . $_POST['domain'] ;
			echo "<pre>";
			echo utf8_decode(get_remote_data($hdomain));
			echo "</pre>";
		}
		
	function zero()
		{
			echo "<pre>ERROR: Select the server type!</pre>";
		}
	
		function get_remote_data($url, $post_paramtrs = false) 
		{
			$c = curl_init();
			
			curl_setopt($c, CURLOPT_URL, $url);
			curl_setopt($c, CURLOPT_RETURNTRANSFER, 1);
			
			if ($post_paramtrs) 
			{
				curl_setopt($c, CURLOPT_POST, TRUE);
				curl_setopt($c, CURLOPT_POSTFIELDS, "var1=bla&" . $post_paramtrs);
			} 
			
			curl_setopt($c, CURLOPT_SSL_VERIFYHOST, false);
			curl_setopt($c, CURLOPT_SSL_VERIFYPEER, false);
			curl_setopt($c, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 6.1; rv:33.0) Gecko/20100101 Firefox/33.0");
			curl_setopt($c, CURLOPT_COOKIE, 'CookieName1=Value;');
			curl_setopt($c, CURLOPT_MAXREDIRS, 10);
			
			$follow_allowed = ( ini_get('open_basedir') || ini_get('safe_mode')) ? false : true;
		
			if ($follow_allowed)
			{
				curl_setopt($c, CURLOPT_FOLLOWLOCATION, 1);
			}
		
			curl_setopt($c, CURLOPT_CONNECTTIMEOUT, 9);
			curl_setopt($c, CURLOPT_REFERER, $url);
			curl_setopt($c, CURLOPT_TIMEOUT, 60);
			curl_setopt($c, CURLOPT_AUTOREFERER, true);
			curl_setopt($c, CURLOPT_ENCODING, 'gzip,deflate');
		
			$data = curl_exec($c);
			$status = curl_getinfo($c);
		
			curl_close($c);
		
			preg_match('/(http(|s)):\/\/(.*?)\/(.*\/|)/si', $status['url'], $link);
		
			$data = preg_replace('/(src|href|action)=(\'|\")((?!(http|https|javascript:|\/\/|\/)).*?)(\'|\")/si', '$1=$2' . $link[0] . '$3$4$5', $data);
			$data = preg_replace('/(src|href|action)=(\'|\")((?!(http|https|javascript:|\/\/)).*?)(\'|\")/si', '$1=$2' . $link[1] . '://' . $link[3] . '$3$4$5', $data);
			if ($status['http_code'] == 200) 
			{
				return $data;
			} 
			elseif ($status['http_code'] == 301 || $status['http_code'] == 302) 
			{
				if (!$follow_allowed) 
				{
					if (empty($redirURL)) 
					{
						if (!empty($status['redirect_url'])) 
						{
							$redirURL = $status['redirect_url'];
						}
				} 
				if (empty($redirURL)) 
				{
					preg_match('/(Location:|URI:)(.*?)(\r|\n)/si', $data, $m);
					if (!empty($m[2])) 
					{
						$redirURL = $m[2];
					}
				}
				if (empty($redirURL)) 
				{
					preg_match('/href\=\"(.*?)\"(.*?)here\<\/a\>/si', $data, $m);
					if (!empty($m[1])) 
					{
						$redirURL = $m[1];
					}
				} 
				if (!empty($redirURL)) 
				{
					$t = debug_backtrace();
					return call_user_func($t[0]["function"], trim($redirURL), $post_paramtrs);
				}
			}
		} 
		return "ERRORCODE22 with $url!!<br/>Last status codes<b/>:" . json_encode($status) . "<br/><br/>Last data got<br/>:$data";
	}
	?>
  </body>
</html>