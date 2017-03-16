#include <cstdio>
#include <cstring>
using namespace std;

int board[4][4];
int possible[4];

int main ()
{
	int TC;
	scanf("%d", &TC);
	
	for(int c = 1; c <= TC; c++){
		int ans;
		scanf("%d", &ans);
		
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				scanf("%d", &board[i][j]);
				if(i == ans - 1){
					possible[j] = board[i][j];
				}
			}
		}
		
		scanf("%d", &ans);
		
		int count = 0;
		int val = 0;
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				scanf("%d", &board[i][j]);
				if(i == ans - 1){
					for(int k = 0; k < 4;k++){
						if(board[i][j] == possible[k]){
							count++;
							val = possible[k];
						}
					}
				}
			}
		}
		if(count == 0)
			printf("Case #%d: Volunteer cheated!\n", c);
		else if(count > 1)
			printf("Case #%d: Bad magician!\n", c);
		else
			printf("Case #%d: %d\n", c, val);
		
		
	}
	return 0;
}

