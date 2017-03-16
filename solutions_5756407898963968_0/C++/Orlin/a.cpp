#include <queue>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

#include <pthread.h>

const bool MULTITHREADED = true;
const int NUM_WORKERS = 8;

using std::string;
using std::vector;

struct input_t {
    void read() {
        std::cin >> answer1;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                std::cin >> board1[i][j];

        std::cin >> answer2;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                std::cin >> board2[i][j];
    }

    int answer1;
    int answer2;
    int board1[4][4];
    int board2[4][4];
};

struct output_t {
    void write(const int& case_number) {
        std::cout << "Case #" << case_number << ": ";
        if (answer == -1)
            std::cout << "Bad magician!\n";
        else if (answer == -2)
            std::cout << "Volunteer cheated!\n";
        else std::cout << answer << '\n';
    }

    int answer;
};

output_t solve(const input_t& input) {
    output_t output;
    output.answer = -2;
    vector<bool> seen(17, false);
    
    for (int j = 0; j < 4; j++)
        seen[input.board1[input.answer1-1][j]] = true;

    for (int j = 0; j < 4; j++) {
        int curr = input.board2[input.answer2-1][j];
        if (seen[curr]) {
            if (output.answer != -2) {
                output.answer = -1;
                break;
            }

            output.answer = curr;
        }
    }

    return output;
}

struct environment {
    environment(const vector<input_t>& in, vector<output_t>& out)
        : input(in), output(out), task_queue() {

        for (int i = 0; i < (int)input.size(); i++) task_queue.push(i);
        pthread_mutex_init(&queue_mutex, NULL);
    }

    ~environment() {
        pthread_mutex_destroy(&queue_mutex);
    }

    const vector<input_t>& input;
    vector<output_t>& output;
    std::queue<int> task_queue;
    pthread_mutex_t queue_mutex;
};

void* worker_thread(void* _env) {
    environment& env = *(reinterpret_cast<environment*>(_env));

    while (true) {
        int task = -1;
        pthread_mutex_lock(&env.queue_mutex);
        if (!env.task_queue.empty()) {
            task = env.task_queue.front();
            env.task_queue.pop();
        }
        pthread_mutex_unlock(&env.queue_mutex);
    
        if (task == -1) break;

        env.output[task] = solve(env.input[task]);
    }

    return NULL;
}

void solve_all(const vector<input_t>& input, vector<output_t>& output) {
    environment env(input, output);

    vector<pthread_t> threads(NUM_WORKERS);
    for (int i = 0; i < NUM_WORKERS; i++)
        pthread_create(&(threads[i]), NULL, worker_thread, &env);

    for (int i = 0; i < NUM_WORKERS; i++)
        pthread_join(threads[i], NULL);
}

int main() {
    int tests;
    string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    iss >> tests;

    vector<input_t> input(tests);
    vector<output_t> output(tests);
    for (int i = 0; i < tests; i++)
        input[i].read();

    if (MULTITHREADED)
        solve_all(input, output);
    else 
        for (int i = 0; i < tests; i++)
            output[i] = solve(input[i]);

    for (int i = 0; i < tests; i++)
        output[i].write(i+1);

    return 0;
}
