#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

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
  std::vector<std::string> strings;
};

struct CResult {
  int S;
};

std::string makeSC(std::string aS) {
  std::string rtn;
  rtn += aS[0];
  for (uint i=1; i<aS.length(); i++) {
    if (aS[i]!=aS[i-1])
      rtn += aS[i];
  }
  return rtn;
}

int cnt(const std::string aS) {
  if (aS=="")
    return 0;
  int cnt = 1;
  for (uint i = 1; i < aS.length(); ++i) {
    cnt += (aS[i]==aS[0]);
    if(aS[i]!=aS[0])
      return cnt;
  }
  return cnt;
}

CResult Solve(CProblem aProblem) {
  CResult rtn;

  std::string canonS = makeSC(aProblem.strings[0]);
  for (uint i = 0; i < aProblem.strings.size(); ++i) {
    std::string cS = makeSC(aProblem.strings[i]);
    if (cS != canonS) {
      rtn.S  = -1;
      return rtn;
    }
  }
  bool done = 0;
  int overallSum = 0;
  while (!done) {
    done = 1;
    std::vector<int> len(aProblem.strings.size());
    for (uint i=0; i<aProblem.strings.size(); i++) {
      len[i] = cnt(aProblem.strings[i]);
//      std::cout << len[i] << " " << aProblem.strings[i] << "\n";
      aProblem.strings[i] = aProblem.strings[i].substr(len[i], 10000);
//      std::cout << aProblem.strings[i] << "\n";
      if (aProblem.strings[i].length())
        done = 0;
    }
    std::sort(len.begin(), len.end());
    int minEdit = 10000000;
    for (int j=1; j<=len.back(); j++) {
      int sum = 0;
      for (uint k=0; k<aProblem.strings.size(); k++)
        sum += std::abs(len[k]-j);
//      std::cout << j << " " << sum << "\n";
      if (sum<minEdit)
        minEdit = sum;
    }
    overallSum += minEdit;
  }

  rtn.S = overallSum;
  return rtn;
}


int main(int argc, char* argv[]) {
  //const std::string KFileName = "test.txt";
  const std::string KFileName = "A-small-attempt0.in";
  //const std::string KFileName = "B-large-practice.in";

  std::ifstream ifs(KFileName);
  assert(ifs);


  u32 T;
  ifs >> T;
  std::string D;
  std::getline(ifs, D);

  for (u32 i=0; i<T; i++) {
    CProblem problem;
    int N;
    ifs >> N;
    for (int j = 0; j < N; ++j) {
      std::string buff;
      ifs >> buff;
      problem.strings.push_back(buff);
    }

    std::cerr << "Solving Problem " << i << "\n";
    const CResult result = Solve(problem);
    std::cout << "Case #" << i+1 << ": ";
    if (result.S == -1)
      std::cout << "Fegla Won\n";
    else
      std::cout << result.S << "\n";
  }
}
