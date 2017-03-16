#pragma comment(linker, "/STACK:65000000")
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cmath>
#include<complex>
#include<ctime>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<int> vi;
typedef vi::iterator vit;
typedef set<ll> si;
typedef si::iterator sit;
typedef vector<pii> vpi;

#define sq(x) ((x)*(x))
#define all(x) (x).begin(),(x).end()
#define cl(x) memset(x,0,sizeof(x))
//#define LL "%I64d"
#define RLL(x) scanf(LL,&(x))

string mas[111];

vi nums[111];
string lst[111];


int proc()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
    {
        nums[i].clear();
        lst[i] = "";
        cin>>mas[i];
        char cur = mas[i][0];
        int num = 1;
        for(int j = 1; j < mas[i].size(); ++j)
            if(cur != mas[i][j])
            {
                lst[i].push_back(cur);
                nums[i].push_back(num);
                num = 1;
                cur = mas[i][j];
            }
            else
                ++num;
        lst[i].push_back(cur);
        nums[i].push_back(num);
    }
    for(int i = 1; i < n; ++i)
        if(lst[i] != lst[i-1])
            return -1;
    int answ = 0;
    vi tmp[111];
    for(int i = 0; i < lst[0].size(); ++i)
        for(int j = 0; j < n; ++j)
            tmp[i].push_back(nums[j][i]);
    for(int i = 0; i < lst[0].size(); ++i)
    {
        sort(tmp[i].begin(), tmp[i].end());
        int k = n/2;
        for(int j = 0; j < n; ++j)
            answ += abs(tmp[i][j] - tmp[i][k]);
    }
    return answ;
}

void test(int T)
{
    int answ = proc();
    if(answ == -1)
        printf("Case #%d: Fegla Won\n", T);
    else
        printf("Case #%d: %d\n", T, answ);
}

int main(int argc, const char * argv[])
{
    
    freopen("/Users/olpet/Downloads/a.in", "r", stdin);
    freopen("/Users/olpet/Downloads/a.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t)
        test(t+1);
    return 0;
}