#include <iostream>
#include <sstream>
#include <iomanip>

#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <string>

#include <numeric>
#include <utility>
#include <functional>
#include <algorithm>
#include <complex>
#include <memory>

#include <cstdio>
#include <cstdlib>
#include <cassert>

#include <cmath>
#include <climits>
#include <cfloat>

#include <cctype>
#include <cstring>

using namespace std;

#define FOR(M_i, M_from, M_to)	for(int M_i = (M_from); M_i < (M_to); ++M_i)
#define REP(M_i, M_n)				FOR(M_i, 0, M_n)
#define FOREACH(M_ite, M_c) for(decltype(M_c.begin()) M_ite = M_c.begin(); M_ite != M_c.end(); ++M_ite)

template<typename CONTAINER_T>
void read(istream& in, CONTAINER_T& list, size_t n)
{
	for(size_t i = 0; i < n; ++i)
	{
		CONTAINER_T::value_type value;
		in >> value;
		list.push_back(value);
	}
};

template<typename T, typename INDEX_T = int>
struct t_indexed_value
{
	typedef t_indexed_value<T, INDEX_T> self; 
	typedef T		value_t;
	typedef INDEX_T	index_t;

	value_t value;
	index_t index;

	bool operator <(const self& obj) const { return value < obj.value; }
	bool operator ==(const self& obj) const { return value == obj.value; }
	bool operator !=(const self& obj) const { return !(*this == obj); }
};

template<typename FORWARD_ITE>
void write(ostream& out, FORWARD_ITE first, FORWARD_ITE last, const string& sep = " ")
{
	if(first != last) { out << *first; ++first; }
	while(first != last)
	{
		out << sep << *first;
		++first;
	}
	out << endl;
}

#include <fstream>

template<typename T>
void print_result(ostream& out, int index, const T& result)
{
	out << "Case #" << (index + 1) << ": " << result << endl;
}

template<typename T>
T gcd_impl(T a, T b)
{
	if(b == 0) { return a; }
	else { return gcd_impl(b, a % b); }
}

template<typename T>

T gcd(T a, T b)
{
	assert(a > 0 && b > 0);
	return gcd_impl(a, b);	
}

template<typename T>

T lcm(T a, T b)
{
	assert(a > 0 && b > 0);
	return a * b / gcd(a, b);
}

template<typename T>
bool is_prime(T n)
{
	assert(n >= 0);
	if(n < 2) { return false; }
	for(T i = 2; i * i <= n; ++i)
	{
		if(n % i == 0) { return false; }
	}
	return true;
}

template<typename T>
set<T> divisor(T n)
{
	assert(n >= 0);
	set<T> list;
	if(n < 2) { return list; }

	for(T i = 2; i * i <= n; ++i)
	{
		if(n % i == 0)
		{
			list.insert(i);
			if(i != n / i) { list.insert(n / i); }
		}
	}
	return list;
}

template<typename T>
map<const T, int> prime_factor(T n)
{
	assert(n >= 0);
	map<const T, int> m;
	if(n < 2) { return m; }

	for(T i = 2; i * i <= n; ++i)
	{
		while(n % i == 0)
		{
			++m[i];
			n /= i;
		}
	}

	if(n != 1) { ++m[n]; }
	return m;
}

template<typename T>
set<T> prime_list(T max_n)
{
	assert(max_n > 0);
	set<T> list;
	vector<bool> is_prime(max_n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for(T i = 2; i <= max_n; ++i)
	{
		if(is_prime[i])
		{
			list.insert(i);
			for(T j = 2 * i; j <= max_n; j += i) { is_prime[j] = false; }
		}
	}
	return list;
}

template<typename T>
T combination(T n, T r)
{
	assert(n >= 0);
	assert(r >= 0);
	assert(n >= r);
	if(n == 0 || r == 0) { return 0; }
	T numerator = 1, denominator = 1;
	if(n - r < r) { r = n - r; }
	if(r == 0) { return 1; }
	for(T i = n; i > n - r; --i)
	{
		numerator *= i;
	}
	for(T i = 2; i <= r; ++i)
	{
		denominator *= i;
	}
	return numerator / denominator;
}

template<typename T>
T permutation(T n, T r)
{
	assert(n >= 0);
	assert(r >= 0);
	assert(n >= r);
	if(n == 0 || r == 0) { return 0; }

	T result = 1;
	for(T i = n; i > n - r; --i)
	{
		result *= i;
	}
	return result;
}


int solve(vector<int>& list, int n)
{
	int lcm_value = 1;
	for(auto value : list)
	{
		lcm_value = lcm(lcm_value, value);
	}

	int interval = 0;
	for(auto value : list)
	{
		interval += lcm_value / value;
	}

	n = (n - 1) % interval;

	struct b_info_t
	{
		int id;
		int rest;

		bool operator <(const b_info_t& other) const
		{
			if(rest != other.rest) { return rest < other.rest; }
			return id < other.id;
		}
	};

	if(n < list.size())
	{
		return n + 1;
	}

	set<int> waiting;
	for(int i = 0; i < list.size(); ++i) { waiting.insert(i); }

	vector<b_info_t> q;
	int last_id = -1;
	while(n >= 0)
	{
		if(waiting.empty())
		{
			auto next = min_element(q.begin(), q.end());
			int id = next->id;
			int rest = next->rest;
			waiting.insert(id);
			auto ite = q.begin();
			while(ite != q.end())
			{
				if(ite->id == id)
				{
					ite = q.erase(ite);
				}
				else
				{
					if(ite->rest <= rest)
					{
						waiting.insert(ite->id);
						ite = q.erase(ite);
					}
					else
					{
						ite->rest -= rest;
						++ite;
					}
				}
			}
		}

		int id = *waiting.begin();
		waiting.erase(waiting.begin());
		q.push_back(b_info_t{id, list[id]});
		last_id = id;
		--n;
	}

	return last_id + 1;
}

void solve(istream& in, ostream& out)
{
	int total_t;
	in >> total_t;
	for(int t = 0; t < total_t; ++t)
	{
		int b, n;
		in >> b >> n;
		vector<int> list(b);
		for(int i = 0; i < b; ++i)
		{
			in >> list[i];
		}
		print_result(out, t, solve(list, n));
	}

}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	if(argc == 2)
	{
		ifstream in(argv[1]);
		string out_path = argv[1];
		out_path += ".result";
		ofstream out(out_path);
		solve(in, out);
	}
	else
	{
		solve(cin, cout);
	}
	return 0;
}

