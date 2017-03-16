#include <stdio.h>
#include <queue>

using namespace std;

struct party{
	char name;
	int num;

	bool operator<(const party& rhs) const {
        return num < rhs.num;
  }
};

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);	
	int T;
	int N;
	party tmp, tmp2;
	priority_queue<party> Que;
	int sum;

	scanf("%d", &T);
	for(int test_case=1;test_case<=T;test_case++)
	{
		scanf("%d", &N);
		sum = 0;
		for(int i=0;i<N;i++)
		{
			tmp.name = 'A'+i;
			scanf("%d", &tmp.num);
			Que.push(tmp);

			sum += tmp.num;
		}

		printf("Case #%d: ", test_case);

		while(sum > 0)
		{
			tmp = Que.top(); Que.pop();
			tmp2 = Que.top(); Que.pop();

			if(tmp2.num * 2 <= sum-1)
			{
				printf("%c ", tmp.name);
				tmp.num--;
				sum-=1;
				Que.push(tmp);
				Que.push(tmp2);
			}
			else
			{
				printf("%c%c ", tmp.name, tmp2.name);
				tmp.num--;
				tmp2.num--;
				sum-=2;
				Que.push(tmp);
				Que.push(tmp2);
			}
		}
		printf("\n");
	}

	return 0;
}