// main.cpp
#include "MemoryManager.h"
#include "CustomOperators.h"

MemoryManager memoryManager; // Define the global memory manager instance

void exampleFunction() {
    int* a = new int(10);     // Allocated memory for a, managed by memoryManager
    int* b = new int(20);     // Allocated memory for b
    int* c = new int(30);     // Allocated memory for c

    memoryManager.addReference(a, b); // a -> b
    memoryManager.addReference(b, c); // b -> c

    delete a; // Deallocate a; b and c become unreachable if no other references

    // Detect memory leaks and cycles
    memoryManager.detectLeaks();
    memoryManager.hasCycle();
}

int main() {
    exampleFunction();
    return 0;
}
