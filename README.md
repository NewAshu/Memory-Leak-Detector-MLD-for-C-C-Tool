In this project, each allocated memory block will be represented as a node in a directed graph, and pointers between these blocks will be represented as edges. The root node will act as a global reference point for reachable memory. Here’s the core concept:

**Explanation of Each File**
**MemoryManager.h:** Contains the class declaration, making the MemoryManager API accessible to other files.
**MemoryManager.cpp:** Implements MemoryManager functions, managing allocations, deallocations, references, and detecting leaks and cycles.
**CustomOperators.h:** Custom new and delete operators use MemoryManager for automatic tracking of heap allocations.
**main.cpp:** Demonstrates usage of MemoryManager, showing how to allocate memory, add references, detect leaks, and check for cycles.



