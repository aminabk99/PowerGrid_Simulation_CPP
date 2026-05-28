<div align="center">

# ⚡ Power Grid Simulation
### C++ Data Structures Applied to a Power Plant Network

A three-part C++ project that models a power grid using **OOP**, **singly linked lists**, and a **stack-based event log** — simulating real infrastructure concepts like capacity analysis and chronological fault tracking.

![C++](https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![OOP](https://img.shields.io/badge/Paradigm-OOP-6A0DAD?style=for-the-badge&logo=buffer&logoColor=white)
![Data Structures](https://img.shields.io/badge/Data_Structures-Linked_List_%26_Stack-FF6600?style=for-the-badge&logo=stackshare&logoColor=white)
![Memory](https://img.shields.io/badge/Memory-Dynamic_Allocation-004080?style=for-the-badge&logo=c&logoColor=white)

</div>

---

## How It Works

This repo contains three independent programs, each targeting a different C++ concept using a power grid as the domain:

**1. `powerplant.cpp` — OOP & Dynamic Memory**
- Defines a `PowerPlant` class with a name and capacity in MW
- Demonstrates default constructors, parameterized constructors, and dynamic allocation with `new` / `delete`
- Shows pointer reassignment to an existing stack object without memory leaks

**2. `powergrid_linked_list.cpp` — Singly Linked List**
- Builds a linked list of `PlantNode` structs, each holding a plant name and MW capacity
- Traverses the list to find the **maximum capacity plant**
- Implements `removeFirstPlant()` with proper memory cleanup and re-queries max after removal

**3. `powergrid_event_stack.cpp` — Stack via Linked List**
- Implements a **LIFO stack** of timestamped grid events (faults, maintenance, startups)
- Supports `pushLog()`, `peekLog()`, and `popLog()` — all backed by a custom linked list
- Demonstrates last-in-first-out event retrieval, mirroring how real SOC alert stacks work

---

## Setup

**Requirements:** Any C++17 compiler (g++, MSVC, clang++)

**Compile & run each file independently:**
```bash
g++ powerplant.cpp -o powerplant && ./powerplant
g++ powergrid_linked_list.cpp -o linked_list && ./linked_list
g++ powergrid_event_stack.cpp -o event_stack && ./event_stack
```

---

## Hardest Part
**Manual memory management in the linked list** — every `removeFirstPlant()` call requires saving the head pointer, advancing head, then deleting the saved pointer in the right order. Getting this wrong causes either a dangling pointer or a memory leak with no compile-time warning.

## Most Interesting
**Using a linked list to implement a stack** — rather than using `std::stack`, the event log stack is built from scratch using raw node pointers. It makes the LIFO behavior completely transparent and shows exactly what push and pop do at the memory level.

---

## Files

- `powerplant.cpp` — OOP: class design, constructors, dynamic memory
- `powergrid_linked_list.cpp` — linked list: traversal, max-finding, node deletion
- `powergrid_event_stack.cpp` — stack: push, peek, pop via custom linked list

---

<div align="center">
  <sub>Built by <a href="https://github.com/aminabk99">Amina Bilal</a> · <a href="https://linkedin.com/in/amina-bilal-926340382">LinkedIn</a></sub>
</div>
