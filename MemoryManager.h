// MemoryManager.h
#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstddef>

using namespace std;

class MemoryManager {
public:
    MemoryManager();
    void* allocate(size_t size);
    void deallocate(void* ptr);
    void addReference(void* from, void* to);
    void removeReference(void* from, void* to);
    void detectLeaks();
    bool hasCycle();

private:
    std::unordered_map<void*, std::vector<void*>> nodes; // Adjacency list for memory graph
    void* rootNode;

    // Helper functions
    void dfs(void* node, std::unordered_set<void*>& visited);
    bool dfsCycleDetection(void* node, std::unordered_set<void*>& visited, std::unordered_set<void*>& recursionStack);
};

#endif // MEMORY_MANAGER_H
