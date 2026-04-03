# 📎 Lesson 04 – Linked List Study Guide
> **Data Structures & Algorithms · Lecturer: Seak Leng**  
> A complete catch-up guide for everything covered while you were absent.

---

## 📚 Table of Contents
1. [What is a Linked List?](#1-what-is-a-linked-list)
2. [Array vs Linked List](#2-array-vs-linked-list)
3. [Types of Linked Lists](#3-types-of-linked-lists)
4. [C++ Structure & Creating a List](#4-c-structure--creating-a-list)
5. [Insertion Operations](#5-insertion-operations)
6. [Display All Elements](#6-display-all-elements)
7. [Search](#7-search)
8. [Update](#8-update)
9. [Practice Problems](#9-practice-problems)

---

## 1. What is a Linked List?

A **linked list** is a linear data structure where elements (called **nodes**) are connected to each other using **pointers**. Unlike arrays, the nodes do NOT need to be stored next to each other in memory — they can be anywhere, linked together like a chain.

> 💡 Think of it like a **train**: each carriage (node) connects to the next. The engine is the *Head*, the last carriage is the *Tail*.

### Visual (Singly Linked List)

```
Head                              Tail
 ↓                                 ↓
[25 | next]──►[50 | next]──►[90 | next]──►[55 | NULL]
```

Each box is one **node**. The left part holds the **data**, the right part holds the **pointer** (address of the next node). The last node always points to `NULL`.

### Key Terms

| Term | Meaning |
|------|---------|
| **Node** | One element of the list — contains data + a next pointer |
| **Head** | Pointer to the **first** node. *Required* — lose this and you lose the whole list! |
| **Tail** | Pointer to the **last** node. Optional but very useful for fast end-insertion |
| **n** | Counter of how many nodes are in the list. Optional but useful |
| **NULL** | The last node's `next` always points to NULL — marks the end of the list |

---

## 2. Array vs Linked List

| Feature | Array | Linked List |
|---------|-------|-------------|
| Size | Fixed — must decide upfront | Dynamic — grows/shrinks freely |
| Memory | Contiguous (side by side) | Scattered anywhere in memory |
| Access | Random access: `arr[3]` is instant ✅ | Sequential only — must traverse from Head ❌ |
| Insert/Delete | Slow — must shift elements | Fast — just change pointers ✅ |
| Flexibility | Low | High ✅ |

> **When to use a linked list:** when you don't know how many items you'll have in advance, or when you need frequent insertions/deletions.  
> **When to use an array:** when you need fast access by index.

---

## 3. Types of Linked Lists

There are **two main types**:

### Singly Linked List
Each node has a pointer to the **next** node only. You can only move **forward**.

```
HEAD ──► [5 | →] ──► [7 | →] ──► [3 | →] ──► [4 | NULL]    ◄── TAIL
```

```cpp
struct Element {
    int data;
    Element *next;        // pointer to next node only
};
```

### Doubly Linked List
Each node has pointers to **both** next AND previous nodes. You can move **both ways**.

```
NULL ◄── [5 | ↔] ↔ [7 | ↔] ↔ [3 | ↔] ↔ [4 | ↔] ──► NULL
HEAD                                         TAIL
```

```cpp
struct Element {
    int data;
    Element *next;        // pointer to next node
    Element *previous;    // pointer to previous node
};
```

> **Successor** = the next element (forward direction)  
> **Predecessor** = the previous element (backward direction)

---

## 4. C++ Structure & Creating a List

You always need **two structs** — one for the node, one for the list itself.

```cpp
#include <iostream>
using namespace std;

// 1. Node structure — one element of the list
struct Element {
    int data;
    Element *next;
};

// 2. List structure — manages the whole list
struct List {
    int n;           // number of nodes
    Element *head;   // pointer to first node
    Element *tail;   // pointer to last node
};

// 3. Function to create an empty list
List* createList() {
    List *ls = new List();
    ls->n    = 0;
    ls->head = nullptr;   // empty list has no first node
    ls->tail = nullptr;   // empty list has no last node
    return ls;
}
```

> ⚠️ **Always** initialize `head` and `tail` to `nullptr`. If you leave them uninitialized, they point to random memory — your program will crash!

---

## 5. Insertion Operations

### 5a. Insert at the Beginning

The new node becomes the new **Head**.

**Steps:**
1. Create a new node `e` and store the data
2. Set `e→next = ls→head` (new node points to the old head)
3. Set `ls→head = e` (new node is now the head)
4. If the list was empty (`n == 0`), also set `ls→tail = e`
5. Increment `n`

```cpp
void add_beg(List* ls, int data) {
    Element* e = new Element();
    e->data = data;
    e->next = ls->head;      // step 2: point to old head

    ls->head = e;            // step 3: e is now the head

    if (ls->n == 0) {
        ls->tail = e;        // step 4: first node is also the tail
    }
    ls->n++;
}
```

> ⚠️ **Order matters!** Always do `e->next = ls->head` BEFORE `ls->head = e`. Reverse them and you lose the reference to the old head!

---

### 5b. Insert at the End

The new node becomes the new **Tail**.

**Steps:**
1. Create a new node `e` and store the data
2. Set `e→next = nullptr` (it's the last node, points to nothing)
3. If the list is **empty**: set `ls→head = e`
4. If the list is **not empty**: set `ls→tail→next = e` (old tail points to new node)
5. Set `ls→tail = e` and increment `n`

```cpp
void add_end(List* ls, int data) {
    Element* e = new Element();
    e->data = data;
    e->next = nullptr;

    if (ls->n == 0) {
        ls->head = e;            // first node: it's also the head
    } else {
        ls->tail->next = e;      // old tail now points to new node
    }

    ls->tail = e;                // e is the new tail
    ls->n++;
}
```

---

### 5c. Insert After a Position

Insert a new node **after** the node at index `pos` (0-based).

**Steps:**
1. Check if `pos` is valid (`0 ≤ pos < n`), else show error
2. Traverse to the node at position `pos`
3. Set `newNode→next = current→next`
4. Set `current→next = newNode`
5. If inserted at the end, update tail. Increment `n`.

```cpp
void add_after_pos(List* ls, int data, int pos) {
    if (pos < 0 || pos >= ls->n) {
        cout << "Cannot add at this position\n";
        return;
    }

    Element* current = ls->head;
    for (int i = 0; i < pos; i++)
        current = current->next;    // walk to position

    Element* e = new Element();
    e->data = data;
    e->next = current->next;        // step 3: point past current
    current->next = e;              // step 4: insert after current

    if (current == ls->tail) ls->tail = e;
    ls->n++;
}
```

---

### 5d. Insert Before a Position

Insert a new node **before** the node at index `pos`.

**Steps:**
1. If `pos < 0` or `pos > n`, show error
2. If `pos == 0`, it's the same as `add_beg()`
3. Otherwise, traverse to node at position `pos - 1` (one before the target)
4. Link the new node in between

```cpp
void add_before_pos(List* ls, int data, int pos) {
    if (pos < 0 || pos > ls->n) {
        cout << "Cannot add before this position\n";
        return;
    }

    Element* e = new Element();
    e->data = data;

    if (pos == 0) {              // inserting before the head
        e->next   = ls->head;
        ls->head  = e;
        if (ls->n == 0) ls->tail = e;
    } else {
        Element* current = ls->head;
        for (int i = 0; i < pos - 1; i++)
            current = current->next;

        e->next       = current->next;
        current->next = e;

        if (e->next == nullptr) ls->tail = e;
    }
    ls->n++;
}
```

---

## 6. Display All Elements

Traverse the entire list from head to tail, printing each node's data.

**Steps:**
1. Set a temporary pointer `tmp = ls→head`
2. While `tmp != NULL`: print `tmp→data`, then move `tmp = tmp→next`

```cpp
void displayList(List* ls) {
    Element* tmp = ls->head;
    while (tmp != nullptr) {
        cout << tmp->data << " ";
        tmp = tmp->next;      // move to the next node
    }
    cout << endl;
}
```

> 💡 This is called **sequential traversal** — you always start from Head and step through one by one. There is no way to jump to the middle directly (unlike arrays).

---

## 7. Search

Find the **position** (0-based index) of a value in the list. Returns `-1` if not found.

**Steps:**
1. Set `current = head`, `position = 0`
2. While `current != NULL`:
   - If `current→data == target`: return `position`
   - Move `current = current→next`, increment `position`
3. If the loop ends without finding: return `-1`

```cpp
int searchData(List* ls, int data) {
    Element* e  = ls->head;
    int position = 0;

    while (e != nullptr) {
        if (e->data == data) {
            cout << data << " is found at " << position;
            return position;
        }
        position++;
        e = e->next;
    }

    cout << data << " is not found";
    return -1;
}
```

---

## 8. Update

Replace the **first occurrence** of a value with a new value.

**Steps:**
1. Traverse the list from head
2. If `current→data == oldData`: set `current→data = newData`, mark as found
3. Move to next node
4. After the loop, report whether the update succeeded

```cpp
void updateData(List* ls, int oldData, int newData) {
    Element* e  = ls->head;
    int isFound = 0;

    while (e != nullptr) {
        if (e->data == oldData) {
            e->data  = newData;    // replace the value
            isFound  = 1;
        }
        e = e->next;
    }

    if (isFound)
        cout << "Data is updated\n";
    else
        cout << "No data is updated\n";
}
```

---

## 9. Practice Problems

These are the exercises from the lecture slides:

### Problem 1 — Integer Linked List
Create a singly linked list that stores integer numbers:
- a. Define `Element` and `List` structs, create an empty list
- b. Function to add an element to the **end**
- c. Function to add an element to the **beginning**
- d. Function to **display** all numbers
- e. Function to add an element **before position p**
- f. Function to add an element **after position p**

### Problem 2 — Student Records Linked List
Create a singly linked list storing student `id` and `name`:
- a. Define `Student`, `Element`, `List` structs, create an empty list
- b. Function to add student info to the **beginning**
- c. Function to add student info to the **end**
- d. **Display** all students
- e. **Search** by student ID, display name if found
- f. **Update** the name for a given student ID

```cpp
// Hint: struct for Problem 2
struct Student {
    int id;
    string name;
};

struct Element {
    Student data;
    Element *next;
};

struct List {
    int n;
    Element *head;
    Element *tail;
};
```

---

## 🔑 Quick Reference — All Operations

| Operation | Key Idea |
|-----------|----------|
| **Create** | Set `head = tail = nullptr`, `n = 0` |
| **Insert at beginning** | New node's next → old head, update head |
| **Insert at end** | Old tail's next → new node, update tail |
| **Insert after pos** | Traverse to pos, splice new node in |
| **Insert before pos** | Traverse to pos-1, splice new node in |
| **Display** | Loop: `tmp = head` → print → `tmp = tmp->next` |
| **Search** | Loop and compare, return index or -1 |
| **Update** | Loop and compare, replace data when found |

> ✅ **The golden rule:** In a linked list you always start from the **Head** and move forward one node at a time. You can never jump to a position directly.