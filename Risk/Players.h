/*
 * Players.h
 *
 *  Written by Ramata Soumounou
 * Comp 345-Assignment 1
 * Instructor: Joey Paquet
 * October 29, 2015
 */

#ifndef PLAYERS_H_
#define PLAYERS_H_

#include <string>
#include <vector>
#include <cstdlib>
#include <utility>
#include "Countries.h"


enum Colours {BLUE, RED, GREEN, YELLOW, PURPLE, ORANGE};
int MINIMUM_NUM_OF_PLAYERS = 2;
int MAXIMUM_NUM_OF_PLAYERS = 6;

class Players{

	public:

		Players();

		Players(const std :: string playersName, const int playersID, int turn);

		Players(int armies, std :: vector<Countries>& co, int numOfOwnedCountries, Colours col);

		void assignCountries(std :: vector<Countries>& co);

		Players(int numBattlesWon, int numBattlesLost, int reinforcements);

		void attack();

		void defend();

		void reinforceArmies();

		int getNumArmies();

		int getNumCountries();

		std :: string getName();

		int getId();

		int getTurn();

		void setTurn(int newTurn);

		int getNumBattlesWon();

		int getNumBattlesLost();

		int getNumReinforcements();

		bool hasCountry(std :: string countryName);

		void addCountry(std :: string countryName);

		void removeCountry(std :: string countryName);

		int roll ();

		bool isActive();


	private:
		std :: string name;
		int id;
		int turn;
		int numberOfArmies;
		std :: vector<Countries>& countries;
		int numCountries;
		Colours assignedColour;
		int numWins;
		int numLosts;
		int numReinforcements;


};
#endif /* PLAYERS_H_ */
