# Data Structures and Algorithms in C

Collection of Data Structures and Algorithms (DSA) programs in C, prepared for MCA Cybersecurity reference and practice. Each implementation includes comprehensive examples, explanations, and interactive demonstrations.

## 📋 Table of Contents

- [Overview](#overview)
- [Data Structures](#data-structures)
- [Algorithms](#algorithms)
- [Compilation Instructions](#compilation-instructions)
- [Usage Examples](#usage-examples)
- [Features](#features)
- [Contributing](#contributing)

## 🎯 Overview

This repository contains well-commented, ready-to-compile C programs implementing fundamental data structures and algorithms. Each program is designed to be educational, demonstrating both the theoretical concepts and practical implementations.

## 📊 Data Structures

### 1. Arrays (`arrays.c`)
- **Operations**: Insert, Delete, Search, Traverse
- **Search Algorithms**: Linear Search, Binary Search
- **Utility Functions**: Find min/max, reverse array, sort
- **Time Complexity**: O(1) access, O(n) search, O(n) insertion/deletion

### 2. Linked Lists (`linked_lists.c`)
- **Types**: Singly Linked List
- **Operations**: Insert (beginning/end/position), Delete, Search
- **Advanced Features**: Reverse, find middle, cycle detection
- **Time Complexity**: O(1) insertion at head, O(n) search

### 3. Stacks (`stack.c`)
- **Implementations**: Array-based and Linked List-based
- **Operations**: Push, Pop, Peek, Display
- **Applications**: 
  - Balanced parentheses checking
  - Postfix expression evaluation
  - Decimal to binary conversion
- **Time Complexity**: O(1) for all operations

### 4. Queues (`queue.c`)
- **Types**: Linear Queue, Circular Queue, Priority Queue, Linked Queue
- **Operations**: Enqueue, Dequeue, Front, Rear
- **Applications**: BFS simulation
- **Time Complexity**: O(1) for all basic operations

### 5. Trees (`trees.c`)
- **Types**: Binary Tree, Binary Search Tree (BST)
- **Traversals**: Inorder, Preorder, Postorder, Level-order
- **Operations**: Insert, Delete, Search, Find min/max
- **Properties**: Height calculation, node counting, diameter
- **Time Complexity**: O(log n) average for BST operations

### 6. Graphs (`graphs.c`)
- **Representations**: Adjacency Matrix, Adjacency List
- **Traversals**: Depth-First Search (DFS), Breadth-First Search (BFS)
- **Algorithms**: 
  - Dijkstra's shortest path
  - Prim's minimum spanning tree
- **Properties**: Connectivity check, edge counting, vertex degree

## 🔍 Algorithms

### 7. Searching Algorithms (`searching.c`)
- **Linear Search**: O(n) - Sequential search
- **Binary Search**: O(log n) - Divide and conquer
- **Interpolation Search**: O(log log n) - For uniformly distributed data
- **Jump Search**: O(√n) - Block-based search
- **Exponential Search**: O(log n) - Growing bound search
- **Fibonacci Search**: O(log n) - Using Fibonacci numbers
- **Ternary Search**: O(log₃ n) - Three-way divide
- **Hash Table Search**: O(1) average case

### 8. Sorting Algorithms (`sorting.c`)
- **Simple Sorts**: Bubble Sort, Selection Sort, Insertion Sort - O(n²)
- **Efficient Sorts**: Merge Sort, Quick Sort, Heap Sort - O(n log n)
- **Specialized Sorts**: 
  - Counting Sort - O(n + k)
  - Radix Sort - O(d × n)
  - Bucket Sort - O(n + k)
- **Hybrid Sorts**: Shell Sort, Cocktail Sort
- **Performance Comparison**: Built-in timing analysis

### 9. Dynamic Programming (`dynamic_programming.c`)
- **Classic Problems**:
  - Fibonacci sequence (multiple approaches)
  - Longest Common Subsequence (LCS)
  - 0/1 Knapsack Problem
  - Coin Change Problem
  - Longest Increasing Subsequence
  - Edit Distance (Levenshtein)
  - Matrix Chain Multiplication
  - Maximum Sum Subarray (Kadane's Algorithm)

## 🛠️ Compilation Instructions

### Individual Programs
```bash
# Arrays
gcc -o arrays arrays.c

# Linked Lists
gcc -o linked_lists linked_lists.c

# Stacks
gcc -o stack stack.c

# Queues
gcc -o queue queue.c

# Trees
gcc -o trees trees.c

# Graphs
gcc -o graphs graphs.c

# Searching (requires math library)
gcc -o searching searching.c -lm

# Sorting
gcc -o sorting sorting.c

# Dynamic Programming
gcc -o dynamic_programming dynamic_programming.c
```

### All Programs at Once
```bash
# Compile all programs
gcc -o arrays arrays.c && \
gcc -o linked_lists linked_lists.c && \
gcc -o stack stack.c && \
gcc -o queue queue.c && \
gcc -o trees trees.c && \
gcc -o graphs graphs.c && \
gcc -o searching searching.c -lm && \
gcc -o sorting sorting.c && \
gcc -o dynamic_programming dynamic_programming.c
```

## 💡 Usage Examples

### Running a Program
```bash
# Run arrays program
./arrays

# Run with specific compiler flags for debugging
gcc -g -Wall -o arrays arrays.c
./arrays
```

### Sample Interaction
```
=== Array Operations Demo ===

Initial array:
Array elements: 10 25 3 40 15 8 30 

--- Array Operations Menu ---
1. Display Array
2. Insert Element
3. Delete Element
4. Linear Search
5. Binary Search (sorts array first)
...
Enter your choice: 4
Enter element to search: 15
Element 15 found at index 4
```

## ✨ Features

- **Interactive Menus**: Each program provides user-friendly menu-driven interfaces
- **Comprehensive Examples**: Pre-loaded sample data for immediate testing
- **Error Handling**: Robust input validation and error messages
- **Educational Comments**: Detailed explanations of algorithms and time complexities
- **Performance Analysis**: Built-in timing for algorithm comparison
- **Memory Management**: Proper allocation and deallocation in dynamic structures
- **Multiple Implementations**: Different approaches for the same problems (e.g., array vs linked implementations)

## 📈 Time & Space Complexities

| Data Structure | Access | Search | Insertion | Deletion | Space |
|----------------|--------|--------|-----------|----------|-------|
| Array          | O(1)   | O(n)   | O(n)      | O(n)     | O(n)  |
| Linked List    | O(n)   | O(n)   | O(1)      | O(1)     | O(n)  |
| Stack          | O(n)   | O(n)   | O(1)      | O(1)     | O(n)  |
| Queue          | O(n)   | O(n)   | O(1)      | O(1)     | O(n)  |
| BST (Average)  | O(log n)| O(log n)| O(log n) | O(log n) | O(n)  |
| Hash Table     | N/A    | O(1)   | O(1)      | O(1)     | O(n)  |

| Algorithm      | Best Case | Average Case | Worst Case | Space |
|----------------|-----------|--------------|------------|-------|
| Bubble Sort    | O(n)      | O(n²)        | O(n²)      | O(1)  |
| Quick Sort     | O(n log n)| O(n log n)   | O(n²)      | O(log n)|
| Merge Sort     | O(n log n)| O(n log n)   | O(n log n) | O(n)  |
| Binary Search  | O(1)      | O(log n)     | O(log n)   | O(1)  |

## 🔧 System Requirements

- **Compiler**: GCC (GNU Compiler Collection) 4.8 or later
- **Operating System**: Linux, macOS, Windows (with MinGW)
- **Memory**: Minimal requirements (programs use small datasets by default)
- **Libraries**: Standard C libraries, math library (-lm) for searching algorithms

## 🎓 Educational Usage

This repository is perfect for:
- **Computer Science Students**: Learning fundamental DSA concepts
- **Interview Preparation**: Understanding common algorithmic problems
- **Academic Reference**: Well-documented implementations for coursework
- **Self-Study**: Progressive learning from basic to advanced topics

## 🤝 Contributing

Contributions are welcome! Please feel free to:
- Report bugs or issues
- Suggest new algorithms or data structures
- Improve documentation or comments
- Add test cases or examples
- Optimize existing implementations

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 📚 Learning Path

Recommended order for studying:
1. **Arrays** - Foundation of all data structures
2. **Linked Lists** - Dynamic memory and pointers
3. **Stacks & Queues** - LIFO and FIFO principles
4. **Trees** - Hierarchical data organization
5. **Graphs** - Complex relationships and traversals
6. **Searching** - Finding data efficiently
7. **Sorting** - Organizing data optimally
8. **Dynamic Programming** - Optimization problems

---

**Happy Coding! 🚀**

*For questions or suggestions, please open an issue or contact the repository maintainer.*
