//Author: Romanov Artem
#include <bits/stdc++.h>
//#define IN "input.txt"
//#define OUT "output.txt"

#define PI          3.141592653589793238462643383279502884L
#define E           2.718281828459045235360287471352662498L
#define EPS         1e-12L
#define D_INF       HUGE_VALL
#define D_NINF      (-HUGE_VALL)
#define T_MAX(T)    std::numeric_limits<T>::max()
#define T_MIN(T)    std::numeric_limits<T>::min()
#define m_p         make_pair
#define r_s         random_shuffle
#define l_b         lower_bound
#define u_b         upper_bound
#define e_r         equal_range
#define b_s         binary_search
#define s_u         set_union
#define s_i         set_intersection
#define s_d         set_difference
#define l_c         lexicographical_compare
#define n_p         next_permutation
#define p_p         prev_permutation
#define F           first
#define S           second
#define j0          j57552
#define j1          j77461
#define jn          j29628
#define y0          y84678
#define y1          y53021
#define yn          y91675

using namespace std;
typedef long double dbl;

int n, t;
int p[32];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(11);
    cout.setf(ios::fixed);
    srand((uint32_t) time(nullptr));
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#ifdef IN
    freopen(IN, "r", stdin);
#endif
#ifdef OUT
    freopen(OUT, "w", stdout);
#endif
#endif

    cin >> t;
    for (int q = 1; q <= t; ++q) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }
        cout << "Case #" << q << ':';
        for (int i = 0; ; ++i) {
            int id = 0;
            int mx = 0;
            int k = 0;
            for (int j = 0; j < n; ++j) {
                k += p[j];
                if (p[j] > mx) {
                    mx = p[j];
                    id = j;
                }
            }
            if (k == 0) break;
            p[id]--;
            k--;
            k = k / 2;
            bool bb = true;
            int id2 = 0;
            for (int l = 0; l < n; ++l) {
                if (p[l] > k) {
                    bb = false;
                    id2 = l;
                }
            }
            if (bb) {
                cout << ' ' << (char) ('A' + id);
            } else {
                p[id2]--;
                cout << ' ' << (char) ('A' + id) << (char) ('A' + id2);
            }
        }
        cout << '\n';
    }
    return 0;
}