#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void getAbbreviation(char *str, char *abb, int *cnt)
{
    int counter = 0;
    int idx = 0;
    abb[counter] = str[idx];
    cnt[counter] = 1;
    for(idx=1; str[idx]!=0; idx++){
        if(str[idx]==str[idx-1])
            cnt[counter]++;
        else{
            counter++;
            abb[counter] = str[idx];
            cnt[counter] = 1;
        }
    }
    abb[counter]=0;
}
int abs(int x){
    if(x<0) return x*(-1);
    else return x;
}
int process()
{
    int N;
    char dict[101][120];
    scanf("%d", &N);
    fgets(dict[0], 10, stdin);
    for(int i=0; i<N; i++)
        fgets(dict[i], 120, stdin);

    char abb[120];
    int abbCnt[101][120];
    getAbbreviation(dict[0], abb, abbCnt[0]);
    for(int i=1; i<N; i++){
        char tmpAbb[120];
        getAbbreviation(dict[i], tmpAbb, abbCnt[i]);
        if(strcmp(tmpAbb, abb)!=0) return -1;
    }

    int ans=0;
    for(int i=0; abb[i]!=0; i++){
        int times[101];
        //copying
        for(int j=0; j<N; j++)
            times[j] = abbCnt[j][i];
        //sorting and find median
        qsort(times, N, sizeof(int), compare);
        int median = times[N/2];
        //get ans
        for(int j=0; j<N; j++)
            ans += abs(times[j]-median);
    }
    return ans;
}
int main()
{
    int caseNum;
    scanf("%d", &caseNum);
    for(int i=1; i<=caseNum; i++){
        int ans = process();
        if(ans==-1)
            printf("Case #%d: Fegla Won\n", i);
        else
            printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}
