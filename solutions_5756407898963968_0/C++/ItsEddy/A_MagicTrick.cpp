#include<cstdio>

int main(){
	int Case = 1,TestCase;
	scanf("%d",&TestCase);
	while(TestCase--){
		int Row;
		int row[2][4];

		for(int Arr = 0;Arr < 2;++Arr){
			scanf("%d",&Row);
			for(int i = 1;i <= 4;++i){
				for(int j = 0;j < 4;++j){
					if(i == Row)
						scanf("%d",&row[Arr][j]);
					else 
						scanf("%*d");
				}
			}
		}
		int result = -1;
		for(int i = 0;i < 4;++i){
			for(int j = 0;j < 4;++j){
				if(row[0][i] == row[1][j]){
					if(result == -1)
						result = row[0][i];
					else result = 17;
				}
			}
		}
		printf("Case #%d: ",Case++);
		if(result == 17)
			puts("Bad magician!");
		else if(result == -1)
			puts("Volunteer cheated!");
		else
			printf("%d\n",result);
	
	}
	return 0;
}
