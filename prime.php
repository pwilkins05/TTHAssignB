<?php 

// Super-simple prime-number-evaluating program.
// Author: Sam Toman, Jan. 30, 2016.
// Includes a couple of TODOs and math-y bug.
// To view: Simply save to your local machine's web server directory
// (/srv/http, in my case) and open in your browser (localhost/prime.php). 
// Enjoy!



// isPrime evaluates whether user-input number
// is prime or not. Returns T or F.
// BUG: Not correctly determining primes. 
// Here's a hint (and explanation about why the sqrt is used: http://stackoverflow.com/questions/5811151/why-do-we-check-upto-the-square-root-of-a-prime-number-to-determine-if-it-is-pri )

function isPrime($number) {
	$root = round(sqrt($number), 0);
	$c = 2; // Counter variable; we know already that all ints are divisible by 1.
	while ($c < $root) {
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
</head>
<body>
	<h4>Plunk in an integer below and hit the "ENTER" key to evaluate its prime-ness or lack thereof:</h4><br />
	<form method="POST">
		<input type="text" name="num" placeholder="Enter an integer">
	<form>
</body>

<?php

if (isset($_POST['num'])) {
// TODO: Add validation to verify that the number is an int.
	$n = $_POST['num'];
	if (isPrime($n)) 
		echo($n . " is a prime number.<br />");
	else
		echo("Nope. $n is not a prime number.<br />");
}

?>
