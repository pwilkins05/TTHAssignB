<?php
// Author: Brady Hyde
// Created: 1/31/2016 and modified: 01/31/2016
// Took a cue from Sam and used one of the basic things we did with Mari
// Three issues:
// 1) Forgot an error message in the function --Done by ST (phew, that was hard!)
// 2) Missing styles or reference to a framework/stylesheet --Inline styles and a tiny bit of Bootstrap gridding added by ST. Someone else, feel free to make this way better.
// 3) Forgot how to math at the bottom (line 76) --Mathing added by ST.

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
				$errorMessage = "Please enter a valid number. \"$number\" does not count."; // TODO: Whoops, looks like I forgot an error message. 
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

// TODO: This badboy is ugly, add some CSS or work a little Bootstrap (or your favorite framework) into the mix -- ST: I made it look...different. 
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" 
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>Number Form</title>
<link rel="stylesheet" href="http://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css">
<meta http-equiv="content-type" content="text/html; charset=iso-8859-1" />
<style type="text/css">
/* Styles go here */

body {
   font-family: Helvetica, sans-serif;
   font-weight: inherit;
   margin: 1px;
   padding: 5px;
   vertical-align: baseline;
   color: #8F0000;
	background-color: rgba(255, 242, 242, 0.7);
}

#numbox {
  background-color: rgba(242, 242, 242, 0.9);
  padding: 10px;
  border-top: 1px solid #8F0000;
  border-right: 1px solid #8F0000;
}

#answer {
  background-color: rgba(242, 242, 242, 0.9);	
	border-bottom: 1px solid #8F0000;
	border-top: 1px solid #8F0000;
}
</style>

</head>
<body>
<form name="NumberForm" action="NumberForm.php" method="post">
<div clas="container">
	<div class="row">
		<div class="col-sm-12">
			<h3>&nbsp;&nbsp;Number-Squarer Deluxe 3000<small>&nbsp;&nbsp;Now with MOAR CATS</small></h3>
		</div>
	</div>
	<div class="row">
	<div class="col-sm-3" id="numbox"><img src="https://i.imgflip.com/i79e2.jpg" alt="mathCat" width="325"></div>
	<div class="col-sm-8" id="numbox">
		<h1><small>Put In A Number and We'll Square It!</small></h1>
			<p>Enter a number: 
				<br /><br /><input type="text" name="Number" value="<?php echo $Number; ?>" />
				<span style="color:red"><?php echo $errorMessage; ?></span>
			<br /><br />
			<input type="reset" value="Clear Form" />&nbsp; &nbsp;
			<input type="submit" name="Submit" value="Send Form" />
			<br /><br />
		</p>
	</div>
</div>
</form>
<div class="row">
	<div class="col-sm-12" id="answer">
<?php
	if ($doIt)
	{
		echo "<p>Thank you for entering a number.</p>\n";
		echo "<p>Your number, $Number, squared is " .
          (pow($Number, 2)) . ".</p>\n "; // TODO: I'm so dumb, I totally forgot how to math. Is it supposed to be ($Number * $Number)? Please fix. Bahahaha, this is great.
	}
?>
	</div>
</div>
</body>
</html>

