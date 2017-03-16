
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;

int abs(int x) {
    return x>=0 ? x : -x;
}

int ac[110];

char *aa[110];
char *ax[110];

void readstuff(void) {
    char buf[110];
    int i;
    scanf("%d",&N);
    for (i=0;i<N;i++) {
        if (aa[i]) free(aa[i]);
        scanf("%s",buf);
        aa[i]=ax[i]=strdup(buf);
    }
}

int scoreit(void) {
    int min,max,i,bestscore=1000000,target,cur;
    min=max=ac[0];
    for (i=1;i<N;i++) {
        if (ac[i]<min) min=ac[i];
        if (ac[i]>max) max=ac[i];
    }
    for (target=min;target<=max;target++) {
        cur=0;
        for (i=0;i<N;i++) {
            cur+=abs(ac[i]-target);
        }
        //printf("[%d %d] ",target,cur);
        if (cur<bestscore) bestscore=cur;
    }
    //printf("=%d\n",bestscore);
    return bestscore;
}

void repeater(void) {
    int i;
    char c;
    int score=0;
    readstuff();
    while (*ax[0]) {
        c=*ax[0];
        for (i=0;i<N;i++) {
            if (*(ax[i])!=c) {score=-1;break;}
            ac[i]=0;
            while (c==*(ax[i])) {ax[i]++;ac[i]++;}
        }
        //printf(" score[%c]=",c);
        score+=scoreit();
    }
    for (i=0;i<N;i++) if (*(ax[i])) score=-1;
    if (score>=0) printf("%d\n",score);
    else printf("Fegla Won\n");
}

int main(int argc, char **argv) {
    int i,tc;
    scanf("%d",&tc);
    for (i=1;i<=tc;i++) {
        printf("Case #%d: ",i);
        repeater();
    }
    return 0;
}
