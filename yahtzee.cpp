#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cctype> // Added by ST to make user's Y/N dice reroll response case-insensitive.

/*******************************
 *
 * Yahtzee
 *
 * Starter code by Paul Wilkins
 * Created: 02/04/2014
 * Last modified: 01/30/2016
 * by Sam Toman (Implemented scoring
 * functions for 1-6; fixed dice-roll bug;
 * made user input case-insensitive for
 * dice-reroll prompt.
 *
 * Last Modified: 1/31/2016 by Brady Hyde
 * Like Jon Snow, I know nothing (about C++ at least).
 * So, I'm just adding this little chunk of comment in hopes of doing the least damage possible.

* Last Modified: 1/31/2016 by Tony Plueard
 * I have absolutely no idea what I am doing with C++ I took one class many terms ago
 * I understand what is going on but I am quite unsure of how to fix anything. So
 * here is a little comment that I thought I would leave

 Last Modified: 2/3/2016 by Jonathan Lukasik
 * Switched all the dice to using arrays
 * Switched all scoring to using arrays
 * Added threeOfAKind and fourOfAKind scoring
 * Fixed bug in getScoreOption(), if you enter a non integer, endlessly loops
 * There is a looping quirk if you enter more then 1 letter when asked for input, doesnt break anything just looks bad in console.

 *******************************/

// TODO: switch to using arrays for scores //Finished by Jonathan Lukasik on 2/3/2016
// TODO switch to using array for dice // Finished by Jonathan Lukasik on 2/3/2016
// TODO: add yahtzee bonus score
// TODO: implement scoring functions (see switch statement, line 125)
// TODO: make ask reroll accept lowercase letters
// BUG: dice not holding correct values // Modified by ST on 01/30/2016; added +1
// based on Rand() documentation: http://www.cplusplus.com/reference/cstdlib/rand/

using namespace std;

void printRoll(int dice[]);
bool askReroll(int n);
void printSeparator();

/* void printScore(int onesScore, int twosScore, int threesScore, int foursScore,
                int fivesScore, int sixesScore, int threeOfAKind,
                int fourOfAKind, int fullHouse, int smallStraight,
                int largeStraight, int yahtzee, int chance);
*/

void printScore(int score[]);
void printScoreLine(string name, int score);
int getScoreOption(int score[]);
int tabulateDice(int n, int dice[]);

int scoreThreeOfAKind(int numDice[]);
int scoreFourOfAKind(int numDice[]);
const int NUM_CATEGORIES = 13;
const int SIDES = 6;
const int EMPTY = -1;
const int NUM_DICE = 5;
enum Category { ONES = 1, TWOS, THREES, FOURS, FIVES, SIXES, THREE_OF_A_KIND,
                    FOUR_OF_A_KIND, FULL_HOUSE, SMALL_STRAIGHT, LARGE_STRAIGHT,
                    YAHTZEE, CHANCE};

int main()
{

    int dice[NUM_DICE];
    bool redoDice[NUM_DICE];
    int score[NUM_CATEGORIES];
    int diceNum[NUM_DICE]; //How many of each dice (ones, twos, threes, fours, fives, sixes)
    int ones, twos, threes, fours, fives, sixes;

    for(int i = 0; i < NUM_CATEGORIES; i++)
    {
        score[i] = EMPTY;
    }

    cout << "Welcome to Yahtzee!" << endl;
    srand(time(0));

    for (int turn = 0; turn < NUM_CATEGORIES; turn++)
    {
        int round = 1;
        for(int i = 0; i < NUM_DICE; i++)
        {
            dice[i] = rand() % SIDES + 1;
            diceNum[i] = 0;
        }
        printRoll(dice);

        do
        {
            for(int i = 0; i < NUM_DICE; i++)
            {
                redoDice[i] = askReroll(i + 1); // +1 used in askReroll for dice to appear for the user correctly
            }

            if (redoDice[0])
            {
                dice[0] = rand() % SIDES + 1;
            }
            if (redoDice[1])
            {
                dice[1] = rand() % SIDES + 1;
            }
            if (redoDice[2])
            {
                dice[2] = rand() % SIDES + 1;
            }
            if (redoDice[3])
            {
                dice[3] = rand() % SIDES + 1;
            }
            if (redoDice[4])
            {
                dice[4] = rand() % SIDES + 1;
            }
            printRoll(dice);
            round++;
        } while ((redoDice[0] || redoDice[1] || redoDice[2] || redoDice[3] || redoDice[4]) && round < 3);
        diceNum[0] = tabulateDice(1, dice); //how many ones
        diceNum[1] = tabulateDice(2, dice); //how many twos
        diceNum[2] = tabulateDice(3, dice); //how many threes
        diceNum[3] = tabulateDice(4, dice); //how many fours
        diceNum[4] = tabulateDice(5, dice); //how many fives
        diceNum[5] = tabulateDice(6, dice); //how many sixes
        int scoreOption = getScoreOption(score);
        switch (scoreOption)
        {
            case ONES:
                score[0] = diceNum[0];
                break;
            case TWOS:
                score[1] = (diceNum[1] * 2);
                break;
            case THREES:
                score[2] = (diceNum[2] * 3);
                break;
            case FOURS:
                score[3] = (diceNum[3] * 4);
                break;
            case FIVES:
                score[4] = (diceNum[4] * 5);
                break;
            case SIXES:
                score[5] = (diceNum[5] * 6);
                break;
            case THREE_OF_A_KIND:
                score[6] = scoreThreeOfAKind(diceNum);
                break;
            case FOUR_OF_A_KIND:
                score[7] = scoreFourOfAKind(diceNum);
                break;
        } /*


            case FULL_HOUSE:
                fullHouse= scoreFullHouse(ones, twos, threes, fours, fives, sixes);
                break;
            case SMALL_STRAIGHT:
                smallStraight = scoreSmallStraight(ones, twos, threes, fours, fives, sixes);
                break;
            case LARGE_STRAIGHT:
                largeStraight = scoreLargeStraight(ones, twos, threes, fours, fives, sixes);
                break;
            case YAHTZEE:
                yahtzee = scoreYahtzee(ones, twos, threes, fours, fives, sixes);
                break;
            case CHANCE:
                chance = scoreChance(ones, twos, threes, fours, fives, sixes);
                break;
        }*/
	printScore(score);
    }
}

/*********************************************************
 *
 * printRoll
 * ------------------
 * This function prints out the current state of the dice,
 * with blank lines before and after the print-out.
 *
 *********************************************************/
void printRoll(int dice[NUM_DICE])
{
    cout << endl;
    cout << "Your roll is:" << endl;
    for(int i = 0; i < NUM_DICE; i++)
    {
        cout << dice[i] << " ";
    }

    cout << endl << endl;
}

/*********************************************************
 *
 * askReroll
 * ------------------
 * This function ask the user if they'd like to reroll one
 * one of the dice.  The function takes an integer which is
 * the number of the die being rerolled, and returns true if
 * the die should be rerolled, false otherwise.  The integer
 * argument is used only for instruction display, this function
 * does not actually reroll any dice.  Responses accepted are
 * 'Y' and 'N'.
 *
 *********************************************************/
bool askReroll(int n)
{
    char ch;
    while (true)
    {
        cout << "Would you like to reroll die " << n << "? (Y/N) ";
        cin >> ch;
        switch (toupper(ch)) //Added by ST
        {
            case 'Y':
                return true;
            case 'N':
                return false;
            default:
                cout << "Invalid response" << endl;
                break;
        }
    }

}



/********************************
 *
 * printScore
 * --------------------
 * This function prints out the complete score table
 * for the yahtzee game in its current state.
 *
 ********************************/

void printScore(int score[NUM_CATEGORIES])
{
    printSeparator();
    printScoreLine("Ones", score[0]);
    printSeparator();
    printScoreLine("Twos", score[1]);
    printSeparator();
    printScoreLine("Threes", score[2]);
    printSeparator();
    printScoreLine("Fours", score[3]);
    printSeparator();
    printScoreLine("Fives", score[4]);
    printSeparator();
    printScoreLine("Sixes", score[5]);
    printSeparator();
    printScoreLine("Three of a kind", score[6]);
    printSeparator();
    printScoreLine("Four of a kind", score[7]);
    printSeparator();
/*


    printScoreLine("Full House", score[8]);
    printSeparator();
    printScoreLine("Small Straight", score[9]);
    printSeparator();
    printScoreLine("Large Straight", score[10]);
    printSeparator();
    printScoreLine("Yahtzee", score[11]);
    printSeparator();
    printScoreLine("Chance", score[12]);
    printSeparator();*/
}

/********************************
 *
 * printSeperator
 * --------------------
 * This helper function prints out a single
 * separator line used as part of the score
 * printing function.
 *
 ********************************/
void printSeparator()
{
    cout << "+-------------------+-------+" << endl;
}

/********************************
 *
 * printScoreLine
 * --------------------
 * This function prints out a single line of the score.
 * The string argument is the name of the category, while
 * the in is the value of the score.  The category name is left
 * aligned, while the score value is right aligned.
 *
 ********************************/
void printScoreLine(string name, int score)
{
    cout << "| " << left << setw(18) << name << "| ";
     if (score >=0)
     {
         cout << right << setw(5) << score;
     }
     else
     {
         cout << "     ";
     }
     cout << " |" << endl;
}

/********************************
 *
 * getScoreOption
 * --------------------
 * This function gets the score category which the player wishes to score
 * with the current roll.  The function ensures that the response corresponds
 * to a valid category.  It also check to make sure that the selected category
 * has not yet been scored (unscored categories contain the value EMPTY).
 *
 * Fixed endless loop if entered non integer - Jonathan Lukasik 2/3/2016
 ********************************/
int getScoreOption(int score[NUM_CATEGORIES])
{
    int ans;
    bool valid = false;
    cout << "Here are the categories: " << endl;
    cout << "1. Ones" << endl;
    cout << "2. Twos" << endl;
    cout << "3. Threes" << endl;
    cout << "4. Fours" << endl;
    cout << "5. Fives" << endl;
    cout << "6. Sixes" << endl;
    cout << "7. Three of a kind" << endl;
    cout << "8. Four of a kind" << endl;
    cout << "9. Full House" << endl;
    cout << "10. Small Straight" << endl;
    cout << "11. Large Straight" << endl;
    cout << "12. Yahtzee" << endl;
    cout << "13. Chance" << endl;
    do
    {
        cout << "How would you like to score this? ";
        cin >> ans;
        if(ans > 0 && ans <= NUM_CATEGORIES )
        {

            switch (ans)
            {
            case ONES:
                if (score[0] == EMPTY) valid = true;
                break;
            case TWOS:
                if (score[1] == EMPTY) valid = true;
                break;
            case THREES:
                if (score[2] == EMPTY) valid = true;
                break;
            case FOURS:
                if (score[3] == EMPTY) valid = true;
                break;
            case FIVES:
                if (score[4] == EMPTY) valid = true;
                break;
            case SIXES:
                if (score[5] == EMPTY) valid = true;
                break;
            case THREE_OF_A_KIND:
                if (score[6] == EMPTY) valid = true;
                break;
            case FOUR_OF_A_KIND:
                if (score[7] == EMPTY) valid = true;
                break;
            case FULL_HOUSE:
                if (score[8] == EMPTY) valid = true;
                break;
            case SMALL_STRAIGHT:
                if (score[9] == EMPTY) valid = true;
                break;
            case LARGE_STRAIGHT:
                if (score[10] == EMPTY) valid = true;
                break;
            case YAHTZEE:
                if (score[11] == EMPTY) valid = true;
                break;
            case CHANCE:
                if (score[12] == EMPTY) valid = true;
                break;
            }
            if (!valid)
            {
                cout << "That category has already been used" << endl;
            }
        }
        else
        {
            cout << "Invalid input..." << endl;
            cout << "Please enter a number between 1 and " << NUM_CATEGORIES << ": ";
            cin.clear();
            cin.ignore();
        }
    } while(!valid);

    return ans;
}

/********************************
 *
 * tabulateDice
 * --------------------
 * This function calculates and returns the number of dice
 * which show the value n.
 *
 ********************************/
int tabulateDice(int n, int dice[NUM_DICE])
{
    int ans = 0;
    for (int i = 0; i < NUM_DICE; i++)
    {
        if (dice[i] == n)
        {
            ans++;
        }
    }
    return ans;
}


/********************************
 *
 * Scoring functions
 * --------------------
 * threeOfAKind and fourOfAKind return sum of number of dice
 ********************************/
int scoreThreeOfAKind(int diceNum[NUM_DICE])
{
    int ans = 0;
    for(int i = 0; i < NUM_DICE; i++)
    {
        if (diceNum[i] >= 3)
            ans = diceNum[i] * (i + 1);
    }
    return ans;
}

int scoreFourOfAKind(int diceNum[NUM_DICE])
{
    int ans = 0;
    for(int i = 0; i < NUM_DICE; i++)
    {
        if (diceNum[i] >= 4)
            ans = diceNum[i] * (i + 1);
    }
    return ans;
}


// Just a comment from Michele T. I don't know enough C++ to edit this file, but still wanted to proove that I was able to clone the directory from Git.


