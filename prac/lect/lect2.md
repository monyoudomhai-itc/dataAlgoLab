## What is Recursion?
Recursion is when a function calls itself to solve a smaller version of the same problem, until it reaches a simple base case.
Think of it like Russian nesting dolls — each doll contains a smaller version of itself, until you reach the tiniest one.

## The 2 Key Parts of Every Recursive Function

**Base Case → the stopping condition (without this, it loops forever!)**

**Recursive Case → the function calls itself with a simpler input**


## Simple Example: Factorial (n!)
5! = 5 × 4 × 3 × 2 × 1 = 120
```cpp
#include <iostream>
using namespace std;

int factorial(int n) {
    // 1. Base case — stop here
    if (n == 0 || n == 1) {
        return 1;
    }
    // 2. Recursive case — call itself with a smaller number
    return n * factorial(n - 1);
}

int main() {
    cout << factorial(5); // Output: 120
}
```

## How it runs step by step:**
```cpp
factorial(5)
  → 5 * factorial(4)
       → 4 * factorial(3)
            → 3 * factorial(2)
                 → 2 * factorial(1)
                      → returns 1   ← BASE CASE hit!
                 → 2 * 1 = 2
            → 3 * 2 = 6
       → 4 * 6 = 24
  → 5 * 24 = 120

Another Example: Sum of 1 to N
cppint sum(int n) {
    if (n == 0) return 0;          // base case
    return n + sum(n - 1);         // recursive case
}

// sum(4) → 4 + sum(3) → 4 + 3 + sum(2) → ... → 10

why Use Recursion?
SituationExampleProblem naturally breaks into smaller versions of itselfFactorial, FibonacciWorking with trees or nested structuresFile folders, XMLDivide and conquer algorithmsMerge Sort, Binary Search

Common Beginner Mistake — Forgetting the Base Case
cppint factorial(int n) {
    return n * factorial(n - 1); // ❌ NEVER STOPS → Stack Overflow crash!
}
```

## Always ask yourself: **"What is the simplest case where I already know the answer?"** — that's your base case.


## The Simple Formula to Think About Recursion
```bash
function solve(problem):
    if problem is simplest case → return answer directly
    else → solve a SMALLER version of the same problem

```