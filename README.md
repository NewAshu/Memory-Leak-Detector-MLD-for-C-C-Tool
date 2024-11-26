In this project, each allocated memory block will be represented as a node in a directed graph, and pointers between these blocks will be represented as edges. The root node will act as a global reference point for reachable memory. Here’s the core concept:

Graph Nodes (Memory Blocks): Each dynamically allocated memory block (new or malloc) will be treated as a node in a directed graph.
Edges (References): If one memory block points to another, an edge will be created from the source block to the destination block.
Reachability: Nodes (memory blocks) not reachable from the root node by DFS/BFS at the end of program execution will be considered memory leaks.
Cycle Detection: Cycles indicate circular references; if nodes in a cycle have no other references from the root, these nodes are also considered leaks.
Implementation Plan
Memory Manager Class: Manages memory allocation, tracks pointers, and builds the directed graph.
Graph Representation: Adjacency list to represent connections between memory blocks.
Cycle Detection and Reachability Check: Use DFS to check if memory nodes are reachable from the root and detect cycles.


Explanation of Each File
MemoryManager.h: Contains the class declaration, making the MemoryManager API accessible to other files.
MemoryManager.cpp: Implements MemoryManager functions, managing allocations, deallocations, references, and detecting leaks and cycles.
CustomOperators.h: Custom new and delete operators use MemoryManager for automatic tracking of heap allocations.
main.cpp: Demonstrates usage of MemoryManager, showing how to allocate memory, add references, detect leaks, and check for cycles.



