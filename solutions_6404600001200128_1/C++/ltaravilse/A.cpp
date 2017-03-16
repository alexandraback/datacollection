#include<algorithm>
#include<cstdio>
#include<iostream>
#include<map>
#include<set>
#include<sstream>
#include<queue>
#include<vector>

using namespace std;

#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

int main()
{
	int casos;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	cin >> casos;
	for(int casito = 1; casito <= casos; casito++)
    {
        int n;
        cin >> n;
        vector<int> vec(n);
        forn(i,n)
            cin >> vec[i];
        long long a=0,b=0,c=0;
        forn(i,n-1)
        {
            a += max(0,vec[i]-vec[i+1]);
            b = max(b,(long long)(vec[i]-vec[i+1]));
        }
        forn(i,n-1)
        {
            c += min(b,(long long)vec[i]);
        }
        cout << "Case #"<<casito<<": "<< a <<" "<< c << endl;
    }
}
