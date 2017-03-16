#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <queue>
#include <stdexcept>
using namespace std;
int ans;
int Solve(int row1,vector<int>& matrix1,int row2,vector<int>& matrix2)
{
	int temp1;
	int temp2;
	int count=0;
	int identicalnum;
	int com1;
	int com2;
	temp1 = 4*(row1-1);
	temp2 = 4*(row2-1);
	com1 = matrix1[temp1];
	for(int i=0;i<4;i++)
	{
		com1 = matrix1[temp1+i];
		for(int j=0;j<4;j++)
		{
			com2 = matrix2[temp2+j];
			if(com2==com1)	
			{
				count++;
				identicalnum = com2;
			}
		}
	}
	if(count==0)
		return 17;
	else if(count>1)
		return 0;
	else
		return identicalnum;
	
}
void main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	//freopen("1.txt", "r", stdin);
	freopen("A-small-practice0.out", "w", stdout);
	//freopen("2.txt", "w", stdout);
	int i,j;
	int Numcase;
	bool res;
	int firstanswer;
	int secondanswer;
	int p1;
	int p2;
	cin>>Numcase;
	for(int test=1;test<=Numcase;test++)
	{
		cout<<"Case #"<<test<<": ";
		cin>>firstanswer;
		vector<int> firstmagic;
		vector<int> secondmagic;
		for(int i=0;i<16;i++)
		{
			cin>>p1;
			firstmagic.push_back(p1);
		}
		cin>>secondanswer;
		for(int i=0;i<16;i++)
		{
			cin>>p2;
			secondmagic.push_back(p2);
		}
		ans=Solve(firstanswer,firstmagic,secondanswer,secondmagic);
		if (ans==0)
			cout<<"Bad magician!"<<endl;
		else if(ans==17) 
			cout<<"Volunteer cheated!"<<endl;
		else
			cout<<ans<<endl;
	}
	fclose(stdout);
}