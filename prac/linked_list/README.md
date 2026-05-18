# 🧠 Linked List Practice in C++ (With Hints + Expected Output)

This guide gives you structured exercises from beginner to advanced, with helpful hints and expected outputs so you can verify your work.

---

# 🔰 Level 1: Basics

## 1. Create and Display

**Task:**

* Create a linked list
* Insert 5 values
* Display the list

**Expected Output:**

```
10 -> 20 -> 30 -> 40 -> 50 -> NULL
```

**Hint:**

* Use a `Node` struct with `data` and `next`
* Traverse using:

```
while(temp != nullptr)
```

---

## 2. Insert at Beginning

**Task:** Insert values at the front

**Expected Output:**

```
Input: 10 20 30
Output: 30 -> 20 -> 10 -> NULL
```

**Hint:**

```
newNode->next = head;
head = newNode;
```

---

## 3. Insert at End

**Task:** Insert values at the end

**Expected Output:**

```
10 -> 20 -> 30 -> NULL
```

**Hint:**

```
while(temp->next != nullptr)
```

---

## 4. Count Nodes

**Task:** Count total nodes

**Expected Output:**

```
Total nodes = 5
```

**Hint:**

* Use a counter variable

---

# ⚙️ Level 2: Intermediate

## 5. Search Element

**Task:** Find a value in list

**Expected Output:**

```
Found at position 3
```

or

```
Not found
```

**Hint:**

```
if(temp->data == value)
```

---

## 6. Delete from Beginning

**Task:** Remove first node

**Expected Output:**

```
Before: 10 -> 20 -> 30
After: 20 -> 30 -> NULL
```

**Hint:**

```
Node* temp = head;
head = head->next;
delete temp;
```

---

## 7. Delete from End

**Task:** Remove last node

**Expected Output:**

```
Before: 10 -> 20 -> 30
After: 10 -> 20 -> NULL
```

**Hint:**

```
while(temp->next->next != nullptr)
```

---

## 8. Delete Specific Value

**Task:** Delete a node with given value

**Expected Output:**

```
Before: 10 -> 20 -> 30
Delete: 20
After: 10 -> 30 -> NULL
```

**Hint:**

* Track previous node

---

## 9. Insert at Position

**Task:** Insert at specific index

**Expected Output:**

```
Before: 10 -> 30 -> 40
Insert 20 at position 2
After: 10 -> 20 -> 30 -> 40
```

**Hint:**

```
newNode->next = temp->next;
temp->next = newNode;
```

---

# 🔥 Level 3: Important

## 10. Reverse Linked List

**Task:** Reverse the list

**Expected Output:**

```
Before: 10 -> 20 -> 30
After: 30 -> 20 -> 10 -> NULL
```

**Hint:**

* Use 3 pointers: prev, current, next

---

## 11. Find Middle Node

**Task:** Get middle element

**Expected Output:**

```
10 -> 20 -> 30 -> 40 -> 50
Middle = 30
```

**Hint:**

* Slow & fast pointers

---

## 12. Remove Duplicates

**Task:** Remove repeated values

**Expected Output:**

```
Before: 10 -> 20 -> 20 -> 30
After: 10 -> 20 -> 30 -> NULL
```

**Hint:**

```
if(current->data == current->next->data)
```

---

# 🚀 Level 4: Advanced

## 13. Detect Loop

**Task:** Check if list has cycle

**Expected Output:**

```
Loop detected
```

or

```
No loop
```

**Hint:**

* Slow & fast pointer meet

---

## 14. Merge Two Lists

**Task:** Merge two sorted lists

**Expected Output:**

```
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
```

**Hint:**

```
if(l1->data < l2->data)
```

---

## 15. Nth Node from End

**Task:** Find nth node from end

**Expected Output:**

```
List: 10 -> 20 -> 30 -> 40
n = 2
Answer = 30
```

**Hint:**

* Two pointer technique

---

# 💪 Final Challenge

## 16. Menu Program

**Task:** Build interactive program

**Expected Output Example:**

```
1. Insert Front
2. Insert End
3. Delete
4. Search
5. Display
6. Reverse
0. Exit
```

---

# 💡 Tips

* Always draw the linked list on paper
* Trace pointer movement
* Compare your output with expected output above

---

Good luck 🚀
