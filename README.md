# ⚡ STUDENT RECORD MANAGEMENT SYSTEM (OOP EDITION) ⚡

[![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=c%2B%2B)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows-brightgreen?style=for-the-badge&logo=windows)](https://github.com/FALCONZeroX)
[![License](https://img.shields.io/badge/License-MIT-purple?style=for-the-badge)](LICENSE)
[![Storage](https://img.shields.io/badge/Storage-Binary%20File-orange?style=for-the-badge&logo=files)](#)
[![OOP](https://img.shields.io/badge/Architecture-OOP-red?style=for-the-badge&logo=github)](#)
[![Validation](https://img.shields.io/badge/Input-Validation-important?style=for-the-badge&logo=checkmarx)](#)
[![Console UI](https://img.shields.io/badge/UI-Console%20Application-lightgrey?style=for-the-badge&logo=windows-terminal)](#)
[![Made with](https://img.shields.io/badge/Made%20with-%E2%96%B6%20Blood%2C%20Sweat%20%26%20Code-red?style=for-the-badge)](https://github.com/FALCONZeroX)
[![Author](https://img.shields.io/badge/Author-FALCONZeroX-black?style=for-the-badge&logo=github)](https://github.com/FALCONZeroX)
[![Year](https://img.shields.io/badge/Year-2026-blue?style=for-the-badge)](#)

---

## 📡 *SYSTEM OVERVIEW*

> **Student Management System (OOP Edition)** is a high‑performance, terminal‑based application written in **C++** following **Object-Oriented Programming** principles. It allows educational institutions to manage student records with **binary file persistence**, **CRUD operations**, **advanced search**, **statistical reports**, **pagination**, **sorting**, **backup/restore**, and **input validation** – all with a clean separation of concerns.

| Feature                | Description                                                                 |
|------------------------|-----------------------------------------------------------------------------|
| 🔥 **CRUD Operations** | Add, Show, Search, Update, Delete (logical or physical)                    |
| 📁 **Persistence**     | Binary `.data` file + human‑readable `.txt`/`.csv` import/export           |
| 📊 **Statistics**      | cGPA ranges, department distribution, semester wise, active/inactive       |
| 🔀 **Sorting**         | Roll number (asc/desc), name (A-Z/Z-A), cGPA (desc), semester (asc)        |
| 💾 **Backup/Restore**  | One‑click full binary backup and restore                                   |
| 🧩 **Input validation**| Robust checks for names, email, phone, semester, cGPA, duplicates          |
| 🖥️ **Paginated view**  | 10 records per page (NEXT/PREV), dynamic width formatting                  |
| 🧱 **OOP Architecture**| Fully modular: Entity, Manager, UI, Validation, Utility layers             |

---

## 🗂️ **PROJECT STRUCTURE (Header‑only)**
```text
Student-Management-System/
├── main.cpp # Entry point – loads binary data & launches main menu
├── clsStudent.h # Student entity (encapsulated data, getters/setters, row formatting)
├── clsStudentManager.h # Business logic: vector management, CRUD, search, sort, file I/O
├── clsStudentUI.h # User interface screens (add, show, search, update, delete, stats, etc.)
├── clsMainScreen.h # Main menu controller & navigation loop
├── clsInputValidate.h # Input validation (numbers, names, email, phone, GPA, dates, etc.)
├── clsUI_Utility.h # Helper tools (headers, separators, messages, confirmation, pagination)
├── data/
│   └── Students.data # Auto‑generated binary database (vector serialization)
├── .gitignore
└── README.md
```
---

## 🧠 **OOP ARCHITECTURE (Layer Separation)**

| Class               | Responsibility                                                                 |
|---------------------|--------------------------------------------------------------------------------|
| `clsStudent`        | Student entity – private char arrays (for safe binary I/O), getters/setters, `GetStudentRowString()` |
| `clsStudentManager` | Static vector storage, CRUD logic, search, sort, statistics, binary/text file handling, backup/restore |
| `clsStudentUI`      | Static UI screens – collects input, displays results, calls Manager functions |
| `clsMainScreen`     | Main menu loop, dispatches to UI screens based on user choice                  |
| `clsInputValidate`  | Static validation functions (integers, names, departments, semester, GPA, date, phone, email, active status) |
| `clsUI_Utility`     | Static helpers – `Header()`, `Message()`, `Print_Student_Header()`, `Confirm_Message()`, `Convert_To_Lower()`, `Clear_Buffer()` |

**Key OOP Principles Applied:**
- **Encapsulation:** All member data is private, accessed via getters/setters.
- **Separation of Concerns:** UI ↔ Logic ↔ Validation ↔ Utility are independent.
- **Static methods & members:** No instantiation needed – global access to shared state (`_vStudents` vector).
- **No Circular Dependencies:** Utility layer never calls other classes.

---

## ⚡ **FEATURES DEEP DIVE**

### 🔹 **MAIN MENU** (11 core modules)
```cpp
[1]  Add New Student Record
[2]  Show All Students (paginated)
[3]  Search (by Roll / Name / Dept / cGPA)
[4]  Update (Semester, cGPA, Phone, Email, Status)
[5]  Delete (Logical / Actual)
[6]  Statistics & Reports
[7]  Arrange Records (5 sorting algorithms)
[8]  Export to .txt / .csv
[9]  Import from .txt / .csv
[10] Backup & Restore (binary)
[11] Exit
```

### 🔹 STUDENT DATA STRUCTURE (`clsStudent` – private members)

| Field | Type | Validation Rules |
| :--- | :--- | :--- |
| `_RollNumber` | `int` | Auto-generated (unique, starts from 1000)[cite: 1] |
| `_FirstName` | `char[40]` | No digits, spaces allowed[cite: 1] |
| `_LastName` | `char[40]` | No digits, spaces allowed[cite: 1] |
| `_Department` | `char[40]` | Strict: `IT`, `CS`, `ME`, `CE`[cite: 1] |
| `_Semester` | `int` | **1 – 8**[cite: 1] |
| `_cGPA` | `float` | **0.0 – 4.0** (2-digit precision)[cite: 1] |
| `_DateOfBirth` | `char[12]` | `DD/MM/YYYY` (day 1-31, month 1-12, year 1980-2026)[cite: 1] |
| `_PhoneNumber` | `char[20]` | Exactly 9 numeric digits[cite: 1] |
| `_Email` | `char[40]` | Must contain `@` and `.`[cite: 1] |
| `_IsActive` | `bool` | `true` (active) / `false` (inactive)[cite: 1] |

### ❓ Why `char[]` instead of `string`?

> **The Short Answer:** Binary file writing with `reinterpret_cast<char*>(&object)` requires a **fixed‑size memory layout**. `std::string` uses dynamic memory and would corrupt data on load.

## 🔹 VALIDATION & ERROR HANDLING

| Field | Method / Logic | Description |
| :--- | :--- | :--- |
| **Numbers** | `Verify_Integers()` | Handles `cin.fail()` and prevents infinite loops on invalid input. |
| **Names** | `Verify_Name()` | Rejects any input containing digits. |
| **Department** | `Verify_Department()` | Strict validation: accepts only `IT`, `CS`, `ME`, `CE`. |
| **Semester** | Range Check | Validates input strictly between **1 – 8**. |
| **cGPA** | Range Check | Validates input strictly between **0.0 – 4.0**. |
| **Date** | `Verify_Date()` | Validates Day (1-31), Month (1-12), and Year (1980-2026). |
| **Phone** | Format Check | Ensures input consists of **exactly 9 numeric digits**. |
| **Email** | Pattern Match | Basic check: must contain `@` and `.`. |
| **Roll Numbers** | `_Get_Unique_Roll()` | **Auto-generated** logic to prevent duplicates; no manual entry. |
| **Input Buffer** | `Clear_Buffer()` | Clears stream and ignores leftovers after failed extractions. |

---

## 🔹 PAGINATION SYSTEM

To ensure readability in the console, the system implements a dynamic pagination mechanism for displaying student records.

* **Capacity:** 10 records per page.
* **Layout:** Dynamic column widths (Total width: **106 characters**).
* **Visuals:** Colored rows based on status (e.g., Green for **Active**, Red for **InActive**) using ANSI console color codes.

### 🕹️ Navigation Commands
The user can navigate through the data using the following intuitive controls:

| Key | Action | Description |
| :---: | :--- | :--- |
| **`N`** | Next Page | Load and display the next 10 students. |
| **`P`** | Previous Page | Go back to the previous set of records. |
| **`M`** | Main Menu | Stop viewing and return to the home screen. |
| **`E`** | Exit | Safely close the application. |

---

### 🎨 Visual Feedback Logic
The UI utility automatically formats the rows to distinguish between active and inactive students:
> `Status == Active`   -> **[✔] Row rendered in Green** > `Status == InActive` -> **[✖] Row rendered in Red / Dimmed**


## 🔹 SORTING ALGORITHMS (using `std::sort` with lambdas)

The system leverages the efficiency of the C++ Standard Template Library (STL) to provide high-performance sorting using lambda expressions.

| Method | Order | Sort By |
| :--- | :---: | :--- |
| `SortByRoll_Ascending()` | ↑ | Roll number |
| `SortByRoll_Descending()` | ↓ | Roll number |
| `SortByName_AtoZ()` | A→Z | First name |
| `SortByName_ZtoA()` | Z→A | First name |
| `SortByGPA_Descending()` | ↓ | cGPA (highest first) |
| `SortBySemester_Ascending()` | ↑ | Semester |

---

### 💾 Auto-Persistence Feature
> [!IMPORTANT]
> All sorting functions automatically call the **`Save()`** method. This ensures that the new order is immediately persisted to the binary database file (`Students.data`), making the sorted view permanent[cite: 1].


### 🔹 STATISTICS REPORT (single pass over vector)
```
-------------------------------------
        Statistics And Reports
-------------------------------------
General Statistics
 - Total Students    : 42
 - Active Students   : 38
 - Inactive Students : 4

Students According to cGPA
 - [3.5 - 4.0] Excellent   : 12
 - [3.0 - 3.49] Very GOOD  : 15
 - [2.5 - 2.99] GOOD       : 10
 - [< 2.5] Accepted        : 5

Students per Department
 - CS : 18
 - IT : 12
 - ME : 8
 - CE : 4

Students per Semester
 - Semester 1 : 5
 - Semester 2 : 7
 ```
---

## 💾 DATA PERSISTENCE MODEL

The system employs a multi-layered storage strategy to ensure data safety, portability, and ease of access.

| File Name | Format | Purpose |
| :--- | :--- | :--- |
| `Students.data` | **Binary** | **Primary storage** – Saves/loads the entire `vector<clsStudent>` atomically using `write()` and `read()`. |
| `StudentsData.txt` | **Text** | **Export/Import** with custom delimiters (`#` or `-`); fully readable by Excel. |
| `StudentsBackup.data` | **Binary** | **Manual backup** via `BackupData()` – copies `Students.data`. Restore via `RestoreData()`[cite: 1]. |

---
### Binary I/O Implementation:
```
// Save entire vector
file.write(reinterpret_cast<char*>(_vStudents.data()), _vStudents.size() * sizeof(clsStudent));

// Load entire vector
_vStudents.resize(count);
file.read(reinterpret_cast<char*>(_vStudents.data()), count * sizeof(clsStudent));
```

## 📌 Logical vs Physical Delete

* **Logical Delete:** Sets `_IsActive = false` – student remains in vector, appears in lists as "InActive".
* **Physical Delete:** Removes student completely from `_vStudents` vector.

> [!IMPORTANT]
> Both options call **`Save()`** after operation to persist changes to the binary file.

### 🎮 USAGE EXAMPLE
## Main Menu
```
====================================================================
================ STUDENTS RECORDS MANAGEMENT SYSTEM ================
====================================================================
[1] Add New Student Record
[2] Show All Students
[3] Search in Students Records
[4] Update Student Record
[5] Delete Student Record
[6] Statistics & Reports
[7] Arrange Records
[8] Export to TXT/CSV File
[9] Import from TXT/CSV File
[10] Backup & Restore
[11] Exit
---------------------------------------------------
Please Enter Your Choice
>> 1
```
##  Adding a Student
```
====================================================
================ ADD NEW Record ====================
====================================================
Please Enter First Name
>> Neo
Please Enter Last Name
>> Anderson
Please Enter Department (CS, IT, ME, CE)
>> CS
Please Enter Semester (1-8)
>> 3
Please Enter cGPA (0.0 - 4.0)
>> 3.75
Please Enter Date of Birth (DD/MM/YYYY)
>> 15/03/2000
Please Enter Phone Number (9 digits)
>> 771234567
Please Enter Email
>> neo@matrix.com
Is Student Active? (1=Yes / 0=No)
>> 1
[✔] Student Added Successfully. Roll Number: 1001
```

## Search Example
```
====================================================
=================== SEARCH MENU ====================
====================================================
[1] By Roll Number
[2] By Name
[3] By Department
[4] By cGPA
Enter your choice >> 2
Enter Name: Anderson

+----------+------------+-----------+-------------+----------+-------+------------+-------------+----------------+----------+
| Roll No. | First Name | Last Name | Department  | Semester | cGPA  | DOB        | Phone       | Email          | Status   |
+----------+------------+-----------+-------------+----------+-------+------------+-------------+----------------+----------+
| 1001     | Neo        | Anderson  | CS          | 3        | 3.75  | 15/03/2000 | 771234567   | neo@matrix.com | Active   |
+----------+------------+-----------+-------------+----------+-------+------------+-------------+----------------+----------+
```

## 👨‍💻 AUTHOR & CREDITS

* **Created by:** Falah Fathel
* **GitHub alias:** [FALCONZeroX](https://github.com/FALCONZeroX)
* **Year:** 2026
* **License:** **MIT** (free to use, modify, distribute)
* **Acknowledgments:** Pure STL implementation – no external dependencies.

## 🧪 TESTING & EDGE CASES

The system has been rigorously tested against various scenarios to ensure stability and data integrity:

* **✅ Empty database:** Handles empty states with graceful messages; no crashes occur when performing CRUD operations on an empty vector.
* **✅ Duplicate roll numbers:** Strictly prevented by the internal `_Get_Unique_Roll()` auto-increment logic.
* **✅ Invalid menu input:** Input validation loops indefinitely until a valid menu choice is entered.
* **✅ Binary file missing:** `LoadDataFromBinary()` returns an empty vector safely and creates a new file automatically on the first save.
* **✅ Corrupted binary file:** Designed with no undefined behavior; the system simply loads zero records if the file structure is unrecognizable.
* **✅ Logical delete:** Correctly toggles `IsActive = false`. The student remains searchable but is clearly flagged as "InActive" in all views.
* **✅ Import from CSV:** Specifically programmed to skip duplicate roll numbers and validate every single field before appending to the database.
* **✅ Export with different delimiters:** Supports custom delimiters like `#` or `-` to ensure seamless compatibility with Excel and other spreadsheet software.


## 🚀 FUTURE PLANS (Glitch-in-the-Matrix Edition)

* **Arabic language support:** Implementing UTF-8 encoding for full localized support.
* **Generic serialization:** Replacing manual `char[]` with `std::string` utilizing custom serialization techniques.
* **Multi-user login with roles:** Implementing access control for Admin, Teacher, and Student roles.
* **Course registration:** Linking student entities to specific course modules.
* **Direct Excel export:** Supporting `.xlsx` format via external libraries for better reporting.
* **Cloud backup:** Integrating Firebase or REST APIs for remote data persistence.
* **GUI version:** Transitioning from CLI to a graphical interface using Qt or FTXUI.
* **Dark/Neon theme toggle:** Adding aesthetic customization for the user interface.

### 📜 LICENSE
## This project is licensed under the MIT License – see the LICENSE file for details.
```
MIT License

Copyright (c) 2026 Falah Fathel

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions...
```
