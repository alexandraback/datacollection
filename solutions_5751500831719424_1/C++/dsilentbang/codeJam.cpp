#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d",&t);
	for(int testCase=1;testCase<=t;testCase++)
		{
			vector<string> arr;
			string temp;
			int n;
			scanf("%d",&n);
			for(int i=0;i<n;i++)
			{
				cin>>temp;
				arr.push_back(temp);
			}
			vector< vector<pair<char,int> > > counterArr(n);
			for(int i=0;i<n;i++)
			{
				counterArr[i].push_back(make_pair(arr[i][0],1));
				for(int j=1;j<arr[i].size();j++)
				{
					if(counterArr[i][counterArr[i].size()-1].first==arr[i][j])
						counterArr[i][counterArr[i].size()-1].second++;
					else
					{
						counterArr[i].push_back(make_pair(arr[i][j],1));
					}
				
				}
			}
	// 		for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<counterArr[i].size();j++)
	// 	printf("%d-%d ",counterArr[i][j].first,counterArr[i][j].second);
	// printf("\n");
	// }
			bool flag=true;
			for(int i=1;i<n;i++)
			{
				if(counterArr[0].size()!=counterArr[i].size())
				{
					flag=false;
					break;
				}
				for(int j=0;j<counterArr[0].size();j++)
				{
					if(counterArr[0][j].first!=counterArr[i][j].first)
					{
						flag=false;
						break;
					}
				}
			}
			int counter=0;
			if(flag)
			{
				for(int j=0;j<counterArr[0].size();j++)
				{
					vector<int > tempArr;
					for(int i=0;i<n;i++)
					{
						tempArr.push_back(counterArr[i][j].second);
					}
					sort(tempArr.begin(),tempArr.end());
					for(int i=0;i<n;i++)
						counter=counter+abs(tempArr[n/2]-tempArr[i]);
				}
				
			}
			if(!flag)
			printf("Case #%d: Fegla Won\n",testCase);
			else
				printf("Case #%d: %d\n",testCase,counter);
		}
		return 0;
}