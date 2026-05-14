#pragma once
#include <iostream>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::transform;
using std::left;
using std::setw;

class clsUI_Utility
{
public:
    inline static const string Separator = string(67, '-');
    static void Header(char symbol, int symbol_length, int M_Left, int M_Right, string Mess)
    {
        cout << string(symbol_length, symbol) << endl;
        cout << string(M_Left, symbol) << " " << Mess << " " << string(M_Right, symbol) << endl;
        cout << string(symbol_length, symbol) << endl;
    }
    static void Message(string NOTE)
    {
        cout << Separator << endl;
        cout << NOTE << endl;
        cout << Separator << endl;
        cout << "Press any key to continue...";
        system("pause");
    }
    static void Print_Student_Header()
    {
        cout << string(106, '=') << endl;
        cout << left << setw(8) << "R.NUM" << setw(20) << "Student Name" << setw(6) << "DEP" << setw(7) << "Sem" << setw(7) << "GPA" << setw(12) << "DOB" << setw(13) << "PhoneNumber" << setw(22) << "Email" << setw(9) << "Status" << endl;
        cout << string(106, '=') << endl;
    }
    static void Confirm_Message(string title)
    {
        cout << "Are You Sure You Want to " << title << "?" << endl;
        cout << Separator << endl;
        cout << "[Y] Yes" << endl;
        cout << "[Any Key] No" << endl;
        cout << Separator << endl;
        cout << ">> ";
    }
    static string Convert_To_Lower(string text)
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);

        return text;
    }
    static void Clear_Buffer()
    {
        cin.clear();
        cin.ignore(100, '\n');
    }
    static void GoBackToMainMenu()
    {
        cout << "\n\nPress any key to go back to Main Menu...";
        system("pause");
    }
};

