#include "main.h"

#include <sstream>

using namespace std;

const static size_t kLinesPerTest = 1;

typedef int solvertype;

int idxOf(int r, int c, int x, int y) {
   if (x < 0 || y < 0 || x >= r || y >= c)
      return -1;
   return x*c + y;
}
int getIdx(solvertype test, int idx, int rbc) {
   if (idx < 0) return 0;
   return (test >> (rbc - idx)) & 1;
}

int unhappyOf(int r, int c, solvertype test) {
   int out = 0;
   int rbc = r*c - 1;
   for (int x = 0; x < r; x++) {
      for (int y = 0; y < c; y++) {
         int idx = idxOf(r, c, x, y);
         if (idx >= 0 && getIdx(test, idx, rbc)) {
            out += getIdx(test, idxOf(r, c, x+1, y), rbc);
            out += getIdx(test, idxOf(r, c, x-1, y), rbc);
            out += getIdx(test, idxOf(r, c, x, y+1), rbc);
            out += getIdx(test, idxOf(r, c, x, y-1), rbc);
         }
      }
   }
   return out / 2;
}

bool solveTest(
   const vector<string>& lines,
   size_t startingIndex,
   string& result,
   size_t& linesUsed) {

   if (startingIndex + kLinesPerTest > lines.size())
      return false;
   linesUsed = kLinesPerTest;

   vector<int> testNums;
   splitAsInt(lines[startingIndex], ' ', testNums);
   assert(testNums.size() == 3);

   int r = testNums[0];
   int c = testNums[1];
   int n = testNums[2];

   int numBits = r * c;

   assert(sizeof(solvertype)*8 >= numBits);

   
#if 0
   //TESTING
   {
      assert(idxOf(3, 3, 0, 0) == 0);
      assert(idxOf(3, 3, 0, 1) == 1);
      assert(idxOf(3, 3, 0, 2) == 2);
      assert(idxOf(3, 3, 1, 0) == 3);
      assert(idxOf(3, 3, 1, 1) == 4);
      assert(idxOf(3, 3, 1, 2) == 5);
      assert(idxOf(3, 3, 2, 0) == 6);
      assert(idxOf(3, 3, 2, 1) == 7);
      assert(idxOf(3, 3, 2, 2) == 8);

      assert(getIdx(98, 0, 8) == 0);
      assert(getIdx(98, 1, 8) == 0);
      assert(getIdx(98, 2, 8) == 1);
      assert(getIdx(98, 3, 8) == 1);
      assert(getIdx(98, 4, 8) == 0);
      assert(getIdx(98, 5, 8) == 0);
      assert(getIdx(98, 6, 8) == 0);
      assert(getIdx(98, 7, 8) == 1);
      assert(getIdx(98, 8, 8) == 0);

      assert(unhappyOf(3, 3, 98) == 0);
      TRACE(unhappyOf(3, 3, 114));
      assert(unhappyOf(3, 3, 114) == 2);
      assert(unhappyOf(3, 3, 178) == 3);
   }
   #endif


   const int maxUnhappy = 2*r*c - r - c;

   solvertype max = 1 << numBits;

   int minUnhappy = maxUnhappy + 1;
   for (solvertype i = 0; i < max; i++) {
      //don't consider cases that don't havve the right number
      if (countSetBits(i) != n)
         continue;
      minUnhappy = min(minUnhappy, unhappyOf(r, c, i));
   }


   assert(minUnhappy <= maxUnhappy);
   //Solve. Complexity is (R*C) choose N

   stringstream answer;
   answer << minUnhappy;
   result = answer.str();

   return true;
}