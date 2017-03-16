//
//  main.cpp
//  A
//
//  Created by Andrey Cherevko on 5/8/16.
//  Copyright © 2016 Andrey Cherevko. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

int a[30];

int main(int argc, const char * argv[]) {
    freopen("inlarge.txt", "r", stdin);
    freopen("outlarge.txt", "w", stdout);
    int t;
    cin >> t;
    set <pair <int, int> > q;
    for (int tt = 0; tt < t; tt++) {
        q.clear();
        for (int i = 0; i < 30; i++)
            a[i] = 0;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            q.insert(make_pair(-a[i], i));
        }
        cout << "Case #" << tt + 1 << ": ";

        while (!q.empty()) {
            if (q.size() > 2) {
                pair <int, int> p = *q.begin();
                cout << char ('A' + p.second) << " ";
                q.erase(p);
                if (p.first < -1) {
                    q.insert(make_pair(p.first + 1, p.second));
                }
            } else {
                auto it1 = q.begin();
                auto it2 = it1;
                it2++;
                if (it1->first == it2->first) {
                    auto p1 = *it1;
                    auto p2 = *it2;
                    q.erase(p1);
                    q.erase(p2);
                    if (p1.first < -1) {
                        q.insert(make_pair(p1.first + 1, p1.second));
                        q.insert(make_pair(p2.first + 1, p2.second));
                    }
                    cout << char ('A' + p1.second) << char ('A' + p2.second) << " ";
                } else {
                    auto p = *it1;
                    q.erase(p);
                    if (p.first < -1) {
                        q.insert(make_pair(p.first + 1, p.second));
                    }
                    cout << char ('A' + p.second) << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}
