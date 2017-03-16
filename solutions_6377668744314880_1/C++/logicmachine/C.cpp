#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <nmmintrin.h>

using namespace std;
typedef long long ll;

static int x[3000] __attribute__((aligned(16)));
static int y[3000] __attribute__((aligned(16)));

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int case_num = 1; case_num <= T; ++case_num){
		int n;
		cin >> n;
		for(int i = 0; i < n; ++i){ cin >> x[i] >> y[i]; }
		vector<int> answer(n);
#pragma omp parallel for
		for(int i = 0; i < n; ++i){
			const __m128i v_xi = _mm_set1_epi32(x[i]);
			const __m128i v_yi = _mm_set1_epi32(y[i]);
			int local = n;
			if(n <= 3){ local = 0; }
			for(int j = 0; j < n; ++j){
				if(i == j){ continue; }
				const int dx = x[j] - x[i], dy = y[j] - y[i];
				const __m128i v_dx = _mm_set1_epi32(dx);
				const __m128i v_dy = _mm_set1_epi32(dy);
				__m128i v_left = _mm_setzero_si128();
				__m128i v_right = _mm_setzero_si128();
				for(int k = 0; k + 3 < n; k += 4){
					const __m128i v_xk = _mm_load_si128(
						reinterpret_cast<const __m128i *>(x + k));
					const __m128i v_yk = _mm_load_si128(
						reinterpret_cast<const __m128i *>(y + k));
					const __m128i v_ex = _mm_sub_epi32(v_xk, v_xi);
					const __m128i v_ey = _mm_sub_epi32(v_yk, v_yi);
					const __m128i c11 = _mm_mul_epi32(v_dx, v_ey);
					const __m128i c12 = _mm_mul_epi32(v_dy, v_ex);
					v_left = _mm_sub_epi64(v_left, _mm_cmpgt_epi64(c11, c12));
					v_right = _mm_sub_epi64(v_right, _mm_cmpgt_epi64(c12, c11));
					const __m128i c21 = _mm_mul_epi32(
						_mm_srli_si128(v_dx, 4), _mm_srli_si128(v_ey, 4));
					const __m128i c22 = _mm_mul_epi32(
						_mm_srli_si128(v_dy, 4), _mm_srli_si128(v_ex, 4));
					v_left = _mm_sub_epi64(v_left, _mm_cmpgt_epi64(c21, c22));
					v_right = _mm_sub_epi64(v_right, _mm_cmpgt_epi64(c22, c21));
				}
				int64_t buffer[2] __attribute__((aligned(16)));
				_mm_store_si128(reinterpret_cast<__m128i *>(buffer), v_left);
				int left = buffer[0] + buffer[1];
				_mm_store_si128(reinterpret_cast<__m128i *>(buffer), v_right);
				int right = buffer[0] + buffer[1];
				for(int k = n & ~3; k < n; ++k){
					const int ex = x[k] - x[i], ey = y[k] - y[i];
					const ll c1 = static_cast<ll>(dx) * ey;
					const ll c2 = static_cast<ll>(dy) * ex;
					if(c1 > c2){
						++left;
					}else if(c2 > c1){
						++right;
					}
				}
				local = min(local, min(left, right));
			}
			answer[i] = local;
		}
		cout << "Case #" << case_num << ":" << endl;
		for(int i = 0; i < n; ++i){ cout << answer[i] << endl; }
	}
	return 0;
}

