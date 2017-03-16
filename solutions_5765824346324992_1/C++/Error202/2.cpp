#include<iostream>
#include<stdio.h>
using namespace std;

const int N=1000010;
int n, a[N], up;
char s[N];
struct node
{
    int a[26];
    int cnt, fail;
    void init()
    {
        memset(a, -1, sizeof(a));
        cnt = fail = 0;
    }
}trie[N];


inline void insert(char *s)
{
    int p=0;
    while(*s)
    {
        if(trie[p].a[*s-'a']==-1)
        {
            trie[up].init();
            trie[p].a[*s-'a'] = up++;
        }
        p = trie[p].a[*s-'a'];
        s++;
    }
    trie[p].cnt++;
}

int q[N], head, tail;
void bfs()
{
    int i, p, p1, p2;
    head = tail = 0;
    for(i=0; i<26; i++)
    {
        if(trie[0].a[i]!=-1)
        {
            p = trie[0].a[i];
            trie[p].fail = 0;
            q[tail++] = p;
        }
    }
    while(head<tail)
    {
        p = q[head++];
        for(i=0; i<26; i++)
        {
            if(trie[p].a[i]!=-1)
            {
                p2 = trie[p].a[i];
                q[tail++] = p2;
                trie[p2].fail = 0;

                p1 = trie[p].fail;
                while(p1!=0 && trie[p1].a[i]==-1)
                    p1 = trie[p1].fail;
                
                if(trie[p1].a[i]!=-1)
                {
                    p1 = trie[p1].a[i];
                    trie[p2].fail = p1;
                }
            }
        }
    }

}
int query(char *s)
{
    int p, p1;
    int cnt=0;

    p = 0;
    while(*s)
    {
        while(p!=0 && trie[p].a[*s-'a']==-1)
            p = trie[p].fail;

        p1 = trie[p].a[*s-'a'];
        if(p1!=-1)
        {
            p = p1;
            while(p1!=0 && trie[p1].cnt!=-1) //这里很关键。。。但注意：要改成一个以前不会出现的值-1。。。
            {
                cnt += trie[p1].cnt;
                trie[p1].cnt = -1;
                p1 = trie[p1].fail;
            }
            /*
            while(p1!=0)  //通过将本段while循环改成上面，减掉了不必要的再次查找一系列fail结点，从800+MS减到了187MS。。。
            {
                if(trie[p1].flag==0)
                {
                    cnt += trie[p1].cnt;
                    trie[p1].flag = 1;
                }
                p1 = trie[p1].fail;
            }
            */
        }
        s++;
    }

    return cnt;
}

int main()
{
    int i, cas;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d", &n);
        gets(s);
        up = 1;
        trie[0].init();
        for(i=0; i<n; i++)
        {
            gets(s);
            insert(s);
        }
        gets(s);
        bfs();
        //for(i=0; i<up; i++)
        //  printf("%d %d..\n", i, trie[i].fail);
        printf("%d\n", query(s));
    }
    return 0;
}