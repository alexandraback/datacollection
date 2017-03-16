#include <stdio.h>
#include <queue>

using namespace std;

priority_queue<pair<int, char> > Q;

FILE *in=fopen("A-large.in", "r");
FILE *out=fopen("output.txt", "w");

int main()
{
	int t;
	fscanf(in, "%d", &t);
	for (int tt=1; tt<=t; tt++){
		int n, count=0;
		fscanf(in, "%d", &n);
		for (int i=0; i<n; i++){
			int x;
			fscanf(in, "%d", &x);
			count+=x;
			Q.push(make_pair(x, 'A'+i));
		}
		fprintf(out, "Case #%d: ", tt);
		while(count!=0){
			int m;
			int j=0;
			int A=Q.top().first;
			char chA=Q.top().second;
			Q.pop();
			A--;
			count--;
			if (Q.top().first>A) m=Q.top().first;
			else m=A;
			if (m<=count-m){
				fprintf(out, "%c ", chA);
				Q.push(make_pair(A, chA));
				continue;
			}
			A--;
			count--;
			if (Q.top().first>A) m=Q.top().first;
			else m=A;
			if (m<=count-m){
				fprintf(out, "%c ", chA);
				Q.push(make_pair(A, chA));
				continue;
			}
			A++;
			count++;

			int B=Q.top().first;
			char chB=Q.top().second;
			Q.pop();
			B--;
			count--;
			fprintf(out, "%c%c ", chA, chB);
			Q.push(make_pair(A, chA));
			Q.push(make_pair(B, chB));
		}
		fprintf(out, "\n");
	}
	return 0;
}
