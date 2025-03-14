#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"
#include <sstream>

TEST(TESTPrintLadder, test){
  stringstream s;
  vector<string> a {"a", "b", "c"};
  std::streambuf *coutbuf = std::cout.rdbuf(s.rdbuf()); //save old buf

  print_word_ladder(a);
  EXPECT_TRUE(s.str() == "a→b→c→[END]\n");

  std::cout.rdbuf(coutbuf);
}