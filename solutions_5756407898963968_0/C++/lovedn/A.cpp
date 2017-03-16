//UESTC_L3

#include <stdexcept>
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <exception>
#include <memory>
#include <locale>
#include <sstream>
#include <set>
#include <list>
#include <bitset>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <string>
#include <utility>
#include <cctype>
#include <climits>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <deque>
#include <cstdlib>
#include <stack>
#include <iterator>
#include <functional>
#include <complex>
#include <valarray>
using namespace std;

int init[4][4];
int final[4][4];

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.out","w",stdout);
	int test;
	scanf("%d",&test);
	int ct=0;
	while(test--)
	{
		int a;
		scanf("%d",&a);
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				scanf("%d",&init[i][j]);
			}
		}
		int b;
		scanf("%d",&b);
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				scanf("%d",&final[i][j]);
			}
		}
		
		a--;b--;
		int num=-1,tot=0;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(init[a][i]==final[b][j]){
					num=init[a][i];
					tot++;
					break;
				}
			}
		}
		printf("Case #%d: ",++ct);
		if(0==tot)printf("Volunteer cheated!\n");
		else if(tot>1)printf("Bad magician!\n");
		else printf("%d\n",num);
	}
	return 0;
}