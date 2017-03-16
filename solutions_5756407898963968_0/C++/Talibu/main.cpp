#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

#define FOR4(TYPE, NAME, FROM, TO) for(TYPE NAME = FROM; NAME < TO; NAME++)
#define FOR3(NAME, FROM, TO) for(u64 NAME = FROM; NAME < TO; NAME++)
#define FOR2(NAME, TO) for(u64 NAME = 0; NAME < TO; NAME++)

typedef unsigned int u32;
typedef unsigned long long u64;

typedef std::tuple<u32, u32> TTuple;

template<typename T>
void HashCombine(std::size_t& aSeed, const T& aValue) {
  aSeed ^= std::hash<T>()(aValue) + 0x9e3779b9 + (aSeed << 6) + (aSeed >> 2);
}
namespace std {
  template<>
  struct hash<TTuple> {
    size_t operator()(const TTuple& aTuple) const {
      size_t hash = 0;
      HashCombine(hash, get<0>(aTuple));
      HashCombine(hash, get<1>(aTuple));
      return hash;
    }
  };
}

struct CProblem {
  int N[2][4][4];
  int F,S;
};

struct CResult {
  std::string S;
};

CResult Solve(CProblem aProblem) {

  std::unordered_set<int> FSet, SSet;
  for (int i=0; i<4; i++) {
    FSet.insert(aProblem.N[0][i][aProblem.F-1]);
    SSet.insert(aProblem.N[1][i][aProblem.S-1]);
  }
  int matches = 0;
  int R;
  for (const auto& N : FSet) {
    if (SSet.find(N)!=SSet.end()) {
      matches++;
      R = N;
    }
  }
  CResult result;
  std::stringstream ss;
  if (matches==1) {
    ss << R;
  }
  if (matches==0) {
    ss << "Volunteer cheated!";
  }
  if (matches>1) {
    ss << "Bad magician!";
  }
  result.S = ss.str();
  return result;
}


int main(int argc, char* argv[]) {
  //const std::string KFileName = "test.txt";
  const std::string KFileName = "A-small-attempt0.in";
  //const std::string KFileName = "B-large-practice.in";

  std::ifstream ifs(KFileName);
  assert(ifs);


  u32 N;
  ifs >> N;
  std::string D;
  std::getline(ifs, D);

  for (u32 i=0; i<N; i++) {
    CProblem problem;
    ifs >> problem.F;

    for (int j=0; j<4; j++) {
      for (int k=0; k<4; k++) {
            ifs >> problem.N[0][k][j];
      }
    }

    ifs >> problem.S;

    for (int j=0; j<4; j++) {
      for (int k=0; k<4; k++) {
            ifs >> problem.N[1][k][j];
      }
    }

    std::cerr << "Solving Problem " << i << "\n";
    const CResult result = Solve(problem);
    std::cout << "Case #" << i+1 << ": ";
    std::cout << result.S << "\n";

    //std::cout << result.A << " " << result.B << "\n";
  }
}
