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
//int solve(vector<pair<char, int> > first, vector<pair<char, int> > second)
//{
//    int len = first.size();
//    int ans =0;
//    for(int i=0; i<len; i++)
//    {
//        ans += ABS(first[i].second - second[i].second);
//    }
//    return ans;
//}



int answer (vector<int> arr)
{
    int len = arr.size();
    int finalAnswer = 100000007;
    for(int number=0; number <= 150; number++ )
    {
            int ans =0;
            for(int i=0; i<len; i++)
            {
                ans += ABS(number - arr[i]);
            }
            finalAnswer = MIN(finalAnswer, ans);
    }
    return finalAnswer;
}
int solve(vector<vector <pair <char, int> > > arr)
{
    int len = arr.size();
    int col = arr[0].size();

    int ans =0;
    for(int i=0; i<col; i++)
    {
        vector<int> amit;
        for(int row =0; row<len; row++)
        {
           // amit.clear();
            amit.push_back(arr[row][i].second);

        }
        ans += answer(amit);
    }
    return ans;
}

int main()
{
    freopen("repeaterLargeInput.txt", "r", stdin);
    freopen("repeaterOutputLarge.txt", "w", stdout);
    int test;
    scanf("%d",&test);

    for(int running=1; running<=test; running++)
    {
        int n;
        cin>>n;
        vector<string> input(n);
        vector<vector< pair<char, int> > > arr(n);
        for(int i=0; i<n; i++)
        {
            cin>>input[i];
            arr[i] = func(input[i]);
        }

        bool notvalid = false;
        for(int i=0; i<n; i++)
        {
            notvalid = false;
            for(int j=(i+1); j<n ; j++)
            {
                notvalid = false;
                if( !possible(arr[i], arr[j]))
                {
                    notvalid = true;
                    break;
                }
            }
            if(notvalid)
                break;
        }
        if(notvalid)
        {
            printf("Case #%d: Fegla Won\n", running);
        }
        else
        {
            int ans = solve(arr);
             printf("Case #%d: %d\n", running,ans);
        }

    }

    return 0;
}
