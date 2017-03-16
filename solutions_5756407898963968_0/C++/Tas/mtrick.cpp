#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>

using namespace std;


vector< set<int> > read_matrix()
{
  vector< set<int> > matrix;
  
  for (int lineNo=0; lineNo < 4; lineNo++)
  {
    set<int> line;
    for (int colNo=0; colNo<4; colNo++)
    {
      int tmp;
      cin >> tmp;
      line.insert(tmp);
    }
    matrix.push_back(line);
  }
  
  return matrix;
}

void proc_case()
{
  int sel1, sel2;
  
  cin >> sel1;
  auto m1 = read_matrix();
  cin >> sel2;
  auto m2 = read_matrix();
  
  vector<int> common;
  set<int>& l1 = m1[sel1-1];
  set<int>& l2 = m2[sel2-1];
  
  set_intersection( l1.begin(), l1.end(), l2.begin(), l2.end(), back_inserter(common) );
  //cout << sel1 << " " << sel2 << endl;
  //cout << common.size() << endl;
  
  if (common.size() == 1)
    cout << common.front() << endl;
  else if (common.empty())
    cout << "Volunteer cheated!" << endl;
  else
    cout << "Bad magician!" << endl;
}

int main()
{
  int nCases;
  cin >> nCases;
  //scout << nCases << endl;
  for (int caseNo=0; caseNo < nCases; caseNo++)
  {
      cout << "Case #" << caseNo+1 << ": ";
      proc_case();
  }
}





