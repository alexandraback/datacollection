#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int N;
long long X[3000],Y[3000], res[3000];

int main()
{
	FILE *in,*out;
//	char line[1000];
	int T, t;
	in = fopen("C.in","r");
	out = fopen("C.out","w+");
//	fgets(line,999,in);
//	sscanf(line,"%d",&T);
	fscanf(in,"%d ",&T);
	for(t = 1; t <= T; t++)
	{
		int i,j;
		fscanf(in,"%d ",&N);
//		fgets(line,999,in);//empty line
		for(i=0; i<N; i++)
		{
			fscanf(in,"%lld %lld ",&X[i], &Y[i]);
if(X[i]<0 || Y[i]<0)
cout<<"yes";
else
cout<<"no";			
			res[i] = 3000;
		}
		for(i=0;i<N;i++)
		{
			for(j= i+1; j<N;j++)
			{
				int pos = 0, neg = 0;
				for(int k =0; k<N;k++)
				{
//					long long val = (Y[k]-Y[i])*(X[i]-X[j])-(Y[i]-Y[j])*(X[k]-X[i]);
					long long val = Y[k]*X[i]-Y[k]*X[j]+Y[i]*X[j]-Y[i]*X[k]+Y[j]*X[k]-Y[j]*X[i];
					if(val < 0)
					{
						neg++;
					}
					if(val > 0)
					{
						pos++;
					}
				}
				if(pos < res[i])
					res[i] = pos;
				if(neg < res[i])
					res[i] = neg;
				if(pos < res[j])
					res[j] = pos;
				if(neg < res[j])
					res[j] = neg;
			}
		}
		fprintf(out, "Case #%d:\n",t);
		for(i=0; i<N; i++)
		{
			fprintf(out, "%d\n",res[i]);
		}
	}
	fclose(in);
	fclose(out);
}
