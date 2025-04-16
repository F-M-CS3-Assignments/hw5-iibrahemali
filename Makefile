all: graph-tests bpq-tests dijkstra

graph-tests: Graph.cpp Graph.h GraphTests.cpp
	g++ -Wall -g Graph.cpp GraphTests.cpp -o graph-tests

bpq-tests: Graph.cpp Graph.h BetterPriorityQueue.cpp BetterPriorityQueue.h BPQTests.cpp
	g++ -Wall -g Graph.cpp BetterPriorityQueue.cpp BPQTests.cpp -o bpq-tests

dijkstra: Graph.cpp Graph.h BetterPriorityQueue.cpp BetterPriorityQueue.h Dijkstra.cpp Dijkstra.h DijkstraTests.cpp
	g++ -Wall -g Graph.cpp BetterPriorityQueue.cpp Dijkstra.cpp DijkstraTests.cpp -o dijkstra

clean:
	rm -f graph-tests bpq-tests dijkstra
