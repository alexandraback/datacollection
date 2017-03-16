//////////////////////////////////////////////////// BEGIN OF SOLUTION ////////////////////////////////////////////////////
//////////////////////////////////////////////////// BEGIN OF SOLUTION ////////////////////////////////////////////////////
//////////////////////////////////////////////////// BEGIN OF SOLUTION ////////////////////////////////////////////////////
//////////////////////////////////////////////////// BEGIN OF SOLUTION ////////////////////////////////////////////////////
//////////////////////////////////////////////////// BEGIN OF SOLUTION ////////////////////////////////////////////////////
//////////////////////////////////////////////////// BEGIN OF SOLUTION ////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;

void preprocess() {

}

void process_testcase(const int testcase, const int should_run) {
    int n;
    scanf("%d", &n);
    int v[n+1];
    for (int i = 1; i <= n; ++i)
        scanf("%d", v+i);
    if (should_run) {
        printf("Case #%d:", testcase);
        for (;;) {
            int total = 0;
            for (int i = 1; i <= n; ++i)
                total += v[i];
            int first = 1;
            while (first <= n && v[first] == 0) ++first;
            if (first == n+1)
                break;
            for (int i = 1; i <= n; ++i)
                if (v[i] > v[first])
                    first = i;
            int second = 1;
            while (second <= n && (second == first || v[second] == 0)) ++second;
            assert(second != n+1);
            for (int i = 1; i <= n; ++i)
                if (i != first && v[i] > v[second])
                    second = i;
            if (v[first]+v[second] == total && v[first] == v[second]) {
                printf(" %c%c", 'A'+first-1, 'A'+second-1);
                --v[first];
                --v[second];
            } else {
                printf(" %c", 'A'+first-1);
                --v[first];
            }
        }
        putchar('\n');
    }
}
//////////////////////////////////////////////////// END OF SOLUTION ////////////////////////////////////////////////////
//////////////////////////////////////////////////// END OF SOLUTION ////////////////////////////////////////////////////
//////////////////////////////////////////////////// END OF SOLUTION ////////////////////////////////////////////////////
//////////////////////////////////////////////////// END OF SOLUTION ////////////////////////////////////////////////////
//////////////////////////////////////////////////// END OF SOLUTION ////////////////////////////////////////////////////
//////////////////////////////////////////////////// END OF SOLUTION ////////////////////////////////////////////////////

#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void naive(const char* input_filename, const char* output_filename) {
    // Redirect standard input
    if (!freopen(input_filename, "r", stdin)) {
        fprintf(stderr, "unable to open input file: %s\n", input_filename);
        exit(4);
    }
    // Redirect standard output
    if (!freopen(output_filename, "w", stdout)) {
        fprintf(stderr, "unable to open output file: %s\n", output_filename);
        exit(5);
    }
    // Preprocess
    preprocess();
    // Sequentially process testcases
    int testcases;
    scanf("%d", &testcases);
    for (int testcase = 1; testcase <= testcases; ++testcase)
        process_testcase(testcase, 1);
}

void better(const char* input_filename, const char* output_filename) {
    // Redirect standard input
    if (!freopen(input_filename, "r", stdin)) {
        fprintf(stderr, "unable to open input file: %s\n", input_filename);
        exit(6);
    }
    // Open output file
    FILE* const output_file = fopen(output_filename, "w");
    if (!output_file) {
        fprintf(stderr, "unable to open output file: %s\n", output_filename);
        exit(7);
    }
    // Retrieve the number of cores
    const int cores = sysconf(_SC_NPROCESSORS_ONLN);
    printf("Number of cores: %d\n", cores);
    // Retrieve the number of testcases
    int testcases;
    scanf("%d ", &testcases);
    printf("Number of testcases: %d\n", testcases);
    // Retrieve testcase sizes
    int testcase_size[testcases+1];
    int pos = ftell(stdin);
    for (int testcase = 1; testcase <= testcases; ++testcase) {
        const int old_pos = pos;
        process_testcase(testcase, 0);
        scanf(" ");
        pos = ftell(stdin);
        testcase_size[testcase] = pos - old_pos;
    }
    // Make sure that the entire input has been read
    if (getchar() != EOF) {
        fprintf(stderr, "the entire input has not been read\n");
        exit(8);
    }
    // Preprocess
    preprocess();
    // Start children processes
    int children_input_pipe[testcases+1][2], children_output_pipe[testcases+1][2];
    pid_t children_pid[testcases+1];
    for (int testcase = 1; testcase <= testcases; ++testcase) {
        // Create the pipes
        if (pipe(children_input_pipe[testcase]) < 0) {
            fprintf(stderr, "unable to create child input pipe\n");
            exit(9);
        }
        if (pipe(children_output_pipe[testcase]) < 0) {
            fprintf(stderr, "unable to create child output pipe\n");
            exit(10);
        }
        // Create the child process
        children_pid[testcase] = fork();
        if (children_pid[testcase] < 0) {
            fprintf(stderr, "unable to create child process\n");
            exit(11);
        }
        if (children_pid[testcase] == 0) {
            // Redirect stderr to /dev/null
            if (!freopen("/dev/null", "w", stderr)) {
                exit(12);
            }
            // Close the write-end of the input pipe
            if (close(children_input_pipe[testcase][1]) < 0) {
                exit(13);
            }
            // Close the read-end of the output pipe
            if (close(children_output_pipe[testcase][0]) < 0) {
                exit(14);
            }
            // Redirect the read-end of the input pipe to stdin
            if (dup2(children_input_pipe[testcase][0], STDIN_FILENO) < 0) {
                exit(15);
            }
            // Redirect the write-end of the output pipe to stdout
            if (dup2(children_output_pipe[testcase][1], STDOUT_FILENO) < 0) {
                exit(16);
            }
            // Process a testcase
            process_testcase(testcase, 1);
            // Close the read-end of the input pipe
            if (close(children_input_pipe[testcase][0]) < 0) {
                exit(17);
            }
            // Close the write-end of the output pipe
            if (close(children_output_pipe[testcase][1]) < 0) {
                exit(18);
            }
            // Exit
            exit(0);
        }
        // Close the read-end of the input pipe
        if (close(children_input_pipe[testcase][0]) < 0) {
            fprintf(stderr, "unable to close the read-end of the input pipe from the parent\n");
            exit(19);
        }
        // Close the write-end of the output pipe
        if (close(children_output_pipe[testcase][1]) < 0) {
            fprintf(stderr, "unable to close the write-end of the output pipe from the parent\n");
            exit(20);
        }
    }
    // Rewind standard input by reopening the file
    if (!freopen(input_filename, "r", stdin)) {
        fprintf(stderr, "unable to reopen input file: %s\n", input_filename);
        exit(21);
    }
    // Skip the number of tescases
    scanf("%*d ");
    // Read testcases and send them to the corresponding processes
    int children_running = 0;
    for (int testcase = 1; testcase <= testcases; ++testcase) {
        // Wait
        if (children_running == cores) {
            int status;
            if (wait(&status) < 0) {
                fprintf(stderr, "unable to wait for child process\n");
                exit(22);
            }
            if (status != 0) {
                fprintf(stderr, "child process did not terminate successfully: %d\n", status);
                exit(23);
            }
        } else {
            ++children_running;
        }
        // Forward testcase to the corresponding child process
        printf("Starting case %d...\n", testcase);
        const int BUFFER_SIZE = 4096;
        char buffer[BUFFER_SIZE];
        int remaining_bytes = testcase_size[testcase];
        while (remaining_bytes > 0) {
            const int bytes_requested = BUFFER_SIZE <= remaining_bytes ? BUFFER_SIZE : remaining_bytes;
            const int bytes_read = fread(buffer, sizeof(char), bytes_requested, stdin);
            if (bytes_requested != bytes_read) {
                fprintf(stderr, "error while reading data from input file\n");
                exit(24);
            }
            write(children_input_pipe[testcase][1], buffer, bytes_read);
            remaining_bytes -= bytes_read;
        }
        // Close the write-end of the input pipe
        if (close(children_input_pipe[testcase][1]) < 0) {
            fprintf(stderr, "unable to close the write-end of the input pipe from the parent");
            exit(25);
        }
    }
    // Make sure that all children terminate successfully
    while (children_running > 0) {
        int status;
        if (wait(&status) < 0) {
            fprintf(stderr, "unable to wait for child process\n");
            exit(26);
        }
        if (status != 0) {
            fprintf(stderr, "child process did not terminate successfully\n");
            exit(27);
        }
        --children_running;
    }
    // Write results to the output file
    puts("Writing results...");
    for (int testcase = 1; testcase <= testcases; ++testcase) {
        const int BUFFER_SIZE = 4096;
        char buffer[BUFFER_SIZE];
        for (;;) {
            const int bytes_read = read(children_output_pipe[testcase][0], buffer, BUFFER_SIZE);
            if (bytes_read == 0)
                break;
            fwrite(buffer, sizeof(char), bytes_read, output_file);
        }
        // Close the read-end of the output pipe
        if (close(children_output_pipe[testcase][0]) < 0) {
            fprintf(stderr, "unable to close the read-end of the output pipe from the parent");
            exit(28);
        }
    }
    // Close the output file
    fclose(output_file);
    // Display finish message
    puts("Finished!");
}

int main(int argc, char** argv) {
    // Validate arguments
    if (argc != 2) {
        fprintf(stderr, "expected one argument, received %d instead\n", argc-1);
        exit(1);
    }
    const int filename_len = strlen(argv[1]);
    if (filename_len > 70) {
        fprintf(stderr, "input filename is too long\n");
        exit(2);
    }
    if (filename_len < 3 || argv[1][filename_len-3] != '.' || argv[1][filename_len-2] != 'i' || argv[1][filename_len-1] != 'n') {
        fprintf(stderr, "input filename does not end with '.in'\n");
        exit(3);
    }
    // Retrieve filenames
    char input_filename[80];
    strcpy(input_filename, argv[1]);
    char output_filename[80];
    strcpy(output_filename, argv[1]);
    output_filename[filename_len-2] = 'o';
    output_filename[filename_len-1] = 'u';
    output_filename[filename_len] = 't';
    output_filename[filename_len+1] = '\0';
    // Process testcases
    #ifdef SEQUENTIAL
        naive(input_filename, output_filename);
    #else
        better(input_filename, output_filename);
    #endif
}
