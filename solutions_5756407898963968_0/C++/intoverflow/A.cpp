#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
std::ios_base::sync_with_stdio(0);
int T;
cin>>T;
	for (int ct=1;ct<=T;ct++)
	{
	int r1;
	cin>>r1;
	bool *l=new bool[100]();
		for (int ct2=1;ct2<=4;ct2++)
		{
		int c;
			if(ct2==r1)
			{
			for (int ct3=1;ct3<=4;ct3++){cin>>c;l[c]=true;}
			}
			else
			cin>>c>>c>>c>>c;
		}
	int r2;
	cin>>r2;
	int count=0;
	int r;
		for (int ct2=1;ct2<=4;ct2++)
		{
		int c;
			if(ct2==r2)
			{
				for (int ct3=1;ct3<=4;ct3++)
				{
				cin>>c;
					if (l[c]==true){count++;r=c;}
				}
			}
			else
			cin>>c>>c>>c>>c;
		}
		if (count==0) printf("Case #%d: Volunteer cheated!\n",ct);
		else if (count==1) printf("Case #%d: %d\n",ct,r);
		else printf("Case #%d: Bad magician!\n",ct);
	}
}
