#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL inf = 1e16;
LL m[1005];
LL N,B;

LL fao(LL cost)
{
	LL sum = 0, i;
	for (i = 0; i < B; i++)
	{
		sum += (cost + m[i] - 1) / m[i];
	}
	return sum;
}
int main()
{
	int i, j, k,Cas=1,T;
	ifstream cin("B-large (1).in");
	ofstream cout("000.out"); 
	cin >> T;
	while (T--)
	{
		cin >> B >> N;
		for (i = 0; i < B; i++)
			cin >> m[i];

		LL L = 0, R = inf,MID,t;
		while (L < R)
		{
			MID = (L + R + 1) >> 1;
			if (fao(MID) >= N)R = MID-1;
			else L = MID;
		}
		t = fao(L);
		for (i = 0; i < B; i++)
		{
			if (L%m[i]==0)
			{
				t++;
				if (t == N)break;
			}
		}
		cout << "Case #" << Cas++ << ": " << " "<<i+1<< endl;
	}
}