
---

```markdown
# 🏦 Bank Management System — C Project

A simple and interactive console-based **Bank Management System** built using the C programming language. Create accounts, deposit/withdraw funds, and check balances — all managed through file storage.

---

## 📋 Features

- 🧾 Create a new bank account
- 💰 Deposit money to your account
- 🏧 Withdraw money from your account
- 📊 Check your account balance
- 💾 Persistent data storage using `account.dat`

---

## 🚀 Getting Started

### 🔧 Prerequisites

- GCC or any C compiler
- Command Line Terminal

### ⚙️ Compile & Run

```bash
gcc bank.c -o bank
./bank
```

---

## 🖥️ Sample Menu Interface

```
*** BANK MANAGEMENT SYSTEM ***
1. Create Account
2. Deposit Money
3. Withdraw Money
4. Check Balance
5. EXIT
```

---

## 📂 Project Structure

```
📁 Bank-Management-System/
│
├── bank.c         # Main source code
├── account.dat    # Binary file storing account data
└── README.md      # Project documentation
```

---

## 🧠 Concepts Used

- ✅ File handling in C (`fopen`, `fread`, `fwrite`, `fseek`)
- ✅ Use of `struct` to store customer data
- ✅ Terminal-based UI with interactive menus
- ✅ Modular functions for clean code organization

---

## 📈 Future Improvements

- 🔒 Add password protection for accounts
- 📃 Display transaction history
- 🌐 Migrate to GUI or web interface
- 🧪 Include unit tests for core functions

---

## 📜 License

This project is licensed under the **MIT License** — feel free to use and modify it.

---

## 🤝 Contributing

Pull requests and suggestions are welcome! Fork the repo and help enhance the system.

---

**Built with ❤️ in C for learning and practice**
