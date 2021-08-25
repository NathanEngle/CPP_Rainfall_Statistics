/*
Nathan Engle
8/25/2021
Program Description: Uses a LinkedList data structure to store, modify, and display rainfall statistics
*/

#include "PrecondViolatedExcept.h"

PrecondViolatedExcept::PrecondViolatedExcept(const std::string& message) :
	std::logic_error("Precondition Violated Exception: " + message)
{}