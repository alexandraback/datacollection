#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
class par
{

public:
	int num;
	char c;
	bool operator<(par d)const{
		return num > d.num;
	}
}s[30];
int main(void){
    int t,sum;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
    	scanf("%d",&n);
    	sum=0;
    	for (int i = 0; i < n; ++i)
    	{
    		s[i].c = 'A'+i;
    		scanf("%d",&s[i].num);
    		sum += s[i].num;
    	}

        printf("Case #%d:", tt);
    	sort(s,s+n);

		for (int i = s[0].num; i > s[1].num; --i)
		{
			printf(" %c", s[0].c);
			s[0].num--;
		}

		for (int i = 2; i < n; ++i)
		{
			for(int j=0;j<s[i].num;j++)
				printf(" %c", s[i].c);
		}

		for (int i = 0; i < s[0].num; ++i)
		{
			printf(" %c%c",s[0].c,s[1].c);
		}
		puts("");
    }
    return 0;
}

