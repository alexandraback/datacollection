//
// Created by Acka on 5/8/16.
//

#include <stdio.h>

char ans[60000];
int N, p[26];

bool rescue(int rem, int idx){
    if(!rem){
        ans[idx - 1] = '\0';
        return true;
    }

    int max1 = -1, max2 = -1, max3 = -1, mi1 = -1, mi2 = -1, mi3 = -1;
    for(int i = 0; i < N; i++){
        if(max1 < p[i]){
            max3 = max2; mi3 = mi2;
            max2 = max1; mi2 = mi1;
            max1 = p[i]; mi1 = i;
        }
        else if(max2 < p[i]){
            max3 = max2; mi3 = mi2;
            max2 = p[i]; mi2 = i;
        }
        else if(max3 < p[i]){
            max3 = p[i]; mi3 = i;
        }
    }

    if(max3 < 0){
        p[mi1]--; p[mi2]--;
        ans[idx] = 'A' + mi1;
        ans[idx + 1] = 'A' + mi2;
        ans[idx + 2] = ' ';
        if(rescue(rem - 2, idx + 3)) return true;
        p[mi1]++; p[mi2]++;
    }
    else{
        if(2 <= p[mi1] && (p[mi2] * 2 <= rem - 2)){
            p[mi1] -= 2;
            ans[idx] = 'A' + mi1;
            ans[idx + 1] = 'A' + mi1;
            ans[idx + 2] = ' ';
            if(rescue(rem - 2, idx + 3)) return true;
            p[mi1] += 2;
        }
        if((2 * (p[mi1] - 1) <= rem - 2) && (p[mi3] * 2 <= rem - 2)){
            p[mi1]--; p[mi2]--;
            ans[idx] = 'A' + mi1;
            ans[idx + 1] = 'A' + mi2;
            ans[idx + 2] = ' ';
            if(rescue(rem - 2, idx + 3)) return true;
            p[mi1]++; p[mi2]++;
        }
        if(2 * p[mi2] <= rem - 1){
            p[mi1]--;
            ans[idx] = 'A' + mi1;
            ans[idx + 1] = ' ';
            if(rescue(rem - 1, idx + 2)) return true;
            p[mi1]++;
        }
    }
    return false;
}

int main()
{
    freopen("/Users/acka/ClionProjects/ProblemSolving/2016_Codejam_1C/A-large.in", "r", stdin);
    freopen("/Users/acka/ClionProjects/ProblemSolving/2016_Codejam_1C/A-large.out", "w", stdout);

    int tc, st = 1; for(scanf("%d", &tc); tc--;){
        scanf("%d", &N);

        int sum = 0, idx;
        for(int i = 0; i < N; i++) {
            scanf("%d", &p[i]);
            sum += p[i];
        }

        rescue(sum, 0);

        printf("Case #%d: %s\n", st++, ans);
    }
    return 0;
}
