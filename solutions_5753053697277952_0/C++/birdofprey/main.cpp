//*****************************************************************************
//  CodePro 1.0 - Programming contests library.
//
//  (c) Dr. Sergey Pogodin, 2015
//      Contact: dr.pogodin@gmail.com


//*****************************************************************************
//  Tuning of the template's behaviour.
//
//  Switching of the i/o binding between files (input.txt and output.txt in the
//  program starting folder) and standart streams. Just comment/uncomment
//  necessary assigments of the <input_binding> and <output_binding> params.

enum IOBinding { File, StdStream };

static const IOBinding InputBinding = File;
//static const IOBinding InputBinding = StdStream;

static const IOBinding OutputBinding = File;
//static const IOBinding OutputBinding = StdStream;

//  Basic handling of the input and output by main function.

enum IOHandlingFlag {
  MultipleTestCases = 0x1,
  PrintCaseNumberInCodeJamStyle = 0x2
};

static const int IOHandlingFlags =
    MultipleTestCases|PrintCaseNumberInCodeJamStyle;


//*****************************************************************************
//  Set of the most common includes, declarations and definitions necessary all
//  around. Keep this section in sync with "global.h".

#include <cmath>
#include <cassert>
#include <climits>
#include <cstdint>
#include <cstring>

#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef std::vector <int> IVec;
typedef std::unordered_set <int> ISet;


//*****************************************************************************
//  Implementation of the problem solution.

std::istream *input = &std::cin;
std::ostream *output = &std::cout;

class Problem {
public:
  Problem();
  ~Problem();
  void solve();

private:
  int N_, total_;
  std::vector<std::pair<int,int>> counts_;
};

Problem::Problem()
{
  total_ = 0;
  *input >> N_;
  counts_.resize(N_);
  for (int n = 0; n < N_; ++n) {
    *input >> counts_[n].second;
    total_ += counts_[n].second;
    counts_[n].first = n;
  }
}

Problem::~Problem() {

}

bool Compare(const std::pair<int,int> &a,
             const std::pair<int,int> &b) {
  return a.second > b.second;
}

void Problem::solve() {
  while (total_ > 0) {
    std::sort(counts_.begin(), counts_.end(), Compare);
    *output << char('A' + counts_[0].first);
    --counts_[0].second; --total_;
    if (counts_[1].second > total_/2) {
      *output << char('A' + counts_[1].first);
      --counts_[1].second; --total_;
    }
    *output << ' ';
  }
  *output << '\n';
}


//*****************************************************************************
//  Setup of <input> and <output> binding to input.txt and output.txt files if
//  necessary.

void InitIOStreams() {
  std::ios_base::sync_with_stdio(false);
  if (InputBinding == File) input = new std::ifstream("input.txt");
  if (OutputBinding == File) output = new std::ofstream("output.txt");
}

void DeinitIOStreams() {
  if (InputBinding == File) delete input;
  if (OutputBinding == File) delete output;
}


//*****************************************************************************
//  Start-up of the solution.

int main(int argc, char *argv[]) {
  (void) argc;
  (void) argv;
  InitIOStreams();
  int num_test_cases = 1;
  if (IOHandlingFlags & MultipleTestCases) *input >> num_test_cases;
  for(int t = 1; t <= num_test_cases; ++t) {
    if (IOHandlingFlags & PrintCaseNumberInCodeJamStyle)
      *output << "Case #" << t << ": ";
    Problem p; p.solve();
  }
  DeinitIOStreams();
  return 0;
}
