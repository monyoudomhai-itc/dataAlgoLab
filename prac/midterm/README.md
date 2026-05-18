# 📝 Data Structures & Algorithms — Exam Practice

> Based on your lab work covering: **Recursion · Pointers · Linked Lists**
> Each problem has an expected output to check your answer.

---

## 📦 TOPIC 1: Recursion

---

### ✏️ Problem 1.1 — Trace the Output

What does the following code print?

```cpp
#include <iostream>
using namespace std;

int sum(int n) {
    if (n == 0) return 0;
    return n + sum(n - 1);
}

int main() {
    cout << sum(4);
    return 0;
}
```

<details>
<summary>✅ Expected Output</summary>

```
10
```

**Trace:** `sum(4)` → `4 + sum(3)` → `4 + 3 + sum(2)` → `4 + 3 + 2 + sum(1)` → `4 + 3 + 2 + 1 + sum(0)` → `10`

</details>

---

### ✏️ Problem 1.2 — Trace the Output

What does the following code print?

```cpp
#include <iostream>
using namespace std;

int fun(int n, int &count) {
    count++;
    if (n <= 1)
        return n;
    else
        return fun(n - 1, count) + fun(n - 2, count);
}

int main() {
    int count = 0;
    fun(5, count);
    cout << count;
    return 0;
}
```

<details>
<summary>✅ Expected Output</summary>

```
15
```

**Explanation:** `fun(5, count)` computes Fibonacci recursively. The total number of function calls for `fun(5)` is 15 (including all recursive calls).

</details>

---

### ✏️ Problem 1.3 — Trace the Output

What does the following code print?

```cpp
#include <iostream>
using namespace std;

int power(int m, int n) {
    if (n == 0) return 1;
    return m * power(m, n - 1);
}

int main() {
    cout << power(3, 4);
    return 0;
}
```

<details>
<summary>✅ Expected Output</summary>

```
81
```

**Trace:** `3 * 3 * 3 * 3 * 1 = 81`

</details>

---

### ✏️ Problem 1.4 — Trace the Output

What does the following code print?

```cpp
#include <iostream>
using namespace std;

int sum(int n) {
    int m = n * n;
    if (n == 0) return 0;
    return m + sum(n - 1);
}

int main() {
    cout << sum(3);
    return 0;
}
```

<details>
<summary>✅ Expected Output</summary>

```
14
```

**Trace:** `9 + 4 + 1 + 0 = 14`  (`3²=9`, `2²=4`, `1²=1`)

</details>

---

### ✏️ Problem 1.5 — Trace the Output

What does the following code print?

```cpp
#include <iostream>
using namespace std;

int multi(int m, int n) {
    if (n == 0) return 0;
    return m + multi(m, n - 1);
}

int main() {
    cout << multi(4, 3);
    return 0;
}
```

<details>
<summary>✅ Expected Output</summary>

```
12
```

**Explanation:** This multiplies by repeated addition: `4 + 4 + 4 = 12`

</details>

---

### ✏️ Problem 1.6 — Trace the Output

What does the following code print?

```cpp
#include <iostream>
using namespace std;

int sum(int n) {
    if (n == 0) return 0;
    return (n % 10) + sum(n / 10);
}

int main() {
    cout << sum(123);
    return 0;
}
```

<details>
<summary>✅ Expected Output</summary>

```
6
```

**Trace:** `3 + sum(12)` → `3 + 2 + sum(1)` → `3 + 2 + 1 + 0 = 6`

</details>

---

### ✏️ Problem 1.7 — Trace the Output

What does this code print?

```cpp
#include <iostream>
using namespace std;

void star(int n) {
    if (n == 0) return;
    cout << "*";
    star(n - 1);
}

int main() {
    star(5);
    cout << endl;
    return 0;
}
```

<details>
<summary>✅ Expected Output</summary>

```
*****
```

</details>

---

### ✏️ Problem 1.8 — Trace the Output

What does this code print?

```cpp
#include <iostream>
using namespace std;

void disNum(int n) {
    if (n == 0) return;
    cout << n << " ";
    disNum(n - 1);
}

int main() {
    disNum(5);
    cout << endl;
    return 0;
}
```

<details>
<summary>✅ Expected Output</summary>

```
5 4 3 2 1
```

</details>

---

### ✏️ Problem 1.9 — Find the Bug

This function should sum only odd numbers from 1 to n. What is wrong?

```cpp
int sum(int n) {
    if (n == 0) return 0;
    return n + sum(n - 1);   // ← Bug here
}
```

<details>
<summary>✅ Answer</summary>

The function sums ALL numbers, not just odd ones. The fix:

```cpp
int sum(int n) {
    if (n == 0) return 0;
    if (n % 2 == 0)
        return sum(n - 1);       // skip even numbers
    else
        return n + sum(n - 1);   // add odd numbers
}
```

</details>

---

### ✏️ Problem 1.10 — Short Answer

What are the **two required parts** of every recursive function? What happens if you forget the base case?

<details>
<summary>✅ Answer</summary>

1. **Base Case** — the stopping condition (simplest input with a known answer)
2. **Recursive Case** — the function calls itself with a smaller/simpler input

If you forget the base case, the function calls itself forever → **Stack Overflow crash**.

</details>

---

## 📦 TOPIC 2: Pointers

---

### ✏️ Problem 2.1 — Trace the Output

What does the following code print?

```cpp
#include <iostream>
using namespace std;

int main() {
    int n1 = 7, n2 = 3, n3 = 15;
    int *p1 = &n1;
    int *p2 = &n2;
    int *p3 = &n3;

    *p3 = n1 + n2;
    cout << n3 << endl;
    return 0;
}
```

<details>
<summary>✅ Expected Output</summary>

```
10
```

**Explanation:** `*p3 = n1 + n2` → `n3 = 7 + 3 = 10`

</details>

---

### ✏️ Problem 2.2 — Trace the Output

```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int *p = &n;
    *p += 7;
    cout << n << endl;
    return 0;
}
```

<details>
<summary>✅ Expected Output</summary>

```
12
```

**Explanation:** `*p += 7` modifies `n` through the pointer: `5 + 7 = 12`

</details>

---

### ✏️ Problem 2.3 — Trace the Output

```cpp
#include <iostream>
using namespace std;

void exchange(float *a, float *b) {
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    float an = 8, bn = 9;
    float *a = &an;
    float *b = &bn;
    cout << "Before: a=" << an << " b=" << bn << endl;
    exchange(a, b);
    cout << "After:  a=" << an << " b=" << bn << endl;
    return 0;
}
```

<details>
<summary>✅ Expected Output</summary>

```
Before: a=8 b=9
After:  a=9 b=8
```

</details>

---

### ✏️ Problem 2.4 — Trace the Output

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;
    cout << *(p + 2) << endl;
    cout << *(p + 4) << endl;
    return 0;
}
```

<details>
<summary>✅ Expected Output</summary>

```
3
5
```

**Explanation:** `*(p+2)` is `arr[2] = 3`, `*(p+4)` is `arr[4] = 5`

</details>

---

### ✏️ Problem 2.5 — Trace the Output

```cpp
#include <iostream>
using namespace std;

struct Employee { string name; float rate; };

void promoteEmployee(Employee *e) {
    e->rate += 10;
}

int main() {
    Employee e = {"John", 15};
    cout << e.name << " " << e.rate << endl;
    promoteEmployee(&e);
    cout << e.name << " " << e.rate << endl;
    return 0;
}
```

<details>
<summary>✅ Expected Output</summary>

```
John 15
John 25
```

</details>

---

### ✏️ Problem 2.6 — Find the Bug

What is wrong with this code?

```cpp
int main() {
    int *p;
    *p = 10;      // ← Bug
    cout << *p;
    return 0;
}
```

<details>
<summary>✅ Answer</summary>

`p` is declared but never initialized — it points to a **random memory address**. Writing to it causes **undefined behavior** (likely a crash).

**Fix:**
```cpp
int n;
int *p = &n;
*p = 10;
cout << *p;  // prints 10
```

</details>

---

### ✏️ Problem 2.7 — Short Answer

Fill in the table:

| Method | Can modify original? | Example |
|--------|----------------------|---------|
| Pass by value | ❓ | `void f(int a)` |
| Pass by pointer | ❓ | `void f(int *a)` |
| Pass by reference | ❓ | `void f(int &a)` |

<details>
<summary>✅ Answer</summary>

| Method | Can modify original? | Example |
|--------|----------------------|---------|
| Pass by value | ❌ No | `void f(int a)` |
| Pass by pointer | ✅ Yes | `void f(int *a)` |
| Pass by reference | ✅ Yes | `void f(int &a)` |

</details>

---

### ✏️ Problem 2.8 — Short Answer

What is the difference between `&` and `*` when used with pointers?

<details>
<summary>✅ Answer</summary>

- `&` (address-of operator) — gets the **memory address** of a variable. Example: `&x` gives the address where `x` is stored.
- `*` (dereference operator) — gets or sets the **value** at the address stored in a pointer. Example: `*p` gives the value that `p` points to.

</details>

---

### ✏️ Problem 2.9 — Trace the Output

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int *p  = &x;
    int **pp = &p;

    *p = 20;
    cout << **pp << endl;
    return 0;
}
```

<details>
<summary>✅ Expected Output</summary>

```
20
```

**Explanation:** `*p = 20` changes `x` to 20. `**pp` dereferences twice: `pp → p → x = 20`

</details>

---

## 📦 TOPIC 3: Linked Lists

---

### ✏️ Problem 3.1 — Trace the Output

```cpp
#include <iostream>
using namespace std;

struct Element { int data; Element* next; };
struct List { int n; Element* head; Element* tail; };

void addEnd(List* ls, int data) {
    Element* e = new Element;
    e->data = data;
    e->next = nullptr;
    if (ls->n == 0) ls->head = e;
    else ls->tail->next = e;
    ls->tail = e;
    ls->n++;
}

void display(List* ls) {
    Element* temp = ls->head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    List* ls = new List;
    ls->n = 0; ls->head = nullptr; ls->tail = nullptr;
    addEnd(ls, 10);
    addEnd(ls, 20);
    addEnd(ls, 30);
    display(ls);
    return 0;
}
```

<details>
<summary>✅ Expected Output</summary>

```
10 20 30
```

</details>

---

### ✏️ Problem 3.2 — Trace the Output

```cpp
#include <iostream>
using namespace std;

struct Element { string data; Element* next; };
struct List { int n; Element* head; Element* tail; };

void addBegin(List* ls, string data) {
    Element* e = new Element;
    e->data = data;
    e->next = ls->head;
    if (ls->n == 0) ls->tail = e;
    ls->head = e;
    ls->n++;
}

void display(List* ls) {
    Element* e = ls->head;
    cout << "total element " << ls->n << " : ";
    while (e != nullptr) {
        cout << e->data << " ";
        e = e->next;
    }
    cout << endl;
}

int main() {
    List* ls = new List;
    ls->n = 0; ls->head = nullptr; ls->tail = nullptr;
    addBegin(ls, "Dom");
    addBegin(ls, "Alice");
    addBegin(ls, "Bob");
    display(ls);
    return 0;
}
```

<details>
<summary>✅ Expected Output</summary>

```
total element 3 : Bob Alice Dom
```

**Explanation:** Each `addBegin` inserts at the front, so the last inserted appears first.

</details>

---

### ✏️ Problem 3.3 — Trace the Output

```cpp
#include <iostream>
using namespace std;

struct Element { int data; Element* next; };
struct List { int n; Element* head; Element* tail; };

void add(List* ls, int data) {
    Element* e = new Element;
    e->data = data;
    e->next = nullptr;
    if (ls->n == 0) ls->head = e;
    else ls->tail->next = e;
    ls->tail = e;
    ls->n++;
}

int main() {
    List* ls = new List;
    ls->n = 0; ls->head = nullptr; ls->tail = nullptr;
    for (int i = 0; i < 5; i++) add(ls, i);
    cout << "Total: " << ls->n << endl;
    cout << "Head: " << ls->head->data << endl;
    cout << "Tail: " << ls->tail->data << endl;
    return 0;
}
```

<details>
<summary>✅ Expected Output</summary>

```
Total: 5
Head: 0
Tail: 4
```

</details>

---

### ✏️ Problem 3.4 — Find the Bug

What is wrong with this `addEnd` function?

```cpp
void addEnd(List* ls, int data) {
    Element* e = new Element;
    e->data = data;
    e->next = nullptr;
    ls->tail->next = e;    // ← Bug when list is empty
    ls->tail = e;
    ls->n++;
}
```

<details>
<summary>✅ Answer</summary>

When the list is **empty** (`n == 0`), `ls->tail` is `nullptr`. Calling `ls->tail->next` dereferences a null pointer → **crash**.

**Fix:**
```cpp
void addEnd(List* ls, int data) {
    Element* e = new Element;
    e->data = data;
    e->next = nullptr;
    if (ls->n == 0)
        ls->head = e;      // first node is also the head
    else
        ls->tail->next = e;
    ls->tail = e;
    ls->n++;
}
```

</details>

---

### ✏️ Problem 3.5 — Find the Bug

What is wrong with this `addBegin` function?

```cpp
void addBegin(List* ls, int data) {
    Element* e = new Element;
    e->data = data;
    ls->head = e;          // ← Bug: wrong order
    e->next = ls->head;
    ls->n++;
}
```

<details>
<summary>✅ Answer</summary>

The order is wrong. `ls->head = e` runs first, so when `e->next = ls->head` executes, `ls->head` is already `e` itself — the new node points to **itself** forever.

**Fix:** Always set `e->next` BEFORE updating `ls->head`:
```cpp
void addBegin(List* ls, int data) {
    Element* e = new Element;
    e->data = data;
    e->next = ls->head;    // point to old head FIRST
    if (ls->n == 0) ls->tail = e;
    ls->head = e;          // THEN update head
    ls->n++;
}
```

</details>

---

### ✏️ Problem 3.6 — Trace the Output

```cpp
#include <iostream>
using namespace std;

struct Element { int data; Element* next; };
struct List { int n; Element* head; Element* tail; };

void add(List* ls, int data) {
    Element* e = new Element;
    e->data = data;
    e->next = nullptr;
    if (ls->n == 0) ls->head = e;
    else ls->tail->next = e;
    ls->tail = e;
    ls->n++;
}

int searchData(List* ls, int data) {
    Element* e = ls->head;
    int position = 0;
    while (e != nullptr) {
        if (e->data == data) {
            cout << data << " found at position " << position << endl;
            return position;
        }
        position++;
        e = e->next;
    }
    cout << data << " not found" << endl;
    return -1;
}

int main() {
    List* ls = new List;
    ls->n = 0; ls->head = nullptr; ls->tail = nullptr;
    add(ls, 10); add(ls, 20); add(ls, 30); add(ls, 40);
    searchData(ls, 30);
    searchData(ls, 99);
    return 0;
}
```

<details>
<summary>✅ Expected Output</summary>

```
30 found at position 2
99 not found
```

</details>

---

### ✏️ Problem 3.7 — Short Answer: Fill in the Blanks

Complete the steps for **Insert at the End**:

1. Create a new node `e`, store the data.
2. Set `e->next = ___________`.
3. If the list is empty: set `ls->head = ___________`.
4. Otherwise: set `ls->tail->next = ___________`.
5. Set `ls->tail = ___________` and increment `n`.

<details>
<summary>✅ Answer</summary>

1. Create a new node `e`, store the data.
2. Set `e->next = nullptr`.
3. If the list is empty: set `ls->head = e`.
4. Otherwise: set `ls->tail->next = e`.
5. Set `ls->tail = e` and increment `n`.

</details>

---

### ✏️ Problem 3.8 — Short Answer: Fill in the Blanks

Complete the steps for **Insert at the Beginning**:

1. Create a new node `e`, store the data.
2. Set `e->next = ___________`.
3. Set `ls->head = ___________`.
4. If the list was empty: set `ls->tail = ___________`.
5. Increment `n`.

<details>
<summary>✅ Answer</summary>

1. Create a new node `e`, store the data.
2. Set `e->next = ls->head`.
3. Set `ls->head = e`.
4. If the list was empty: set `ls->tail = e`.
5. Increment `n`.

</details>

---

### ✏️ Problem 3.9 — Concept Question

What is the difference between a **singly linked list** and a **doubly linked list**? Draw a simple diagram for each.

<details>
<summary>✅ Answer</summary>

**Singly Linked List** — each node has one pointer (`next`) pointing forward only:
```
HEAD ──► [5 | →] ──► [7 | →] ──► [3 | NULL]  ◄── TAIL
```

**Doubly Linked List** — each node has two pointers (`next` and `previous`), you can go both ways:
```
NULL ◄── [5 | ↔] ↔ [7 | ↔] ↔ [3 | NULL]
HEAD                              TAIL
```

The struct for doubly adds a `previous` field:
```cpp
struct Element {
    int data;
    Element *next;
    Element *previous;
};
```

</details>

---

### ✏️ Problem 3.10 — Concept Question

Compare **Array** vs **Linked List**. When should you use each?

<details>
<summary>✅ Answer</summary>

| Feature | Array | Linked List |
|---------|-------|-------------|
| Size | Fixed at creation | Grows/shrinks dynamically |
| Memory | Contiguous (side by side) | Scattered, linked by pointers |
| Access by index | Fast O(1): `arr[3]` | Slow O(n): must traverse from head |
| Insert/Delete | Slow — must shift elements | Fast — just change pointers |

**Use Array when:** you need fast random access by index and know the size in advance.

**Use Linked List when:** you need frequent insertions/deletions or don't know the size in advance.

</details>

---

### ✏️ Problem 3.11 — Write the Code

Write a function `countNodes(List* ls)` that returns the total number of nodes in a linked list **without using `ls->n`** (traverse manually).

```cpp
// Given these structs:
struct Element { int data; Element* next; };
struct List { int n; Element* head; Element* tail; };

int countNodes(List* ls) {
    // YOUR CODE HERE
}
```

<details>
<summary>✅ Answer</summary>

```cpp
int countNodes(List* ls) {
    int count = 0;
    Element* temp = ls->head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}
```

</details>

---

### ✏️ Problem 3.12 — Write the Code

Write a function `updateData(List* ls, int oldData, int newData)` that finds the first node with value `oldData` and replaces it with `newData`. Print `"Data updated"` if found, or `"Not found"` otherwise.

<details>
<summary>✅ Answer</summary>

```cpp
void updateData(List* ls, int oldData, int newData) {
    Element* e = ls->head;
    while (e != nullptr) {
        if (e->data == oldData) {
            e->data = newData;
            cout << "Data updated" << endl;
            return;
        }
        e = e->next;
    }
    cout << "Not found" << endl;
}
```

</details>

---

### ✏️ Problem 3.13 — Trace the Output (Product Linked List)

What does the following code print?

```cpp
#include <iostream>
using namespace std;

struct Product { int id; string name; int price; };
struct Element { Product data; Element* next; };
struct List { int n; Element* head; Element* tail; };

void addToBegin(List* ls, Product data) {
    Element* e = new Element;
    e->data = data;
    e->next = ls->head;
    if (ls->n == 0) ls->tail = e;
    ls->head = e;
    ls->n++;
}

void addToEnd(List* ls, Product data) {
    Element* e = new Element;
    e->data = data;
    e->next = nullptr;
    if (ls->n == 0) ls->head = e;
    else ls->tail->next = e;
    ls->tail = e;
    ls->n++;
}

int main() {
    List* ls = new List;
    ls->n = 0; ls->head = nullptr; ls->tail = nullptr;

    Product p1 = {1, "Apple", 30};
    Product p2 = {2, "Banana", 70};
    Product p3 = {3, "Cherry", 45};

    // price < 50 → addToBegin, else addToEnd
    if (p1.price < 50) addToBegin(ls, p1); else addToEnd(ls, p1);
    if (p2.price < 50) addToBegin(ls, p2); else addToEnd(ls, p2);
    if (p3.price < 50) addToBegin(ls, p3); else addToEnd(ls, p3);

    cout << "Head: " << ls->head->data.name << endl;
    cout << "Tail: " << ls->tail->data.name << endl;
    cout << "Total: " << ls->n << endl;
    return 0;
}
```

<details>
<summary>✅ Expected Output</summary>

```
Head: Cherry
Tail: Banana
Total: 3
```

**Explanation:**
- p1 (price=30 < 50) → `addToBegin` → list: `[Apple]`
- p2 (price=70 ≥ 50) → `addToEnd`  → list: `[Apple, Banana]`
- p3 (price=45 < 50) → `addToBegin` → list: `[Cherry, Apple, Banana]`

So Head = Cherry, Tail = Banana.

</details>

---

## 🚀 BONUS — Mixed Challenge

### ✏️ Problem B.1 — Recursive + Pointer

What does the following code print?

```cpp
#include <iostream>
using namespace std;

int sum(int *nump, int n) {
    if (n == -1) return 0;
    return *(nump + n) + sum(nump, n - 1);
}

int main() {
    int num[] = {2, 4, 6, 8, 10};
    cout << sum(num, 4) << endl;
    return 0;
}
```

<details>
<summary>✅ Expected Output</summary>

```
30
```

**Trace:** `10 + 8 + 6 + 4 + 2 = 30`

</details>

---

### ✏️ Problem B.2 — Quick Concept Quiz

Answer True or False:

1. In a linked list, `ls->head` must always be set to `nullptr` when the list is empty.
2. `*(p + 3)` is the same as `p[3]`.
3. A recursive function without a base case causes an infinite loop that eventually crashes.
4. When inserting at the beginning, you must do `e->next = ls->head` BEFORE `ls->head = e`.
5. Pass by value lets a function modify the original variable.

<details>
<summary>✅ Answers</summary>

1. ✅ **True** — uninitialized head is a common source of crashes.
2. ✅ **True** — pointer arithmetic and array indexing are equivalent.
3. ✅ **True** — the call stack fills up → Stack Overflow.
4. ✅ **True** — reversing the order causes a self-referencing node.
5. ❌ **False** — pass by value works on a copy; use pointer or reference to modify the original.

</details>

---

*Good luck on your exam! 🚀 Draw diagrams on paper when tracing linked lists — it helps a lot.*[text](<../../../../../../../../../home/monyoudom/Downloads/TP02-Recursion (1).pdf>)