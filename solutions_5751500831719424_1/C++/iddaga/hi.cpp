#include <stdio.h>
#include <vector>
#define MN 100
#define abs(x) (((x)>0)?(x):-(x))
using namespace std;
int n, r;
vector<pair<char,int> > d[MN];
char str[128];
int main()
{
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");
	int t, T, i, j, k;
	
	fscanf(in,"%d",&T);
	for (t = 1; t <= T; t++) {
		printf("Case #%d:\n",t);
		fprintf(out,"Case #%d: ",t);
		fscanf(in,"%d",&n);
		for (i = 0; i < n; i++) {
			fscanf(in,"%s",str);
			d[i].clear();
			for (j = 0; str[j]; j++) {
				if (j == 0 || str[j-1] != str[j])
					d[i].push_back(make_pair(str[j],1));
				else d[i][d[i].size()-1].second++;
			}
		}
		bool f = false;
		for (i = 0; i < n; i++) {
			if (d[i].size() != d[0].size())
				f = true;
		}
		if (f == false) {
			for (i = 0; i < d[0].size(); i++) {
				for (j = 0; j < n; j++) {
					if (d[j][i].first != d[0][i].first)
						f = true;
				}
			}
		}
		if (f == false) {
			r = 0;
			for (i = 0; i < d[0].size(); i++) {
				int m = -1, mm;
				for (j = 1; j <= 100; j++) {
					mm = 0;
					for (k = 0; k < n; k++)
						mm += abs(d[k][i].second-j);
					if (m == -1 || m > mm)
						m = mm;
				}
				r += m;
			}
			fprintf(out,"%d\n",r);
		}
		else fprintf(out,"Fegla Won\n");
	}
	fclose(in);
	fclose(out);
	return 0;
}