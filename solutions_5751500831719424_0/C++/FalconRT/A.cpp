#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string GetSkeleton(std::string s){
    int l = s.length();
    char c = '\0';
    std::string ans = "";
    for (int i=0; i<l; i++){
        if (s[i] != c){
            c = s[i];
            ans += s[i];
        }
    }
    return ans;
}

void SolveTestcase(int TestCase){
    int N;
    int ANS = 0;
    std::string m[100];
    std::string sk[100];

    std::cin >> N;
    std::getline(std::cin, m[99]);
    for (int i=0; i<N; i++){
        std::getline(std::cin, m[i]);
        sk[i] = GetSkeleton(m[i]);
    }
    bool same = true;
    for (int i=0; i<N-1; i++){
        same = same && (sk[i] == sk[i+1]);
    }
    if (!same){
        std::cout << "Case #" << TestCase << ": " << "Fegla Won" << std::endl;
        return ;
    }
    std::string skelet = sk[0];
    int sklen = skelet.length();

    std::vector< int > newvec(N, 0);
    std::vector< std::vector< int > > symb(sklen, newvec);


    for (int i=0; i<N; i++){
        //processing i-th string
        int l = m[i].length();
        int t = 0;
        for (int k=0; k<l; k++){
            if (m[i][k] == skelet[t]) symb[t][i]++;
            else {
                t++;
                if (m[i][k] == sk[i][t]) symb[t][i]++;
            }
        }
    }
    for (int i=0; i<sklen; i++){
        std::sort(symb[i].begin(), symb[i].end());
        int mid = N/2;
        int midel = symb[i][mid];
        for (int j=0; j<N; j++) ANS += abs(symb[i][j] - midel);
    }

    std::cout << "Case #" << TestCase << ": " << ANS << std::endl;
    return ;
}

int main(){
    int T;
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; testcase++)
        SolveTestcase(testcase);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
