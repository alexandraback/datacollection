#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;
static const double EPS = 1e-9;
typedef long long ll;
typedef long long LL;
typedef pair<int,int>            PI;
typedef map<PI, int> MPI;
typedef vector<int>	VI;
typedef vector< vector<int> >	VII;
typedef unsigned int UINT32;
typedef unsigned short UINT16;
typedef unsigned char UINT8;
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define PB push_back
#define MP make_pair
typedef vector<string>	VS;

int get_max_pos(VI vi)
{
  int N = vi.size();
  int mp =N;
  int max_num = 0;
  for(int n = 0 ; n < N ; n++){
    int tmp = vi[n];
    if(tmp>max_num){
      max_num = tmp;
      mp = n;
    }
  }
  return mp;
}

int main(void)
{
  int T,t;
  int ret;
  cin>>T;
  for(t=1;t<=T;t++)
  {
    int N;
    cin>>N;
    VI vi;
    VI ans;
    int sum = 0;
    for(int n=0;n<N;n++){
      int tmp;
      cin>>tmp;
      vi.push_back(tmp);
      sum += tmp;
    }
    int tmp_sum = sum;
    while(tmp_sum>0){
      int mp = get_max_pos(vi);
//cout<<mp<<endl;
      ans.push_back(mp);
      vi[mp]--;
      tmp_sum--;
    }
    cout<<"Case #"<<t<<": ";
    int index = 0;
    while(sum>0){
      char c;
      c = 'A' + ans[index];
      cout << c;
      index++;
      sum--;
      if(sum!=2 && sum != 0){
        c = 'A' + ans[index];
        cout << c;
        index++;
        sum--;
      }
      cout<<" ";
    }
    cout<<endl;
  }
  return 0;
}

