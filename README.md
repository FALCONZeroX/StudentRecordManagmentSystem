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
Student-Management-System/
├── main.cpp                # نقطة الانطلاق - تحميل البيانات الثنائية وتشغيل القائمة الرئيسية
├── clsStudent.h            # كائن الطالب (تغليف البيانات، Getters/Setters، وتنسيق السجلات)
├── clsStudentManager.h     # منطق العمل: إدارة الـ Vector، عمليات CRUD، البحث، والتعامل مع الملفات
├── clsStudentUI.h          # شاشات واجهة المستخدم (إضافة، عرض، بحث، تحديث، حذف، إحصائيات)
├── clsMainScreen.h         # المتحكم في القائمة الرئيسية وحلقة التنقل (Navigation Loop)
├── clsInputValidate.h      # التحقق من المدخلات (الأرقام، الأسماء، البريد، المعدل، التواريخ)
├── clsUI_Utility.h         # أدوات مساعدة (العناوين، الفواصل، الرسائل، التأكيد، الترقيم)
├── data/
│   └── Students.data       # قاعدة البيانات الثنائية (Binary Data) - تخزين متسلسل للبيانات
├── .gitignore              # ملف استثناء الملفات غير المرغوبة من التتبع (مثل ملفات VS)
└── README.md               # وثيقة شرح المشروع


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
