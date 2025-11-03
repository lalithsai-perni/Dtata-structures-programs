# Data Structures Programs in C

This repository contains implementations of fundamental **Data Structures** in the C programming language.  
Each program focuses on clarity, modularity, and understanding of the core operations such as insertion, deletion, traversal, searching, and memory management.

---

## 📘 About This Repository

This project is designed to help students and beginners understand how different data structures work **internally** by building them from scratch using C.  
Every program is implemented using **Abstract Data Type (ADT)** principles for better structure and reusability.

---

## 🧩 Currently Implemented

### 🔹 Singly Linked List (ADT-based)
**File:** `singlelinkedlist.c`

**🧠 Concept Overview:**  
A **Singly Linked List** is a linear data structure where each node contains data and a pointer to the next node.  
It allows efficient insertion and deletion without requiring contiguous memory like arrays.  
Linked lists are especially useful when frequent insertion and deletion operations are needed.

**Features:**
- Create a linked list dynamically  
- Insert a node:
  - Before a given value  
  - After a given value  
  - At a specific position  
- Delete a node:
  - By value  
  - At a specific position  
- Search for a value  
- Reverse the list  
- Display all elements  
- Free all allocated memory safely before exit  

---

### 🔹 Breadth-First Search (Graph Traversal)
**File:** `BFS(2DARRAYS).c`

**🧠 Concept Overview:**  
**Breadth-First Search (BFS)** is a graph traversal algorithm that explores all neighboring vertices at the current depth before moving on to the next level.  
It uses a **queue** to ensure nodes are processed in the order they are discovered, making it ideal for finding the **shortest path** in an unweighted graph.

**Features:**
- Create and represent graphs using an **adjacency matrix**  
- Supports both **directed** and **undirected** graphs  
- Accepts custom input for **vertices** and **edges**  
- Displays the **Adjacency Matrix** clearly  
- Performs **Breadth-First Search (BFS)** traversal  
- Implements **queue-based level-order exploration**  
- Includes **error handling** for invalid vertices or inputs 

## 🚀 Upcoming Implementations

Planned additions to this repository include:
- Doubly Linked List  
- Circular Linked List  
- Stack (Array & Linked List implementation)  
- Queue (Array & Linked List implementation)  
- Trees (Binary Tree, BST)  
- Graphs (Adjacency List)  
- Sorting & Searching Algorithms  

---

## 🛠️ How to Run

1. Clone this repository:
   ```bash
   git clone https://github.com/lalithsai-perni/Dtata-structures-programs
