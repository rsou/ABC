/*
 * Countries.cpp
 *
 * Written by Ramata Soumounou
 * Comp 345-Assignment 1
 * Instructor: Joey Paquet
 * October 29, 2015
 */


#include "Players.h"
#include "Countries.h”
#include <iostream>


Countries :: Coutries(const int value):countryValue(value);


Countries :: Countries(const string countryName, const string continentName, int numberOfArmies, Players* p) : country(countryName), continent(continentName), numArmies(numberOfArmies), owner(p){
}


inline void Countries :: setNumArmies(int newArmies){
	numArmies(newArmies);
}

inline int Countries :: getNumArmies(){
	return numArmies;
}

inline void Countries :: setOwner(Players*  newOwner){
	owner(newOwner);
}

inline Players* Countries :: getOwner(){
	return numArmies;
}

bool Countries :: isOccupied(){
	if(owner != NULL)
		return true;
return false;
}

// end of class definition











