#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int num, guess, hitting_tries = 0;
	srand(time(0)); //seed random number generator
	num = rand() % 100 + 1; // random number between 1 and 100
	cout << "Guess My Number Game\n\n";

	do
	{
		cout << "Enter a guess between 1 and 100 : ";
		cin >> guess;
		hitting_tries++;

		if (guess > num)
			cout << "Too high!\n\n";
		else if (guess < num)
			cout << "Too low!\n"<<endl;
		else
			cout << "\nCorrect! You got it in " << hitting_tries << " guesses!"<<endl;;
	} while (guess != num);

	return 0;
}
