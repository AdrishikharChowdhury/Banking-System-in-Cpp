# 🏦 Banking System in C++ — Interactive Guide

A lightweight, console-based banking system implemented in C++ using simple OOP. Create accounts, deposit, withdraw, and view balances via a console menu — ideal for learning classes, file structure, and basic I/O.

## ✨ Highlights
- Create multiple accounts with auto-generated account numbers 🎰  
- Secure operations with a password check (4 attempts) 🔐  
- Deposit / Withdraw / View balance via an interactive menu 🧾  
- Small codebase — easy to read & extend 🛠️

## ▶️ Quick Start (build & run)
1. From the dev container (Ubuntu 24.04.2 LTS) open a terminal in the workspace root.
2. Build:
    ```sh
    g++ main.cpp Account.cpp -o bank_program
    ```
3. Run:
    ```sh
    ./bank_program
    ```
Tip: to open a webpage on the host from this dev container use:
```sh
"$BROWSER" <url>
```

## 🧭 Interactive flow overview
- On start the program asks how many accounts to create and prompts for name, password, and initial balance.  
- Main menu actions (as implemented in main.cpp):
  1. Deposit
  2. Withdraw
  3. Show Balance
  4. Display Account Info
  5. Display All Accounts
  6. Exit

Each action locates an account using Account::searchAccount and authenticates with Account::checkLogin before proceeding.

## 🧩 Key files
- Account.h — class declaration  
- Account.cpp — implementation (account creation, login check, credit/debit, display)  
- main.cpp — program entry / interactive menu

## 🔎 Behavior & Validation
- Account numbers: generated randomly (10 digits).  
- Password: user gets up to 4 attempts per secured operation.  
- Deposits: rejected if <= 0 or > 100000.  
- Withdrawals: rejected if <= 0 or greater than balance.

## 📝 Example interactive session
1. Start program → "Enter no. of accounts you want to create:" → `2`  
2. Create account: name `Alice`, password `alice123`, balance `5000`  
3. From menu choose `1` (Deposit) → enter Alice's account number → deposit amount → authenticate → balance updated  
4. Choose `3` (Show Balance) → enter account number → authenticate → view balance

## 📂 Repo file list
- main.cpp  
- Account.h  
- Account.cpp  
- README.md  
- LICENSE (if present)

## 🛠️ Ideas to extend
- Persist accounts to disk (file I/O) 💾  
- Add transaction history per account 🧾  
- Hide password input (no echo) for better UX 🔒  
- Add unit tests and CI integration ✅

## 🧪 Quick checks
- Rebuild after edits:
    ```sh
    g++ main.cpp Account.cpp -o bank_program && ./bank_program
    ```
- Run a single command to open this repo in the host browser (replace <url>):
    ```sh
    "$BROWSER" <url>
    ```

Enjoy exploring and extending the project — small, clear, and designed for rapid experimentation 🚀
