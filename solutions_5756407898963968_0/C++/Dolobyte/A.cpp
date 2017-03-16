#include<cstdio>
#include<cstring>

bool mark[20];
int ans, row;

int main()
{
	freopen("A.in", "r", stdin);

	int T; scanf("%d", &T);
	for(int o=0; o<T; o++){
		ans = 0;
		memset(mark, 0, sizeof(mark));
		
		scanf("%d", &row);
		for(int i=0; i<4; i++)
			for(int j=0, t; j<4; j++){
				scanf("%d", &t);
				if (i==row-1) mark[t] = 1;
			}

		scanf("%d", &row);
		for(int i=0; i<4; i++)
			for(int j=0, t; j<4; j++){
				scanf("%d", &t);
				if (i == row-1) {
					if (mark[t]){
						if (ans == 0) ans = t; else ans = -1;
					} else mark[t] = 1;
				}
			}
			
		

		printf("Case #%d: ", o+1);
		switch (ans){
			case 0:
				printf("Volunteer cheated!");
				break;
			case -1:	
				printf("Bad magician!");
				break;
			default:
				printf("%d", ans);
		}
		printf("\n");
	}

	return 0;
}
