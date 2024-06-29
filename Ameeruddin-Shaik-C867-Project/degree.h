#pragma once
#include <iostream>
#include <string>

enum DegreeProgram { SECURITY, NETWORK, SOFTWARE, NONE };
static const std::string degree_program_array[] = { "SECURITY", "NETWORK", "SOFTWARE", "NONE" };
// NONE used a temporary for enum 