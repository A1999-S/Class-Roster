#pragma once
#include <iostream>
#include <string>
#include "degree.h"



class Student {

public:
    // Variable Declarations
    static const int array_size{ 15 };
    int num_days_course[array_size];
    std::string student_id;
    std::string first_name;
    std::string last_name;
    std::string email_address;
    int student_age{ 0 };
    DegreeProgram degree;

    // Getters Declarations
    std::string get_id();
    std::string get_first_name();
    std::string get_last_name();
    std::string get_email();
    int get_age();
    int* get_days_course(); // Dereference
    DegreeProgram get_degree();

    // Setters Declarations
    void set_id(std::string id);
    void set_first_name(std::string first_n);
    void set_last_name(std::string last_n);
    void set_email(std::string email);
    void set_age(int stu_age);
    void set_days_course(int course_days[]);
    void set_DegreeProgram(DegreeProgram deg);



    //Print

    void print();

    static void print_info();

    //Constructors
    Student();

    Student(int num_days_course[], std::string student_id, std::string first_name, std::string last_name,
        std::string email_address, int student_age, DegreeProgram degree);

    ~Student();

};