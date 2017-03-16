#include <vector>
#include <map>
#include <unordered_set>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

#define real int

real N,L;

vector<string> input;

string common;

string smallestString;

string getSingleSmallestString(string& input)
{
	string ret="";
	char lastChar='\0';
	for(int i=0;i<input.length();i++)
	{
		if(input[i]!=lastChar)
		{
			lastChar=input[i];
			ret+=lastChar;
		}
	}
	return ret;
}


bool getSmallestString()
{
	string ret=getSingleSmallestString(input[0]);
	for(int i=1;i<input.size();i++)
	{
		if(ret!=getSingleSmallestString(input[i]))
		{
			return false;
		}
	}
	smallestString=ret;
	return true;
}



int getTimes()
{
	if(!getSmallestString()) return -1;
	int longest=0;
	int smallest=150;
	for(int i=0;i<input.size();i++)
	{
		if(input[i].length()>longest) longest=input[i].length();
		if(input[i].length()<smallest) smallest=input[i].length();
	}
	common=smallestString;
	int times=0;
	int index=0;
	vector<int> strIndex;
	strIndex.resize(input.size(),1);
	while(true)
	{
		int leftCount=1;
		int currentCount=0;
		char commonChar='0';
		bool empty=false;
		bool allSame=true;
		for(int i=0;i<input.size();i++)
		{
			if(strIndex[i]>=input[i].length())
			{
				empty=true;
				break;
			}
		}
		if(empty)
		{
			while(true)
			{
				bool allEmpty=true;
				int emptyCount=0;
				for(int i=0;i<input.size();i++)
				{
					if(strIndex[i]<input[i].length()) allEmpty=false;
					else emptyCount++;
					strIndex[i]++;
				}
				if(allEmpty) break;

				int leftCount=input.size()-emptyCount;
				times+=std::min(leftCount,emptyCount);
					
			}
			return times;
		}
		else
		{
			for(int i=0;i<input.size();i++)
			{
				if(commonChar=='0') commonChar=input[i][strIndex[i]];
				else
				{
					if(input[i][strIndex[i]]!=commonChar)
					{
						currentCount++;
						allSame=false;
					}
					else leftCount++;
				}
			}
			if(allSame)
			{
				if(commonChar!=common[index]) index++;
				for(int i=0;i<input.size();i++)
				{
					strIndex[i]++;
				}
			}
			else
			{
				if(currentCount<=leftCount)
				{
					times+=currentCount;
				}
				else
				{
					times+=leftCount;
				}
				for(int i=0;i<input.size();i++)
				{
					if(input[i][strIndex[i]]==common[index]) strIndex[i]++;
				}
			}
				
		}
	}
	
}

void main()
{
	freopen("11.in","r",stdin);
	freopen("11.out","w",stdout);
	
	int times;
	scanf("%d",&times);
	for(int time=1;time<=times;time++)
	{
		scanf("%d",&N);
		char s[150];
		input.clear();
		for(int i=0;i<N;i++)
		{
			scanf("%s",s);
			string str=s;
			input.push_back(str);
		}


		printf("Case #%d: ",time); 
		
		int k=getTimes();
		if(k>=0) printf("%d\n",k);
		else printf("Fegla Won\n");
	}
}