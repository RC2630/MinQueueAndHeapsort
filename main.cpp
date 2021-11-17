#include "minHeapQueue.h"

#include <cstdlib>
#include <ctime>

using namespace std;

// facilitate output of vectors
template <typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
  if (v.empty()) {
    out << "[]";
    return out;
  }
  out << "[";
  for (int i = 0; i < v.size() - 1; i++) {
    out << v.at(i) << ", ";
  }
  out << v.back() << "]";
  return out;
}

void testPriorityQueue() {

  MinHeapQueue minQueue;
  cout << "\nempty minQueue: " << minQueue << "\ncurrent size of minQueue: " << minQueue.size() << "\n\n";

  cout << "INSERTIONS ONLY:\n\n";
  for (int i = 1; i <= 10; i++) {
    int randint = rand() % 50; // some random small integer in [0, 49]
    minQueue.insert(randint);
    cout << "after inserting " << randint << ", minQueue: " << minQueue
         << "\ncurrent size of minQueue: " << minQueue.size() << "\n\n";
  }

  cout << "INSERTIONS & REMOVALS TOGETHER:\n\n";
  for (int i = 1; i <= 4; i++) {
    for (int r = 1; r <= i; r++) {
      int currMin = minQueue.removeMin();
      cout << "removed " << currMin << ", now minQueue: " << minQueue
           << "\ncurrent size of minQueue: " << minQueue.size() << "\n\n";
    }
    int randint = rand() % 100; // some random medium-sized integer in [0, 99]
    minQueue.insert(randint);
    cout << "after inserting " << randint << ", minQueue: " << minQueue
         << "\ncurrent size of minQueue: " << minQueue.size() << "\n\n";
  }

  cout << "REMOVALS ONLY:\n\n";
  while (minQueue.size() != 0) {
    int currMin = minQueue.removeMin();
    cout << "removed " << currMin << ", now minQueue: " << minQueue
         << "\ncurrent size of minQueue: " << minQueue.size() << "\n\n";
  }

}

void testHeapSort() {
  vector<int> v;
  for (int i = 1; i <= 20; i++) {
    v.push_back(rand() % 100); // random integer in [0, 99]
  }
  cout << "\nv (before sorting) = " << v;
  MinHeapQueue::heapsort(v);
  cout << "\nv  (after sorting) = " << v << "\n\n";
}

int main() {
  srand(time(nullptr)); // seeding the random number generator
  //testPriorityQueue();
  testHeapSort();
}