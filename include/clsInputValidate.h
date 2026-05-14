#pragma once
#include <iostream>
#include <cctype>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::getline;
using std::ws;
using std::to_string;

class clsInputValidate
{
private:
    static bool _Is_Digit(string st)
    {
        for (char& c : st)
        {
            if (isdigit(c)) return true;
        }
        return false;
    }
    static bool _Has_at(string email)
    {
        return (email.find('@') != string::npos && email.find('.') != string::npos);
    }
public:
    static int Verify_Integers(string message, string Title)
    {
        int number;
        cout << message << endl;
        cout << ">> ";
        cin >> number;

        while (true)
        {
            if (cin.fail())
            {
                system("color 40");
                system("cls");
                clsUI_Utility::Clear_Buffer();
                clsUI_Utility::Header('=', 67, 25, 26, Title);
                cout << clsUI_Utility::Separator << endl;
                cout << "Invalid Character, Please Re-Enter A Valid Value" << endl;
                cout << clsUI_Utility::Separator << endl;
                cout << ">> ";
                cin >> number;
            }
            else if (number < 0)
            {
                system("color 40");
                system("cls");
                clsUI_Utility::Header('=', 67, 25, 26, Title);
                cout << clsUI_Utility::Separator << endl;
                cout << "Invalid Value, Value Must be > 0" << endl;
                cout << clsUI_Utility::Separator << endl;
                cout << ">> ";
                cin >> number;
            }
            else
            {
                break;
            }
        }
        system("color 0f");
        return number;
    }
    static string Verify_Name(string message, string Title)
    {
        system("cls");
        clsUI_Utility::Header('=', 67, 25, 26, Title);
        string name;
        cout << message << endl;
        cout << ">> ";
        getline(cin >> ws, name);

        while (_Is_Digit(name))
        {
            system("cls");
            system("color 40");
            clsUI_Utility::Header('=', 67, 25, 26, Title);

            cout << clsUI_Utility::Separator << endl;
            cout << "Invalid Character, Must be letters only!" << endl;
            cout << clsUI_Utility::Separator << endl;

            cout << ">> ";
            getline(cin >> ws, name);
        }

        system("color 0f");
        return name;
    }
    static string Verify_Department(string message, string Title)
    {
        system("cls");
        clsUI_Utility::Header('=', 67, 25, 26, Title);
        string department;
        cout << message << endl;
        cout << ">> ";

        getline(cin >> ws, department);

        while (department != "CS" && department != "IT" && department != "ME" && department != "EE" && department != "CE")
        {
            system("color 40");
            system("cls");
            clsUI_Utility::Header('=', 67, 25, 26, Title);
            cout << clsUI_Utility::Separator << endl;
            cout << "Invalid Department, Must be one of the following:" << endl;
            cout << "[IT] Information Technology" << endl;
            cout << "[CS] Computer Science" << endl;
            cout << "[CE] Civil Engineering" << endl;
            cout << "[ME] Mechanical Engineering" << endl;
            cout << "[EE] Electrical Engineering" << endl;
            cout << clsUI_Utility::Separator << endl;
            cout << ">> ";
            getline(cin >> ws, department);
        }
        system("cls");
        system("color 0f");
        clsUI_Utility::Header('=', 67, 25, 26, Title);
        return department;
    }
    static int Verify_Semester(string message, string Title)
    {
        int semester;
        cout << message << endl;
        cout << ">> ";
        cin >> semester;

        while (cin.fail() || semester <= 0 || semester > 8)
        {
            system("color 40");
            system("cls");
            clsUI_Utility::Clear_Buffer();
            clsUI_Utility::Header('=', 67, 25, 26, Title);

            cout << clsUI_Utility::Separator << endl;
            cout << "Invalid Value, Value Must be between [1] and [8]" << endl;
            cout << clsUI_Utility::Separator << endl;
            cout << ">> ";
            cin >> semester;
        }
        system("cls");
        system("color 0f");
        clsUI_Utility::Header('=', 67, 25, 26, Title);
        return semester;
    }
    static float Verify_cGPA(string message, string Title)
    {
        float cGPA;
        cout << message << endl;
        cout << ">> ";
        cin >> cGPA;

        while (cin.fail() || cGPA < 0.0 || cGPA > 4.0)
        {
            system("color 40");
            system("cls");
            clsUI_Utility::Clear_Buffer();
            clsUI_Utility::Header('=', 67, 25, 26, Title);
            cout << clsUI_Utility::Separator << endl;
            cout << "Invalid Value, Value Must be between [0.00] &  [4.00]" << endl;
            cout << clsUI_Utility::Separator << endl;
            cout << ">> ";
            cin >> cGPA;
        }
        system("cls");
        system("color 0f");
        clsUI_Utility::Header('=', 67, 25, 26, Title);
        return cGPA;
    }
    static string Verify_Date(string message)
    {
        int day = verify_Day("Please Enter Day of birth", "Add New Student");
        int month = verify_Month("Please Enter Month of birth", "Add New Student");
        int year = verify_Year("Please Enter Year of birth", "Add New Student");

        string d = (day < 10 ? "0" : "") + to_string(day);
        string m = (month < 10 ? "0" : "") + to_string(month);

        return d + "/" + m + "/" + to_string(year);
    }
    static int verify_Day(string message, string Title)
    {
        int day;
        cout << message << endl;
        cout << ">> ";
        cin >> day;

        while (true)
        {
            if (cin.fail())
            {
                system("color 40");
                system("cls");
                clsUI_Utility::Clear_Buffer();
                clsUI_Utility::Header('=', 67, 25, 26, Title);
                cout << clsUI_Utility::Separator << endl;
                cout << "Invalid Character, Please Re-Enter A Valid Value" << endl;
                cout << clsUI_Utility::Separator << endl;
                cout << ">> ";
                cin >> day;
            }
            else if (day < 0 || day > 31)
            {
                system("color 40");
                system("cls");
                clsUI_Utility::Header('=', 67, 25, 26, Title);
                cout << clsUI_Utility::Separator << endl;
                cout << "Invalid Value, Value Must be > 0 and <= 31" << endl;
                cout << clsUI_Utility::Separator << endl;
                cout << ">> ";
                cin >> day;
            }
            else
            {
                break;
            }
        }
        system("cls");
        system("color 0f");
        clsUI_Utility::Header('=', 67, 25, 26, Title);
        return day;
    }
    static int verify_Month(string message, string Title)
    {
        int month;
        cout << message << endl;
        cout << ">> ";
        cin >> month;
        while (true)
        {
            if (cin.fail())
            {
                system("color 40");
                clsUI_Utility::Clear_Buffer();
                system("cls");
                clsUI_Utility::Header('=', 67, 25, 26, Title);
                cout << clsUI_Utility::Separator << endl;
                cout << "Invalid Character, Please Re-Enter A Valid Value" << endl;
                cout << clsUI_Utility::Separator << endl;
                cout << ">> ";
                cin >> month;
            }
            else if (month < 0 || month > 12)
            {
                system("color 40");
                system("cls");
                clsUI_Utility::Header('=', 67, 25, 26, Title);
                cout << clsUI_Utility::Separator << endl;
                cout << "Invalid Value, Value Must be > 0 and <= 12" << endl;
                cout << clsUI_Utility::Separator << endl;
                cout << ">> ";
                cin >> month;
            }
            else
            {
                break;
            }
        }
        system("cls");
        system("color 0f");
        clsUI_Utility::Header('=', 67, 25, 26, Title);
        return month;
    }
    static int verify_Year(string message, string Title)
    {
        int month;
        cout << message << endl;
        cout << ">> ";
        cin >> month;
        while (true)
        {
            if (cin.fail())
            {
                system("color 40");
                clsUI_Utility::Clear_Buffer();
                system("cls");
                clsUI_Utility::Header('=', 67, 25, 26, Title);
                cout << clsUI_Utility::Separator << endl;
                cout << "Invalid Character, Please Re-Enter A Valid Value" << endl;
                cout << clsUI_Utility::Separator << endl;
                cout << ">> ";
                cin >> month;
            }
            else if (month < 1980 || month > 2026)
            {
                system("color 40");
                system("cls");
                clsUI_Utility::Header('=', 67, 25, 26, Title);
                cout << clsUI_Utility::Separator << endl;
                cout << "Invalid Value, Value Must be > 1980 and <= 2026" << endl;
                cout << clsUI_Utility::Separator << endl;
                cout << ">> ";
                cin >> month;
            }
            else
            {
                break;
            }
        }
        system("cls");
        system("color 0f");
        clsUI_Utility::Header('=', 67, 25, 26, Title);
        return month;
    }
    static string Verify_Phone(string message, string Title)
    {
        string phone;
        cout << message << endl;
        cout << ">> ";
        cin >> phone;

        while (phone.length() != 9 || _Is_Digit(phone) == false)
        {
            system("color 40");
            system("cls");
            clsUI_Utility::Header('=', 67, 25, 26, Title);
            cout << clsUI_Utility::Separator << endl;
            if(phone.length() != 9)
                cout << "Invalid Phone Number, Must be Exactly Digits" << endl;
            else
                cout << "Invalid Phone Number, Must be Numbers Only" << endl;

            cout << clsUI_Utility::Separator << endl;
            cout << ">> ";
            cin >> phone;
        }
        system("cls");
        system("color 0f");
        clsUI_Utility::Header('=', 67, 25, 26, Title);
        return phone;
    }
    static string Verify_Email(string message, string Title)
    {
        string email;
        cout << message << endl;
        cout << ">> ";
        cin >> email;
        while (!_Has_at(email))
        {
            system("color 40");
            system("cls");
            clsUI_Utility::Header('=', 67, 25, 26, Title);
            cout << clsUI_Utility::Separator << endl;
            cout << "Invalid Email, Must Contain (@) & (.)" << endl;
            cout << clsUI_Utility::Separator << endl;
            cout << ">> ";
            cin >> email;
        }
        system("cls");
        system("color 0f");
        clsUI_Utility::Header('=', 67, 25, 26, Title);
        return email;
    }
    static bool Verify_Is_Active(string message, string Title)
    {
        int choice;
        cout << message << " [1] Active, [0] InActive" << endl;
        cout << ">> ";
        cin >> choice;

        while (cin.fail() || (choice != 0 && choice != 1))
        {
            system("color 40");
            system("cls");
            clsUI_Utility::Clear_Buffer();
            clsUI_Utility::Header('=', 67, 25, 26, Title);
            cout << clsUI_Utility::Separator << endl;
            cout << "Invalid Value, Must be one of the following:" << endl;
            cout << "[1] True" << endl;
            cout << "[0] False" << endl;
            cout << clsUI_Utility::Separator << endl;
            cout << ">> ";
            cin >> choice;
        }
        system("cls");
        system("color 0f");
        clsUI_Utility::Header('=', 67, 25, 26, Title);
        return (bool)choice;
    }
};


