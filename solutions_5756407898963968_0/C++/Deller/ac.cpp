//source here
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <cstring>
#include <ctime>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <list>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <sstream>
//C++11
//#include <array>
//#include <forward_list>
//#include <unordered_map>
//#include <unordered_set>
using namespace std;
int a1[4][4],a2[4][4];
int r1,r2;
void read(int &r,int a[][4])
{
	scanf("%d",&r);
	--r;
	for (int i=0;i<4;++i)
		for (int j=0;j<4;++j)
			scanf("%d",&a[i][j]);
}
int main()
{
	freopen("out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;++t)
	{
		read(r1,a1);
		read(r2,a2);
		vector<int> v;
		for (int i=0;i<4;++i)
		{
			for (int j=0;j<4;++j)
				if (a1[r1][i]==a2[r2][j])
					v.push_back(a1[r1][i]);
		}
		printf("Case #%d: ",t);
		if (v.size()==1)
			printf("%d\n",v.front());
		else if (v.size()>1)
			printf("Bad magician!\n");
		else
			printf("Volunteer cheated!\n");
	}
	return 0;
}