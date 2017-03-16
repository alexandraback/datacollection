#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Info {
	int count;
	char letter;
};

int n;
Info p[27];

int cmp(const void* p1, const void* p2) {
	Info* v1=(Info*)p1;
	Info* v2=(Info*)p2;
	return v2->count - v1->count;
}

void process() {
	// sortujemy od największej
	qsort(p, n, sizeof(Info), cmp);
	if(n==2) {	// to nie ma co robić tylko zawsze po dwa
		for(int i=0;i<p[0].count;++i) {
			printf(" %c%c", p[0].letter, p[1].letter);
		}
		return;
	}
	// n>2
	
	// etap 1 - wyrównujemy ze sobą dwie największe partie
	// czyli 1 z największej, jeden z najmniejszej
	// az ilość człónków z największej zrówna się z drugą
	while(p[0].count>p[1].count) {
		--p[0].count;
		printf(" %c%c", p[0].letter, p[n-1].letter);
		if(--p[n-1].count==0) --n;
	}
	// etap 2 - jak dwie największe partie mają po tyle samo członków
	// to wyprowadzamy inne partie
	while(n>3) {
		printf(" %c%c", p[n-2].letter, p[n-1].letter);
		--p[n-2].count;
		--p[n-1].count;
		while(p[n-1].count==0) --n;
	}
	
	if(n==3) {	// jeżeli jest jeszcze jakaś partia, to jej członkowie pojedyńczo wychodzą
		for(int i=0;i<p[2].count;++i) {
			printf(" %c", p[2].letter);
		}
		p[2].count=0;
		--n;
	}
	// etap 3 - wyprowadzamy członków dwówch największych partii
	for(int i=0;i<p[0].count;++i) {
		printf(" %c%c", p[0].letter, p[1].letter);
	}
}


int main(int argc, char** argv) {
	int tests;
	scanf("%d", &tests);
	
	for(int t=1;t<=tests;++t) {
		// odczyt danych
		scanf("%d",&n);
		for(int i=0;i<n;++i) {
			scanf("%d", &p[i].count);
			p[i].letter='A'+i;
		}

		printf("Case #%d:", t);
		process();
		printf("\n");
	}
	
	return 0;
}