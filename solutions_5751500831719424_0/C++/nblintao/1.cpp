#include<cstdio> 
#include<cstdlib>

FILE *fp;
int re,r,n;
int table[102][102];
int i,letter,p,stdp,y,z;
int answer;
char ch;

int dodo(){
	answer=0;
	
	scanf("%d",&n);
	getchar();
	for(i=1;i<=n;i++){
		letter=0;p=-1;
		
		scanf("%c",&ch);
		while(ch>='a'&&ch<='z'){
			if(letter!=ch){
				letter=ch;
				if(i==1){
					p++;
					table[p][0]=letter;
					table[p][1]=1;
				}					
				else if(table[++p][0]==letter){
					table[p][i]=1;
				}else
					answer = -1;
				
			} else{
				table[p][i]++;
			}	
			scanf("%c",&ch);
		}
		if(i==1){
			stdp=p;
		}else if(p!=stdp)
			answer = -1;
	}
/*	for(y=0;y<=stdp;y++){
		printf("%c:",table[y][0]);
		for(z=1;z<=n;z++){
			printf(" %d",table[y][z]);
		}
		printf("\n");
	}*/
	if(answer==0){
		for(y=0;y<=stdp;y++){
			int j,p,tmp;
			for(p=2;p<n+1;p++)
			{				
				tmp=table[y][p];
				for(j=p;j>1&&table[y][j-1]>tmp;j--)
					table[y][j]=table[y][j-1];
				table[y][j]=tmp;
			}
			for(i=(n+1)/2+1;i<=n;i++)
				answer+=table[y][i];
			for(i=1;i<=n/2;i++)
				answer-=table[y][i];
		}
	}
		
}



int main(void){

	fp=fopen("haha","w");

	scanf("%d",&re);
	for(r=1;r<=re;r++){
		fprintf(fp,"Case #%d: ",r);
		dodo();
		if(answer==-1){
			fprintf(fp,"Fegla Won\n");
		}else{
			fprintf(fp,"%d\n",answer);
		}
	} 
}
