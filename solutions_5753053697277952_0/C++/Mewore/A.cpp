#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 26;


int N;
int ar[MAXN];

void init()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &ar[i]);
}

struct Party {
	char c;
	int num;
	
	Party() {}
	
	Party(int chr, int n) { c=chr; num=n; }
	
	bool operator < (const Party &other) const { return (num < other.num); }
};

int totalNum=0;

bool oneCanDo(priority_queue<Party> &q)
{
	if(q.size() == 1) return true;
	Party tmp = q.top();
	q.pop();
	//q.push(Party(tmp.c, tmp.num-1));
	
	Party tmp2 = q.top();
	
	
	q.push(tmp);
	
	if(tmp2.num > (totalNum-1)/2) return false;
	
	return true;
}

void solve(int caseNum)
{
	priority_queue<Party> q;
	for(int i=0; i<N; i++) q.push(Party('A'+i, ar[i]));
	
	totalNum = 0;
	for(int i=0; i<N; i++) totalNum += ar[i];
	
	
	printf("Case #%d: ", caseNum+1);
	
	Party tmp,tmp2;
	
	while(!q.empty())
	{
		//printf("(%d/%d)", q.top().num, totalNum);
		
		if(oneCanDo(q))
		{
			//printf("(removing 1)");
			tmp = q.top();
			q.pop();
			printf("%c ", tmp.c);
			if(tmp.num > 1) q.push(Party(tmp.c, tmp.num-1));
			
			totalNum -= 1;
		} else {
			//printf("(removing 2)");
			tmp = q.top();
			q.pop();
			printf("%c", tmp.c);
			if(tmp.num > 1) q.push(Party(tmp.c, tmp.num-1));
			
			tmp = q.top();
			q.pop();
			printf("%c ", tmp.c);
			if(tmp.num > 1) q.push(Party(tmp.c, tmp.num-1));
			
			totalNum -= 2;
		}
	}
	
	printf("\n");
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	
	for(int i=0; i<T; i++)
	{
		init();
		solve(i);
	}
	
	return 0;
}
