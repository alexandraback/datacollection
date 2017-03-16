
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <cassert>



using namespace std;
#pragma comment(linker, "/STACK:50000000")

typedef vector<int> vi; 
#define sz(a) int((a).size()) 
#define all(c) (c).begin(),(c).end() 

string problem_name = "A-small-attempt2(1)";

void init(){
  freopen((problem_name+".in").c_str(),"rt",stdin);
  freopen((problem_name+".out").c_str(),"wt",stdout);
}




int main()
{
	init();

	int tst;
	scanf("%d\n",&tst);

	for (int cas = 1; cas<=tst;cas++)
	{

		int n;
		scanf("%d",&n);
		vi cnt(n,0);
		int tot = 0;
		for (int i=0;i<n;i++) {
			scanf("%d",&cnt[i]);
			tot+=cnt[i];
		}
		printf("Case #%d:",cas);
		while (1)
		{
			if (tot==2)
			{
				string res = "";
				for (int i=0;i<n;i++)
					if (cnt[i])
						res+=string(1,'A'+i);			
				cout << " " << res << endl;
				break;
			} else
			{
				int mx = 0;
				for (int i=0;i<n;i++) {
					if (cnt[i]>mx) mx = cnt[i];
				}
				
				string res = "";
				for (int i=0;i<n;i++)
				{
					if (cnt[i]==mx)
					{
						if (sz(res)==2) break;
						if (sz(res)==0)
						{
							cnt[i]--;
							res+=string(1,'A'+i);
							tot--;
						} else
						if (tot!=2)
						{
							cnt[i]--;
							res+=string(1,'A'+i);
							tot--;						
						}

					}
				}
				
				cout << " " << res;			
			}		
		}
		
	
	}


	return 0;
}
