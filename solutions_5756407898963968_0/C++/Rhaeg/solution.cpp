#include <cstdio>
#define SORT(A) sort(A.begin(),A.end())
#define fori(l,n) for(int l=1;l<=n;l++)
int main() {
	int I,IT,nada;
	int p,q,ii,jj,res,ban;
	int A[100][100],B[100],C[100];
    freopen("A-small-attempt0.in","r",stdin);
    freopen("magic1.out","w",stdout);
    I=1;
    scanf("%d", &IT); 
    
    while(I<=IT){
       
       scanf("%d", &p); 
       fori(i,4){
          fori(j,4){           
             scanf("%d", &A[i][j]);
          }
       }
       fori(k,4){
          B[k]=A[p][k];
       }
       
       scanf("%d", &q); 
       fori(i,4){
          fori(j,4){           
             scanf("%d", &A[i][j]);
          }
       }
       fori(k,4){
          C[k]=A[q][k];
       }
       
       //fori(i,4) printf ("valor%d ",B[i] );
       //if(ban==2) fprintf (opFile, "Case #%d: %d\n",I,P);
       //else fprintf (opFile, "Case #%d: Too Bad\n",I);
       
       //printf("Case %d",A[3][3]);
     //  printf (" valro de t %d:\n",IT);
      // printf ("Case #%d: Too Bad\n",A[3][3]);
      
      //COMPARACION
      ii=1;ban=0;
      while(ii<=4){
         jj=1;
         while(jj<=4){
            if(B[ii]==C[jj]){
               ban++;
               res=B[ii];
            }
            jj++;
         }
         ii++;
      }
      //RESPUESTA
      if(ban==0){
          printf("Case #%d: Volunteer cheated!\n",I);          
      }
      else{
         if(ban==1){
          printf("Case #%d: %d\n",I,res);          
         }
         else{
             printf("Case #%d: Bad magician!\n",I); 
         }
         
      }   
           
       I++;
    }
  /*  while(I<=IT){
       scanf("%d %d", &, &);
       
       
       printf("Case %d: %d\n",I,);
       I++;
    }
*/

//      printf("Case %d:\n",I);
	//scanf("%d", &nada);
	return 0;
}

