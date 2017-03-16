#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <deque>
#include <iostream>
#include <math.h>
#include <sstream>
#include <assert.h>
#include <numeric>
#include <limits>
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
    //freopen("A-small-attempt0.in","r",stdin);
    //freopen("A-small-attempt0.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int caso=1; caso<=t; caso++)
    {
        int n;
        scanf("%d",&n);
        string word;
        string temp;
        set<string> diff;
        vector<string> words;
        for(int i=0; i<n; i++)
        {
            cin >> word;
            temp = "";
            temp.push_back(word[0]);
            for(int j=1; j<word.size(); j++)
            {
                if(word[j] != word[j-1])
                {
                    temp.push_back(word[j]);
                }
            }
            diff.insert(temp);
            words.push_back(word);
        }

        if(diff.size() == 1)
        {
            vector<int> vet[n];
            for(int i=0; i<n; i++)
            {
                int cont = 1;
                for(int j=1; j<words[i].size(); j++)
                {
                    if(words[i][j] != words[i][j-1])
                    {
                        vet[i].push_back(cont);
                        cont=1;
                    }
                    else
                    {
                        cont++;
                    }
                }
                vet[i].push_back(cont);
            }
            int ans=0;
            for(int i=0; i<vet[0].size(); i++)
            {
                int minimum = INF;
                for(int j=0; j<n; j++)
                {
                    int atual = 0;
                    for(int k=0; k<n; k++)
                    {
                        atual += abs(vet[j][i]-vet[k][i]);
                    }
                    minimum = min(minimum, atual);
                }
                ans += minimum;
            }
            printf("Case #%d: %d\n",caso,ans);
        }
        else
        {
            printf("Case #%d: Fegla Won\n",caso);
        }
    }
    return 0;
}

