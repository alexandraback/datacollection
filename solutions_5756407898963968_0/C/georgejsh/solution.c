#include<stdio.h>
#define MAX 1000000007
int main()
{
 int t;
 int a[4][4],b[4][4],i,j,k,p,q,n,l;
 for(scanf("%d",&t),n=0;n<t;n++)
 {
  scanf("%d",&p);
  for(i=0;i<4;i++)
   for(j=0;j<4;j++)
    scanf("%d",&a[i][j]);
  scanf("%d",&q);
  for(i=0;i<4;i++)
   for(j=0;j<4;j++)
    scanf("%d",&b[i][j]);
	k=0;l=-1;
  for(i=0;i<4;i++)
   for(j=0;j<4;j++)
   {
    if(a[p-1][i]==b[q-1][j])
	{
	 if(l==-1)
	  l=a[p-1][i],k=1;
	 else
	  k++;
	}
   }
  if(k==0)
   printf("Case #%d: Volunteer cheated!\n",n+1);
  else if(k>1)
   printf("Case #%d: Bad magician!\n",n+1);
  else
   printf("Case #%d: %d\n",n+1,l);
 }
 return 0;
}