#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"
#include <sstream>

TEST(TESTLadder, testPrint){
  stringstream s;
  vector<string> a {"a", "b", "c"};
  std::streambuf *coutbuf = std::cout.rdbuf(s.rdbuf()); //save old buf

  print_word_ladder(a);
  EXPECT_TRUE(s.str() == "a→b→c→[END]\n");

  std::cout.rdbuf(coutbuf);
}

TEST(TESTLadder, testEditDistanceWithin){
  string a, b;
  a = b = "abc";
  EXPECT_TRUE(edit_distance_within(a, b, 100));
  EXPECT_TRUE(edit_distance_within(a, b, 0));
  b = "cba";
  EXPECT_FALSE(edit_distance_within(a, b, 0));
  EXPECT_TRUE(edit_distance_within(a, b, 100));
  EXPECT_TRUE(edit_distance_within(a, b, 2));
  EXPECT_FALSE(edit_distance_within(a, b, 1));
}

TEST(TESTLadder, testIsAdjacent){
  string a, b, c;
  a = "abc";
  b = "ab";
  c = "";
  EXPECT_TRUE(is_adjacent(a,b));
  EXPECT_FALSE(is_adjacent(a,c));
}