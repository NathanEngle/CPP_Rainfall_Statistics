/*
Nathan Engle
8/25/2021
Program Description: Uses a LinkedList data structure to store, modify, and display rainfall statistics
*/

#pragma once
#include <string>

class Rainfall
{
private:
	std::string month;
	double rainfall;
public:
	Rainfall();
	void setMonth(std::string);
	void setRain(double);
	std::string getMonth();
	double getRain();
};