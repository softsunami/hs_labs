#include <gtest/gtest.h>

#include "substring.h"

TEST(SearchBoyerMoore, Test1) {
  std::string haystack(
      "I cheated while playing the darts tournament by using a longbow");
  std::string needle("the");
  std::vector<int> occurrences = SearchBoyerMoore(haystack, needle);
  std::vector<int> occurrences_expected = {24};

  EXPECT_EQ(occurrences[0], occurrences_expected[0]);
}

TEST(SearchBoyerMoore, Test2) {
  std::string haystack(
      "I cheated while playing the darts tournament by using a longbow");
  std::string needle("softsunami");
  std::vector<int> occurrences = SearchBoyerMoore(haystack, needle);

  EXPECT_TRUE(occurrences.empty());
}

TEST(SearchRabinKarp, Test1) {
  std::string haystack("You can't compare apples and oranges");
  std::string needle("You");
  std::vector<int> occurrences = SearchRabinKarp(haystack, needle);
  std::vector<int> occurrences_expected = {0};

  EXPECT_EQ(occurrences[0], occurrences_expected[0]);
}

TEST(SearchRabinKarp, Test2) {
  std::string haystack("You can't compare apples and oranges");
  std::string needle("softsunami");
  std::vector<int> occurrences = SearchRabinKarp(haystack, needle);

  EXPECT_TRUE(occurrences.empty());
}

TEST(SearchKnuthMorrisPratt, Test1) {
  std::string haystack("There can never be too many cherries");
  std::string needle("cherries");
  std::vector<int> occurrences = SearchKnuthMorrisPratt(haystack, needle);
  std::vector<int> occurrences_expected = {28};

  EXPECT_EQ(occurrences[0], occurrences_expected[0]);
}

TEST(SearchKnuthMorrisPratt, Test2) {
  std::string haystack("There can never be too many cherries");
  std::string needle("softsunami");
  std::vector<int> occurrences = SearchKnuthMorrisPratt(haystack, needle);

  EXPECT_TRUE(occurrences.empty());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
