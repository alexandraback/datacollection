#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<cmath>
#include<climits>

using namespace std;

int Solve(vector<string> s, int tc)
{
//  cout << "input : " << s[0] << endl;
//  cout << "input : " << s[1] << endl;

  int n = s.size();

  int result = 0;

  int c[101][101];
  for(int i=0; i<101; i++) for(int j=0; j<101; j++) c[i][j]=0;

  string seq = s[0];
  seq.erase(1);
 // cout << "seq 1st : " << seq << endl;

  // construct std seq
  c[0][0]=1;
  char last_char = s[0][0];
  //cout << "All initialized!" << endl;
  for(int k=1; k<s[0].length(); k++)
  {
    int index_in_seq = seq.length() - 1;
    if (s[0][k] == last_char)
    {
      c[0][index_in_seq]++;
    }
    else
    {
      seq = seq + s[0][k];
      c[0][index_in_seq+1] = 1;
      last_char = s[0][k];
    }
  }
  //cout << "Std Seq : " << seq << endl;

  // check all the other seq
  for(int i=1; i<s.size(); i++)
  {
    string str = s[i];
    string tmp = str;
    string cseq = tmp.erase(1);
    c[i][0]=1;
    char last_char = str[0];
    for(int k=1; k<str.length(); k++)
    {
      int index_in_seq = cseq.length() - 1;
      if (str[k] == last_char)
      {
        c[i][index_in_seq]++;
      }
      else
      {
        cseq = cseq + str[k];
        c[i][index_in_seq+1]=1;
        last_char = str[k];
      }
    }
    if (cseq != seq) return -1;
  }
  
  if (tc == 19)
  {
    cout << seq << endl;
    for(int i=0; i<n; i++)
    {
      for(int j=0; j<seq.size(); j++) cout << c[i][j] << " ";
      cout << endl;
    }
  }

  // check counts
  result = 0;

  for(int i=0; i<seq.size(); i++)
  {

    int min_cost = INT_MAX;
    
    // choose string c[k][i] as std
    for(int k=0; k<n; k++)
    {
      int cost = 0;
      for(int j=0; j<n; j++)
        cost += abs(c[j][i]- c[k][i]);

     // cout << "computed cost : " << cost << endl;

      min_cost = min(min_cost, cost);
    }    

    //cout << "choosing min : " << min_cost << endl;

    result += min_cost;
  }

  return result;
}

int main()
{
  ifstream f("A-small-attempt1.in");
  ofstream of("A-small-attempt1.out");
  
  int test_cases = 0;
  f >> test_cases;

  int n;

  for(int tc=0; tc<test_cases; tc++)
  {
    // read from if
    f >> n;
    string tmp;
    vector<string> s;
    for(int i=0; i<n; i++)
    {
      f >> tmp;
      s.push_back(tmp);
    }

    // solve
    int sol = Solve(s, tc+1);
/*

t ccc eee rrrrrrrr iiiiiiiiiii n cc y mmmmmmmmmm rrrrrrrrrrr g sss h ssss
tttt cccccccc e rrrrrrrrrrr iii nnnnnn cccccc y mmmmm r g ssssssssssssssssssssss hh s



3 + 5 + 2 + 3 + 8 + 5 + 4 + 10 + 10 + 19 + 1 + 3
10 + 11 + 9 + 20 + 22
10 + 20 + 20 + 22
*/
    // write to of
    of << "Case #" << tc+1 << ": ";
    
//    of << endl;
//    of << s[0] << endl;
//    of << s[1] << endl;

    if (sol == -1) of << "Fegla Won";
    else of << sol;
    of << endl;


//    of << endl;
  }

  f.close();
  of.close();
}
