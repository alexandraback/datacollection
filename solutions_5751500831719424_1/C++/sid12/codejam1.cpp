//Author: Siddharth Saluja
//Quote: "DIE FOR YOUR AIM"
#include <bits/stdc++.h>

using namespace std;


#define mod 1000000007
//#define DEBUG
#define inf 2147483647
#define ninf -2147483648
#define FOR(i,a,b) for(i=a;i<b;i++)
#define s(a) scanf("%d",&a)
#define lls(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define p(a) printf("%d",a)
#define llp(a) printf("%lld",a)
#define sp(a) printf("%s",a)
#define cp(a) printf("%c",a)
#define nline printf("\n")
#define space printf(" ")
#define fs(a) fscanf(fp,"%d",&a)
#define flls(a) fscanf(fp,"%lld",&a)
#define fss(a) fscanf(fp,"%s",a)
#define fp(a) fprintf(fo,"%d",a)
#define fllp(a) fprintf(fo,"%lld",a)
#define fsp(a) fprintf(fo,"%s",a)
#define fcp(a) fprintf(fo,"%c",a)
#define fnline fprintf(fo,"\n")
#define fspace fprintf(fo," ")
#define ll long long


int main()
{
#ifdef DEBUG
    cout<<"Debugging\n";
#endif
ios::sync_with_stdio(false);
FILE *fp,*fo;
fp=fopen("input.txt","r");
fo=fopen("output.txt","w");


int t,n,i,j,u=0;
fscanf(fp,"%d",&t);
while(t--)
{
    u++;
    char s[500][500];
    int len[500]={0},st[500]={0},flag=0,r,x,ans=0,z=0,cnt=0;
    char ch,prev='Z';
    vector<int> v;
    fscanf(fp,"%d",&n);
    for(i=0;i<n;i++)
    {
        fscanf(fp,"%s",&s[i]);
        len[i]=strlen(s[i]);
    }
    while(1)
    {
    for(i=0;i<n;i++)
    {
        ch=s[i][st[i]];
        if(prev==ch || i==0)
        {

        }
        else
        {
            flag=1;
        }
        cnt=0;
        for(st[i];st[i]<len[i] && flag==0 && s[i][st[i]]==ch;st[i]++)
        {
            cnt++;
        }
        if(flag==0)
        v.push_back(cnt);
        prev=ch;
    }
    if(flag==1)
        break;
    sort(v.begin(),v.end());
    x=v.size();
    if(x<n)
        break;
    x=x/2;
    for(r=0;r<v.size();r++)
        ans+=(abs(v[x]-v[r]));
    v.clear();
    for(r=0;r<n;r++)
    {
        if(st[r]==len[r])
            z++;
        else
            break;
    }
    if(z==n)
        break;
    else
        z=0;
}
if(flag==0)
    fprintf(fo,"Case #%d: %d\n",u,ans);
else
    fprintf(fo,"Case #%d: Fegla Won\n",u);
}
return 0;
}
