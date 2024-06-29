#include "roster.h"
#include "student.h"


// Parse
void Roster::parse(std::string studentData) {
    DegreeProgram deg = NONE; // Temporary
    if (studentData.at(1) == '1')
        deg = SECURITY;
    else if (studentData.at(1) == '4')
        deg = SECURITY;
    else if (studentData.at(1) == '2')
        deg = NETWORK;
    else
        deg = SOFTWARE;

    // Student ID
    int right_index = studentData.find(","); // Getting location of ','
    std::string studentID = studentData.substr(0, right_index); // Making substring
    // First name
    int left_index = right_index + 1;
    right_index = studentData.find(",", left_index);
    std::string stu_first = studentData.substr(left_index, right_index - left_index);
    // Last name
    left_index = right_index + 1;
    right_index = studentData.find(",", left_index);
    std::string stu_last = studentData.substr(left_index, right_index - left_index);
    // Email
    left_index = right_index + 1;
    right_index = studentData.find(",", left_index);
    std::string stu_email = studentData.substr(left_index, right_index - left_index);
    // Age
    left_index = right_index + 1;
    right_index = studentData.find(",", left_index);
    int stu_age = stoi(studentData.substr(left_index, right_index - left_index));
    // First days in course
    left_index = right_index + 1;
    right_index = studentData.find(",", left_index);
    int days_course_1 = stoi(studentData.substr(left_index, right_index - left_index));
    // Second days in course   
    left_index = right_index + 1;
    right_index = studentData.find(",", left_index);
    int days_course_2 = stoi(studentData.substr(left_index, right_index - left_index));
    // Third days in course
    left_index = right_index + 1;
    right_index = studentData.find(",", left_index);
    int days_course_3 = stoi(studentData.substr(left_index, right_index - left_index));

    add(studentID, stu_first, stu_last, stu_email, stu_age, days_course_1, days_course_2, days_course_3, deg);

}



void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
    int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
    DegreeProgram degreeprogram) {

    int days_array[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    classRosterArray[++end_index] = new Student(days_array, studentID,
        firstName, lastName, emailAddress, age, degreeprogram);



}

void Roster::printAll() {

    Student::print_info();
    for (int i{ 0 }; i <= Roster::end_index; ++i) {
        std::cout << std::endl;
        std::cout << classRosterArray[i]->get_id(); std::cout << '\t' << "    ";
        std::cout << classRosterArray[i]->get_first_name(); std::cout << '\t';
        std::cout << classRosterArray[i]->get_last_name(); std::cout << "      ";
        std::cout << classRosterArray[i]->get_email(); std::cout << "            ";
        std::cout << classRosterArray[i]->get_age(); std::cout << '\t' << "       ";
        std::cout << "{ " << classRosterArray[i]->get_days_course()[0]; std::cout << ",";
        std::cout << classRosterArray[i]->get_days_course()[1]; std::cout << ",";
        std::cout << classRosterArray[i]->get_days_course()[2]; std::cout << " }" << '\t' << "\t" << "  ";
        std::cout << degree_program_array[classRosterArray[i]->get_degree()]; std::cout << std::endl;
    }
}


void Roster::printAverageDaysInCourse(std::string studentID) {

    for (int i{ 0 }; i <= Roster::end_index; ++i) {
        if (classRosterArray[i]->get_id() == studentID) {
            std::cout << studentID << " - ";
            std::cout << (classRosterArray[i]->get_days_course()[0] + classRosterArray[i]->get_days_course()[1] +
                classRosterArray[i]->get_days_course()[2]) / 3.0 << std::endl;
        }

    }
}


void Roster::printInvalidEmails() {

    bool invalid = false;
    for (int i{ 0 }; i <= Roster::end_index; ++i) {
        std::string stu_email = (classRosterArray[i]->get_email());
        if (stu_email.find(" ") == true || stu_email.find('.') == std::string::npos || stu_email.find('@') == std::string::npos) {

            invalid = true;
            std::cout << " - " << classRosterArray[i]->get_email() << std::endl;
        }
    }
    if (!invalid)
        std::cout << "No invalid email addresses" << std::endl;
}


void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    Student::print_info();
    for (int i{ 0 }; i <= Roster::end_index; ++i) {
        if (Roster::classRosterArray[i]->get_degree() == degreeProgram)
            classRosterArray[i]->print();
    }
}


void Roster::remove(std::string studentID) {

    bool tf = false;
    for (int i{ 0 }; i <= Roster::end_index; ++i) {
        if (classRosterArray[i]->get_id() == studentID) {
            tf = true;
            if (i < number_students - 1) {
                Student* exchange = classRosterArray[i];
                classRosterArray[i] = classRosterArray[number_students - 1];
                classRosterArray[number_students - 1] = exchange;
            }
            Roster::end_index--;
        }
    }
    if (tf) {
        std::cout << studentID << " has been removed" << std::endl;
    }
    else std::cout << studentID << " was not found" << std::endl;
}

// Destructor
Roster::~Roster() {
    for (int i{ 0 }; i < number_students; ++i) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
