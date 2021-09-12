#include "../std_lib_facilities.h";

int main() {

	printf("\033c");

	double money = 100;
	double money1;
	double player_bet;
	int dice = 5;
	int dice_bet;
	int ending = 1;
	int round = 1;
	int difficulty;
	double diff_mult;
	int lost;
	int game_mode;

	cout << "Dice betting game (really simple)\nPlease choose a difficulty:\nEasy (1)\nNormal (2)\nHard (3)\nExtreme (4)\n";
	while (1 > difficulty || difficulty > 4) {

		cin >> difficulty;
	
	}

	printf("\033c");

	cout << "Choose a game mode:\nEndless (1)\nBlind tournament (2)\n";

	while (1 > game_mode || game_mode > 2) {

		cin >> game_mode;

	}

	if (difficulty == 1) {
		diff_mult = 0.5;
	}

	else if (difficulty == 2) {
		diff_mult = 1;
	}

	else if (difficulty == 3) {
		diff_mult = 3;
	}

	else if (difficulty == 4) {
		diff_mult = 10;
	}

	while (money > 0 && ending != 0) {

		printf("\033c");

		cout << "Round " << round << "\n\n";
		cout << "Difficulty: ";

		if(difficulty == 1) {
			cout << "Easy\nLoss multiplier: " << diff_mult << "\n";
		}

		else if(difficulty == 2) {
			cout << "Normal\nLoss multiplier: " << diff_mult << "\n";
		}

		else if(difficulty == 3) {
			cout << "Hard\nLoss multiplier: " << diff_mult << "\n";
		}

		else if(difficulty == 4) {
			cout << "Extreme\nLoss multiplier: " << diff_mult << "\n";
		}

		cout << "You currently have $" << money << "\n";
		cout << "What do you think the dice is going to roll?\n";
		do {
			
			cin >> dice_bet;
		
		} while (1 > dice_bet || dice_bet > 6);
		
		cout << "How much are you going to bet?\n";
		do {

			cin >> player_bet;

		} while (1 > player_bet || player_bet > money);

		cout << "\n" << "Rolling the dice...\n";
		srand((unsigned) time(0));
		int dice = 1 + (rand() % 6);
		cout << "The dice rolls to " << dice << "\n";

		if (dice == dice_bet) {

			money = money + player_bet;
			cout << "YOU WIN!!!\n";
			cout << "You won $" << player_bet <<"!\n";
			cout << "Now you have $" << money << "!\n";

		}
		else {
		
			money = money - player_bet * diff_mult;

			if (money < 0) {
				money = 0;
			}

			cout << "Bad guess!\n";
			cout << "You lost $" << player_bet * diff_mult << "!\n";
			cout << "Now you have $" << money << "!\n";

		}
		if (money != 0 && game_mode == 1) {

		do {
			cout << "Please press (1) for a new round or press (0) to exit: \n";
			cin >> ending;
		} 
		while (0 > ending || ending > 1);

		printf("\033c");
		round = round + 1;
		
		}

		else if (money != 0 && game_mode == 2) {

			if (round == 10) {

				cout << "Game over!\n";
				cout << "You have $" << money << " after 10 rounds!\n";
				break; 

			}
			else cout << "Next round...\n";
			round = round + 1;

		}

		else {

			cout << "Game over!\n";
			if (round == 1) {

				cout << "You lasted only 1 round!\n";
			
			}
			else cout << "You lasted " << round << " rounds!\n";
		}
	}

	return 0;

}
