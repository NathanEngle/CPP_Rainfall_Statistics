/*
Nathan Engle
8/25/2021
Program Description: Uses a LinkedList data structure to store, modify, and display rainfall statistics
*/

#include "Rainfall.h"

Rainfall::Rainfall()
{
	month = "Mercedonius";
	rainfall = -1;
}

void Rainfall::setMonth(std::string m)
{
	month = m;
}

void Rainfall::setRain(double r)
{
	rainfall = r;
}

std::string Rainfall::getMonth()
{
	return month;
}

double Rainfall::getRain()
{
	return rainfall;
}