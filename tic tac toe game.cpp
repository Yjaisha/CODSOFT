#include <iostream>
#include <cmath>
#include <string> 
#define Dimension 3 
using namespace std;

class Player
{
private:
	
    string name;
	 
public:
	
    Player(string n)
    {
        name = n;
    }

    string PlayerName()
    {
        return this->name;
    }
};

class Game
{
private:

    char gb[Dimension][Dimension];

    int c;
    
public:

    void CreateBoard()
    {

        for (int i = 0; i < Dimension; i++)
        {

            for (int j = 0; j < Dimension; j++)

                gb[i][j] = ' ';
        }
        
        showBoard();
    }

void showBoard()
{
        printf("\n\n");

        for (int i = 0; i < Dimension; i++)
        {

            cout << "\t\t\t";

            for (int j = 0; j < Dimension; j++)
                cout << " | " << gb[i][j];
            cout << " |\n\t\t\t----------------" << endl;
        }
}

void PlayerTurn(Player & player)
{

        int position;

        int row;

        cout << "Turn of " << player.PlayerName() <<":"<<endl;

        cout << "Enter the position to be marked: ";
        cin >> position;

        row = ceil((float)position / Dimension);

        int col = (position - 1) % Dimension;

        if (gb[row - 1][col] != ' ')
        {
            cout << "Position already marked. Please select another position" << endl;

            PlayerTurn(player);
        }
        else
        {

            player.PlayerName().compare("Player I") == 0 ? gb[row - 1][col] = 'X' : gb[row - 1][col] = 'O';
            cout << " Marked at position: " << position << endl;
            
            c++;
        }
        showBoard();
}

void MachineTurn()
{

        int random_position;

        cout << "Turn of Machine: " << endl;
        random_position = rand() % (Dimension * Dimension + 1);

        int row = ceil((float)random_position / Dimension);

        int col = (random_position - 1) % 3;

        if (gb[row - 1][col] != ' ')
        {

            MachineTurn();
        }
        else
        {
            cout << " Marked at position: " << random_position << endl;

            gb[row - 1][col] = 'O';
            
            c++;
        }

        showBoard();
}

string Winner()
    {

        int r1 = 0, r2 = 0;
        
        int c1 = 0, c2 = 0;

        int d1 = 0, d2 = 0;

        char x = 'X';
        char O = 'O';

        for (int i = 0; i < Dimension; i++)
        {

            r1 = 0, r2 = 0;
            c1 = 0, c2 = 0;

            if (gb[i][i] == x)
            {
                d1++;
            }
            else if (gb[i][i] == O)
            {
                d2++;
            }

            for (int j = 0; j < Dimension; j++)
            {

                if (gb[i][j] == x)
                {
                    r1++;
                }
                else if (gb[i][j] == O)
                {
                    r2++;
                }

                if (gb[j][i] == x)
                {
                    c1++;
                }
                else if (gb[j][i] == O)
                {
                    c2++;
                }
            }

            if (r1 == Dimension || r2 == Dimension)
            {
                return (r1 == Dimension) ? "Player I" : "Player 2";
            }

            else if (c1 == Dimension || c2 == Dimension)
            {
                return (c1 == Dimension) ? "Player I" : "Player 2";
            }

            else if (d1 == Dimension || d2 == Dimension)
            {
                return (d1 == Dimension) ? "Player I" : "Player 2";
            }
        }
        if (c == Dimension * Dimension)
        {
            return "Draw";
        }
        return "";
    }
};

int main()
{
    
    Game *game = new Game;
    int ch;

    game->CreateBoard();
    
    cout << "Press 1 for single-player and 2 for a two-player game" << endl;
    cin >> ch;
    
    string fin = "";
    
    bool flag = true;
    
    switch (ch)
    {
        
    case 1:
    {
        
        Player player("Player I");
        
        while (flag)
        {
            
            game->PlayerTurn(player);
            
            fin = game->Winner();
            if (fin != "")
            {
                goto point;
            }
            
            game->MachineTurn();
            
            fin = game->Winner();
            
        point:
            if (fin == "Player I")
            {
                cout << " Player 1 win";

                flag = false;
            }
            else if (fin == "Player 2")
            {
                cout << "Computer Wins";
                flag = false;
            }
            else if (fin == "Draw")
            {
                cout << "The game ended in a draw";
                flag = false;
            }
        }
    }
    case 2:
    {
        
        Player player("Player I");
        Player player2("Player 2");
        
        while (flag)
        {
            
            game->PlayerTurn(player);
            
            fin = game->Winner();
            if (fin != "")
            {
                goto point2;
            }
            game->PlayerTurn(player2);
            
            fin = game->Winner();
            
        point2:
            if (fin == "Player I")
            {
                cout << " Player 1 win";
                flag = false;
            }
            else if (fin == "Player 2")
            {
                cout << "Computer Wins";
                flag = false;
            }
            else if (fin == "Draw")
            {
                cout << "The game ended in a draw";
                flag = false;
            }
        }
    }
        
    default:
    {
        exit(0);
    }
    }
    return 0;
}
