/*
 * Google Code Jam
 * Vladimir Rutsky <vladimir@rutsky.org>
 */

#undef NDEBUG
#include <cassert>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <locale>
#include <ctime>
#include <iterator>
#include <algorithm>
#include <array>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;


int min_unhappiness(vector<vector<int>> & M, size_t R, size_t C, size_t N, size_t cur_r, size_t cur_c, size_t space_left)
{
  if (N == 0)
    return 0;

  size_t next_c = cur_c + 1;
  size_t next_r = cur_r;
  if (next_c == C)
  {
    next_c = 0;
    next_r = cur_r + 1;
  }

  if (next_r == R)
  {
    assert(cur_r == R - 1 && cur_c == C - 1);

    int res = 0;

    assert(N == 1);
    if (R >= 2)
      res += M[cur_r - 1][cur_c];

    if (C >= 2)
      res += M[cur_r][cur_c - 1];

    return res;
  }

  M[cur_r][cur_c] = 1;
  int res = min_unhappiness(M, R, C, N - 1, next_r, next_c, space_left - 1);
  if (cur_r >= 1)
    res += M[cur_r - 1][cur_c];

  if (cur_c >= 1)
    res += M[cur_r][cur_c - 1];

  M[cur_r][cur_c] = 0;
  if (space_left > N)
  {
    int res0 = min_unhappiness(M, R, C, N, next_r, next_c, space_left - 1);

    res = min(res, res0);
  }

  return res;
}


string solve(size_t R, size_t C, size_t N)
{
  vector<vector<int>> M(R, vector<int>(C, 0));

  int res = min_unhappiness(M, R, C, N, 0, 0, R * C);


  return to_string(res);
}

int main(int argc, char *argv[])
{
  if (true)
  {
    std::tm local_tm;
    // "Mmm dd yyyy hh:mm:ss"
    char const * compile_time_string = __DATE__ " " __TIME__;
    std::time_t const cur_time = std::time(nullptr);

    /*
    std::istringstream ss(compile_time_string);
    ss.imbue(std::locale::classic());
    ss >> std::get_time(&local_tm, "%b %d %Y %H:%M:%S");
    */

    std::memcpy(&local_tm, localtime(&cur_time), sizeof(local_tm));
    strptime(compile_time_string, "%b %d %Y %H:%M:%S", &local_tm);

    std::time_t const compile_time = mktime(&local_tm);

    double const diff = difftime(cur_time, compile_time);

    std::cerr << "DEBUG: Compiled " << diff << " seconds ago" << (diff > 60 ? "!!!" : ".") << "\n";
  }

  //FILE * res = std::freopen("small.in", "rt", stdin);
  //FILE * res = std::freopen("A-small-attempt0.in", "rt", stdin);
  //FILE * res = std::freopen("A-large.in", "rt", stdin);
  //assert(res);

  if (argc > 2)
  {
    std::cerr
      << "Usage:\n"
      << "    " << argv[0] << " [input.in]";
  }
  else if (argc == 2)
  {
    std::string const suffix = ".in";
    std::string const input_path = argv[1];
    assert(input_path.size() > suffix.size());
    assert(input_path.substr(input_path.length() - suffix.size()) == suffix);

    std::string const file_path = input_path.substr(0, input_path.length() - suffix.size());

    std::string const output_path = file_path + ".out";

    std::FILE * in_file = std::freopen(input_path.c_str(), "rt", stdin);
    assert(in_file);

    std::FILE * out_file = std::freopen(output_path.c_str(), "wt", stdout);
    assert(out_file);

    std::cerr << "DEBUG: Reading from '" << input_path << "', writing to '" << output_path << "'\n";
  }
  else
  {
    std::cerr << "DEBUG: Reading from STDOUT, writing to STDOUT\n";
  }

  size_t T = 0;
  cin >> T;

  for (size_t ci = 1; ci <= T; ++ci)
  {
    size_t R, C, N;
    cin >> R >> C >> N;

    cout << "Case #" << ci << ": " << solve(R, C, N) << "\n";
  }
}
