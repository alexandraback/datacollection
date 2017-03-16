#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>


using namespace std;


int t;
int n;
char str[200][200];
vector<char> mem[200];
int Count[200][200];

int counting[200];


int abs(int a)
{
	if(a < 0)
		return -a;
	return a;
}

int main()
{
	
	
	scanf("%d",&t);
	for(int k = 1 ; k <= t ; k++)
	{
		//init
		memset(Count, 0, sizeof(Count));
		for(int i = 0 ; i < 300 ; i++)
			mem[i].clear();
		
		
		//input
		scanf("%d",&n);
		for(int i = 0 ; i < n ; i++)
			scanf("%s",str[i]);
		
		
		//set mem
		for(int i = 0 ; i < n ; i++)
		{
			mem[i].push_back(str[i][0]);
			Count[i][0]++;
			for(int j = 1, m=0 ; str[i][j] != '\0' ; j++)
			{
				if(str[i][j] != str[i][j-1])
				{
				//	cout << "new " << str[i][j] << endl;
					++m;
					mem[i].push_back(str[i][j]);
					Count[i][m]++;
				}
				else
					Count[i][m]++;
			}
		}
		
		/*
		puts("member");
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; count[i][j] > 0 ; j++)
			{
				cout << mem[i][j];
				cout << count[i][j] << " ";
			}
			puts("");
		}
		puts("");
		*/
		
		
		
		//pre check size
	//	puts("Pre 1");
		bool check = true;
		int mcount = mem[0].size();
	//	cout << mcount << " mem\n"; 
		for(int i = 1 ; i < n ; i++)
		{
			if(mem[i].size() != mcount)
			{
				printf("Case #%d: Fegla Won\n",k);
				check = false;
				break;
			}
		}
		if(check == false)
			continue;
		
		
		//pre check mem
	//	puts("Pre 2");
		bool ok = true;
		for(int i = 0 ; i < mcount ; i++)
		{
			bool sam = true;
			char m = mem[0][i];
			for(int j = 1 ; j < n ; j++)
				if(mem[j][i] != m)
				{
					sam = false;
					break;
				}
			if(!sam)
			{
				ok = false;
				break;
			}
		}
		if(!ok)
		{
			printf("Case #%d: Fegla Won\n",k);
			continue;
		}
		
		
		
		// move
		int ans = 0;
	//	puts("Move");
		for(int i = 0 ; i < mcount ; i++)
		{
			for(int j = 0 ; j < n ; j++)
				counting[j] = Count[j][i];
				
			sort(counting, counting+n);
			
			/*
			for(int i = 0 ; i < n ; i++)
				cout << counting[i] << "," ;
			cout << endl;
			*/
			
			int mid = counting[(n>>1)];

			for(int i = 0 ; i < n ; i++)
			{
		//		cout << "ans += " << mid << "-" << counting[i] << endl;
				ans += abs(mid-counting[i]);
			}
		}
		
		//outputs
		
		printf("Case #%d: %d\n",k,ans);
	}
	return 0;
}

