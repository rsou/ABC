/*
 * Driver.cpp
 *
 *   Written by Ramata Soumounou
 * Comp 345-Assignment 1
 * Instructor: Joey Paquet
 * October 29, 2015
 */

#include <iostream>
#include <vector>
using std::cout;
using std::cin;

//Function to create initialize the game players with their names and id.
int createPlayers(std :: vector<Players>& gamePlayers){

	cout « "Enter the number of players as an integer.\n"
	     « "The number of players should be at least 2 and at most 6" ;

	cin » numberOfPlayers;

	if((numberOfPlayers < 2)||( numberOfPlayers > 6)){
		cout « "Illegal number of players. Program aborted";
		exit(1);
	}

	for(unsigned int i = 0; i < numberOfPlayers; i++){
		cout « "Enter player’s name: ";
		std :: string name;
		cin » name;

		//To create 4 digits id for each players.
		int id = (2000 + rand()%1000);

		//Temporarily set the player’s turn to zero until they each roll the dice.
		Players newPlayer(name, id, 0);
		gamePlayers.push_back(newPlayer);

	}
return gamePlayers.size();
}//end of createPlayers function definition



//Function to initilize the turn of each player.
void initializePlayersTurn(std::vector<Players>& gamePlayers){

	int size = gamePlayers.size();
	int rollValues[size];

	for(unsigned int i = 0; i < size; i++){
		rollValues[i] = gamePlayers[i].roll();
	}

	//Sort the array in a descending order
	Players tempPlayer;
	int temp;

	for(unsigned int i = 0; i < size; i++){
		for(unsigned int j = i+1; j < size; j++){
			if(rollValues[i] > rollValues[j]){
				temp = rollValues[i];
				rollValues[i] = rollValues[j];
				rollValues[j] = temp;

				tempPlayer = gamePlayers.at(i);
				gamePlayers.at(i) = gamePlayers.at(j);
				gamePlayers.at(j) = tempPlayer;
			}
		}
	}

}//end of initializePlayersTurn function definition


//Function to give random countries to each players.
void distributeCountries(std::vector<Players>& gamePlayers){
	int size = gamePlayers.size();

	for(unsigned int i = 0; i < size; i++){
		gamePlayers[i].assignCountries();
	}
}//end of distributeCountries function definition





//main function
int main(){

	Map gameMap;
	gameMap.load();

	std :: vector<Players> gamePlayers;

	int numPlayers = createPlayers(gamePlayers);
	initializePlayersTurn(gamePlayers);
	distributeCountries(gamePlayers);

	do{

		int numArmies = 25;

		for(unsigned int i = 0; gamePlayers.size(); i++){
			gamePlayers[i].reinforceArmies();
		}

		for(unsigned int i = 0; gamePlayers.size(); i++){
			gamePlayers[i].attack();
			gamePlayers[i].defend();

		}

		for(unsigned int i = 0; gamePlayers.size(); i++){
			if(!(gamePlayers[i].isActive())){
				gamePlayers[i].erase(gamePlayers[i].begin()+i);
				numPlayers--;
			}
		}

	} while(numPlayers > 1);


	std :: string winner;
	winner = gamePlayers[i].getName();
	cout « "Congratulations to the winner of the game : winner";

	return 0;

}

