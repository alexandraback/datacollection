#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
int ntc;
	cin>>ntc;
	for(int tc=1;tc<=ntc;tc++)
	{int flag=1;
	vector<char> vec;
vector<char> vec2;
vector<int> v[101];
char ch[1000][1000];
		printf("Case #%d: ",tc);
		int n;
		cin>>n;
		for(int i=0;i<n;i++)scanf("%s",&ch[i]);
		vec.push_back(ch[0][0]);
		for(int i=1;ch[0][i]!='\0';i++)
		if(ch[0][i]!=vec[vec.size()-1]) vec.push_back(ch[0][i]);
		
		
		for(int j=1;j<n;j++)
		{ vec2.clear();
		//printf("here");
		vec2.push_back(ch[j][0]);
		for(int i=1;ch[j][i]!='\0';i++)
		{
		
		if(ch[j][i]!=vec2[vec2.size()-1]) vec2.push_back(ch[j][i]);
	//	printf("zzz\n");
		} 
		if(vec2!=vec) 
			{
				flag=0;
				break;
			}	
			
		}
		if(flag==0) printf("Fegla Won\n");
		else
		{  //printf("hhhh\n");
			
			for(int i=0;i<n;i++)
			{
				char c=ch[i][0];
				int count =1;
				for(int j=1;ch[i][j]!='\0';j++)
				if(c!=ch[i][j]) 
					{
					v[i].push_back(count); count =1;c=ch[i][j];
					}
				else count++;	
				
				v[i].push_back(count);
			} //printf("ggggggg\n");
			long long ans=0LL;
			
			//cout<<" line "<<v[0][0]<<"  "<<v[0][1]<<endl;
			
			for(int k=0;k<vec.size();k++)
			{
			int aa=10000000;
			for(int j=1;j<101;j++)
			{
			int an=0;
			for(int i=0;i<n;i++)
			{
			if(v[i][k]>j) an=an+v[i][k]-j;
			else an=an+j-v[i][k];	
			}
			//printf(" an j=%d  %d\n",j,an);
			if(an<aa) aa=an;
			}
			ans=ans+aa;
			}
		printf("%d\n",ans);
		for(int i=0;i<101;i++) v[i].clear();
		vec.clear();vec2.clear();
		}
	}
}
