g++ -c MemoryManager.cpp -o MemoryManager.o
g++ -c main.cpp -o main.o
g++ MemoryManager.o main.o -o memoryLeakDetector
./memoryLeakDetector
