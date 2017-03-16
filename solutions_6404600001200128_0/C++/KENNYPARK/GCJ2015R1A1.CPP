#include<fstream>
using namespace std;
FILE*fin=fopen("input.txt","r");
FILE*fout=fopen("output.txt","w");
int n,a[1010];
inline double mx2(double a,double b)
{
	if(a>b)return a;
	else return b;
}
inline int mn2(int a,int b)
{
	if(a>b)return b;
	else return a;
}
int main()
{
	int i,j,x,y,z;
	double t;
	fscanf(fin,"%d",&n);
	for(i=1;i<=n;++i)
	{
		fscanf(fin,"%d",&x);
		for(j=1;j<=x;++j)fscanf(fin,"%d",&a[j]);
		y=0;
		z=0;
		t=0;
		for(j=1;j<=x;++j)if(a[j-1]>a[j])y=y+a[j-1]-a[j];
		for(j=1;j<=x;++j)if(a[j-1]>a[j])t=mx2(t,(a[j-1]-a[j])/10.0);
		for(j=1;j<x;++j)z=z+mn2(a[j],t*10);
		fprintf(fout,"Case #%d: %d %d\n",i,y,z);
	}
	fcloseall();
	return 0;
}