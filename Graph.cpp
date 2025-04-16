// swe: ibrahem ali 
// date: 14/4/25

#include "Graph.h"
#include <algorithm>
using namespace std;

Graph::Graph() {} // i forgot it - got compling error

// helper - check if edge exists already
const GraphEdge* findExistingEdge(nodekey_t from, nodekey_t to, const vector<vector<GraphEdge*>>& adjList, const vector<nodekey_t>& nodes) {
    for (size_t i = 0; i < nodes.size(); ++i) {
        for (auto edge : adjList[i]) {
            if (edge->from == from && edge->to == to)
                return edge;
        }
    }
    return nullptr;
}

// helper - turn edge into string
string GraphEdgeToString(const GraphEdge* e) {
    return "((" + to_string(e->from) + ")->(" + to_string(e->to) + ") w:" + to_string(e->weight) + ")";
}

// add node if it doesn't already exist
void Graph::AddNode(nodekey_t key) {
    if (IsPresent(key)) throw invalid_argument("duplicate node: " + to_string(key));
    nodes.push_back(key);
    adjList.push_back({});
}

// add edge between existing nodes
const GraphEdge* Graph::AddEdge(nodekey_t from, nodekey_t to, unsigned int weight) {
    if (!IsPresent(from) || !IsPresent(to)) throw invalid_argument("invalid node(s)");
    if (findExistingEdge(from, to, adjList, nodes)) throw invalid_argument("edge already exists");

    GraphEdge* ge = new GraphEdge{from, to, weight};
    auto it = find(nodes.begin(), nodes.end(), from);
    size_t idx = distance(nodes.begin(), it);
    adjList[idx].push_back(ge);
    return ge;
}

// check if node is in the graph
bool Graph::IsPresent(nodekey_t key) const {
    return find(nodes.begin(), nodes.end(), key) != nodes.end();
}

// get edges going out from node
set<const GraphEdge*> Graph::GetOutwardEdgesFrom(nodekey_t node) const {
    auto it = find(nodes.begin(), nodes.end(), node);
    if (it == nodes.end()) throw invalid_argument("node not found");
    size_t idx = distance(nodes.begin(), it);

    set<const GraphEdge*> result;
    for (auto edge : adjList[idx]) result.insert(edge);
    return result;
}

// get all nodes
set<nodekey_t> Graph::GetNodes() const {
    return set<nodekey_t>(nodes.begin(), nodes.end());
}

// turn node list to string
string Graph::NodesToString() const {
    if (nodes.empty()) return "[]";
    string result = "[";
    for (size_t i = 0; i < nodes.size(); ++i) {
        result += "(" + to_string(nodes[i]) + ")";
        if (i != nodes.size() - 1) result += ", ";
    }
    return result + "]";
}

// turn edge list to string
string Graph::EdgesToString() const {
    string result = "[";
    size_t total = Size();
    size_t count = 0;
    for (const auto& row : adjList) {
        for (const auto& edge : row) {
            result += GraphEdgeToString(edge);
            if (++count < total) result += ", ";
        }
    }
    return result + "]";
}

// number of nodes
size_t Graph::Order() const {
    return nodes.size();
}

// number of edges
size_t Graph::Size() const {
    size_t total = 0;
    for (const auto& row : adjList) total += row.size();
    return total;
}

// cleanup any heap mem
Graph::~Graph() {
    for (auto& row : adjList) for (auto edge : row) delete edge;
}