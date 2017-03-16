#include<fstream>
using namespace std;
FILE*fin=fopen("input.txt","r");
FILE*fout=fopen("output.txt","w");
int n,a[1010],d[1010];
int main()
{
	int i,j,k,x,y,mnv,mnp,jmp,out;
	fscanf(fin,"%d",&n);
	for(i=1;i<=n;++i)
	{
		fscanf(fin,"%d%d",&x,&y);
		for(j=1;j<=x;++j)fscanf(fin,"%d",&a[j]);
		for(j=1;j<=x;++j)d[j]=0;
		for(j=1;j<=y;++j)
		{
			mnv=999999999;
			for(k=1;k<=x;++k)
			{
				if(d[k]<mnv)
				{
					mnv=d[k];
					mnp=k;
				}
			}
			jmp=mnv;
			for(k=1;k<=x;++k)d[k]=d[k]-jmp;
			for(k=1;k<=x;++k)if(d[k])break;
			if(j!=1&&k>x)y=j-1+(y-1)%(j-1)+1;
			d[mnp]=a[mnp];
		}
		fprintf(fout,"Case #%d: %d\n",i,mnp);
	}
	fcloseall();
	return 0;
}