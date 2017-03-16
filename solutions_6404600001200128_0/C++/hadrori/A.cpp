/*
  template for C++11 in GCJ
  
  using multi thread
  use only cout for output
  ///////////////////////
  //do not use "printf"//
  ///////////////////////

  compile option
  -fopenmp -O2
  ./a.out -p -> parallel
  ./a.out -s -> show status
*/
#include <bits/stdc++.h>
#include <sys/time.h>
#ifdef _OPENMP
#include <omp.h>
#endif
using namespace std;
#define BEGIN_SOLVER struct solver {
#define END_SOLVER };

const string starter = " "; // "\n"
#define cout ss
// cout << setprecision(10)

void initializer()
{
}
//////////////////////////////////////////////////////////////////////////////////////////////////
BEGIN_SOLVER //////////////   Coding from here   /////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

int n, m[1024];

void solve()
{
        int ans = 0, md = 0;
        for (int i = 1; i < n; i++) {
                if(m[i] < m[i-1]) {
                        ans += m[i-1]-m[i];
                        md = max(md, m[i-1]-m[i]);
                }
        }
        cout << ans << ' ';
        ans = 0;
        for (int i = 0; i < n-1; i++) ans += min(md, m[i]);
        cout << ans << endl;
}

void input()
{
        cin >> n;
        for (int i = 0; i < n; i++) cin >> m[i];
}

void init()
{
}


stringstream ss;
string output_s;
solver(){
        output_s = "";
        ss.str("");
}

void output(){
        output_s = starter;
        output_s += ss.str();
}

//////////////////////////////////////////////////////////////////////////////////////////////////
END_SOLVER //////////////   Do not edit from here   //////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////


double sec()
{
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return tv.tv_sec + tv.tv_usec * 1e-6;
}
void print_status(int c, int C, double t0, double t1, int nth)
{
        static const int L = 5;
        if (C > L && c % (C / L) != 0) return;
        else if (c - (nth - 1) / 2 <= 0) fprintf(stderr, "[ case: %d / %d ]\n", c, C);
        else {
                double t = sec();
                fprintf(stderr, "[ case: %d / %d | time: %.3f / %.3f ]\n",
                        c, C, t - t0, (t1 - t0) + (t - t1) / (c - (nth - 1) / 2) * C);
        }
}

int main(int argc, char **argv)
{
        bool parallel = false, status = false;
        for (int i = 1; i < argc; i++) {
                if (strcmp(argv[i], "-p") == 0) parallel = status = true;
                else if (strcmp(argv[i], "-s") == 0) status = true;
                else {
                        fprintf(stderr, "usage: %s [-p] [-s]\n", argv[0]);
                        exit(EXIT_FAILURE);
                }
        }

        double t0 = sec();
        initializer();
        double t1 = sec();
        if (status) fprintf(stderr, "[ init: %.3f ]\n", t1 - t0);

        int T; cin >> T;
        if (!parallel) {
                if (status) fprintf(stderr, "[ mode: single thread ]\n");
                for (int t = 0; t < T; t++) {
                        if (status) print_status(t, T, t0, t1, 1);
                        printf("Case #%d:", t+1);
                        solver *s = new solver();
                        assert(s != NULL);
                        s->init();
                        s->input();
                        s->solve();
                        s->output();
                        printf("%s", s->output_s.c_str());
                        delete s;
                }
        }
        else{
#ifdef _OPENMP
                int nth = omp_get_max_threads();
                vector<string> out(T);
                vector<bool> done(T);
                int solve_c = 0, out_t = 0;
                omp_lock_t lock;
                omp_init_lock(&lock);
#pragma omp parallel for schedule(dynamic, 1)
                for (int t = 0; t < T; t++) {
                        solver *s = new solver();
                        assert(s != NULL);
                        int my_c;
                        omp_set_lock(&lock);
                        {
                                while (out_t < T && done[out_t]) {
                                        printf("Case #%d:", out_t+1);
                                        printf("%s", out[out_t].c_str());
                                        out_t++;
                                }
                                if (status) print_status(solve_c, T, t0, t1, nth);
                                my_c = solve_c++;
                                s->init();
                                s->input();
                        }
                        omp_unset_lock(&lock);
            
                        s->solve();
                        s->output();
            
                        omp_set_lock(&lock);
                        {
                                out[my_c] = s->output_s;
                                done[my_c] = true;
                        }
                        omp_unset_lock(&lock);
                        delete s;
                }
                omp_destroy_lock(&lock);

                while (out_t < T) {
                        assert(done[out_t]);
                        printf("Case #%d:", out_t+1);
                        printf("%s", out[out_t].c_str());
                        out_t++;
                }
#else
                cerr <<"error: compile with -fopenmp !!\n";
#endif
        }
        return 0;
}
