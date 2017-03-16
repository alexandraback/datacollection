#include <iostream>
#include <string.h>
#include <stdio.h>
#include <queue>

using namespace std;
typedef unsigned long long ULL;
const int N = 27;
int v[N];

struct Node {
    int id;
    int num;

    friend bool operator<(Node a, Node b) {
        return a.num < b.num; //结构体中，x小的优先级高
    }
};

int main() {
    int T;
    freopen("/Users/vino/Desktop/A-small-attempt4.in", "r", stdin);
    freopen("/Users/vino/Desktop/A-small-attempt4.out", "w", stdout);
    cin >> T;
    int cas = 0;
    while (T--) {
        int n;
        cin >> n;
        priority_queue<Node> q;
        int all = 0;
        for (int i = 0; i < n; i++) {
            Node node;
            int x;
            cin >> x;
            node.id = i;
            node.num = x;
            q.push(node);
            all += x;
        }
        printf("Case #%d:", ++cas);
        while (!q.empty() && all > 2) {
            Node node = q.top();
            q.pop();
            int id = node.id;
            int ct = node.num;
            printf(" %c", id + 'A');
            if (ct > 1) {
                node.num--;
                q.push(node);
            }
            all--;
            if (all == 2)
                break;
            node = q.top();
            q.pop();
            id = node.id;
            ct = node.num;
            printf("%c", id + 'A');
            if (ct > 1) {
                node.num--;
                q.push(node);
            }
            all--;
            if (all == 2)
                break;

        }
        Node node1 = q.top();
        q.pop();
        Node node2 = q.top();
        q.pop();
        printf(" %c%c", node1.id + 'A', node2.id + 'A');
        cout << endl;
    }


    return 0;
}