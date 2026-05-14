#pragma once
#include <iostream>
#include "clsUI_Utility.h"
#include "clsInputValidate.h"
#include "clsStudentUI.h"

using std::cout;
using std::cin;


class clsMainScreen 
{
private:
    static void _GoBackToMainMenu() 
    {
        cout << "\n\nPress any key to go back to Main Menu...";
        system("pause>0");
    }

public:
    static void ShowMainMenu() 
    {
        bool Exit = false;

        while (!Exit) 
        {
            system("cls");
            system("color 0F");
            clsUI_Utility::Header('=', 67, 15, 16, "STUDENTS RECORDS MANAGEMENT SYSTEM");

            cout << "[1] Add New Student Record" << endl;
            cout << string(26, '-') << endl;
            cout << "[2] Show All Students" << endl;
            cout << string(21, '-') << endl;
            cout << "[3] Search in Students Records" << endl;
            cout << string(29, '-') << endl;
            cout << "[4] Update Student Record" << endl;
            cout << string(25, '-') << endl;
            cout << "[5] Delete Student Record" << endl;
            cout << string(25, '-') << endl;
            cout << "[6] Statistics & Reports" << endl;
            cout << string(24, '-') << endl;
            cout << "[7] Arrange Records" << endl;
            cout << string(19, '-') << endl;
            cout << "[8] Export to TXT File" << endl;
            cout << string(22, '-') << endl;
            cout << "[9] Import from TXT File" << endl;
            cout << string(24, '-') << endl;
            cout << "[10] Backup & Restore" << endl;
            cout << string(24, '-') << endl;
            cout << "[11] Exit" << endl;
            cout << string(67, '-') << endl;

            int choice = clsInputValidate::Verify_Integers("Please Enter Your Choice [1-11]", "STUDENTS RECORDS MANAGEMENT SYSTEM");

            switch (choice) {
            case 1:
                clsStudentUI::ShowAddNewStudentScreen(); 
                break;
            case 2:
                clsStudentUI::ShowAllStudentsScreen();
                break;
            case 3:
                clsStudentUI::ShowSearchScreen();
                break;
            case 4:
                clsStudentUI::ShowUpdateStudentScreen();
                break;
            case 5:
                clsStudentUI::ShowDeleteStudentScreen();
                break;
            case 6:
                clsStudentUI::ShowStatisticsScreen();
                break;
            case 7:
                clsStudentUI::ShowSortScreen();
                break;
            case 8:
                clsStudentUI::ShowExportScreen();
                break;
            case 9:
                clsStudentUI::ShowImportScreen();
                break;
            case 10:
                clsStudentUI::ShowBackupRestoreScreen();
                break;
            case 11:
                Exit = true;
                break;
            default:
                break;
            }
        }

        system("cls");
        cout << "\n\n\t\tSystem Closed. Thank you for using Our System! [FALCON]\n\n";
    }
};