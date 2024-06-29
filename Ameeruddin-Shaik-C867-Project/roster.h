#pragma once
#include <iostream>
#include <string>
#include "degree.h" // Enum
#include "student.h"

class Roster {

public:
    const static int number_students = 5;
    Student* classRosterArray[number_students];
    int end_index = -1;

    // Parse
    void parse(std::string table_string);

    // Create
    void add(std::string studentID, std::string firstName, std::string lastName,
        std::string emailAddress, int age, int daysInCourse1, int daysInCourse2,
        int daysInCourse3, DegreeProgram degreeprogram);


    void remove(std::string studentID);


    // Print functions
    void printAll();
    void printAverageDaysInCourse(std::string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);






    ~Roster();
};
