<?php
// Author: Brady Hyde
// Created: 1/31/2016
// Took a cue from Sam and used one of the basic things we did with Mari
// Three issues:
// 1) Forgot an error message in the function
// 2) Missing styles or reference to a framework/stylesheet
// 3) Forgot how to math at the bottom (line 76)

	$Number = "";
	$errorMessage = "";
	$doIt = false;
	
	function isValid($number)
	{
		global $errorMessage;
		if (strlen(trim($number)) > 0)
		{
			if (is_numeric($number))
				return true;
			else
			{	
				$errorMessage = ""; // TODO: Whoops, looks like I forgot an error message. 
				return false;
			}
		}
		else
		{
			$errorMessage = "You need to enter a value.";
			return false;
		}
	}
	
	if (isset($_POST['Submit']))
	{
		$Number = $_POST['Number'];
		if (isValid($Number))
		{
			$doIt = true;
		}
	}

// TODO: This badboy is ugly, add some CSS or work a little Bootstrap (or your favorite framework) into the mix
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" 
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>Number Form</title>
<meta http-equiv="content-type" content="text/html; charset=iso-8859-1" />
<style type="text/css">
/* Styles go here */
	* {

	}

</style>
</head>
<body>
<h1>Put In A Number and We'll Square It!</h1>
<form name="NumberForm" action="NumberForm.php" method="post">
	<p>Enter a number: 
		<input type="text" name="Number" value="<?php echo $Number; ?>" />
		<span style="color:red"><?php echo $errorMessage; ?></span>
	</p>
	<p>
		<input type="reset" value="Clear Form" />&nbsp; &nbsp;
		<input type="submit" name="Submit" value="Send Form" />
	</p>
</form>
<?php
	if ($doIt)
	{
		echo "<p>Thank you for entering a number.</p>\n";
		echo "<p>Your number, $Number, squared is " .
          ($Number) . ".</p>\n "; // TODO: I'm so dumb, I totally forgot how to math. Is it supposed to be ($Number * $Number)? Please fix. 
	}
?>
</body>
</html>

