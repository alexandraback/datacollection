#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
void solve(int caseNum)
{
	
	int Len = 4;
	vector<int> number;
	int data[4]={0,0,0,0};
	int row;
	scanf("%d",&row);
	for (int i = 0; i < 4; i++)
	{
		scanf("%d %d %d %d",&data[0],&data[1],&data[2],&data[3]);
		if (row == i+1)
		{
			number.assign(data,data+4);
		}
	}
	scanf("%d",&row);
	for (int i = 0; i < 4; i++)
	{
		scanf("%d %d %d %d",&data[0],&data[1],&data[2],&data[3]);
		if (row == i+1)
		{
			for (int j = 0 ;j < 4; j++)
			{
				if (data[j]==number[0] || data[j]==number[1] || data[j]==number[2] || data[j]==number[3])
				{
					number.push_back(data[j]);
				}
			}
		}
	}
	if (number.size()==5)
	{
		printf("Case #%d: %d\n",caseNum,number[4]);
	}
	else if (number.size()>5)
	{
		printf("Case #%d: Bad magician!\n",caseNum);
	}
	else
	{
		
		printf("Case #%d: Volunteer cheated!\n",caseNum);		
		
	}

}
int main()
{
	int caseNum = 0;
	scanf("%d",&caseNum);
	for (int i = 0; i < caseNum; i ++)
	{
		solve(i+1);
	}
	return 0;
}