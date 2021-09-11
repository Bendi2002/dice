#include "../std_lib_facilities.h";

int main() {

	printf("\033c");

	double money = 100;
	double player_bet;
	int dice;
	int dice_bet;
	int ending = 1;
	int round = 1;
	
	cout << "Dice betting game (really simple)\n\n";
	
	while (money > 0 && ending != 0) {

		cout << "Round " << round << "\n";

		cout << "You currently have $" << money << "\n";
		cout << "What do you think the dice is going to roll?\n";
		do {
			
			cin >> dice_bet;
		
		} while (1 > dice_bet || dice_bet > 6);
		
		cout << "How much are you going to bet?\n";
		do {

			cin >> player_bet;

		} while (0 > player_bet || player_bet > money);

		cout << "\n" << "Rolling the dice...\n";
		dice = randint(5) + 1;
		cout << "The dice rolls to " << dice << "\n";

		if (dice == dice_bet) {

			money = money + player_bet;
			cout << "YOU WIN!!!\nNow you have $" << money << "!\n";

		}
		else {

			money = money - player_bet;
			cout << "You lost!\nNow you have $" << money << "!\n";

		}
		if (money != 0) {

		do {
			cout << "Please press (1) for a new round or press (0) to exit: \n";
			cin >> ending;
		} 
		while (0 > ending || ending > 1);

		printf("\033c");
		round = round + 1;
		
		}
		else {

			cout << "Game over!\nYou lasted " << round << " round(s)!\n";
		}
	}
}