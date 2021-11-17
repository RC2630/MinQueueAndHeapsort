#ifndef MIN_HEAP_QUEUE_DOT_H
#define MIN_HEAP_QUEUE_DOT_H

#include <vector>
#include <utility>
#include <iostream>
#include <climits>

#include "minQueue.h"

using namespace std;

struct MinHeapQueue : public MinQueue {

private:

  vector<int> heap = {INT_MAX}; // initialized with useless element because index 0 is not used

  void heapifyUp(int cIndex) {
    if (cIndex > 1 && heap.at(cIndex) < heap.at(parent(cIndex))) {
      swap(heap.at(cIndex), heap.at(parent(cIndex)));
      heapifyUp(parent(cIndex));
    }
  }

  void heapifyDown(int cIndex) {
    if (hasChild(cIndex)) {
      int minChildIndex = minimumChildIndex(cIndex);
      if (heap.at(minChildIndex) < heap.at(cIndex)) {
        swap(heap.at(minChildIndex), heap.at(cIndex));
      }
      heapifyDown(minChildIndex);
    }
  }

  static int parent(int cIndex) {
    return cIndex / 2; // integer division
  }

  bool hasChild(int cIndex) const {
    return 2 * cIndex <= size();
  }

  int minimumChildIndex(int cIndex) const {
    int leftIndex = 2 * cIndex; // we know for sure that this left index is within bounds
    int rightIndex = leftIndex + 1; // but not for the right one
    if (rightIndex > size()) {
      return leftIndex;
    }
    return (heap.at(leftIndex) < heap.at(rightIndex)) ? leftIndex : rightIndex;
  }

  static MinHeapQueue makeHeap(const vector<int>& v) {
    MinHeapQueue minHeap;
    minHeap.heap.insert(minHeap.heap.end(), v.begin(), v.end());
    for (int i = parent(minHeap.size()); i > 0; i--) {
      minHeap.heapifyDown(i);
    }
    return minHeap;
  }

  // friend declaration for operator << (so this function can access the private stuff of this struct)
  friend ostream& operator << (ostream& out, const MinHeapQueue& minQueue);

public:

  void insert(int data) override {
    heap.push_back(data);
    heapifyUp(size());
  }

  int removeMin() override {
    int minVal = heap.at(1);
    heap.at(1) = heap.back();
    heap.pop_back();
    heapifyDown(1);
    return minVal;
  }

  int size() const override {
    return heap.size() - 1;
  }

  static void heapsort(vector<int>& v) {
    int initialSize = v.size();
    MinHeapQueue minHeap = makeHeap(v);
    v.clear();
    for (int i = 0; i < initialSize; i++) {
      v.push_back(minHeap.removeMin());
    }
  }

};

// to facilitate outputting of a MinHeapQueue
ostream& operator << (ostream& out, const MinHeapQueue& minQueue) {
  if (minQueue.size() == 0) {
    out << "[]";
    return out;
  }
  if (minQueue.size() == 1) {
    out << "[" << minQueue.heap.at(1) << "]";
    return out;
  }
  out << "[";
  for (int i = 1; i <= minQueue.size() - 1; i++) {
    out << minQueue.heap.at(i) << ", ";
  }
  out << minQueue.heap.back() << "]";
  return out;
}

#endif