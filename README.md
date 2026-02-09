# Bank Management System (Console-based, C++)

High-performance Console-based Bank Management System built with C++.  
This project demonstrates OOP principles, secure banking operations, currency exchange, and user activity tracking.

---

## 🚀 Main Features

### 🔐 Authentication & Access
- Secure login system with credential verification.
- Dynamic permissions (Admin/User).
- Colored status indicators based on user permissions.

### 👥 Client & User Management
- Full CRUD operations for clients with encrypted storage.
- User management with security levels.
- Permission display screen for each user.

### 💰 Banking & Transactions
- Deposit, Withdraw, Total Balance.
- Secure transfers with validation.
- Transfer logs for auditing.

### 🌍 Currency Exchange System
- Live currency rates relative to USD.
- Search by code/country.
- Instant currency conversions.

### 🛡️ Security & Logs
- Tracks every user action (Login, Edit, View).
- Clean admin logs viewer.
- Re-encryption for security.

### 🎨 User Interface (UI)
- Full color-coded terminal support.
- Modular menus with formatted tables.
- Password encryption for all users.

---

## 📂 Project Structure

| Layer | Responsibility | Key Files |
|-------|----------------|-----------|
| Core  | Business Logic & Models | clsPerson.h, clsBankClient.h, clsUser.h, clsCurrency.h |
| Libs  | Logic Utilities & Security | clsInputValidation.h, clsUtility.h |
| Screens | UI: Management & Logic | clsLoginScreen.h, clsMainScreen.h, clsScreen.h |
| Screens/Bank | Client UI Operations | clsAddNewClientScreen.h, clsClientListScreen.h |
| Screens/Curr | Currency UI Operations | clsCurrencyExhangeScreen.h, clsCalculationScreen.h |
| Screens/Trans | Financial UI Operations | clsDepositScreen.h, clsTransfareScreen.h |
| Screens/Logs | Auditing UI Operations | clsSystemLogsScreen.h, clsTransferLogsScreen.h |
| Data | User/Client/Transaction/Currency files | Users.txt, clients.txt, LogFile.txt, TransferLogs.txt, Currencies.txt |

---

## 🛠 Tools & Technologies
- Language: C++
- Paradigm: Object-Oriented Programming (OOP)
- Key Concepts: Encapsulation, Inheritance, Polymorphism, Abstraction, File Handling

---

## ⚡ How to Run
1. Clone the repository:

```bash
git clone https://github.com/YourUsername/BankOOP.git
