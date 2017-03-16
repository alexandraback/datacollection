//Author : pakhandi
//
using namespace std;

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iterator>
#include<sstream>
#include<fstream>
#include<cassert>
#include<climits>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; i++)
#define rev(i,a,b) for(i=a; i>=b; i--)
#define scan(n) scanf("%d", &n)
#define scans(s) scanf("%s", s)
#define scanc(c) scanf("%c", &c)
#define scanp(f) scanf("%f", &f)
#define scanll(l) scanf("%lld", &l)
#define print(n) printf("%d\n", n)
#define prints(s) printf("%s\n", s)
#define printc(c) printf("%c\n", c)
#define printp(f) printf("%f\n", f)
#define printll(l) printf("%lld\n", l)
#define nline printf("\n")
#define mclr(strn) strn.clear()
#define ignr cin.ignore()
#define MOD 1000000007
#define ll long long int

int mat1[4][4], mat2[4][4];

int main()
{
	freopen("C:\\Users\\DELL\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\DELL\\Desktop\\output.txt","w",stdout);
	int i, j, cases;
	int bingo=0, count=0;
	int ans1, ans2;
	int k=0;
	scan(cases);
	wl(cases)
	{
		k++;
		count=0;
		scan(ans1);
		fl(i,0,4)
			fl(j,0,4)
				scan(mat1[i][j]);
		scan(ans2);
		fl(i,0,4)
			fl(j,0,4)
				scan(mat2[i][j]);
		fl(i,0,4)
		{
			fl(j,0,4)
			{
				if(mat1[ans1-1][i]==mat2[ans2-1][j])
				{
					count++;
					if(count==1)
						bingo=mat1[ans1-1][i];
				}	
			}
		}
		printf("Case #%d: ", k);
		if(count==1)
			printf("%d", bingo);
		else if(count==0)
			printf("Volunteer cheated!");
		else
			printf("Bad magician!");
		nline;
	}
	return 0;
}

