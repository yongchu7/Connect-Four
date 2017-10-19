/* c++ connect four, finsh step I but not finish step J, also have some problem when restart the game*/
#include <iostream>
const int ROWS = 20;
const int COLUMNS = 20;
using namespace std;
int Board[ROWS][COLUMNS];
int X,Y;
char choice;
int rows;
int columns;
int wins;
bool winner;
bool optionMode = false;
char decs;
int counter = 1;
int total = 1;

void select() { // select mode 
	cout << "select Mode n/w(normal/ wrap around)";
	cin >> decs;
	if (decs == 'n') 
		optionMode = false;
	
	else if 
		(decs == 'w')
		optionMode = true;
	
}

void special()//create new array bu insert value 
{
	cout << "ROWS£º";
	cin >> rows;
	if (rows < 4 || rows > 20) {
		cout << "I'm sorry, I don't understand. Please try again:";
		cin >> rows;
	}
	cout << "COLUMNS:";
	cin >> columns;
	if (columns < 4 || columns > 20) {
		cout << "I'm sorry, I don't understand. Please try again:";
		cin >> columns;
	}
	cout << "Required to win:";
	cin >> wins;
	if (wins < 3 || wins > 20) {
		cout << "I'm sorry, I don't understand. Please try again:";
		cin >> wins;
	}


}
void Initialize()//initialize board 
{
	cout << "1234567891011121314151617181920" << endl;
	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < columns; y++)
		{
			if (Board[x][y] == 0) cout << ".";
			else if (Board[x][y] == 1) cout << "X";
			else if (Board[x][y] == 2) cout << "O";
			
		}
		cout << endl;
	}
}

void restart() {
	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < columns; y++)
		{
			Board[x][y] = 0;
		}
	}
}

void playerX( int playerX) {//position for playerX
	int input;
	cout << "Player X's turn! Type the column number to insert a piece:";
	cin >> input;
	while (input > columns || input <= 0)
	{
		cout << "I'm sorry, I don't understand. Please try again:";
		cin >> input;
	}
	int num = 0;
	while (Board[(rows - 1) - num][input - 1] != 0) {
		num++;
		if (num > (rows - 1))
		{
			cout << "I'm sorry, I don't understand. Please try again:";
			cin >> input;
			num = 0;
		}
	};
	Board[(rows - 1) - num][input - 1] = playerX;
	X = input - 1;
	Y = (rows - 1) - num;
}

void playerO(int playerO) {//position for playerO
	int input;
	cout << "Player O's turn! Type the column number to insert a piece:";
	cin >> input;
	while (input > columns || input <= 0)
	{
		cout << "I'm sorry, I don't understand. Please try again:";
		cin >> input;
	}
	int num = 0;
	while (Board[(rows - 1) - num][input - 1] != 0) {
		num++;
		if (num > (rows - 1))
		{
			cout << "I'm sorry, I don't understand. Please try again:";
			cin >> input;
			num = 0;
		}
	};
	Board[(rows - 1) - num][input - 1] = playerO;
	X = input - 1;
	Y = (rows - 1) - num;
}

bool checkWinner(int x, int y, int player) {//check multple direction 

	int total = 1;
	int counter = 1;
	int times = 0;
	bool winner;

	while (y + counter >= 0 && y + counter < rows)
	{
		if (Board[y + counter][x] == player) //check vertical 
		{
			total++;
			counter++;
		}
		else break;
	}

	while ((x + counter >= 0) && (x + counter < columns))//left
	{
		if (Board[y][x + counter] == player)
		{
			total++;
			counter++;
		}
		else break;
	}


	while ((x - counter < columns) && (x - counter >= 0))//right
	{
		if (Board[y][x - counter] == player)
		{
			total++;
			counter++;
		}
		else break;
	}

	while ((y - counter >= 0) && (x + counter < columns))//four corner
	{
		if (Board[y - counter][x + counter] == player)
		{
			total++;
			counter++;
		}
		else break;
	}


	while ((y + counter < rows) && (x - counter >= 0))
	{
		if (Board[y + counter][x - counter] == player)
		{
			total++;
			counter++;
		}
		else break;
	}

	while ((y + counter >= 0) && (x + counter < columns))
	{
		if (Board[y + counter][x + counter] == player)
		{
			total++;
			counter++;
		}
		else break;
	}

	while ((y - counter < rows) && (x - counter >= 0))
	{
		if (Board[y - counter][x - counter] == player)
		{
			total++;
			counter++;
		}
		else break;
	}

	while (optionMode = true) { // step J

		if (Board[y][x+counter] == 1) {
			times++;
			if (times == wins)
				return true;
			else return false;
		}
		else break;
	}



	if (total == wins) return true;
	else return false;
}
/*void check() {
	if (!winner && Board[rows-1][columns-1] == 1 || Board[rows-1][columns-1] == 2) {
		cout << "game over!" << endl;
	}
}*/

void game() {//set up game

	cout << "Let's play Connect Four!" << endl;
	cout << endl;
	
	Initialize();
	int limit = (rows * columns) / 2;
	for (int i = 0; i < limit; i++)
	{
		playerX(1);
		Initialize();
		winner = checkWinner(X, Y, 1);
		if (winner)
		{
			cout << "Player X has won the game!" << endl;
			cout << "Game over! Do you want to play again£¿ (y/n)";
			cin >> choice;
			if (choice == 'y') { // reset the game 
				restart();
				select();
				special();
				Initialize();
				game();
			}
			else if (choice == 'n') {
				break;
			}
			else break;
		}

		playerO(2);
		Initialize();
		winner = checkWinner(X, Y, 2);
		if (winner)
		{
			cout << "Player O has won the game!" << endl;
			cout << "Game over! Do you want to play again£¿ (y/n)";
			cin >> choice;
			if (choice == 'y') {
				restart();
				select();
				special();
				Initialize();
				game();
			}
			else if (choice == 'n') {
				break;
			}
			else break;
		}
	}
	if (!winner) cout << "game over!"<< endl;
	system("pause");
}



int main()
{
	int total = 1;
	int counter = 1;
	select();
	special();
	game();
	//check();
}
		
