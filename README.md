# Assignment 5: Dijkstra's Algorithm

This project implements Dijkstra's algorithm using:

- A custom `Graph` class with dynamic memory
- A `BetterPriorityQueue` built on top of C++'s `priority_queue`
- Full unit tests for each module (`Graph`, `BetterPriorityQueue`, and `Dijkstra`)

## 

- `Graph.h / Graph.cpp`: defines and implements the graph structure using adjacency lists
- `BetterPriorityQueue.h / .cpp`: priority queue that allows updating node priorities
- `Dijkstra.h / Dijkstra.cpp`: Dijkstra's shortest path implementation
- `GraphTests.cpp`: tests for the graph
- `BPQTests.cpp`: tests for the priority queue
- `DijkstraTests.cpp`: tests for the algorithm

## 

```bash
make all         # builds all tests
./graph-tests    # runs Graph tests
./bpq-tests      # runs BetterPriorityQueue tests
./dijkstra       # runs Dijkstra tests
