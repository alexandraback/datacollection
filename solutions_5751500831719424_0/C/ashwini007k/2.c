# include <stdio.h>
# include <string.h>
struct node
{
int c;
int value;
};

int main()
{
freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
int t,k,n,i,r,c,j,max,min,total,l,flag,sum,s;
scanf("%d",&t);
for(s=1;s<=t;s++)
{
printf("Case #%d: ", s);
flag=0;
total=0;
scanf("%d",&n);
char a[n][150];struct node b[n][150];
for(i=0;i<n;i++)
scanf("%s",a[i]);
for(i=0;i<n;i++)
{
r=0;
b[i][r].c=a[i][0];c=a[i][0];b[i][r].value=1;
for(j=1;j<strlen(a[i]);j++)
{
if(c==a[i][j])
b[i][r].value++;
else
{
b[i][++r].value=1;b[i][r].c=a[i][j];c=a[i][j];
}
}
if(i==0)l=r;
else if(l!=r){ flag=1; break;}
}
if(flag==0)
{
for(i=1;i<n;i++)
{
for(j=0;j<=r;j++)
{
if(b[0][j].c!=b[i][j].c)
{flag=1; break; }
}
if(flag==1)break;
}}
if(flag==0)
{
//printf("%d r\n",r);
for(i=0;i<=r;i++)
{
max=b[0][i].value;
for(j=1;j<n;j++)
{
if(max<b[j][i].value)
max=b[j][i].value;
}
for(j=0;j<=max;j++)
{
sum=0;
for(k=0;k<n;k++)
{
if(j>b[k][i].value)
sum=sum+j-b[k][i].value;
else
sum=sum+b[k][i].value-j;
}
if(j==0)min=sum;
else
{
if(min>sum)
min=sum;
}}
total+=min;
}
printf("%d\n",total);
}
if(flag==1)
printf("Fegla Won\n");
}
return 0;
}
