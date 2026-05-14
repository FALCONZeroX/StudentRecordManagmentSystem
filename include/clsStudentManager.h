#pragma once
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <vector>
#include "clsStudent.h"

using std::vector;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::stringstream;

class clsStudentManager
{
private:
	inline static vector <clsStudent> _vStudents;
    static void _Export_To_Binary()
    {
        ofstream export_binary("Students.data", ios::binary);
        if (export_binary.is_open())
        {
            for (clsStudent& s : _vStudents)
            {
                export_binary.write(reinterpret_cast<char*>(&s), sizeof(s));
            }
            export_binary.close();
        }
    }
    static int _Get_Uniqe_Roll()
    {
        if (_vStudents.empty())
        {
            return 1000;
        }

        int max = _vStudents[0].GetRollNumber();
        for (clsStudent& s : _vStudents)
        {
            if (s.GetRollNumber() > max)
            {
                max = s.GetRollNumber();
            }
        }
        return max + 1;
    }
    static bool _Exist_Student(int roll)
    {
        for (clsStudent& s : _vStudents)
        {
            if (s.GetRollNumber() == roll)
            {
                return true;
            }
        }
        return false;
    }
    static vector <clsStudent> _Import_From_Binary_File()
    {
        ifstream import_binary("Students.data", ios::binary);
        vector <clsStudent> students;
        clsStudent s;

        if (import_binary.is_open())
        {
            while (import_binary.read(reinterpret_cast<char*>(&s), sizeof(s)))
            {
                students.push_back(s);
            }
            import_binary.close();
        }
        return students;
    }
public:
    /* Add Functions */
    static vector<clsStudent> GetAllStudents()
    {
        return _vStudents;
    }
    static void Add_New_Student(clsStudent & NewStudent)
    {
        NewStudent.SetRollNumber(_Get_Uniqe_Roll());
        _vStudents.push_back(NewStudent);
        _Export_To_Binary();
    }
    /* Search Functions */
    static clsStudent FindByRollNumber(int RollNumber) 
    {
        for (clsStudent& S : _vStudents) 
        {
            if (S.GetRollNumber() == RollNumber)
            {
                return S;
            }
        }
        return clsStudent(); 
    }
    static vector<clsStudent> FindByName(string Name) 
    {
        vector<clsStudent> Results;
        string LowerSearch = clsUI_Utility::Convert_To_Lower(Name);
        for (clsStudent& S : _vStudents) 
        {
            if (clsUI_Utility::Convert_To_Lower(S.GetFirstName()) == LowerSearch) 
            {
                Results.push_back(S);
            }
        }
        return Results;
    }
    static vector<clsStudent> FindByDepartment(string Dept) 
    {
        vector<clsStudent> Results;
        for (clsStudent& S : _vStudents) 
        {
            if (S.GetDepartment() == Dept)
            {
                Results.push_back(S);
            }
        }
        return Results;
    }
    static vector<clsStudent> FindByGPA(float cgpa)
    {
        vector<clsStudent> Results;
        for (clsStudent& S : _vStudents)
        {
            if (S.GetcGPA() == cgpa)
            {
                Results.push_back(S);
            }
        }
        return Results;
    }
    static bool IsEmpty()
    {
        return _vStudents.empty();
    }
    /* Update Functions */
    static clsStudent* FindByRollNumberPtr(int RollNumber) 
    {
        for (clsStudent& S : _vStudents) 
        {
            if (S.GetRollNumber() == RollNumber)
            {
                return &S;
            }
        }
        return nullptr;
    }
    static void Save()
    {
        _Export_To_Binary();
    }
    /* Delete Functions */ 
    static void LogicalDelete(int RollNumber) 
    {
        clsStudent* S = FindByRollNumberPtr(RollNumber);
        if (S != nullptr) 
        {
            S->SetIsActive(false);
            Save();
        }
    }
    static bool ActualDelete(int RollNumber) 
    {
        for (auto it = _vStudents.begin(); it != _vStudents.end(); ++it) 
        {
            if (it->GetRollNumber() == RollNumber) 
            {
                _vStudents.erase(it);
                Save();
                return true;
            }
        }
        return false;
    }
    /* Statistics Functions */
    struct stStatistics 
    {
        int Total = 0, Active = 0, InActive = 0;
        int IT = 0, CS = 0, ME = 0, EE = 0, CE = 0;
        int Excellent = 0, VeryGood = 0, Good = 0, Accepted = 0;
        int Semesters[9] = { 0 }; 
    };
    static stStatistics GetStatistics()
    {
        stStatistics Stats;
        Stats.Total = _vStudents.size();

        for (clsStudent& s : _vStudents) 
        {
            if (s.GetIsActive()) Stats.Active++; else Stats.InActive++;

            if (s.GetDepartment() == "IT") Stats.IT++;
            else if (s.GetDepartment() == "CS") Stats.CS++;
            else if (s.GetDepartment() == "ME") Stats.ME++;
            else if (s.GetDepartment() == "EE") Stats.EE++;
            else if (s.GetDepartment() == "CE") Stats.CE++;

            float gpa = s.GetcGPA();
            if (gpa >= 3.5) Stats.Excellent++;
            else if (gpa >= 3.0) Stats.VeryGood++;
            else if (gpa >= 2.5) Stats.Good++;
            else Stats.Accepted++;

            if (s.GetSemester() >= 1 && s.GetSemester() <= 8)
                Stats.Semesters[s.GetSemester()]++;
        }
        return Stats;
    }
    /* Arrange Functions */
    static void SortByRoll_Ascending()
    {
        sort(_vStudents.begin(), _vStudents.end(), [](clsStudent& a, clsStudent& b) 
        {
            return a.GetRollNumber() < b.GetRollNumber();
        });
        Save();
    }
    static void SortByRoll_Descending()
    {
        sort(_vStudents.begin(), _vStudents.end(), [](clsStudent& a, clsStudent& b)
            {
                return a.GetRollNumber() > b.GetRollNumber();
            });
        Save();
    }
    static void SortByName_AtoZ() 
    {
        sort(_vStudents.begin(), _vStudents.end(), [](clsStudent& a, clsStudent& b) 
        {
            return (string(a.GetFirstName()) < string(b.GetFirstName()));
        });
        Save();
    }
    static void SortByName_ZtoA()
    {
        sort(_vStudents.begin(), _vStudents.end(), [](clsStudent& a, clsStudent& b)
            {
                return (string(a.GetFirstName()) > string(b.GetFirstName()));
            });
        Save();
    }
    static void SortByGPA_Descending() 
    {
        sort(_vStudents.begin(), _vStudents.end(), [](clsStudent& a, clsStudent& b) 
        {
            return a.GetcGPA() > b.GetcGPA(); 
        });
        Save();
    }
    static void SortBySemester_Ascending()
    {
        sort(_vStudents.begin(), _vStudents.end(), [](clsStudent& a, clsStudent& b)
            {
                return a.GetSemester() < b.GetSemester();
            });
        Save();
    }
    /* Export & Import From Text File Functions */
    static bool ExportToTXT(string FileName, char Delimiter = '#')
    {
        ofstream txt_export(FileName, ios::out);

        if (!txt_export.is_open())
        {
            return false;
        }

        for (clsStudent& s : _vStudents)
        {
            txt_export << s.GetRollNumber() << Delimiter
                << s.GetFirstName() << Delimiter
                << s.GetLastName() << Delimiter
                << s.GetDepartment() << Delimiter
                << s.GetSemester() << Delimiter
                << s.GetcGPA() << Delimiter
                << s.GetDOB() << Delimiter
                << s.GetPhone() << Delimiter
                << s.GetEmail() << Delimiter
                << s.GetIsActive() << endl;
        }

        txt_export.close();
        return true;
    }
    static void ImportFromTXT(string FileName, char Delimiter = '#') 
    {
        ifstream txt_import(FileName);
        if (!txt_import.is_open())
        {
            return;
        }

        string Line;
        while (getline(txt_import, Line)) 
        {
            if (Line.empty())
            {
                continue;
            }

            stringstream ss(Line);
            string roll, fname, lname, dept, sem, gpa, dob, phone, email, active;

            getline(ss, roll, Delimiter);
            getline(ss, fname, Delimiter);
            getline(ss, lname, Delimiter);
            getline(ss, dept, Delimiter);
            getline(ss, sem, Delimiter);
            getline(ss, gpa, Delimiter);
            getline(ss, dob, Delimiter);
            getline(ss, phone, Delimiter);
            getline(ss, email, Delimiter);
            getline(ss, active, Delimiter);

            int RollNum = stoi(roll);
            if (FindByRollNumberPtr(RollNum) == nullptr) 
            {
                clsStudent s;
                s.SetRollNumber(RollNum);
                s.SetFName(fname);
                s.SetLName(lname);
                s.SetDepartment(dept);
                s.SetSemester(stoi(sem));
                s.SetcGPA(stof(gpa)); 
                s.SetDOB(dob);
                s.SetPhone(phone);
                s.SetEmail(email);
                s.SetIsActive(stoi(active));

                _vStudents.push_back(s);
            }
        }
        txt_import.close();
        Save(); 
    }
    /* Backup & Restore Functions */
    static void BackupData() 
    {
        _Export_To_Binary();
    }
    static void RestoreData() 
    {
        _vStudents = _Import_From_Binary_File();
    }
    /* Loading from file Getter Function */
    static void LoadDataFromBinary()
    {
        _vStudents = _Import_From_Binary_File();
    }
};

