# Lesson 03 — Pointer

**Data Structure and Algorithms** | Lecturer: Seak Leng

**prepared by** | HAI Monyoudom
---

## What is a Pointer?

A **pointer** is a variable that holds the **memory address** of another variable of the same type. Rather than storing data itself, it points to the location in RAM where data lives.

- Every variable is stored at a unique memory address (e.g., `0x61fe14`)
- A pointer stores that address — not the value itself
- Through a pointer, you can **read** or **modify** the original data directly in memory

---

## Pointer Operators

| Operator | Name | Purpose | Example |
|----------|------|---------|---------|
| `&` | Address / Reference | Gets the memory address of a variable | `&x` → address of x |
| `*` | Dereference / Indirection | Gets or sets the value at an address | `*p` → value at address stored in p |

---

## Declaration & Initialization

```cpp
// Declaration
type *pointerName;

// Initialization
type *pointerName = &variable;

// Example
int a = 5;
int *p = nullptr;   // declare, no target yet
p = &a;             // p now holds the address of a
cout << *p;         // prints 5
*p = 100;           // changes a to 100 through pointer
```

---

## Dereferencing a Pointer

Accessing the value at the address a pointer refers to is called **dereferencing**, done with the `*` operator.

```cpp
int x = 10;
int *p = &x;
int y = *p;        // y = 10
*p = *p + 10;      // x is now 20
cout << x;         // prints 20
```

---

## Passing Arguments to Functions

| Method | Syntax | Modifies original? | Memory copy? |
|--------|--------|--------------------|--------------|
| Pass by value | `void f(int a)` | No | Yes (full copy) |
| Pass by pointer | `void f(int *a)` | Yes | No (address only) |
| Pass by reference | `void f(int &a)` | Yes | No (alias) |
| Const reference | `void f(const int &a)` | No (read-only) | No |

```cpp
void addValue(int a)   { a += 10; }        // original unchanged
void addValue2(int *a) { *a += 20; }       // modifies original
void addValue3(int &a) { a += 5; }         // modifies original

int a = 10;
addValue(a);            // a = 10 (no change)
addValue2(&a);          // a = 30
addValue3(a);           // a = 35
```

---

## Pointer and Array

The **array name** is a pointer to its first element (`&array[0]`). Pointer arithmetic lets you walk through elements.

- `p + i` → points to the i-th element ahead
- `p - i` → points to the i-th element behind
- `*(p+i)` is equivalent to `arr[i]`

```cpp
int arr[5] = {1, 2, 3, 4, 5};
int *p = arr;            // same as &arr[0]
cout << *(p+2);          // prints 3
p++;                     // now points to arr[1]

// Traverse using pointer arithmetic (no [ ])
for (int i = 0; i < 5; i++) {
    cout << p << ": " << *p << endl;
    p++;
}
```

---

## Pointer to Pointer (`**`)

A double pointer stores the address of another pointer. Useful for dynamic 2D arrays and multi-level indirection.

```cpp
int x = 10;
int *p  = &x;     // p  holds address of x
int **pp = &p;    // pp holds address of p

cout << *p;       // prints 10
cout << **pp;     // prints 10
```

---

## Pointer to Structure

Three ways to access struct members through a pointer:

- `(*ptr).member` — dereference then dot
- `ptr->member` — **arrow operator (preferred)**
- `ptr[0].member` — array index syntax

```cpp
struct Person { int id; string name; };

Person p1 = {1, "Alice"};
Person *ptr = &p1;

cout << ptr->name;      // prints Alice   (arrow operator)
cout << (*ptr).id;      // prints 1       (dereference + dot)
ptr->name = "Bob";      // modifies original
```

### Passing a struct pointer to a function

```cpp
struct Employee { string name; float rate; };

void printEmployee(const Employee *e) {
    cout << e->name << " " << e->rate << endl;
}

void promoteEmployee(Employee *e) {
    e->rate += 10;
}

Employee e = {"John", 15};
printEmployee(&e);   // John 15
promoteEmployee(&e);
printEmployee(&e);   // John 25
```

---

## ⭐ Key Points to Remember

1. **A pointer stores a memory ADDRESS, not a value.**
2. Always **initialize** a pointer before using it — use `nullptr` if no target yet.
3. Use `&` to get an address; use `*` to dereference (get/set the value at that address).
4. Pass by pointer or reference when you need a function to **modify the original variable**.
5. **Array name == pointer to first element**; use `*(p+i)` same as `arr[i]`.
6. **Double pointer (`**`)** is a pointer to another pointer — useful for 2D arrays.
7. Use the **arrow operator (`->`)** to access struct members through a pointer.
8. Use `const T &` for large read-only function parameters — no copy, no modification risk.
9. **Uninitialized or dangling pointers** cause undefined behavior — always manage memory carefully.
10. Call `delete` after `new` to avoid **memory leaks**.

---

*Data Structure and Algorithms — Lesson 03: Pointer | Lecturer: Seak Leng*