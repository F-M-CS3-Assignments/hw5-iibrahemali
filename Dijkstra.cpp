// swe: ibrahem ali
// date: 14/4/25

#include "Dijkstra.h"
#include "BetterPriorityQueue.h"

// time complexity: around O((v + e) log v) depending on graph + pq impl
int dijkstra(nodekey_t start, nodekey_t end, const Graph* g) {
    BetterPriorityQueue pq;
    set<nodekey_t> visited;

    BPQNode startNode;
    startNode.gnode = start;
    startNode.pri = 0;
    pq.push(startNode);

    while (!pq.empty()) {
        BPQNode cur = pq.top(); pq.pop();
        if (visited.count(cur.gnode)) continue;
        visited.insert(cur.gnode);

        if (cur.gnode == end) return cur.pri;

        for (const GraphEdge* edge : g->GetOutwardEdgesFrom(cur.gnode)) {
            if (visited.count(edge->to)) continue;

            BPQNode next;
            next.gnode = edge->to;
            next.pri = cur.pri + edge->weight;

            // push if new or better
            if (!pq.Contains(next)) {
                pq.push(next);
            } else {
                pq.Update(next);
            }
        }
    }

    return -1; // end not reachable
}
