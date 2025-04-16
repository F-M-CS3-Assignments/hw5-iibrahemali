
#include "Graph.h"
#include "BetterPriorityQueue.h"
#include "Dijkstra.h"

#include <iostream>
#include <cassert>

using namespace std;


int DijkstraTest(){
	cout << "Testing Dijkstra Algorithm..." << endl;
	
	// Test 1: graph from assignment
	Graph *g = new Graph();
	
	g->AddNode(1);
	g->AddNode(2);
	g->AddNode(3);
	g->AddNode(4);
	g->AddNode(5);
	g->AddNode(6);
	
	g->AddEdge(1, 2, 7);
	g->AddEdge(2, 1, 7);
	g->AddEdge(1, 3, 9);
	g->AddEdge(3, 1, 9);
	g->AddEdge(1, 6, 14);
	g->AddEdge(6, 1, 14);
	
	g->AddEdge(2, 3, 10);
	g->AddEdge(3, 2, 10);
	g->AddEdge(2, 4, 15);
	g->AddEdge(4, 2, 15);
	
	g->AddEdge(3, 6, 2);
	g->AddEdge(6, 3, 2);
	g->AddEdge(3, 4, 11);
	g->AddEdge(4, 3, 11);
	
	g->AddEdge(6, 5, 9);
	g->AddEdge(5, 6, 9);
	
	g->AddEdge(4, 5, 6);
	g->AddEdge(5, 4, 6);
	
	cout <<  "---Graph---" << endl;
	cout << "\tnodes: " << g->NodesToString() << endl;
	cout << "\tedges: " << g->EdgesToString() << endl;
	cout << "---Graph---" << endl << endl;

	nodekey_t start = 1;
	nodekey_t end = 5;

	cout << "start: " << to_string(start) << "  goal: " << to_string(end) << endl;
	
	int ans = dijkstra(start, end, g);
	cout << "Output from Dijkstra(" << to_string(start) << ", " << to_string(end) << ") => " << ans << endl;
	assert(ans == 20);

	delete g;
	
	cout << "DONE Testing Dijkstra Algorithm" << endl;
	
	return ans;
}


void MoreDijkstraTests(){
	cout << "Deep Testing Dijkstra Algorithm..." << endl;

	// case 1: no path between nodes
	Graph g1;
	g1.AddNode(1);
	g1.AddNode(2);
	g1.AddNode(3);
	g1.AddEdge(1, 2, 4);
	// no edge to 3
	assert(dijkstra(1, 3, &g1) == -1);

	// case 2: single node path to itself
	Graph g2;
	g2.AddNode(42);
	assert(dijkstra(42, 42, &g2) == 0);

	Graph g3;
	g3.AddNode(9);
	g3.AddEdge(9, 9, 5); // loop
	
	// NOTE: even though there's a (9 -> 9) edge with weight 5,
	// the algorithm returns 0 since we start & end at the same node
	// before exploring neighbors
	assert(dijkstra(9, 9, &g3) == 0);
	

	// case 4: multiple paths, same cost
	Graph g4;
	g4.AddNode(1);
	g4.AddNode(2);
	g4.AddNode(3);
	g4.AddNode(4);

	g4.AddEdge(1, 2, 2);
	g4.AddEdge(2, 4, 3);
	g4.AddEdge(1, 3, 3);
	g4.AddEdge(3, 4, 2);

	// 1 → 2 → 4 = 5,  1 → 3 → 4 = 5
	assert(dijkstra(1, 4, &g4) == 5);

	cout << "DONE Deep Testing Dijkstra Algorithm" << endl;
}


int main(){
	
	DijkstraTest(); // this one by itself tests the graph on the assignment
	cout << endl;
	MoreDijkstraTests();
	cout << endl;
	cout << "ALL TESTS PASSED!" << endl;

	return 0;
}
