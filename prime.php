<?php 

// Super-simple prime-number-evaluating program.
// Author: Sam Toman, Jan. 30, 2016.
// Includes a couple of TODOs and math-y bug.
// To view: Simply save to your local machine's web server directory
// (/srv/http, in my case) and open in your browser (localhost/prime.php). 
// Enjoy!

// Modified Comment by Tony Plueard 1/31/2016
// I have never taken a PHP class and this code only looks slightly familiar to me.

// isPrime evaluates whether user-input number
// is prime or not. Returns T or F.
// BUG: Not correctly determining primes. 
// Here's a hint (and explanation about why the sqrt is used: http://stackoverflow.com/questions/5811151/why-do-we-check-upto-the-square-root-of-a-prime-number-to-determine-if-it-is-pri )
function isPrime($number) {
	$root = round(sqrt($number), 0);
	$c = 2; // Counter variable; we know already that all ints are divisible by 1.
	while ($c <= $root) {	// fixed, needed to be less than or equal to
		if ($number % $c == 0)
			return false;
		$c++;
	}
	return true;
}


// TODO: Make the below prettier. Add a reference to Bootstrap via CDN
// and grid-ify it, or add some images, cheesy midi background music, snarky copy, etc.
?>
<html>
<head>
	<title>Is it prime?</title>
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" integrity="sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7" crossorigin="anonymous">
	<style type="text/css">
		* {
			margin: 0 auto;
			text-align: center;
		}
	</style>
</head>
<body>
	<h2>Plunk in an integer below and hit the "ENTER" key to evaluate its prime-ness or lack thereof:</h2><br />
<div class="row">
	<div class="col med-3">
		<form class="form" method="POST">
			<input type="text" name="num" placeholder="Enter an integer">
		<form>
	</div>	
</div>
</body>

<?php


if (isset($_POST['num'])) {
// TODO: Add validation to verify that the number is an int.
	$n = $_POST['num'];
	if (is_numeric($n)) {
		if (isPrime($n)) 
			echo("<br /><p class='lead'>" . $n . " is a prime number.</p><br />");
		else
			echo("<br /><p class='lead'>Nope. $n is not a prime number.</p><br />");
	}
	else
		echo "<br /><p class='lead'>Please enter a valid integer.</p><br />";
}

?>
