#ifndef MIN_QUEUE_DOT_H
#define MIN_QUEUE_DOT_H

#ifndef abstract
#define abstract = 0
#endif

struct MinQueue {

  virtual void insert(int data) abstract;
  virtual int removeMin() abstract;
  virtual int size() const abstract;

  virtual ~MinQueue() {
    // absolutely nothing (just so implementers of MinQueue can deallocate properly)
  }

};

#endif