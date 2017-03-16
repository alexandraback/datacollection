#include<stdio.h>
#include<string.h>
int abs(int a){return a>0?a:-a;}
int main(){
int t,l=1,i,j,k,p;
scanf("%d",&t);
while(l<=t){
int n;
int answer=0;
int zzz=0,max,min;
scanf("%d",&n);
char str1[n+2][110];
for(i=0;i<n;i++)
scanf("%s",str1[i]);
i=0;
int count[110][110]={0};
char arr[110][110];
for(j=0;j<n;j++){
i=0;
k=0;
while(str1[j][i]){
char id=str1[j][i];
arr[j][k]=id;
while(str1[j][i] && str1[j][i]==id){
count[j][k]++;
i++;
}
k++;
}
arr[j][k]='\0';
}
for(j=1;j<n;j++)
if(strcmp(arr[0],arr[j]))
break;
if(j==n){
for(i=0;i<k;i++){
max=0;
for(j=0;j<n;j++){
if(count[j][i]>max)
max=count[j][i];
}
min=100000000;
for(p=1;p<=max;p++){
zzz=0;
for(j=0;j<n;j++){
zzz+=abs(p-count[j][i]);
}
if(zzz<min)
min=zzz;
}
answer+=min;
}
printf("Case #%d: %d\n",l,answer);
}
else
printf("Case #%d: Fegla Won\n",l);
l++;
}
return 0;
}





