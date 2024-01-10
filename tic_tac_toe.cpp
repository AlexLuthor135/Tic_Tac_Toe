#include <iostream>
#include <vector>
#include <string>

int check_win(std::vector<char> board, char tic)
{
	if (tic == board[0] && tic == board[1] && tic == board[2])
		return (1);
	else if (tic == board[3] && tic == board[4] && tic == board[5])
		return (1);
	else if (tic == board[6] && tic == board[7] && tic == board[8])
		return (1);
	else if (tic == board[0] && tic == board[4] && tic == board[8])
		return (1);
	else if (tic == board[2] && tic == board[4] && tic == board[6])
		return (1);
	else if (tic == board[0] && tic == board[3] && tic == board[6])
		return (1);
	else if (tic == board[1] && tic == board[4] && tic == board[7])
		return (1);
	else if (tic == board[2] && tic == board[5] && tic == board[8])
		return (1);
	return (0);
}



int draw(std::vector<char> board)
{
	if (board[0] != ' ' && board[1] != ' ' && board[2] != ' ' && board[3] != ' ' 
		&& board[4] != ' ' && board[5] != ' '
		&& board[6] != ' ' && board[7] != ' ' && board[8] != ' ')
		return (1);
	return (0);
}

int main()
{
	std::vector<char> board = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	char player1 = 'X';
	char player2 = 'O';
	int turn = 0;
	int choice = 0;
	std::cout << " T | I | C \n";;
	std::cout << "--------\n";
	std::cout << " T | A | C \n";
	std::cout << "--------\n";
	std::cout << " T | O | E \n\n";
	while (!check_win(board, player1) && !check_win(board, player2) && !draw(board))
	{
		if (turn == 0)
		{
			std::cout << "Player 1 turn\n" << "Choose cell from 1 to 9\n";
			std::cin >> choice;
			while (choice != 10)
			{
				if (board[choice - 1] == ' ')
				{
					board[choice - 1] = player1;
					turn = 1;
					choice = 10;
				}
				else
				{
					std::cout << "This cell is occupied, choose another\n\n";
					break ;
				}
			}
		}
		else if (turn == 1)
		{
			std::cout << "Player 2 turn\n" << "Choose cell from 1 to 9\n";
			std::cin >> choice;
			while (choice != 10)
			{
				if (board[choice - 1] == ' ')
				{
					board[choice - 1] = player2;
					turn = 0;
					choice = 10;
				}
				else
				{
					std::cout << "This cell is occupied, choose another\n\n";
					break ;
				}
			}
		}
		std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " \n";
		std::cout << "-----------\n";
		std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " \n";
		std::cout << "-----------\n";
		std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " \n\n";
		if (check_win(board, player1))
			std::cout << "Congratulations to Player 1, he won the game!\n\n";
		else if (check_win(board, player2))
			std::cout << "Congratulations to Player 2, he won the game!\n\n";
		else if (draw(board))
			std::cout << "Draw!!!\n\n";
	}
}
