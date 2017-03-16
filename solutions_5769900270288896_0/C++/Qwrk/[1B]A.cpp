#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <future>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <string>
#include <sstream>
#include <memory>
#include <atomic>
#include <queue>
#include <array>
#include <functional>

// -----
// =====

int check(int _r, int _c, std::vector<std::vector<bool>> const &_map)
{
	int res = 0;
	for (int r = 0; r < _r - 1; ++ r) {
		for (int c = 0; c < _c; ++c) {
			if (_map[r][c] && _map[r][c] == _map[r+1][c]) {
				++res;
			}
		}
	}
	for (int r = 0; r < _r; ++r) {
		for (int c = 0; c < _c - 1; ++c) {
			if (_map[r][c] && _map[r][c] == _map[r][c+1]) {
				++res;
			}
		}
	}
	return res;
}

std::vector<bool> to_bits(int _r, int _c, int _v, int &_s)
{
	_s = 0;
	int idx = 0;
	std::vector<bool> result(_r * _c, 0);
	while (_v != 0) {
		result[idx++] = _v & 1;
		_s += _v & 1;
		_v /= 2;
	}
	return result;
}

std::vector<std::vector<bool>> reshape(int _r, int _c, std::vector<bool> const &_v)
{
	std::vector<std::vector<bool>> result(_r, std::vector<bool>(_c, 0));
	for (int i = 0; i < _r; ++i) {
		for (int j = 0; j < _c; ++j) {
			result[i][j] = _v[i * _c + j];
		}
	}	
	return result;
}

struct Solution
{
	int case_id;
	/* Input fields HERE */
	int R, C, N;
	// ------------------- 

	void read(int _case)
	{
		case_id = _case;
		/* Reading input HERE */
		std::cin >> R >> C >> N;
		// --------------------
	}

	std::stringstream solve()
	{
		std::stringstream out;
		out << "Case #" << case_id << ": ";
		/*  Solution HERE  */
		int best = 1000000, s;
		for (int i = 1; i < (1 << (R * C)); ++i) {
			std::vector<bool> d = to_bits(R, C, i, s);
			if (s == N) {
				best = std::min(best, check(R, C, reshape(R, C, d)));
			}
		}
		out << (N == 0 ? 0 : best) << '\n';
		// -----------------
		return out;
	}
};

// ---- Thread-safe Queue template

template <class F>
class thread_pool;

template <class R, class ...Args>
class thread_pool<R(Args...)>
{
public:
	using task_type = std::packaged_task<R(Args...)>;

	thread_pool(unsigned int thread_count = std::thread::hardware_concurrency()) 
	{
		finish.store(false);
		for (unsigned int t = 0; t < thread_count; ++t) {
			threads.emplace_back(&thread_pool::thread_function, this);
		}
	}

	~thread_pool()
	{
		if (!finish.load()) {
			shutdown();
		}
	}

	std::future<R> submit(std::function<R(Args...)> &&data)
	{
		std::shared_ptr<task_type> task = std::make_shared<task_type>(task_type(data));
		std::future<R> result = task->get_future();
		std::unique_lock<std::mutex> lock(mutex);
		queue.push(task);
		lock.unlock();
		non_empty_cond.notify_one();
		return result;
	}

	void shutdown()
	{
		finish.store(true);
		non_empty_cond.notify_all();
		for (auto &thread : threads) {
			thread.join();
		}
		threads.clear();
	}

	bool flag()
	{
		return finish.load();
	}

private:
	std::shared_ptr<task_type> pop_task()
	{
		std::unique_lock<std::mutex> lock(mutex);
		while (!finish.load() && queue.empty()) {
			non_empty_cond.wait(lock);
		}
		if (finish.load()) {
			return std::shared_ptr<task_type>();
		}
		std::shared_ptr<task_type> result;
		queue.front().swap(result);
		queue.pop();
		return result;
	}

	void thread_function()
	{
		std::cerr << "Thread " << std::this_thread::get_id() << " started.\n";
		while (!flag()) {
			std::shared_ptr<task_type> task = pop_task();
			if (task) {
				(*task)();
			}
		}
		std::cerr << "Thread " << std::this_thread::get_id() << " finished.\n";
	}

	
	std::vector<std::thread>				threads;
	std::atomic<bool>						finish;
	std::mutex								mutex;
	std::condition_variable					non_empty_cond;
	std::queue<std::shared_ptr<task_type>>	queue;
};

// -----


// -----
// =====


int main()
{
	thread_pool<std::stringstream()>			pool;
	std::vector<std::future<std::stringstream>>	results;

	int T; std::cin >> T;
	for (int c = 1; c <= T; ++c) {
		std::shared_ptr<Solution> solution = std::make_shared<Solution>();
		solution->read(c);
		results.push_back(pool.submit(std::bind(&Solution::solve, solution)));
	}

	for (auto &out : results) {
		std::cout << out.get().str();
	}

	return 0;
}