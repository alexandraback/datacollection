#include <iostream>
#include <set>
#include <utility>


int main() {
    int T, Ti, n, x, i;
    std::set<std::pair<int, char> > s;
    std::set<std::pair<int, char> >::iterator it1, it2;
    std::pair<int, char> a, b;
    
    std::cin >> T;
    for (Ti = 1; Ti <= T; ++Ti) {
        std::cout << "Case #" << Ti << ":";
        
        std::cin >> n;
        s.clear();
        for (i = 0; i < n; ++i) {
            std::cin >> x;
            s.insert(std::make_pair(x, char('A' + i)));
        }

        while (s.size() >= 2) {
            std::cout << " ";
            it1 = s.end();
            --it1;
            it2 = it1;
            --it2;
            if ((it1->first == it2->first) || (it1->first < 2)) {
                if ((it1-> first == 1) && (s.size()%2 == 1)) {
                    std::cout << it1->second;
                    s.erase(it1);
                    continue;
                }
                a = std::make_pair(it1->first - 1, it1->second);
                b = std::make_pair(it2->first - 1, it2->second);
                std::cout << it1->second << it2->second;
                s.erase(it1);
                s.erase(it2);
                if (a.first > 0) {
                    s.insert(a);
                }
                if (b.first > 0) {
                    s.insert(b);
                }
            } else {
                a = std::make_pair(it1->first - 2, it1->second);
                std::cout << it1->second << it1->second;
                s.erase(it1);
                if (a.first > 0) {
                    s.insert(a);
                }
            }
        }
        if (s.size() > 0) {
            it1 = s.end();
            --it1;
            x = it1->first;
            while (x > 1) {
                std::cout << " " << it1->second << it1->second;
                x -= 2;
            }
            if (x > 0) {
                std::cout << " " << it1->second;
            }
        }
        
        std::cout << std::endl;
    }
    return 0;
}
