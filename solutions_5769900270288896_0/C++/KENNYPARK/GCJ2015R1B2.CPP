#include<fstream>
using namespace std;
FILE*fin=fopen("input.txt","r");
FILE*fout=fopen("output.txt","w");
int n,a,b,c,a2,b2,c2,d,d2;
inline int mn2(int a,int b)
{
	if(a>b)return b;
	else return a;
}
int main()
{
	int i,x,y,z,z2,out,out2;
	fscanf(fin,"%d",&n);
	for(i=1;i<=n;++i)
	{
		fscanf(fin,"%d%d%d",&x,&y,&z);
		if(x>=2&&y>=2)
		{
			a=0;
			if((1+1)%2==0)a++;
			if((x+1)%2==0)a++;
			if((1+y)%2==0)a++;
			if((x+y)%2==0)a++;
			b=(x/2-1)+((x+1-y%2)/2-1)+(y/2-1)+((y+1-x%2)/2-1);
			c=(x/2-1)*(y/2-1)+((x+1)/2-1)*((y+1)/2-1);
			a2=4-a;
			b2=2*(x-2)+2*(y-2)-b;
			c2=(x-2)*(y-2)-c;
			out=0;
			z2=z;
			if(z2>x*y-a-b-c)
			{
				z2=z2-(x*y-a-b-c);
				out=out+2*mn2(z2,a);
				z2=z2-a;
				if(z2>0)
				{
					out=out+3*mn2(z2,b);
					z2=z2-b;
					if(z2>0)out=out+4*z;
				}
			}
			out2=0;
			z2=z;
			if(z2>x*y-a2-b2-c2)
			{
				z2=z2-(x*y-a2-b2-c2);
				out2=out2+2*mn2(z2,a2);
				z2=z2-a2;
				if(z2>0)
				{
					out2=out2+3*mn2(z2,b2);
					z2=z2-b2;
					if(z2>0)out2=out2+4*z2;
				}
			}
		}
		else
		{
			if(x==1)swap(x,y);
			a=0;
			if(1%2==1)a++;
			if(x%2==1)a++;
			b=(x/2-1);
			a2=2-a;
			b2=(x-2)-b;
			out=0;
			z2=z;
			if(z2>x-a-b)
			{
				z2=z2-(x-a-b);
				out=out+mn2(z2,a);
				z2=z2-a;
				if(z2>0)out=out+2*z2;
			}
			out2=0;
			z2=z;
			if(z2>x-a2-b2)
			{
				z2=z2-(x-a2-b2);
				out2=out2+mn2(z2,a2);
				z2=z2-a2;
				if(z2>0)out2=out2+2*z2;
			}
		}
		fprintf(fout,"Case #%d: %d\n",i,mn2(out,out2));
	}
	return 0;
}