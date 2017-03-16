#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int
get_result(const int _N);

int
recursion();

int main(int argc, char *argv[])
{
  int case_amount = 0;
  cin >> case_amount;
    
  for (int i = 0; i < case_amount; ++i)
  {
    int N = 0;
    cin >> N;

    const int result = get_result(N);
    if (-1 == result)
      cout << "Case #" << 1 + i << ": Fegla Won" << endl;
    else
      cout << "Case #" << 1 + i << ": " << result << endl;
  }

  return 0;
}

int
get_result(const int _N)
{
  string first_line = "";
  cin >> first_line;

  vector<vector<int> > matrix(_N, vector<int>());
  vector<char> category;

  char c = first_line[0];
  int index = 0;
  int pre = 0;

  while (index < first_line.length())
  {
    category.push_back(first_line[index]);
    index = first_line.find_first_not_of(c, index);
    if (-1 == index)
      matrix[0].push_back(first_line.length() - pre);
    else
      matrix[0].push_back(index - pre);
    pre = index;
    c = first_line[index];
  }

  for (int j = 1; j < _N; ++j)
  {
    string line;
    cin >> line;

    char c = line[0];
    size_t index = 0;
    size_t pre = 0;

    int cat = 0;
    while (index < line.length())
    {
      if (cat == category.size())
        return -1;
      if (c != category[cat])
        return -1;
          
      index = line.find_first_not_of(c, index);
      if (string::npos == index)
        matrix[j].push_back(line.length() - pre);
      else
        matrix[j].push_back(index - pre);
      pre = index;
      c = line[index];
      cat++;
    }

    if (cat != category.size())
      return -1;
  }

  int changes = 0;
  for (int i = 0; i < category.size(); ++i)
  {
    int average = 0;
    for (int j = 0; j < _N; ++j)
      average += matrix[j][i];
    average = average / _N;

    for (int j = 0; j < _N; ++j)
      changes += abs(matrix[j][i] - average);
  }
  
  return changes;
}

int
recursion()
{
  return 0;
}
