#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char game_char[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' }; //The game board is initialised as an array of base elements as numbers
int num; //The input to be taken from the user/player for the move
char Player = 'X'; //The player symbol is initialised as 'X'
char Computer = 'O'; //The player symbol is initialised as 'O'

//All functions used in the game
bool is_Draw();
void Screen_update();
void Player_move();
bool Player_wins();
bool Computer_wins();
void Computer_move();


void Screen_update() //Updates the screen after every move
{
    system("CLS");

    cout << endl;
    cout << endl;
    cout << "\t\t\t\tTic Tac Toe Game - AE-01 \n" << endl << endl;
    cout << "\t\t\t\tAteeq ur Rehman - 465502 \n" << endl;
    cout << "\t\t\t\tMuhammad Awais Ali - 461465 \n" << endl;
    cout << "\t\t\t\tSyed Shah Umer - 463322 \n" << endl << endl;
    cout << "\t\t\t\tPlayer v/s Computer \n" << endl << endl;
    cout << "\t\t\t\tPlayer: X\n";
    cout << "\t\t\t\tComputer: O\n";
    cout << endl << endl;

    cout << "\t\t\t\t" << game_char[0] << "  |  " << game_char[1] << "  |  " << game_char[2] << "\n";
    cout << "\t\t\t\t-------------" << endl;

    cout << "\t\t\t\t" << game_char[3] << "  |  " << game_char[4] << "  |  " << game_char[5] << "\n";
    cout << "\t\t\t\t-------------" << endl;

    cout << "\t\t\t\t" << game_char[6] << "  |  " << game_char[7] << "  |  " << game_char[8] << "\n\n";
}

void Player_move() //Takes the input for the move from the player
{
    cout << "\t\t\t\tPlayer - Enter number: ";
    cin >> num;

    switch (num)
    {
    case 1:
        game_char[0] = Player;
        break;
    case 2:
        game_char[1] = Player;
        break;
    case 3:
        game_char[2] = Player;
        break;
    case 4:
        game_char[3] = Player;
        break;
    case 5:
        game_char[4] = Player;
        break;
    case 6:
        game_char[5] = Player;
        break;
    case 7:
        game_char[6] = Player;
        break;
    case 8:
        game_char[7] = Player;
        break;
    case 9:
        game_char[8] = Player;
        break;
    default:
        cout << "\t\t\t\t\nPlease enter a number from 1 to 9!\n\n" << endl;
        Player_move();
        break;
    }
}

void Computer_move() //Makes the computer to marks its symbol 'O' based on conditions
{
    srand(time(0)); //Initiates seed of random fuction 

    for (int i = 0; i < 9; ++i) //Checks if there is a winning move
    {
        if (game_char[i] != 'X' && game_char[i] != 'O')
        {
            char originalValue = game_char[i];
            game_char[i] = Computer;
            if (Computer_wins())
            {
                return;
            }
            game_char[i] = originalValue;
        }
    }

    for (int i = 0; i < 9; ++i) //Checks if there is a blocking move
    {
        if (game_char[i] != 'X' && game_char[i] != 'O')
        {
            char originalValue = game_char[i];
            game_char[i] = Player;
            if (Player_wins())
            {
                game_char[i] = Computer;
                return;
            }
            game_char[i] = originalValue;
        }
    }

    // Fork: Create an opportunity for the computer to win in the next move
    // Block Fork: Block the user from creating a fork
    // Center: Take the center if available
    if (game_char[4] != 'X' && game_char[4] != 'O')
    {
        game_char[4] = Computer;
        return;
    }

    for (;;) 
    {
        int i = rand() % 10;
        while (i == 9)
        {
            i = rand() % 10;
        }
        if (game_char[i] != 'X' && game_char[i] != 'O')
        {
            game_char[i] = Computer;
            break;
        }
    }
}

bool is_Draw() //Checks if the game is drawed
{
    for (int i = 0; i <= 8; i++)
    {
        if (game_char[i] != 'X' && game_char[i] != 'O')
        {
            //If there is an empty space, the game is not a draw
            return false;
        }
        else
        {
            continue;
        }
    }
    //If all spaces are filled and no one has won
    return true;
}

bool Player_wins() //Checks if the player has won the game
{
    if (game_char[0] == 'X' && game_char[1] == 'X' && game_char[2] == 'X')
        return true;
    else if (game_char[3] == 'X' && game_char[4] == 'X' && game_char[5] == 'X')
        return true;
    else if (game_char[6] == 'X' && game_char[7] == 'X' && game_char[8] == 'X')
        return true;
    else if (game_char[0] == 'X' && game_char[3] == 'X' && game_char[6] == 'X')
        return true;
    else if (game_char[1] == 'X' && game_char[4] == 'X' && game_char[7] == 'X')
        return true;
    else if (game_char[2] == 'X' && game_char[5] == 'X' && game_char[8] == 'X')
        return true;
    else if (game_char[0] == 'X' && game_char[4] == 'X' && game_char[8] == 'X')
        return true;
    else if (game_char[2] == 'X' && game_char[4] == 'X' && game_char[6] == 'X')
        return true;
    else
        return false;
}

bool Computer_wins() //Checks if the computer has won the game
{
    if (game_char[0] == 'O' && game_char[1] == 'O' && game_char[2] == 'O')
        return true;
    else if (game_char[3] == 'O' && game_char[4] == 'O' && game_char[5] == 'O')
        return true;
    else if (game_char[6] == 'O' && game_char[7] == 'O' && game_char[8] == 'O')
        return true;
    else if (game_char[0] == 'O' && game_char[3] == 'O' && game_char[6] == 'O')
        return true;
    else if (game_char[1] == 'O' && game_char[4] == 'O' && game_char[7] == 'O')
        return true;
    else if (game_char[2] == 'O' && game_char[5] == 'O' && game_char[8] == 'O')
        return true;
    else if (game_char[0] == 'O' && game_char[4] == 'O' && game_char[8] == 'O')
        return true;
    else if (game_char[2] == 'O' && game_char[4] == 'O' && game_char[6] == 'O')
        return true;
    else
        return false;
}

int main() //Main calling function of all other functions
{
    do
    {
        Screen_update(); //Initializes the game board before and after every turn
        Player_move(); //Takes input from the player
        Screen_update(); //Updates the screen after the move
        if (Player_wins()) //Checks whether the player has won
        {
            cout << "\t\t\t\tThe Player Wins!" << endl;
            break;
        }

        if (is_Draw()) //Checks whether the game is drawed
        {
            cout << "\t\t\t\tThe game is a draw!" << endl;
            break;
        }

        Computer_move(); //The computer makes amove
        Screen_update(); //Updates the screen after the move

        if (is_Draw()) //Checks if the game is drawed
        {
            cout << "\t\t\t\tThe game is a draw!" << endl;
            break;
        }

        if (Computer_wins()) //Checks whether the computer has won
        {
            cout << "\t\t\t\tThe Computer Wins!" << endl;
            break;
        }

        cout << "\n\n\n";

    } while (true);

    return 0;
}
