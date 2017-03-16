#include <cstdio>
#include <vector>
using namespace std;

void open(){
 freopen("A-small-attempt0.in","r",stdin);
 freopen("Af.out","w",stdout);
}

void close(){
 fclose(stdin);
 fclose(stdout);
}

int tc,arr[5][5],r[2];
bool flag[2][17];
vector<int> ans;

int main(){
 open();
 scanf("%d",&tc);
 for(int t=1;t<=tc;t++){
  ans.clear();
  for(int i=0;i<17;i++)
   flag[1][i]=flag[0][i]=0;
  for(int i=0;i<2;i++){
   scanf("%d",&r[i]);
   r[i]--;
   for(int j=0;j<4;j++)
    for(int k=0;k<4;k++)
     scanf("%d",&arr[j][k]);
   for(int j=0;j<4;j++)
    flag[i][arr[r[i]][j]]=1;
  }
  for(int i=1;i<=16;i++)
   if(flag[0][i]&&flag[1][i])
    ans.push_back(i);
  printf("Case #%d: ",t);
  if(ans.empty()) printf("Volunteer cheated!\n");
  else if(ans.size()>1) printf("Bad magician!\n");
  else printf("%d\n",ans[0]);
 }
 close();
 return 0;
}
