#include<cstdio>
#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<ctime>
#include<cstring>

using namespace std;

int main()
{
    //freopen("practice.in","r",stdin);
    //freopen("A-large.in","r",stdin);
	//freopen("A-small-attempt0.in","r",stdin);
	//freopen("output.out","w",stdout);
    int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
    {
        printf("Case #%d: ",t);
        int n;
        vector<pair<int,char> > arr;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int temp;
            scanf("%d",&temp);
            arr.push_back(make_pair(temp,'A'+i));
        }
        sort(arr.begin(),arr.end());
        /*for(int i=0;i<n;i++)
        {
            printf("%d %c\n",arr[i].first,arr[i].second);
        }*/
        while(arr[n-1].first!=arr[n-2].first)
        {
            printf("%c ",arr[n-1].second);
            arr[n-1].first--;
        }
        for(int i=0;i<n-2;i++)
        {
            while(arr[i].first--)
            {
                printf("%c ",arr[i].second);
            }
        }
        while(arr[n-1].first--)
        {
            printf("%c%c ",arr[n-1].second,arr[n-2].second);
        }
        printf("\n");
    }
    return 0;
}
