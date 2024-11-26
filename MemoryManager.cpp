// MemoryManager.cpp
#include "MemoryManager.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Constructor
MemoryManager::MemoryManager() : rootNode(nullptr) {}

// Allocate memory and register it in the graph
void* MemoryManager::allocate(size_t size) {
    void* ptr = malloc(size);
    if (ptr) {
        nodes[ptr] = {};  // Initialize empty adjacency list for the new node
        if (!rootNode) {
            rootNode = ptr;  // Set first allocation as the root node
        }
    }
    return ptr;
}

// Deallocate memory and remove from graph
void MemoryManager::deallocate(void* ptr) {
    if (nodes.find(ptr) != nodes.end()) {
        nodes.erase(ptr);  // Remove node from graph
        free(ptr);
    }
}

// Add a reference from one memory block to another
void MemoryManager::addReference(void* from, void* to) {
    if (nodes.find(from) != nodes.end() && nodes.find(to) != nodes.end()) {
        nodes[from].push_back(to);
    }
}

// Remove a reference
void MemoryManager::removeReference(void* from, void* to) {
    if (nodes.find(from) != nodes.end()) {
        auto& edges = nodes[from];
        edges.erase(std::remove(edges.begin(), edges.end(), to), edges.end());
    }
}

// Detect memory leaks by checking reachability from root node
void MemoryManager::detectLeaks() {
    std::unordered_set<void*> visited;
    dfs(rootNode, visited);

    for (const auto& node : nodes) {
        if (visited.find(node.first) == visited.end()) {
            std::cerr << "Memory leak detected at address: " << node.first << std::endl;
        }
    }
}

// Detect if there are cycles in the graph
bool MemoryManager::hasCycle() {
    std::unordered_set<void*> visited, recursionStack;
    for (const auto& node : nodes) {
        if (dfsCycleDetection(node.first, visited, recursionStack)) {
            std::cerr << "Cycle detected involving memory at address: " << node.first << std::endl;
            return true;
        }
    }
    return false;
}

// Depth-first search to mark reachable nodes
void MemoryManager::dfs(void* node, std::unordered_set<void*>& visited) {
    if (!node || visited.find(node) != visited.end()) return;
    visited.insert(node);

    for (void* neighbor : nodes[node]) {
        dfs(neighbor, visited);
    }
}

// DFS-based cycle detection
bool MemoryManager::dfsCycleDetection(void* node, std::unordered_set<void*>& visited, std::unordered_set<void*>& recursionStack) {
    if (visited.find(node) == visited.end()) {
        visited.insert(node);
        recursionStack.insert(node);

        for (void* neighbor : nodes[node]) {
            if (recursionStack.find(neighbor) != recursionStack.end() || dfsCycleDetection(neighbor, visited, recursionStack)) {
                return true;
            }
        }
    }
    recursionStack.erase(node);
    return false;
}
