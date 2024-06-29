// Ameeruddin-Shaik-C867-Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"

int main() {

    const std::string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Ameer,Shaik,ashai39@wgu.edu,24,20,22,24,SOFTWARE" };


    std::cout << "C867 -- C++ -- ID# 011074833 -- Ameeruddin Shaik " << std::endl << std::endl;
    int num_stu = 5;

    Roster classRoster;

    for (int i{ 0 }; i < num_stu; ++i) {
        classRoster.parse(studentData[i]);
    }

    classRoster.printAll(); // 1
    std::cout << std::endl << std::endl << std::endl;

    std::cout << "Printing invalid emails: " << std::endl;
    classRoster.printInvalidEmails(); // 2
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "Printing Average days in courses for students : " << std::endl; // 3
    for (int i{ 0 }; i < num_stu; ++i) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->get_id());
    }
    std::cout << std::endl << std::endl << std::endl;

    classRoster.printByDegreeProgram(SOFTWARE); // Printing Software students
    std::cout << std::endl << std::endl << std::endl;
    classRoster.remove("A3"); // Removing A3
    std::cout << std::endl << std::endl << std::endl;
    classRoster.printAll(); // Printing Roster again to show A3 removed
    std::cout << std::endl << std::endl << std::endl;
    classRoster.remove("A3"); // Trying to remove A3 again





    return 0;
}