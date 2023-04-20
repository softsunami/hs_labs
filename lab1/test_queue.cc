#include <gtest/gtest.h>

#include "priority_queue.h"

TEST(Empty, test1) {
  priority_queue<int> q;
  EXPECT_TRUE(q.empty());
}

TEST(Empty, test2) {
  priority_queue<int> q;
  q.push(1);
  EXPECT_FALSE(q.empty());
}

TEST(Size, test1) {
  priority_queue<int> q;
  EXPECT_EQ(q.size(), 0);
}

TEST(Size, test2) {
  priority_queue<int> q;
  q.push(1);
  q.push(2);
  EXPECT_EQ(q.size(), 2);
}

TEST(Push, test1) {
  priority_queue<int> q;
  q.push(15);
  EXPECT_EQ(q.top(), 15);
}

TEST(Push, test2) {
  priority_queue<int> q;
  q.push(7);
  q.push(1);
  q.push(25);
  q.push(18);
  EXPECT_EQ(q.top(), 25);
}

TEST(Pop, test1) {
  priority_queue<int> q;
  q.push(7);
  q.push(1);
  q.push(25);
  q.push(18);
  EXPECT_EQ(q.size(), 4);
  q.pop();
  EXPECT_EQ(q.size(), 3);
}

TEST(Top, test1) {
  priority_queue<int> q;
  q.push(7);
  q.push(1);
  q.push(140);
  q.push(141);
  q.push(1);
  q.push(-204);
  EXPECT_EQ(q.top(), 141);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
