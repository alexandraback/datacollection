#include<stdio.h>
#include<stdbool.h>
int main()
{
  int T,test=1,R1,R2,i,j,answer,tmp,h[17];
  scanf("%d",&T);
  while(T--)
    {
      scanf("%d",&R1);
      for(i=1;i<=16;i++)h[i]=false;
      for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	  {
	    scanf("%d",&tmp);
	    if(i==R1-1)
	      h[tmp]=true;
	  }
      
      scanf("%d",&R2);
      answer=-1;
      for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	  {
	    scanf("%d",&tmp);
	    if(i==R2-1)
	      {
		if(h[tmp] && answer!=-1)
		  answer=-2;
		else if(h[tmp] && answer==-1)
		  answer=tmp;
	      }
	  }
      printf("Case #%d: ",test++);
      if(answer==-2)
	printf("Bad Magician!\n");
      else if(answer==-1)
	printf("Volunteer cheated!\n");
      else
	printf("%d\n",answer);
    }
  return 0;
}
