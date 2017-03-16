#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <string.h>

#define SZ(c) c.size()
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define SORT(a) sort(a.begin(),a.end())
#define tests int test; scanf("%d",&test); while(test--)
#define dbg(n) cout<<#n<<" = "<<n<<endl;

using namespace std;

int strToInt(string str) {int ans; stringstream s; s<<str; s>>ans; return ans;}
string intToStr(int n) {string str; stringstream s; s<<n; s>>str; return str;}
int MAX(int a,int b) {if(a >b) return a; return b;}
int MIN(int a,int b) {if(a <b) return a; return b;}
int ABS(int a) {if(a >0) return a; return -a;}

vector<pair<char, int> > func(string first)
{
    int lenOne = first.size();
    vector<pair<char, int> >aaa;
    int index =0;
    char current = first[0];
    aaa.push_back(make_pair(current, 0));
    for(int i=0; i<lenOne; i++)
    {
        if(current == first[i])
        {
            aaa[index].second++;
        }
        else
        {
            current = first[i];
            index++;
            aaa.push_back(make_pair(current,0));
        }
    }
    return aaa;

}

bool possible(vector<pair<char, int> > first, vector<pair<char, int> > second)
{
  int one = first.size(), two = second.size();
  if(one != two)
    return false;
  for(int i=0; i<one; i++)
  {
      if(first[i].first != second[i].first)
        return false;

  }
  return true;
}
int solve(vector<pair<char, int> > first, vector<pair<char, int> > second)
{
    int len = first.size();
    int ans =0;
    for(int i=0; i<len; i++)
    {
        ans += ABS(first[i].second - second[i].second);
    }
    return ans;
}

int solve(string first, string second)
{
    int lenOne = first.size(), lenTwo= second.size();
}

int main()
{
    freopen("repeaterInput.txt", "r", stdin);
    freopen("repeaterOutput.txt", "w", stdout);
    int test;
    scanf("%d",&test);

    for(int running=1; running<=test; running++)
    {
        string a,b;
        int n;
        cin>>n;
        cin>>a>>b;
        if(possible(func(a),func(b)))
        {
            int ans = solve(func(a),func(b));
            //ans = MIN(ans, solve(func(a),func(b));
            printf("Case #%d: %d\n", running,ans);
        }
        else
        {
            printf("Case #%d: Fegla Won\n", running);
        }
    }

    return 0;
}
