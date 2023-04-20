#ifndef LAB1_PRIORITY_QUEUE_H_
#define LAB1_PRIORITY_QUEUE_H_

#include <iostream>
#include <queue>

template <typename T, typename Container = std::vector<T>>
class priority_queue {
 private:
  std::priority_queue<T, Container> store;

 public:
  priority_queue() = default;

  explicit priority_queue(T var) { store.push(var); }

  explicit priority_queue(Container pr_queue) { store.swap(pr_queue); }

  bool empty() const { return store.empty(); }

  size_t size() const { return store.size(); }

  void push(T const& value) { store.push(value); }

  void pop() { store.pop(); }

  T const& top() const { return store.top(); }
};

#endif  // LAB1_PRIORITY_QUEUE_H_