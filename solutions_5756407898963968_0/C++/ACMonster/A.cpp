//program A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int get()
{
  char c;
  while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
  bool flag=(c=='-');
  if(flag)
    c=getchar();
  int x=0;
  while(c>='0'&&c<='9')
    {
      x=x*10+c-48;
      c=getchar();
    }
  return flag?-x:x;
}

void output(int x)
{
  if(x<0)
    {
      putchar('-');
      x=-x;
    }
  int len=0,data[10];
  while(x)
    {
      data[len++]=x%10;
      x/=10;
    }
  if(!len)
    data[len++]=0;
  while(len--)
    putchar(data[len]+48);
  putchar('\n');
}

int main()
{
  freopen("A.in","r",stdin);
  //freopen("A.out","w",stdout);
  int totaltest=get();
  for(int test=1;test<=totaltest;test++)
    {
      int r=get()-1,m0=0;
      for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
          if(i==r)
            m0|=1<<get();
          else
            get();
      r=get()-1;
      int m1=0;
      for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
          if(i==r)
            m1|=1<<get();
          else
            get();
      int mask=m0&m1;
      printf("Case #%d: ",test);
      if(!mask)
        printf("Volunteer cheated!\n");
      else
        {
          int ans=-1;
          for(int i=1;i<=16;i++)
            if(mask==(1<<i))
              ans=i;
          if(ans==-1)
            printf("Bad magician!\n");
          else
            output(ans);
        }
    }
  return 0;
}
