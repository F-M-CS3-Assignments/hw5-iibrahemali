// swe: ibrahem ali
// date: 14/4/25


#include "BetterPriorityQueue.h"

// check if item exists in the queue
bool BetterPriorityQueue::Contains(const BPQNode &n) {
	for (const auto &item : this->c) {
		if (item == n) return true;
	}
	return false;
}

// update item's priority if it's better (lower)
bool BetterPriorityQueue::Update(const BPQNode& n) {
	for (auto& item : this->c) {
		if (item == n) {
			if (n.pri < item.pri) {
				item = n;
				std::make_heap(this->c.begin(), this->c.end(), this->comp);
				return true;
			} else {
				return false; // higher or same priority: no update
			}
		}
	}
	return false; // not found
}


// print the full queue
std::string BetterPriorityQueue::ToString() const {
	std::string result = "[";
	for (size_t i = 0; i < this->c.size(); ++i) {
		result += BPQNodeToString(this->c[i]);
		if (i < this->c.size() - 1) result += ", ";
	}
	return result + "]";
}

// print single node
std::string BetterPriorityQueue::BPQNodeToString(const BPQNode &n) {
	return "(" + std::to_string(n.gnode) + ", pri: " + std::to_string(n.pri) + ")";
}
