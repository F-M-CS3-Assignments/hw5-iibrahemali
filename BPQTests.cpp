#include "Graph.h"
#include "BetterPriorityQueue.h"
#include <cassert>
#include <iostream>

using namespace std;

void ContainsTest() {
	cout << "Testing Contains Helper Method..." << endl;
	
	Graph g = Graph();
	BetterPriorityQueue q;
	
	g.AddNode(1);
	g.AddNode(2);
	g.AddNode(3);
	g.AddNode(4);
	g.AddNode(5);
	g.AddNode(6);
	set<nodekey_t> nodes = g.GetNodes();
	for(nodekey_t n : nodes){
		BPQNode cur;
		cur.gnode = n;
		q.push(cur);
	}
	
	// 1st test
	BPQNode positive;
	positive.gnode = 2;
	assert(q.Contains(positive) == true);
	
	// 2nd test
	BPQNode negative;
	assert(q.Contains(negative) == false);
	
	// 3rd test (again)
	assert(q.Contains(positive) == true);
	
	cout << "PASSED!" << endl;
}

void UpdateTest() {
	cout << "Testing Update Helper Method..." << endl;
	
	Graph g = Graph();
	BetterPriorityQueue q;
	
	g.AddNode(1);
	g.AddNode(2);
	g.AddNode(3);
	g.AddNode(4);
	g.AddNode(5);
	g.AddNode(6);
	set<nodekey_t> nodes = g.GetNodes();
	size_t i = 0;
	for(nodekey_t n : nodes){
		BPQNode cur;
		cur.pri = i;
		cur.gnode = n;
		q.push(cur);
		i++;
	}

	// Test 1: update a node with lower pri (normal case)
	BPQNode positive;
	positive.gnode = 6;
	positive.pri = 0;
	cout << "q before: " << q.ToString() << endl;
	assert(q.Update(positive) == true);
	cout << "q after: " << q.ToString() << endl;
	string result = q.ToString();
	assert(result.find("(6, pri: 0)") != string::npos);

	// Test 2: update with undefined node
	BPQNode negative;
	assert(q.Update(negative) == false);
	cout << "q after test 2: " << q.ToString() << endl;

	// Test 3: update with higher pri (should fail)
	BPQNode negative2;
	negative2.gnode = 5;
	negative2.pri = 80;
	assert(q.Update(negative2) == false);
	cout << "q after test 3: " << q.ToString() << endl;
	assert(result.find("(5, pri: 4)") != string::npos);

	cout << "PASSED!" << endl;
}

void PriorityOrderTest() {
	cout << "Testing ordering of priority queue..." << endl;
	BetterPriorityQueue q;

	BPQNode a{3, false, 100};
	BPQNode b{1, false, 200};
	BPQNode c{2, false, 300};
	
	q.push(a);
	q.push(b);
	q.push(c);

	// top should be b (pri 1)
	BPQNode top = q.top();
	assert(top.pri == 1);
	assert(top.gnode == 200);

	cout << "PASSED!" << endl;
}

void EmptyQueueTest() {
	cout << "Testing edge cases on empty queue..." << endl;
	BetterPriorityQueue q;
	BPQNode n;
	n.gnode = 1;
	n.pri = 0;
	assert(q.Update(n) == false);
	assert(q.Contains(n) == false);
	assert(q.ToString() == "[]");
	cout << "PASSED!" << endl;
}

int main(){
	ContainsTest();
	UpdateTest();
	PriorityOrderTest();
	EmptyQueueTest();

	cout << "ALL TESTS PASSED!!" << endl;
	return 0;
}
