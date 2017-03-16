#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
#define INT64 long long
struct Tree{
    INT64 x, y;
};
struct v{
    INT64 x, y;
};

Tree tree[3005];

int main(){
    int T, n;
    scanf("%d", &T);

    for (int _T = 1; _T <= T; _T++){
        printf("Case #%d:\n", _T);

        scanf("%d" ,&n);

        for (int i = 0; i < n; ++i)
            scanf("%lld %lld", &tree[i].x, &tree[i].y);

        for (int k = 0; k < n; ++k)
        {
            int cut = n;
            int left;
            int right;
            for (int j = 0; j < n; ++j){
                if(j == k)
                    continue;
                v tv;
                tv.x = tree[k].x - tree[j].x;
                tv.y = tree[k].y - tree[j].y;

                left = 0;
                right = 0;

                for (int i = 0; i < n; ++i)
                {   
                    //if(i == k || i == j)
                    //    continue;
                    if((tree[i].x - tree[k].x) * tv.y > (tree[i].y - tree[k].y) * tv.x)
                        right++;
                    else if((tree[i].x - tree[k].x) * tv.y < (tree[i].y - tree[k].y) * tv.x)
                        left++;
                }
                cut = min(cut, min(left,right));
                
            }
            printf("%d\n", cut);

        }


    }

}