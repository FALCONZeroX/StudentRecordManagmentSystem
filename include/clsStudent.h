#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <iomanip>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::left;
using std::ostringstream;

class clsStudent
{
private:
    int _RollNumber;
    char _FirstName[40];
    char _LastName[40];
    char _Department[40];
    int _Semester;
    float _cGPA;
    char _DateofBirth[12];
    char _PhoneNumber[20];
    char _Email[40];
    bool _IsActive;

protected:
    string Print_Boolean_as_String(bool isactive)
    {
        if (isactive)
            return "Active";
        else
            return "InActive";
    }

public:

    clsStudent() {}
    clsStudent(int RollNumber, string FirstName, string LastName, string Department, int Semester, float cGPA, string DateofBirth, string PhoneNumber, string Email, bool IsActive)
    {
        _RollNumber = RollNumber;
        _Semester = Semester;
        _cGPA = cGPA;
        _IsActive = IsActive;
        strcpy_s(_FirstName, FirstName.c_str());
        strcpy_s(_LastName, LastName.c_str());
        strcpy_s(_Department, Department.c_str());
        strcpy_s(_DateofBirth, DateofBirth.c_str());
        strcpy_s(_PhoneNumber, PhoneNumber.c_str());
        strcpy_s(_Email, Email.c_str());
    }

    //string PrintStudentRow()
    //{
    //    cout << left << setw(8) << _RollNumber
    //        << setw(20) << string(_FirstName) + ' ' + string(_LastName)
    //        << setw(6) << _Department
    //        << setw(7) << _Semester
    //        << setw(7) << fixed << setprecision(2) << _cGPA
    //        << setw(12) << _DateofBirth
    //        << setw(13) << _PhoneNumber
    //        << setw(22) << _Email
    //        << setw(9) << Print_Boolean_as_String(_IsActive) << endl;
    //}

    string GetStudentRowString() 
    {
        ostringstream oss;

        oss << left << setw(8) << _RollNumber
            << setw(20) << (string(_FirstName) + " " + string(_LastName))
            << setw(6) << _Department
            << setw(7) << _Semester
            << setw(7) << fixed << setprecision(2) << _cGPA
            << setw(12) << _DateofBirth
            << setw(13) << _PhoneNumber
            << setw(22) << _Email
            << setw(9) << Print_Boolean_as_String(_IsActive);

        return oss.str(); 
    }

    //RollNumber Set/Get
    void SetRollNumber(int newRoll)
    {
        _RollNumber = newRoll;
    }
    int GetRollNumber()
    {
        return _RollNumber;
    }

    //FirstName Set/Get
    void SetFName(string newFName)
    {
        strcpy_s(_FirstName, newFName.c_str());
    }
    string GetFirstName()
    {
        return _FirstName;
    }

    //LastName Set/Get
    void SetLName(string newLName)
    {
        strcpy_s(_LastName, newLName.c_str());
    }
    string GetLastName()
    {
        return _LastName;
    }

    //Department Set/Get
    void SetDepartment(string newDepartment)
    {
        strcpy_s(_Department, newDepartment.c_str());
    }
    string GetDepartment()
    {
        return _Department;
    }

    //Semester Set/Get
    void SetSemester(int newSem)
    {
        _Semester = newSem;
    }
    int GetSemester()
    {
        return _Semester;
    }

    //cGPA Set/Get
    void SetcGPA(float newcGPA)
    {
        _cGPA = newcGPA;
    }
    float GetcGPA()
    {
        return _cGPA;
    }

    //DateofBirth Set/Get
    void SetDOB(string newDOB)
    {
        strcpy_s(_DateofBirth, newDOB.c_str());
    }
    string GetDOB()
    {
        return _DateofBirth;
    }

    //PhoneNumber Set/Get
    void SetPhone(string newPhone)
    {
        strcpy_s(_PhoneNumber, newPhone.c_str());
    }
    string GetPhone()
    {
        return _PhoneNumber;
    }

    //Email Set/Get
    void SetEmail(string newEmail)
    {
        strcpy_s(_Email, newEmail.c_str());
    }
    string GetEmail()
    {
        return _Email;
    }

    //IsActive Set/Get
    void SetIsActive(int newIsActive)
    {
        _IsActive = newIsActive;
    }
    int GetIsActive()
    {
        return _IsActive;
    }

};


