# ⚡ STUDENT RECORD MANAGEMENT SYSTEM ⚡

[![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=c%2B%2B)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-brightgreen?style=for-the-badge&logo=windows)](https://github.com/FALCONZeroX)
[![License](https://img.shields.io/badge/License-MIT-purple?style=for-the-badge)](LICENSE)
[![Storage](https://img.shields.io/badge/Storage-Binary%20File-orange?style=for-the-badge&logo=files)](#)
[![Restore](https://img.shields.io/badge/Restore-Supported-success?style=for-the-badge&logo=databricks)](#)
[![Validation](https://img.shields.io/badge/Input-Validation-important?style=for-the-badge&logo=checkmarx)](#)
[![Console UI](https://img.shields.io/badge/UI-Console%20Application-lightgrey?style=for-the-badge&logo=windows-terminal)](#)
[![Color Output](https://img.shields.io/badge/Output-Colored%20Console-blue?style=for-the-badge&logo=gnu-bash)](#)
[![Made with](https://img.shields.io/badge/Made%20with-%E2%96%B6%20Blood%2C%20Sweat%20%26%20Code-red?style=for-the-badge)](https://github.com/FALCONZeroX)
[![Author](https://img.shields.io/badge/Author-FALCONZeroX-black?style=for-the-badge&logo=github)](https://github.com/FALCONZeroX)
[![Year](https://img.shields.io/badge/Year-2026-blue?style=for-the-badge)](#)


## 📡 *SYSTEM OVERVIEW*

> **Student Management System** is a high‑performance, terminal‑based application written in **C++**. It allows educational institutions to manage student records with **binary file persistence**, **advanced search**, **statistical reports**, **pagination**, and **cyberpunk‑styled CLI** animations. Built with pure STL – no external dependencies.

| Feature                | Description                                                                 |
|------------------------|-----------------------------------------------------------------------------|
| 🔥 **CRUD Operations** | Add, Show, Search, Update, Delete (logical or physical)                    |
| 📁 **Persistence**     | Binary `.data` + human‑readable `.txt` import/export                       |
| 📊 **Statistics**      | cGPA ranges, department distribution, semester wise, active/inactive       |
| 🔀 **Sorting**         | Roll number (asc/desc), name (A-Z), cGPA (desc), semester (asc)            |
| 💾 **Backup/Restore**  | One‑click full binary backup and restore                                   |
| 🧩 **Input validation**| Robust checks for names, email, phone, semester, cGPA, duplicates          |
| 🖥️ **Paginated view**  | 10 records per page (NEXT/PREV), dynamic width formatting                  |

---

## 🗂️ **PROJECT STRUCTURE**

```

Student-Management-System/
├── src/                      # ☣️ source code – heart of the matrix
│   ├── main.cpp              # entry point + ASCII splash
│   └── student.cpp           # all CRUD logic, file I/O, helpers
│
├── include/                  # ⚙️ headers – contracts & interfaces
│   └── student.h             # stStudents struct + prototypes
│
├── data/                     # 💽 persistent storage (binary)
│   └── Students.data         # auto‑generated binary database
│
├── .gitignore                # 🧹 ignore binaries, temp files
└── README.md                 # 📜 this neon manifesto

```

---

## ⚡ **FEATURES DEEP DIVE**

### 🔹 **MAIN MENU** (10 core modules)
```cpp
[1]  Add New Student Record
[2]  Show All Students (paginated)
[3]  Search (by Roll / Name / Dept / cGPA)
[4]  Update (Semester, cGPA, Phone, Email, Status)
[5]  Delete (Logical / Actual)
[6]  Statistics & Reports
[7]  Arrange Records (5 sorting algorithms)
[8]  Export to .txt
[9]  Import from .txt
[10] Backup & Restore (binary)
[11] Exit
```

🔹 DATA STRUCTURE

```cpp
struct stStudents {
    int RollNumber;
    char First_Name[40];
    char Last_Name[40];
    char Department[40];    // CS, IT, ME, EE, CE
    int Semester;           // 1..8
    float cGPA;             // 0.0 – 4.0
    char Date_of_Birth[12]; // DD/MM/YYYY
    char Phone_Number[20];  // exactly 9 digits
    char Email[40];         // must contain '@'
    bool Is_Active;
};
```

## 🔹 VALIDATION & ERROR HANDLING

- **Name:** only letters, no digits, spaces allowed  
- **Department:** strict 5-option enum  
- **Semester:** 1-8 range  
- **cGPA:** 0.0 – 4.0 with 2-digit precision  
- **Phone:** exactly 9 numeric characters  
- **Email:** must contain `@` symbol  
- **Roll number:** auto-incremented, duplicate check  
- **Buffer cleanup:** `cin.fail()` + `cin.ignore()` for robust input  

---

## 🔹 PAGINATION SYSTEM

- **10 records per page**
- **Commands:**
  - `N` (next)
  - `P` (prev)
  - `M` (main menu)
  - `E` (exit)
- **Dynamic column widths** *(106 chars total)*
- **Colored rows** for active/inactive status
---

🎮 USAGE EXAMPLE

```
====================================================================
================ STUDENTS RECORDS MANAGEMENT SYSTEM ================
====================================================================
[1] Add New Student Record
--------------------------
[2] Show All Students
---------------------
[3] Search in Students Records
-----------------------------
[4] Update Student Record
-------------------------
[5] Delete Student Record
-------------------------
[6] Statistics & Reports
------------------------
[7] Arrange Records
-------------------
[8] Export to TXT File
----------------------
[9] Import from TXT File
------------------------
[10] Backup & Restore
---------------------
[11] Exit
---------------------------------------------------
Please Enter Your Choice
>> 1
```

✨ Adding a student

```
====================================================
================ ADD NEW Record ====================
====================================================
Please Enter First Name
>> Neo
Please Enter Last Name
>> Anderson
Please Enter Department
>> CS
Please Enter Semester
>> 3
Please Enter cGPA
>> 3.75
... (DOB, Phone, Email, Status)
>> Y
[✔] Student Added Successfully
```

📈 Statistics report snippet

```
-------------------------------------
        Statistics And Reports
-------------------------------------
General Statistics
 - Total Students   : 42
 - Active Students  : 38
 - InActive Students: 4

Students According to cGPA
 - [3.5 - 4.0] Excellent  : 12
 - [3.0 - 3.49] Very GOOD : 15
 - [2.5 - 2.99] GOOD      : 10
 - [< 2.5] Accepted       : 5
```

---

## 💾 DATA PERSISTENCE MODEL

| File Name      | Format | Purpose |
|---------------|--------|---------|
| `Students.data` | Binary | Primary storage, read/written on every CRUD operation |
| `Student.txt`   | Text   | Human-readable export/import *(delimiter: `-`)* |

---

### 📌 Backup
- Copies the current vector to the binary file.

### 📌 Restore
- Reloads from the binary file even after total data loss.

---

## 👨‍💻 AUTHOR & CREDITS

- **Created by:** Falah Fathel  
- **GitHub alias:** `FALCONZeroX`  
- **Year:** 2026  
- **License:** MIT *(free to use, modify, distribute)*

---

## 🧪 TESTING & EDGE CASES

- ✅ **Empty database** → graceful messages, no crashes  
- ✅ **Duplicated roll numbers** → prevented by `Verify_Roll_Number`  
- ✅ **Invalid menu input** → loops until correct  
- ✅ **File missing** → `Import_From_Binary_File` returns empty vector  
- ✅ **Corrupted binary** → no UB, simply no records loaded  
- ✅ **Logical delete** → `Is_Active = false`, still appears in show/search but flagged **"InActive"**

---

## 🚀 FUTURE PLANS *(Glitch-in-the-Matrix edition)*

- Add GUI *(Qt or FTXUI)*
- Multi-user login with roles *(admin/teacher)*
- Course registration linked to students
- Export to CSV/Excel
- Cloud backup *(Firebase / REST API)*
- Dark/Neon theme toggle

---

📜 LICENSE

This project is licensed under the MIT License – see the LICENSE file for details.

```text
MIT License

Copyright (c) 2026 Falah Fathel

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction...
```

```
