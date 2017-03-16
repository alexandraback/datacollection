#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

bool arr[25];

int main(){
   int TC;
   scanf("%d",&TC);
   for(int T=1;T<=TC;T++){
      int N1,N2,ans;
      for(int i=0;i<20;i++)
            arr[i]=false;
      scanf("%d",&N1);
      for(int i=0;i<4;i++)
         for(int j=0;j<4;j++){
            int temp;
            scanf("%d",&temp);
            if(i+1==N1){
               arr[temp]=true;
            }
         }
      ans=0;
      int last=-1;
      scanf("%d",&N2);
      for(int i=0;i<4;i++)
         for(int j=0;j<4;j++){
            int temp;
            scanf("%d",&temp);
            if(i+1==N2){
               if(arr[temp]){
                  ans++;
                  last=temp;
               }
            }
         }
      printf("Case #%d: ",T);
      if(ans==0)
         printf("Volunteer cheated!\n");
      else if(ans>1)
         printf("Bad magician!\n");
      else printf("%d\n",last);
   }
   return 0;
}