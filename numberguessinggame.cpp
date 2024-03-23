#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class NumberGuessingGame
{
    int num;
    int guess;
    int tries;

public:
    NumberGuessingGame()
    {
        srand(time(0));
        num = rand() % 101;
        tries = 5;
        guess = 0;
    }
    void playgame()
    {
        cout << "Number Guessing Game" << endl;
        cout << "I'm Thinking Of a Number Between 1 and 100" << endl;
        do
        {
            cout << "Tries Left: " << tries << endl;
            cout << "Enter Your Guess: " << endl;
            cin >> guess;
            if (guess < num)
            {
                cout << "Your Guess Is Too Low" << endl;
            }
            else if (guess > num)
            {
                cout << "Your Guess Is Too High" << endl;
            }
            else
            {
                cout << "Congratulations, Your Guess Was On Point" << endl;
            }
            tries--;
        } while (guess != num && tries != 0);
        if (tries == 0)
        {
            cout << "Tries Left: 0" << endl;
            cout << "You Lose, Better Luck Next Time" << endl;
        }
    }
};
int main()
{
    NumberGuessingGame game;
    while (1)
        game.playgame();
}
