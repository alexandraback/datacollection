#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN  16384

void solve(int it, int n);

FILE *fp;
FILE *foutp;

int T,N;
int Pcnt[27];

main(int argc, char** argv)
{
	char sl[MAX_LEN+1], *rp;
	int it;

	if (argc<=1) { exit(-1); }
	fprintf(stderr,"infile:  %s\n",argv[1]);

	fp=fopen(argv[1], "r");
	if (fp==NULL) { exit(-1); }

	{
		char *cp;
		char foutname[256];
		strcpy(foutname, argv[1]);
		cp=strstr(foutname, ".in");
		if (cp) {	strcpy(cp, ".out.txt"); }
		else {		strcat(foutname, ".out.txt"); }

		fprintf(stderr,"outfile: %s\n",foutname);
		foutp=fopen(foutname, "w");
		if (foutp==NULL) { exit(-1); }
	}

	rp=fgets(sl,MAX_LEN,fp);
	if (rp==NULL) exit(-1);

	T=atoi(sl);
	fprintf(stderr,"T: %d\n",T);

	for (it=1; it<=T; it++) {
		int i;
		int r;

		rp=fgets(sl,MAX_LEN,fp);
		if (rp==NULL) exit(-1);

		r=sscanf(sl, "%d", &N);
		if (r!=1) exit (-1);

		fprintf(stderr,"N: %d\n", N);

		rp=fgets(sl,MAX_LEN,fp);
		if (rp==NULL) exit(-1);

		for (i=0;i<N;i++) {
			r=sscanf(rp, "%d", &Pcnt[i]);
			if (r!=1) exit (-1);
			
			for (;*rp;rp++) {
				if (*rp==' ') { rp++; break; }
			}
		}
		
		solve(it, N);
	}

}

void solve(int it, int N)
{
	int Ptot;
	int j,i;
	int m1,m2;

	for (i=0,Ptot=0;i<N;i++) { Ptot+=Pcnt[i]; }

	fprintf(stderr,"Case #%d: ", it);
	fprintf(foutp ,"Case #%d: ", it);

	for (;Ptot>0;) {
		for (i=0,m1=0;i<N;i++) { if (Pcnt[i]>Pcnt[m1]) m1=i; }
		Pcnt[m1]--;
		Ptot--;
		fprintf(stderr,"%c", 'A'+m1);
		fprintf(foutp ,"%c", 'A'+m1);
		if (Ptot==0) {
			fprintf(stderr,"\n");
			fprintf(foutp ,"\n");
			break;
		}
		
		for (i=0,m1=0;i<N;i++) { if (Pcnt[i]>Pcnt[m1]) m1=i; }
		if (Ptot==1) {
			fprintf(stderr,"%c\n", 'A'+m1);
			fprintf(foutp ,"%c\n", 'A'+m1);
			break;
		}
		if (Ptot>1) {
			m2=(m1==0)?1:0;
			for (i=0;i<N;i++) {
				if (i==m1) continue;
				if (Pcnt[i]>Pcnt[m2]) m2=i;
			}
			if ( Pcnt[m2]<=(Ptot-1)/2) {
				Pcnt[m1]--;
				Ptot--;
				fprintf(stderr,"%c", 'A'+m1);
				fprintf(foutp ,"%c", 'A'+m1);
			}
			fprintf(stderr," ");
			fprintf(foutp ," ");
		}
	}
}


