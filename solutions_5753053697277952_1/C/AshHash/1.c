#include<stdio.h>
#include<string.h>

int sort(int *A, char *C,int n){
	int i,j;
	for(i=1;i<n;++i){
		int key=A[i];
		char k = C[i];
		j=i-1;
		
		while(j>=0 && A[j]>key){
			C[j+1]=C[j];
			A[j+1]=A[j];
			j--;
		}
		
		C[j+1]=k;
		A[j+1]=key;
	}
	return A[n-1];
}

//int main_test(){
//	int A[]={5,4,3,2,1};
//	sort(A,5);
//	int i;
//	for(i=0;i<5;++i)printf("%d ",A[i]);
//}

int main(){
	int testcases,tc,temp;
	scanf("%d",&testcases);
	
	int n_p,np[26],i;
	char ch[26];
	for(tc=1;tc<=testcases;++tc){
		//init
		for(i=0;i<26;++i){
			np[i]=-1;
			ch[i]='A'+i;
		}
		//start
		int max=-1;
		scanf("%d",&n_p);
		for(i=0;i<n_p;++i){
			scanf("%d",&np[i]);
		}
		
		max=sort(np,ch,n_p);
		
		//output
		printf("Case #%d: ",tc);
		while(n_p!=0){
			if(max==1 && n_p==3){
				n_p=2;
				printf("%c ",ch[2]);
			}
			else{
				printf("%c%c ",ch[n_p-1],ch[n_p-2]);
				np[n_p-1]-=1;
				np[n_p-2]-=1;
				
				if(np[n_p-1]==0 && np[n_p-2]==0)n_p-=2;
				else if(np[n_p-1]==0) n_p-=1;
				else if(np[n_p-2]==0){
					ch[n_p-2]=ch[n_p-1];
					np[n_p-2]=np[n_p-1];
					n_p-=1;
				}
				max = sort(np,ch,n_p);
			}
		}
		
		
		printf("\n");
	}
	return 0;
}
