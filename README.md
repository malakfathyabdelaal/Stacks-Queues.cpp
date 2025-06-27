# Stacks-Queues.cpp
Two C++ programs demonstrating Stacks and Queues  with rich operations.
# 🖨️ Printer Queue & 🌐 Browser Navigation Simulator

This repository contains two C++ projects simulating:
1. A **printer queue** system.
2. A **browser navigation** system with forward/backward functionality.

---

## 📁 Files

- **`task1.cpp`** — Simulates a prioritized printer queue using a sorted linked list.
- **`task2.cpp`** — Simulates browser navigation using two stacks (backward & forward navigation).
- **`Printer.txt`** — Input file containing job data (not included here).
- **`urls.txt`** — Input file with a list of URLs and commands (not included here).

---

## 🖨️ Printer Queue (`task1.cpp`)

### 📋 Features:
- Maintains a sorted job queue based on arrival time.
- Each job includes:
  - Computer name
  - Arrival time (HH:MM)
  - Print duration (in minutes)
- Outputs:
  - Execution time of each job
  - Waiting time per job
  - Total printer occupation time
  - Average waiting time

### 📥 Sample Input (`Printer.txt`)
3
PC1 08:10 5
PC2 08:05 3
PC3 08:10 4


---

## 🌐 Browser Navigation (`task2.cpp`)

### 📋 Features:
- Simulates a browser history using two stacks:
  - Main stack: current and previous URLs
  - Backup stack: forward navigation
- Handles commands:
  - `"Backward"` — go back in history
  - `"Forward"` — go forward if possible
- Displays the current, next, and previous page on each command

### 📥 Sample Input (`urls.txt`)
4
http://example.com
http://example.org
http://site.com
http://another.net
Backward
Forward

---

## 🛠️ How to Compile and Run

Ensure `Printer.txt` and `urls.txt` are in the same directory as the `.cpp` files.

### Compile:
```bash
g++ task1.cpp -o printerQueue
g++ task2.cpp -o browserSimulator
