#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <assert.h>
#include <cstdio>

using namespace std;

int n , mi , A[50];

int main()
{
    freopen("A-large.in" , "r" , stdin);
    freopen("out.out" , "w" , stdout);

    int T , cc = 0;
    scanf("%d" , &T);
    while(T--)
    {
        ++cc;
        mi = 100000;
        scanf("%d" , &n);
        for(int i = 0;i < n;++i)
        {
            scanf("%d" , A + i);
            mi = min(mi , A[i]);
        }

        priority_queue < pair < int , int > > q;
        assert(q.size() == 0 and "Adsad");


        for(int i = 0;i < n;++i)
            q.push({A[i] , i});

        vector < string > ans;
        while(1)
        {
            pair< int , int > temp = q.top();   q.pop();
            if(temp.first == mi)
            {
                q.push(temp);
                break;
            }

            string x;
            x += temp.second + 'A';
            ans.push_back(x);
            --temp.first;

            q.push(temp);
        }

        while(q.size() > 2)
        {
            pair < int , int > temp = q.top();  q.pop();
            while(temp.first >= 2)
            {
                string x;
                x += temp.second + 'A';
                x += temp.second + 'A';
                ans.push_back(x);
                temp.first -= 2;
            }
            if(temp.first)
            {
                string x;
                x += temp.second + 'A';
                ans.push_back(x);
                --temp.first;
            }
        }
        if(q.size() == 2)
        {
            pair < int , int > temp1 = q.top();     q.pop();
            pair < int , int > temp2 = q.top();     q.pop();

            string x;
            x += temp1.second + 'A';
            x += temp2.second + 'A';
            for(int i = 0;i < temp1.first;++i)
                ans.push_back(x);
        }
        else if(q.size() == 1)
        {
            pair < int , int > temp = q.top();  q.pop();
            while(temp.first >= 2)
            {
                string x;
                x += temp.second + 'A';
                x += temp.second + 'A';
                ans.push_back(x);
                temp.first -= 2;
            }
            if(temp.first)
            {
                string x;
                x += temp.second + 'A';
                ans.push_back(x);
                --temp.first;
            }
        }

        printf("Case #%d:" , cc);
        for(int i = 0;i < (int)ans.size();++i)
            printf(" %s" , ans[i].c_str());

        printf("\n");


        cerr << "done   ->   " << cc << "\n";
    }
    return 0;
}
