#include <vector>
#include <map>
#include <unordered_set>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

int matrix1[4][4];
int matrix2[4][4];
int index1;
int index2;
#define real int


int checkMatrix()
{
	//0 bad  -1 cheat other getNumber
	index1--;
	index2--;
	int find=0;
	int count=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(matrix1[index1][i]==matrix2[index2][j])
			{
				find=matrix1[index1][i];
				count++;
			}
		}
	}
	if(count==0) return -1;
	if(count==1) return find;
	else return 0;
}

void main()
{
	freopen("11.in","r",stdin);
	freopen("11.out","w",stdout);

	int times;
	scanf("%d",&times);
	for(int time=1;time<=times;time++)
	{
		scanf("%d",&index1);
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				scanf("%d",&matrix1[i][j]);
			}
		}
		scanf("%d",&index2);
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				scanf("%d",&matrix2[i][j]);
			}
		}
		printf("Case #%d: ",time);
		int k=checkMatrix();
		switch(k)
		{
		case -1:
			printf("Volunteer cheated!\n");
			break;
		case 0:
			printf("Bad magician!\n");
			break;
		default:
			printf("%d\n",k);
		}
	}
}