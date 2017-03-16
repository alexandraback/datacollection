//
//  main.cpp
//  Senate Evacuation
//
//  Created by Nasca Sergiu Alin on 08/05/16.
//  Copyright © 2016 Nasca Sergiu Alin. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>

using namespace std;

vector<int> a;
vector< pair<int, int> > maxim;
pair<int, int> aux;

int main(int argc, const char * argv[])
{
    int t, n, x, number;
    bool ok = false;
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    scanf("%d ", &t);
    for(int i = 1; i <= t; ++i)
    {
        printf("Case #%d: ", i);
        scanf("%d ", &n);
        
        a.clear();
        for(int j = 1; j <= n; ++j)
        {
            scanf("%d ", &x);
            a.push_back(x);
        }
        
        ok = false;
        while(!ok)
        {
            ok = true;
            number = 0;
            maxim.clear();
            maxim.push_back({-(1<<28), 0});
            maxim.push_back({-(1<<28), 0});
            
            for(int j = 0; j < a.size(); ++j)
            {
                number = number + a[j];
                if(maxim[0].first < a[j])
                {
                    maxim[0].first = a[j];
                    maxim[0].second = j;
                }
                if(maxim[0].first > maxim[1].first)
                {
                    aux = maxim[0];
                    maxim[0] = maxim[1];
                    maxim[1] = aux;
                }
            }
            if(number == 3)
            {
                printf("%c ", maxim[1].second + 'A');
                a[ maxim[1].second ] = a[ maxim[1].second ] - 1;
            }
            else
            {
                if(maxim[1].first >= maxim[0].first + 2)
                {
                    printf("%c%c ", maxim[1].second + 'A', maxim[1].second + 'A');
                    a[ maxim[1].second ] = a[ maxim[1].second ] - 2;
                }
                else
                {
                    printf("%c%c ", maxim[1].second + 'A', maxim[0].second + 'A');
                    a[ maxim[1].second ] = a[ maxim[1].second ] - 1;
                    a[ maxim[0].second ] = a[ maxim[0].second ] - 1;
                }
            }
            
            for(int j = 0; j < a.size(); ++j)
            {
                if(a[j] != 0)
                {
                    ok = false;
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
