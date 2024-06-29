#include "degree.h"
#include "roster.h"
#include "student.h"

Student::Student() {
    for (int i{ 0 }; i < array_size; ++i) {
        num_days_course[i] = 0;
    }
    degree = { DegreeProgram::NONE };
    student_id = "";
    first_name = "";
    last_name = "";
    email_address = "";
    student_age = 0;
}


Student::Student(int num_days_course[], std::string student_id, std::string first_name, std::string last_name,
    std::string email_address, int student_age, DegreeProgram degree) {
    for (int i{ 0 }; i < array_size; ++i) {
        this->num_days_course[i] = num_days_course[i];
    }
    this->degree = degree;
    this->student_id = student_id;
    this->first_name = first_name;
    this->last_name = last_name;
    this->email_address = email_address;
    this->student_age = student_age;

}
Student::~Student() {
}

// Getters Implementations
std::string Student::get_id() {
    return student_id;
}
std::string Student::get_first_name() {
    return first_name;
}
std::string Student::get_last_name() {
    return last_name;
}
std::string Student::get_email() {
    return email_address;
}
int Student::get_age() {
    return student_age;
}
int* Student::get_days_course() {
    return num_days_course;
}
DegreeProgram Student::get_degree() {
    return degree;
}


// Setters Implementations
void Student::set_days_course(int course_days[]) {
    for (int i{ 0 }; i < array_size; ++i) {
        num_days_course[i] = num_days_course[i];
    }
}
void Student::set_id(std::string ID) {
    student_id = ID;
}
void Student::set_first_name(std::string first_n) {
    first_name = first_n;
}
void Student::set_last_name(std::string last_n) {
    last_name = last_n;
}
void Student::set_email(std::string email) {
    email_address = email;
}
void Student::set_age(int stu_age) {
    student_age = stu_age;
}
void Student::set_DegreeProgram(DegreeProgram deg) {
    degree = deg;
}

void Student::print_info() {
    std::cout << "==========================================================================================================================================" << std::endl;
    std::cout << "Student ID  First Name  Last Name   Email                       Age              daysInCourse            Degree Program" << std::endl;
}

void Student::print() {
    std::cout << std::endl;
    std::cout << get_id() << "\t" << "    ";
    std::cout << get_first_name() << "\t" << "";
    std::cout << get_last_name() << "\t" << "    ";
    std::cout << get_email() << "\t" << "     ";
    std::cout << get_age() << "\t" << "\t" << "\t";
    std::cout << "{ " << get_days_course()[0] << ",";
    std::cout << get_days_course()[1] << ",";
    std::cout << get_days_course()[2] << " }" << "\t" << "\t" << "";
    std::cout << degree_program_array[get_degree()] << "\t";

}