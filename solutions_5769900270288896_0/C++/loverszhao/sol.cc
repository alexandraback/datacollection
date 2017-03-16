#include <climits>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>


using std::cin;
using std::cout;
using std::endl;


// ====== Defines ======

#define DBG

#define MAX_SIZE 10010

// ------ Defines ------


// ====== Types ======


// ------ Types ------


// ====== Global Variables ======

std::fstream log_fs;

int R, C, N, M;

int matrix[MAX_SIZE][MAX_SIZE];

// ------ Global Variables ------


// ====== Function declarations ======

void print_array(const int array[], const char *array_name, const int array_size);

// ------ Function declarations ------

int init_only_once()
{
#ifdef DBG
	log_fs << ">>>>init_only_once()" << endl;
#endif 

#ifdef DBG
	log_fs << "<<<<init_only_once()" << endl << endl;
#endif

        return 0;
}

int handle_input()
{
#ifdef DBG
	log_fs << ">>>>>>handle_input()" << endl;
#endif

        cin >> R >> C >> N;
	M = R * C - N;

#ifdef DBG
	log_fs << "<<<<<<handle_input()" << endl << endl;
#endif
        return 0;
}

int init_per_case()
{
#ifdef DBG
	log_fs << ">>>>>>init_per_case()" << endl;
#endif

        for (int iii = 1; iii <= R; iii++) {
		for (int jjj = 1; jjj <= C; jjj++) {
			matrix[iii][jjj] = 4;
                }
        }

	for (int iii = 1; iii <= C; iii++) {
		matrix[1][iii] = 3;
                matrix[R][iii] = 3;
        }
        
	for (int iii = 1; iii <= R; iii++) {
		matrix[iii][1] = 3;
                matrix[iii][C] = 3;
        }

	matrix[1][1] = 2;
        matrix[1][C] = 2;
        matrix[R][1] = 2;
        matrix[R][C] = 2;

#ifdef DBG
	log_fs << "<<<<<<init_per_case()" << endl << endl;
#endif
        return 0;
}

int get_ans()
{
	int ans = 0;

	int largest_r = 1, largest_c = 1;

	while (M--) {

	        for (int iii = 1; iii <= R; iii++) {
			for (int jjj = 1; jjj <= C; jjj++) {
				if (matrix[iii][jjj] > matrix[largest_r][largest_c]) {
					largest_r = iii;
                                        largest_c = jjj;
                                }
	                }
	        }
		
		matrix[largest_r][largest_c] = 0;

		if (largest_r >= 2)
			matrix[largest_r-1][largest_c]--;
		if (largest_r < R)
			matrix[largest_r+1][largest_c]--;

		if (largest_c >= 2)
			matrix[largest_r][largest_c-1]--;
		if (largest_c < C)
			matrix[largest_r][largest_c+1]--;
        }

        ans = 0;
        
	        for (int iii = 1; iii <= R; iii++) {
			for (int jjj = 1; jjj <= C; jjj++) {
                                ans += matrix[iii][jjj];
	                }
	        }

	return ans / 2;
}


int run()
{
#ifdef DBG
	log_fs << ">>>>>>run()" << endl;
#endif

	if (0 == R * C % 2) {
		if (N <= R * C / 2)
			return 0;
        } else {
		if (N <= 1 + R * C / 2)
			return 0;
        }

	int ans = get_ans();

#ifdef DBG
	log_fs << "<<<<<<run() = " << ans << endl << endl;
#endif
	return ans;
}

int main()
{
#ifdef DBG
        log_fs.open("log.txt", std::fstream::out);
	log_fs << ">>main()" << endl << endl;
#endif

        init_only_once();

        int total_cases_count = 0;
        cin >> total_cases_count;

        int run_ret = 0;

        for (int tt = 1; tt <= total_cases_count; tt++) {

                handle_input();

                init_per_case();

                run_ret = run();

                cout << "Case #" << tt << ": " << run_ret << endl;

#ifdef DBG
		log_fs << "Case #" << tt << ": " << run_ret << endl;
#endif
        }

#ifdef DBG
	log_fs << "<<main()" << endl;
	log_fs.close();
#endif
        return 0;
}

void print_array(const int array[], const char *array_name, const int array_size)
{
#ifdef DBG

        log_fs << "\t[" << array_name << "]=" << endl << "\t";

	for (int iii = 0; iii < array_size; iii++) {
		log_fs << array[iii] << "  ";
        }
	log_fs << endl << endl;
#endif
}

