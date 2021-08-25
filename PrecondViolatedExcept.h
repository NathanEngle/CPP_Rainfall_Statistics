/*
Nathan Engle
8/25/2021
Program Description: Uses a LinkedList data structure to store, modify, and display rainfall statistics
*/

#pragma once
#include <stdexcept>
#include <string>

class PrecondViolatedExcept : public std::logic_error
{
public:
	PrecondViolatedExcept(const std::string& message = "");
};