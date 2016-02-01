"""
alphacode.py:  CIS 210 assignment 1, Fall 2013
Authors: FIXME: Anthony Plueard
Credits: FIXME: list sources and collaborators.	 If none, delete this line. 

Convert PIN code to mnemonic alphabetic code
"""
import argparse	 # Used in main PROGRAM to get PIN code from command line

# # Constants used by this program
CONSONANTS = "bcdfghjklmnpqrstvwyz"
VOWELS = "aeiou"


def alphacode(pin):
	"""
	Convert numeric pin code to an
	easily pronounced mnemonic.
	args:
		pin:  code as positive integer
	returns:
		mnemonic as string
	"""
	mnemonic = ""
	while pin > 0:
		pin2 = pin % 100
		pin = pin // 100
		x = pin2 // 5
		y = pin2 % 5
		z = CONSONANTS[x]
		w = VOWELS[y]
		mnemonic = z + w + mnemonic
	return mnemonic


def run_tests():
	"""
	This function runs a set of tests to help you debug your
	program as you develop it.
	"""
	##	(Cell marker for running tests in IEP) ## 
	print("**** TESTING --- examples from course assignment page")
	print("4327 => 'lohi'?", alphacode(4327))
	print("1298 => 'dizo'?", alphacode(1298))
	print("***** Longer PIN CODES ****")
	print("1234567 => begomari?", alphacode(1234567))
	print("42424242 => lililili ?", alphacode(4242424242))
	print("98765 => cuwira?", alphacode(98765))
	print("987654 => zotenu?", alphacode(987654))
	print("(same digit pairs, reverse order) 547698 => nutezo ?", alphacode(547698))
	print("**** Edge cases (robustness testing) ****")
	print("0 => empty mnemonic ?", alphacode(0))
	print("-42 and all negative numbers => empty mnemonic? ", alphacode(-42))
	## (Marks end of cell in IEP) 


def main():
	"""
	Interaction if run from the command line.
	Magic for now; we'll look at what's going on here
	in the next week or two. 
	"""

	parser = argparse.ArgumentParser(description="Create mnemonic for PIN code")
	parser.add_argument("PIN", type=int,
						help="personal identifier number (an integer)")
	args = parser.parse_args()	# gets arguments from command line
	pin = args.PIN
	mnemonic = alphacode(pin)
	print("Encoding of " + str(pin) + " is:", mnemonic)


if __name__ == "__main__":
	#run_tests()	 #FIXME: Comment this out when your program is working
	main()	 #FIXME: Uncomment this when your program is working



