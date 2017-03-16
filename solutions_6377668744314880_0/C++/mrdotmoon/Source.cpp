#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#include <iostream>
#include <cmath>
using namespace std;

/*
PointSet[]：输入的点集
ch[]：输出的凸包上的点集，按照逆时针方向排列
n：PointSet中的点的数目
len：输出的凸包上的点的个数
*/

struct Point
{
    __int64 x, y;
};

//小于0,说明向量p0p1的极角大于p0p2的极角
__int64 multiply(Point p1, Point p2, Point p0)
{
    return((p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y));
}

double dis(Point p1, Point p2)
{
    return(sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y)));
}


void Graham_scan(Point PointSet[], Point ch[], int n, int &len)
{
    int i, j, k = 0, top = 2;
    Point tmp;

    //找到最下且偏左的那个点
    for (i = 1; i < n; i++)
        if ((PointSet[i].y < PointSet[k].y) || ((PointSet[i].y == PointSet[k].y) && (PointSet[i].x < PointSet[k].x)))
            k = i;
    //将这个点指定为PointSet[0]
    tmp = PointSet[0];
    PointSet[0] = PointSet[k];
    PointSet[k] = tmp;

    //按极角从小到大,距离偏短进行排序
    for (i = 1; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
            if ((multiply(PointSet[j], PointSet[k], PointSet[0])>0)
                || ((multiply(PointSet[j], PointSet[k], PointSet[0]) == 0)
                && (dis(PointSet[0], PointSet[j]) < dis(PointSet[0], PointSet[k]))))
                k = j;//k保存极角最小的那个点,或者相同距离原点最近
        tmp = PointSet[i];
        PointSet[i] = PointSet[k];
        PointSet[k] = tmp;
    }
    //第三个点先入栈
    ch[0] = PointSet[0];
    ch[1] = PointSet[1];
    ch[2] = PointSet[2];
    //判断与其余所有点的关系
    for (i = 3; i < n; i++)
    {
        //不满足向左转的关系,栈顶元素出栈
        while (multiply(PointSet[i], ch[top], ch[top - 1]) >= 0) top--;
        //当前点与栈内所有点满足向左关系,因此入栈.
        ch[++top] = PointSet[i];
    }
    len = top + 1;
}

bool isPointOnSegment(Point p, Point p1, Point p2)
{
    //差积是否为0，判断是否在同一直线上
    if ((p1.x - p.x)*(p2.y - p.y) - (p2.x - p.x)*(p1.y - p.y) != 0)
    {
        return false;
    }
    //判断是否在线段上
    if ((p.x > p1.x && p.x > p2.x) || (p.x < p1.x && p.x < p2.x))
    {
        return false;
    }
    if ((p.y > p1.y && p.y > p2.y) || (p.y < p1.y && p.y < p2.y))
    {
        return false;
    }
    return true;
}

const int maxN = 20;
Point PointSet[maxN];
int n;


int slove(int cur)
{
    int res = n;
    for (int i = 0; i <= ((1 << n) - 1); i++)
    {
        if ((1 << cur) & i)
        {
            Point temp[maxN];
            Point ch[maxN];
            int count = 0;
            int len = 0;
            for (int j = 0; j < n; j++)
            {
                if ((1 << j) & i)
                {
                    temp[count++] = PointSet[j];
                }
            }

            if (count > 3)
                Graham_scan(temp, ch, count, len);
            else
            {
                res = min(res, n - count);
                continue;
            }

            bool valid = false;
            for (int k = 0; k < len; k++)
            {
                if (isPointOnSegment(PointSet[cur], ch[k], ch[(k + 1) % len])
                    || (ch[k].x == PointSet[cur].x && ch[k].y == PointSet[cur].y))
                {
                    valid = true;
                    break;
                }
            }

            if (valid) res = min(res, n - count);
        }
    }
    return res;
}

void _main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        __int64 x, y;
        scanf("%lld%lld", &x, &y);
        PointSet[i].x = x;
        PointSet[i].y = y;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", slove(i));
    }
}


int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small.out", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++)
    {
        printf("Case #%d:\n", cases);
        _main();
    }
}