#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int occ[16][16];

int unhap[1<<16];
int cbit[1<<16];
int R,C,N;

int calcUnhap(int p)
{
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
			occ[i][j] = p&(1<<(i*C+j));
	unhap[p] = 0;
	for(int i=0;i<R;i++)
		for(int j=1;j<C;j++)
			if(occ[i][j]&&occ[i][j-1])
				unhap[p]++;
	for(int i=1;i<R;i++)
		for(int j=0;j<C;j++)
			if(occ[i][j]&&occ[i-1][j])
				unhap[p]++;
	return unhap[p];
}


int test()
{
	cbit[0] = 0;
	for(int i=1;i<(1<<(R*C));i++)
		cbit[i] = 1+cbit[i - (i & -i)];
	int best = 1000000;
	for(int i=0;i<(1<<(R*C));i++)
	{
		if(cbit[i] == N)
			best = min(best,calcUnhap(i));
	}
	return best;

}

int main()
{
	freopen("C:\\Users\\Dhruv\\Desktop\\Programs\\Cpp Files\\input.txt","r",stdin);
	freopen("C:\\Users\\Dhruv\\Desktop\\Programs\\Cpp Files\\output.txt","w",stdout);

	int T;
	int a,b,c;
	cin >> T;
	for(int i=0;i<T;i++)
	{
		cin >> R >> C >> N;
		cout << "Case #" << i+1 << ": " << test() << "\n";
	}
}