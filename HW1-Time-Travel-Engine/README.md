# ⏳ Time Travel Engine: Stack-Based Timeline Simulation

This project is an Object-Oriented simulation of a "Time Travel" universe, built entirely from scratch in C++. It demonstrates advanced mastery of the **Stack** data structure, dynamic memory allocation, and complex state management across multiple timelines.

> ⚠️ **Technical Highlight:** The use of the C++ Standard Template Library (STL) was strictly prohibited. The core of this engine relies on a custom-built, dynamically resizing stack class (`StringStack`) with manual memory management and pointer operations.

---

## 🌌 Core Mechanics & Architecture

The simulation manages parallel universes (Branches) where a time traveler can move through different locations. The logic is strictly governed by Stack operations (LIFO - Last In, First Out).

### 1. The Custom `StringStack`
A fully dynamic array-based stack handling capacity expansion (`expand()`), deep copying, and memory cleanup to prevent leaks. 

### 2. Timeline State (`TimeBranch`)
Each parallel universe maintains its own state using three distinct stacks:
* **`pastStack`:** Records every location visited. Traveling to a new location pushes the current state here and irrevocably destroys the `futureStack` (creating a new timeline).
* **`futureStack`:** Stores locations when the traveler uses the `rewind` function, allowing them to `fastForward` back to where they were.
* **`stoneStack`:** A specialized stack for "Time Stones" which act as fixed checkpoints. Activating a stone dynamically calculates the steps needed to jump across the past or future stacks to reach the target anomaly.

### 3. The Multiverse Manager (`TimeTravelEngine`)
An overarching engine that manages an array of pointers to `TimeBranch` objects. It handles the creation, deletion, state-printing, and even the **merging** of two distinct timelines into a unified branch.

---

## 🛠️ Tech Stack & Concepts
* **Language:** C++
* **Data Structures:** Custom Dynamic Stacks, Arrays of Pointers.
* **OOP Principles:** Encapsulation, Destructor-based Memory Management (avoiding memory leaks), Modular Design.

---
*Disclaimer: This repository is intended to serve as a personal portfolio. Direct copying of these solutions for academic submissions is a violation of the Bilkent University Honor Code.*
