#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

int main()
{
	int T;
	scanf("%d\n",&T);  
	for(int t=1; t<=T; t++)
	{		
		int r1,r2;
		vector <int> row(4);
		vector <bool> cards(17,false);
		scanf("%d\n",&r1);
        for(int i=1; i<=4; i++){
		    scanf("%d %d %d %d",&row[0],&row[1],&row[2], &row[3]);
		    if(i==r1) for(int j=0;j<4;j++) cards[row[j]]=true;
		}
		scanf("%d\n",&r2);
		int result=0;
        for(int i=1; i<=4; i++){
		    scanf("%d %d %d %d",&row[0],&row[1],&row[2],&row[3]);
		    if(i==r2) for(int j=0;j<4;j++) if(cards[row[j]]) if(result==0) result=row[j]; else result=-1;
		}
		if(result==-1) printf("Case #%d: Bad magician!\n",t);
		else if(result==0) printf("Case #%d: Volunteer cheated!\n",t);
		else  printf("Case #%d: %d\n",t,result);				
	}
  return 0;
}
