# 🚗 Highway Charging Station Planner

**Final Project – Algorithms and Data Structures (2022–2023)**  
**Author**: Jonatan Sciaky

## 📌 Overview

This project simulates an electric vehicle rental system along a highway. Each **service station** is located at a unique distance from the highway’s start and hosts a **fleet of electric cars**, each defined by a maximum driving range (autonomy). The goal is to efficiently plan journeys with the fewest possible stops, while respecting directionality and vehicle autonomy constraints.

> ⛔ The main difficulty was satisfying **strict memory and execution time limits**, which required careful use of optimized data structures and minimal memory overhead.

---

## 🧠 Problem Description

- Stations are uniquely identified by their distance from the start of the highway.
- Each station has up to 512 electric vehicles, each with its own autonomy.
- A rented vehicle can only go **forward** and reach other stations within its range.
- The goal is to compute the **shortest route (fewest stops)** between two stations. In case of ties, the path with **stations closer to the start** is preferred (lexicographically smallest).

---

## 📦 Repository Contents

- `api.c`: Main implementation file containing the complete project code.
  - Binary Search Trees for managing stations and vehicle fleets.
  - Custom hash table for fast station lookups.
  - Efficient memory handling for all dynamic structures.
- `test/`: Contains sample input files and their expected outputs.
- `project_specification.pdf`: Official problem description provided by the course instructors.
- `README.md`: This file.

---

## ⚙️ Data Structures

- **Binary Search Tree (BST)**:
  - Used to store service stations ordered by distance.
  - Each station node contains a nested BST for its car fleet.
- **Hash Table**:
  - Allows constant-time access to stations by distance.
  - Prevents redundant tree traversal during command processing.
- **Memory Management**:
  - Carefully designed to avoid memory leaks and reduce allocations.
  - Each tree and node is recursively deallocated.

---

## 🚀 Supported Commands
aggiungi-stazione <distanza> <numero-auto> <autonomia-auto-1> ... <autonomia-auto-n>
demolisci-stazione <distanza>
aggiungi-auto <distanza-stazione> <autonomia-auto>
rottama-auto <distanza-stazione> <autonomia-auto>
pianifica-percorso <partenza> <arrivo>


## Example
```bash
aggiungi-stazione 10 3 100 200 300
aggiungi-auto 10 150
pianifica-percorso 10 50
---
output
aggiunta
aggiunta
10 30 50
```

## 📄 Notes

This project is written in **C** and optimized for:

- 🧠 **Low memory usage**
- ⚡ **High performance**
- 🔍 **Fast lookup and update times**

Data structures were carefully chosen and implemented to respect the **strict runtime and memory constraints** defined in the project specification.


