#pragma once
#include <iostream>
#include "clsStudent.h"
#include "clsUI_Utility.h"
#include "clsStudentManager.h"
#include "clsInputValidate.h"

using std::cout;
using std::cin;
using std::string;
using std::min;

class clsStudentUI
{
private:
    static void _PrintSearchResults(vector<clsStudent> Results)
    {
        if (Results.empty())
        {
            system("color 40");
            clsUI_Utility::Message("No Students Found");
            return;
        }
        else
        {
            clsUI_Utility::Print_Student_Header();
            for (clsStudent& S : Results)
            {
                system("color 20");
                cout << S.GetStudentRowString() << endl;
            }
        }
        clsUI_Utility::Message("Search Done Successfully");

    }
public:
    static void ShowAddNewStudentScreen()
    {
        system("cls");
        clsUI_Utility::Header('=', 67, 25, 26, "ADD NEW RECORD");

        string FName = clsInputValidate::Verify_Name("Please Enter First Name", "ADD NEW RECORD");
        string LName = clsInputValidate::Verify_Name("Please Enter Last Name", "ADD NEW RECORD");
        string Dept = clsInputValidate::Verify_Department("Please Enter Department", "ADD NEW RECORD");
        int Sem = clsInputValidate::Verify_Semester("Please Enter Semester", "ADD NEW RECORD");
        float GPA = clsInputValidate::Verify_cGPA("Please Enter cGPA", "ADD NEW RECORD");
        string DOB = clsInputValidate::Verify_Date("Please Enter Date of Birth");
        string Phone = clsInputValidate::Verify_Phone("Please Enter Phone Number", "ADD NEW RECORD");
        string Email = clsInputValidate::Verify_Email("Please Enter Email", "ADD NEW RECORD");
        bool Active = clsInputValidate::Verify_Is_Active("Please Enter Student Status", "ADD NEW RECORD");

        clsStudent NewStudent(0, FName, LName, Dept, Sem, GPA, DOB, Phone, Email, Active);

        clsStudentManager::Add_New_Student(NewStudent);

        system("color 20");
        clsUI_Utility::Message("Student Added Successfully");
        system("color 0f");
    }
    static void ShowAllStudentsScreen()
    {
        vector<clsStudent> students = clsStudentManager::GetAllStudents();

        if (students.empty())
        {
            system("color 40");
            system("cls");
            clsUI_Utility::Header('=', 67, 23, 25, "SHOW ALL STUDENTS");
            clsUI_Utility::Message("NO Students Found!");
            return; 
        }

        int Page_Size = 10;
        int Total_Students = students.size();
        int Total_Pages = (Total_Students + Page_Size - 1) / Page_Size;
        int Current_Page = 0;
        char op = ' ';

        while (true)
        {
            system("cls");
            system("color 60");
            string Title = "SHOW ALL STUDENTS (Page " + to_string(Current_Page + 1) + "/" + to_string(Total_Pages) + ")";
            clsUI_Utility::Header('=', 106, 38, 38, Title);

            cout << left << setw(4) << "N" << setw(8) << "R.NUM" << setw(20) << "Student Name"
                << setw(6) << "DEP" << setw(7) << "Sem" << setw(7) << "GPA" << setw(12)
                << "DOB" << setw(13) << "Phone" << setw(22) << "Email" << setw(9) << "Status" << endl;
            cout << string(106, '=') << endl;

            int start = Current_Page * Page_Size;
            int end = min(start + Page_Size, Total_Students);

            for (int i = start; i < end; i++)
            {
                cout << left << setw(4) << i + 1
                    << setw(8) << students[i].GetRollNumber()
                    << setw(20) << (students[i].GetFirstName() + " " + students[i].GetLastName())
                    << setw(6) << students[i].GetDepartment()
                    << setw(7) << students[i].GetSemester()
                    << setw(7) << fixed << setprecision(2) << students[i].GetcGPA()
                    << setw(12) << students[i].GetDOB()
                    << setw(13) << students[i].GetPhone()
                    << setw(22) << students[i].GetEmail()
                    << setw(9) << (students[i].GetIsActive() ? "Active" : "InActive") << endl;
            }

            cout << string(106, '=') << endl;
            cout << "[N] Next Page | [P] Previous Page | [M] Main Menu | [E] Exit\n";
            cout << ">> ";
            cin >> op;

            if (tolower(op) == 'n' && Current_Page < Total_Pages - 1)
                Current_Page++;
            else if (tolower(op) == 'p' && Current_Page > 0)
                Current_Page--;
            else if (tolower(op) == 'm')
                return; 
            else if (tolower(op) == 'e')
                exit(0);
        }
    }
    static void ShowSearchScreen() 
    {
        if (clsStudentManager::IsEmpty()) 
        { 
            system("color 40");
            system("cls");
            clsUI_Utility::Header('=', 67, 21, 23, "SEARCH STUDENT RECORD");
            clsUI_Utility::Message("NO Students Found");
            return;
        }

        system("cls");
        clsUI_Utility::Header('=', 67, 21, 23, "SEARCH STUDENT RECORD");
        cout << "[1] Search BY Roll Number\n[2] Search BY Name\n[3] Search BY Department\n[4] Search BY cGPA\n[Any Number] Main Menu\n";
        cout << string(67, '-') << endl;

        int choice = clsInputValidate::Verify_Integers("Please Enter Your Choice", "SEARCH");
        switch (choice) 
        {
        case 1: 
        {
            system("cls");
            clsUI_Utility::Header('=', 67, 25, 26, "SEARCH BY ROLL");
            int Roll = clsInputValidate::Verify_Integers("Enter Roll Number:", "SEARCH BY ROLL");
            clsStudent S = clsStudentManager::FindByRollNumber(Roll);
            if (S.GetIsActive() == 0 || S.GetIsActive() == 1)
            {
                vector<clsStudent> temp = {S}; 
                _PrintSearchResults(temp);
            }
            else
            {
                _PrintSearchResults({});
            }
            break;
        }
        case 2: 
        {
            system("cls");
            clsUI_Utility::Header('=', 67, 25, 26, "SEARCH BY NAME");
            string Name = clsInputValidate::Verify_Name("Enter Name to search:", "SEARCH BY NAME");
            _PrintSearchResults(clsStudentManager::FindByName(Name));
            break;
        }
        case 3: 
        {
            system("cls");
            clsUI_Utility::Header('=', 67, 25, 26, "SEARCH BY DEPT");
            string Dept = clsInputValidate::Verify_Department("Enter Department:", "SEARCH BY DEPT");
            _PrintSearchResults(clsStudentManager::FindByDepartment(Dept));
            break;
        }
        case 4: 
        {
            system("cls");
            clsUI_Utility::Header('=', 67, 25, 26, "SEARCH BY GPA");
            float GPA = clsInputValidate::Verify_cGPA("Enter GPA to search:", "SEARCH BY GPA");
            _PrintSearchResults(clsStudentManager::FindByGPA(GPA));
            break;
        }
        default:
            return; 
        }
    }
    static void ShowUpdateStudentScreen() 
    {
        if (clsStudentManager::IsEmpty()) 
        {
            system("color 40");
            clsUI_Utility::Header('=', 67, 25, 26, "UPDATE STUDENT");
            clsUI_Utility::Message("NO Students Found");
            return;
        }

        system("cls");
        clsUI_Utility::Header('=', 67, 25, 26, "UPDATE STUDENT");
        int Search_roll = clsInputValidate::Verify_Integers("Please Enter Student ID to Update", "UPDATE STUDENT");

        clsStudent* StudentToUpdate = clsStudentManager::FindByRollNumberPtr(Search_roll);

        if (StudentToUpdate == nullptr) 
        {
            system("color 40");
            clsUI_Utility::Message("Student Not Found!");
            return;
        }

        system("color 20");
        clsUI_Utility::Print_Student_Header();
        cout << StudentToUpdate->GetStudentRowString() << endl;

        cout << clsUI_Utility::Separator << endl;
        cout << "What Do You Want To Edit? \n";
        cout << clsUI_Utility::Separator << endl;
        cout << "[1] Semester | [2] cGPA | [3] Phone | [4] Email | [5] Status | [M] Cancel\n";
        cout << clsUI_Utility::Separator << endl;

        int choice = clsInputValidate::Verify_Integers("Please Enter Your Choice", "UPDATE");
        char confirm = 'n';

        switch (choice) 
        {
        case 1: 
        {
            int New_Sem = clsInputValidate::Verify_Semester("Enter New Semester", "UPDATE SEMESTER");
            clsUI_Utility::Confirm_Message("Update");
            cin >> confirm;
            if (tolower(confirm) == 'y') StudentToUpdate->SetSemester(New_Sem);
            break;
        }
        case 2: 
        {
            float New_GPA = clsInputValidate::Verify_cGPA("Enter New cGPA", "UPDATE cGPA");
            clsUI_Utility::Confirm_Message("Update");
            cin >> confirm;
            if (tolower(confirm) == 'y') StudentToUpdate->SetcGPA(New_GPA);
            break;
        }
        case 3: 
        {
            string New_Phone = clsInputValidate::Verify_Phone("Enter New Phone", "UPDATE PHONE");
            clsUI_Utility::Confirm_Message("Update");
            cin >> confirm;
            if (tolower(confirm) == 'y') StudentToUpdate->SetPhone(New_Phone);
            break;
        }
        case 4: 
        {
            string New_Email = clsInputValidate::Verify_Email("Enter New Email", "UPDATE EMAIL");
            clsUI_Utility::Confirm_Message("Update");
            cin >> confirm;
            if (tolower(confirm) == 'y') StudentToUpdate->SetEmail(New_Email);
            break;
        }
        case 5: 
        {
            bool New_Status = clsInputValidate::Verify_Is_Active("Enter New Status", "UPDATE STATUS");
            clsUI_Utility::Confirm_Message("Update");
            cin >> confirm;
            if (tolower(confirm) == 'y') StudentToUpdate->SetIsActive(New_Status);
            break;
        }
        default:
            return; 
        }

        if (tolower(confirm) == 'y') 
        {
            clsStudentManager::Save();
            system("color 20");
            clsUI_Utility::Message("Student Updated Successfully");
        }
        else 
        {
            system("color 60");
            clsUI_Utility::Message("Update Canceled");
        }
    }
    static void ShowDeleteStudentScreen() 
    {
        if (clsStudentManager::IsEmpty()) 
        {
            system("color 40");
            clsUI_Utility::Header('=', 67, 25, 26, "DELETE STUDENT");
            return;
        }

        system("cls");
        clsUI_Utility::Header('=', 67, 25, 26, "DELETE STUDENT");
        int Roll = clsInputValidate::Verify_Integers("Enter Student Roll Number to Delete", "DELETE STUDENT");

        clsStudent* S = clsStudentManager::FindByRollNumberPtr(Roll);

        if (S == nullptr) 
        {
            system("color 40");
            clsUI_Utility::Message("Student Not Found!");
            return;
        }

        system("color 20");
        clsUI_Utility::Print_Student_Header();
        cout << S->GetStudentRowString() << endl;

        cout << clsUI_Utility::Separator << endl;
        cout << "[1] Logical Delete (Set InActive)\n";
        cout << "[2] Actual Delete (Remove Permanently)\n";
        cout << "[Any Number] Cancel and Return\n";
        cout << clsUI_Utility::Separator << endl;

        int choice = clsInputValidate::Verify_Integers("Please Enter Your Choice", "DELETE");
        char confirm = 'n';

        if (choice == 1 || choice == 2) 
        {
            cout << "\nAre you sure you want to delete this record? (y/n): ";
            cout << ">> ";
            cin >> confirm;
        }
        else
        {
            return;
        }

        if (tolower(confirm) == 'y') 
        {
            if (choice == 1) 
            {
                system("color 20");
                clsStudentManager::LogicalDelete(Roll);
                clsUI_Utility::Message("Record Deleted Logically (InActive).");
            }
            else 
            {
                system("color 20");
                clsStudentManager::ActualDelete(Roll);
                clsUI_Utility::Message("Record Deleted Permanently From System.");
            }
        }
        else 
        {
            system("color 60");
            clsUI_Utility::Message("Deletion Canceled.");
        }
    }
    static void ShowStatisticsScreen() 
    {
        if (clsStudentManager::IsEmpty()) 
        {
            system("color 40");
            clsUI_Utility::Header('=', 67, 21, 22, "STATISTICS AND REPORTS");
            clsUI_Utility::Message("NOT Enough Data To Display");
            return;
        }

        clsStudentManager::stStatistics Stats = clsStudentManager::GetStatistics();
        
        system("color 60");
        system("cls");
        clsUI_Utility::Header('=', 67, 21, 22, "STATISTICS AND REPORTS");

        cout << clsUI_Utility::Separator << endl;
        cout << "\t\t\tGeneral Statistics" << endl;
        cout << clsUI_Utility::Separator << endl;
        cout << " - Total Students   : " << Stats.Total << endl;
        cout << " - Active Students  : " << Stats.Active << endl;
        cout << " - InActive Students: " << Stats.InActive << endl;

        cout << endl;
        cout << clsUI_Utility::Separator << endl;
        cout << "\t\tStudents According to Department" << endl; 
        cout << clsUI_Utility::Separator << endl;

        printf(" - IT: %d | CS: %d | ME: %d | EE: %d | CE: %d\n",
            Stats.IT, Stats.CS, Stats.ME, Stats.EE, Stats.CE);
        
        cout << endl;
        cout << clsUI_Utility::Separator << endl;
        cout << "\t\t\tStudents According to cGPA" << endl;
        cout << clsUI_Utility::Separator << endl;

        cout << " - Excellent [3.5 - 4.0]: " << Stats.Excellent << endl;
        cout << " - Very GOOD [3.0 - 3.4]: " << Stats.VeryGood << endl;
        cout << " - GOOD      [2.5 - 2.9]: " << Stats.Good << endl;
        cout << " - Accepted  [ < 2.5 ]  : " << Stats.Accepted << endl;

        cout << endl;
        cout << clsUI_Utility::Separator << endl;
        cout << "\t\t\tStudents According to Semester" << endl;
        cout << clsUI_Utility::Separator << endl;

        for (int i = 1; i <= 8; i++) 
        {
            cout << " - Semester [" << i << "] : " << Stats.Semesters[i] << (i % 2 == 0 ? "\n" : "\t");
        }

        cout << endl;
        clsUI_Utility::Message("End of Report");
    }
    static void ShowSortScreen() 
    {
        if (clsStudentManager::IsEmpty()) 
        {
            system("color 40");
            clsUI_Utility::Header('=', 67, 24, 26, "ARRANGE RECORDS");
            clsUI_Utility::Message("NOT Enough Data to Arrange");
            return;
        }

        system("cls");
        clsUI_Utility::Header('=', 67, 24, 26, "ARRANGE RECORDS");
        cout << "[1] Roll Number [Ascending]" << endl;
        cout << "[2] Roll Number [Descending]" << endl;
        cout << "[3] Name [A-Z]" << endl;
        cout << "[4] Name [Z-A]" << endl;
        cout << "[5] cGPA [Descending]" << endl;
        cout << "[6] Semester [Ascending]" << endl;
        cout << "[Any Number] Return to Main Menu" << endl;
        cout << string(67, '-') << endl;

        int choice = clsInputValidate::Verify_Integers("Enter Your Choice", "ARRANGE");
        char confirm = 'n';

        if (choice >= 1 && choice <= 6) 
        {
            clsUI_Utility::Confirm_Message("Arrange");
            cin >> confirm;
        }
        else
        {
            return;
        }

        if (tolower(confirm) == 'y') 
        {
            system("color 20");
            switch (choice) 
            {
            case 1: clsStudentManager::SortByRoll_Ascending(); break;
            case 2: clsStudentManager::SortByRoll_Descending(); break;
            case 3: clsStudentManager::SortByName_AtoZ(); break;
            case 4: clsStudentManager::SortByName_ZtoA(); break;
            case 5: clsStudentManager::SortByGPA_Descending(); break;
            case 6: clsStudentManager::SortBySemester_Ascending(); break;
            }
            clsUI_Utility::Message("Records Arranged and Saved Successfully!");
        }
        else 
        {
            system("color 60");
            clsUI_Utility::Message("Operation Canceled.");
        }
    }
    static void ShowExportScreen()
    {
        if (clsStudentManager::IsEmpty())
        {
            system("color 40");
            clsUI_Utility::Header('=', 67, 23, 24, "EXPORT TO TXT FILE");
            clsUI_Utility::Message("NOT Enough Data to Export");
            return;
        }

        system("cls");
        clsUI_Utility::Header('=', 67, 23, 24, "EXPORT TO TXT FILE");

        cout << clsUI_Utility::Separator << endl;
        cout << "Choose Delimiter Type:\n";
        cout << clsUI_Utility::Separator << endl;
        cout << "[1] Hashtag (#) - Standard\n";
        cout << "[2] Comma (,)   - CSV for Excel\n";
        cout << "[Any Number] Cancel\n";
        cout << clsUI_Utility::Separator << endl;

        int choice = clsInputValidate::Verify_Integers("Enter Choice", "EXPORT");
        char Delimiter = '#';
        string Ext = ".txt";

        if (choice == 1) Delimiter = '#';
        else if (choice == 2) { Delimiter = ','; Ext = ".csv"; }
        else return;

        clsUI_Utility::Confirm_Message("Export");
        char confirm;
        cin >> confirm;

        if (tolower(confirm) == 'y')
        {
            string Path = "StudentsData" + Ext;
            if (clsStudentManager::ExportToTXT(Path, Delimiter))
            {
                system("color 20");
                clsUI_Utility::Message("Exported Successfully to: " + Path);
            }
            else
            {
                system("color 40");
                clsUI_Utility::Message("Error: Could not create file!");
            }
        }
        else
        {
            system("color 60");
            clsUI_Utility::Message("Operation Canceled");
        }
    }
    static void ShowImportScreen() 
    {
        system("cls");
        clsUI_Utility::Header('=', 67, 22, 23, "IMPORT FROM TXT FILE");

        cout << "Note: This will add students from 'StudentsData.txt' to your system.\n";
        clsUI_Utility::Confirm_Message("Import");

        char confirm;
        cin >> confirm;

        if (tolower(confirm) == 'y') 
        {
            system("color 20");
            clsStudentManager::ImportFromTXT("StudentsData.txt", '#');
            clsUI_Utility::Message("Data Imported and Synced with Binary File.");
        }
        else {
            system("color 60");
            clsUI_Utility::Message("Import Canceled.");
        }
    }
    static void ShowBackupRestoreScreen() 
    {
        system("cls");
        clsUI_Utility::Header('=', 67, 24, 25, "BACKUP & RESTORE");
        cout << "[1] Backup All Data (Save to Binary)\n";
        cout << "[2] Restore All Data (Load from Binary)\n";
        cout << "[Any Number] Return to Main Menu\n";
        cout << string(67, '-') << endl;

        int choice = clsInputValidate::Verify_Integers("Please Enter Your Choice", "BACKUP/RESTORE");
        char confirm = 'n';

        switch (choice) 
        {
        case 1: 
        { 
            if (clsStudentManager::IsEmpty()) 
            {
                system("color 40");
                clsUI_Utility::Message("Nothing to backup! System is empty.");
                return;
            }
            cout << "\nAre you sure you want to perform Backup? (y/n): ";
            cin >> confirm;
            if (tolower(confirm) == 'y') 
            {
                clsStudentManager::BackupData();
                system("color 20");
                clsUI_Utility::Message("Backup Done Successfully.");
            }
            break;
        }
        case 2: 
        {
            cout << "\nWARNING: This will overwrite current session data! Proceed? (y/n): ";
            cin >> confirm;
            if (tolower(confirm) == 'y') 
            {
                clsStudentManager::RestoreData();
                system("color 20");
                clsUI_Utility::Message("Data Restored Successfully from Disk.");
            }
            break;
        }
        default:
            return; 
        }

        if (tolower(confirm) != 'y') 
        {
            system("color 60");
            clsUI_Utility::Message("Operation Canceled.");
        }
    }
};

