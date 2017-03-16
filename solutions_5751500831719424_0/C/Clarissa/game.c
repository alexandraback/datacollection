#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

void count(char** word_array, char** unique_array, int** count_array,
           int n_words){
    /* 
     * Sets up the arrays by splitting words into unique characters and
     * counting them.
     */
    int word, index;
    int tmp_wordlen;
    char tmp_char;
    int char_count;
    int unique_index;
    for(word = 0; word < n_words; word++){
        tmp_wordlen = strlen(word_array[word]);
        unique_index = 0;
        char_count = -1;
        tmp_char = '0';
        
        for(index = 0; index < tmp_wordlen; index++){
            if(tmp_char == word_array[word][index]){
                char_count++;
            } else {
                if(unique_index > 0){
                    count_array[word][unique_index-1] = char_count;
                }
                tmp_char = word_array[word][index];
                char_count = 1;
                unique_array[word][unique_index] = tmp_char;
                unique_index++;
            }
        }
        unique_array[word][unique_index] = '\0';
        count_array[word][unique_index-1] = char_count;
    }
}

int compare(const void* a, const void* b){
    int a_int = *(int*) a;
    int b_int = *(int*) b;
    return (b_int < a_int) - (a_int < b_int);
}

int findWinner(char** unique_array, int** count_array, int n_words){
    int word, index;
    /* Sanity check: are all words the same? */
    for(word = 0; word < n_words-1; word++){
        if(strcmp(unique_array[word], unique_array[word+1]) != 0){
            return -1;
        }
    }
    
    int n_chars = strlen(unique_array[0]);
    int total_moves = 0;
    /* All words are the same. Find the best one. */
    for(index = 0; index < n_chars; index++){
        int* counts = malloc(sizeof(int)*n_words);
        for(word = 0; word < n_words; word++){
            counts[word] = count_array[word][index];
        }
        
        int median_index = n_words/2;
        qsort(counts, n_words, sizeof(int), compare);
        
        for(word = 0; word < n_words; word++){
            total_moves += abs(counts[word]-counts[median_index]);
        }
        
        free(counts);
    }
    
    return total_moves;
}

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Forgot file name or added extra arguments.\n");
        return -1;
    }
    
    FILE* fp = fopen(argv[1], "r");
        
    int n_inputs = 0;
    fscanf(fp, "%d", &n_inputs);
    
    int test_case;
    int word;
    int n_words;
    int winning_moves;
    
    for(test_case = 0; test_case < n_inputs; test_case++){
        /* Initialize empty word arrays */
        fscanf(fp, "%d", &n_words);
        char** word_array = malloc(sizeof(char*)*n_words);
        char** unique_array = malloc(sizeof(char*)*n_words);
        int** count_array = malloc(sizeof(int*)*n_words);
        
        for(word = 0; word < n_words; word++){
            word_array[word] = malloc(sizeof(char)*100);
            count_array[word] = malloc(sizeof(int)*100);
            unique_array[word] = malloc(sizeof(char)*100);
            fscanf(fp, "%s", word_array[word]);
        }
        /* Step 1: split words into unique characters, counting chars */
        count(word_array, unique_array, count_array, n_words);
        winning_moves = findWinner(unique_array, count_array, n_words);
        
        /* Print results */
        if(winning_moves < 0){
            printf("Case #%d: %s\n", test_case+1, "Fegla Won");
        } else {
            
            printf("Case #%d: %d\n", test_case+1, winning_moves);
        }
        
        /* Don't leak */
        for(word = 0; word < n_words; word++){
            free(word_array[word]);
            free(unique_array[word]);
            free(count_array[word]);
        }
        free(word_array);
        free(count_array);
        free(unique_array);
    }
    
    fclose(fp);
    
    return 1;
}
