#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>


typedef std::vector<std::pair<char, int>> Word;

Word normalize(std::string const &w)
{
  Word r;
  auto current_pair = std::make_pair('\0', 0);
  for ( char c: w )
  {
    if ( c != current_pair.first )
    {
      if ( current_pair.second > 0 )
        r.push_back(current_pair);
      current_pair.first = c;
      current_pair.second = 1;
    }
    else
      current_pair.second++;
  }
  if ( current_pair.second > 0 )
    r.push_back(current_pair);
  return r;
}


bool compat(Word const &w1, Word const &w2)
{
  if ( w1.size() != w2.size() )
    return false;
  for ( size_t i = 0; i != w1.size(); ++i )
    if ( w1[i].first != w2[i].first )
      return false;
  return true;
}


typedef std::vector<Word> Words;
bool read_case(Words &res)
{
  int N;
  std::cin >> N;
  res.clear();
  res.reserve(N);
  bool bad = false;
  for ( int i = 0; i < N; ++i )
  {
    std::string w;
    std::cin >> w;
    Word ww = normalize(w);
    if ( not res.empty() )
      if ( not compat(ww, res.back()) )
        bad = true;
    res.push_back(ww);
  }
  return not bad;
}


int score(Words const &res)
{
  int nl = res[0].size();
  int score = 0;
  for ( int i = 0; i < nl; ++i )
  {
    int m = res[0][i].second;
    int M = m;
    for ( size_t j = 1; j < res.size(); ++j )
    {
      m = std::min(m, res[j][i].second);
      M = std::max(M, res[j][i].second);
    }
    int bs = std::numeric_limits<int>::max();
    for ( int b = m; b <= M; ++b )
    {
      int ss = 0;
      for ( auto &w: res )
        ss += abs(w[i].second - b);
      bs = std::min(bs, ss);
    }
    score += bs;
  }
  return score;
}


int main()
{
  int T;
  std::cin >> T;
  for ( int t = 1; t <= T; ++t )
  {
    Words res;
    if ( not read_case(res) )
      std::cout << "Case #" << t << ": Fegla Won\n";
    else
      std::cout << "Case #" << t << ": " << score(res) << '\n';
  }
  return 0;
}
