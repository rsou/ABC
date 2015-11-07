/*
 * Players.cpp
 *
 * Written by Ramata Soumounou
 * Comp 345-Assignment 1
 * Instructor: Joey Paquet
 * October 29, 2015
 *
 */

#include "Players.h"
#include "Countries.h"
#include <iostream>
#include <vector>


Players :: Players(){
}

Players :: Players(const std :: string playersName, const int playersID, int playersTurn) : name(playersName), id(playersID), turn(playersTurn){
}

Players :: Players(int armies, std :: vector<Countries>& co, int numOfOwnedCountries, Colours col) : numberOfArmies(armies), countries(co), numCountries(numOfOwnedCountries), assignedColour(col){
}

Players :: Players(int numBattlesWon, int numBattlesLost, int reinforcements) : numWins(numBattlesWon), numLosts(numBattlesLost), numReinforcements(reinforcements){
}

void Players :: assignCountries(std :: vector<Countries>& co){
	// To generate 10 random countries
	for(unsigned int i = 0; i <= 10; i++){
		Countries newCountry = static_cast<CountriesName>(rand()% 199);
		co.push_back(newCountry);
	}
}

void Players :: attack(){
}

void Players :: defend(){
}

void Players:: reinforceArmies(){
}

bool Players :: hasCountry(std :: string countryName){
	for (unsigned int i = 0; i < countries.size(); i++){
		if(countries.at(i) == countryName)
		return true;
	}
return false;
}

void Players::addCountry(std :: string countryName){
	countries.push_back(static_cast<Countries>(countryName));
}

void Players :: removeCountry(std :: string countryName){
	for (unsigned int i = 0; i < countries.size(); i++){
		if(countries.at(i) == countryName)
		countries.erase(countries.begin()+i);
	}
}

inline int Players :: getNumArmies(){
	return numberOfArmies;
}

inline int Players :: getNumCountries(){
	return numCountries;
}

inline  std :: string Players :: getName(){
	return name;
}

inline int Players :: getId(){
	return id;
}

inline void Players :: setTurn(int newTurn){
	turn(newTurn);
}

inline int Players :: getTurn(){
	return turn;
}

inline int Players :: getNumBattlesWon(){
	return numWins;
}

inline int Players :: getNumBattlesLost(){
	return numLosts;
}

inline int Players :: getNumReinforcements(){
	return numReinforcements;
}

inline int Players :: roll (){
	int num= (1 + rand()%6);
	return num;
}


inline bool Players :: isActive(){
	if(numCountries != 0)
	return true;
return false;
}







