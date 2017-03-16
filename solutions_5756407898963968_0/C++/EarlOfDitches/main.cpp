//==================================
//==========   WARNING   ===========
//==================================
//===   Contains too many bugs   ===
//==================================

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <set>
#include <functional>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pr;
typedef pair<ll,ll> prl;

#define double long double

const ll mod7 = 1000000007;

#define NAME "A-small-attempt0"

int arr1[5][5];
int arr2[5][5];

int main()
{
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    freopen(NAME".in","r",stdin); freopen(NAME".out","w",stdout);

	int t;
    cin >> t;

	for(int Case=1;Case<=t;++Case)
	{
		int n1;
		cin >> n1;
		for(int i=1;i<=4;++i)
			for(int j=1;j<=4;++j)
				cin >> arr1[i][j];
		int n2;
		cin >> n2;
		for(int i=1;i<=4;++i)
			for(int j=1;j<=4;++j)
				cin >> arr2[i][j];
		cout << "Case #" << Case << ": ";
		set<int> f,s;
		for(int i=1;i<=4;++i)
		{
			f.insert(arr1[n1][i]);
		}
		for(int i=1;i<=4;++i)
		{
			if(f.find(arr2[n2][i])!=f.end())
				s.insert(arr2[n2][i]);
		}
		if(s.size()==1)
		{
			cout << *s.begin();
		}
		else if(s.size()>1)
		{
			cout << "Bad magician!";
		}
		else
			cout << "Volunteer cheated!";
		cout << endl;
	}

    return 0;
}