#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


//=====================================================
// Define
//=====================================================
#define DEBUG 1
#define SQUARE_SIZE 4


//=====================================================
// Variables
//=====================================================


//=====================================================
// Struct
//=====================================================

//=====================================================
// Utils
//=====================================================


//=====================================================
// Functions
//=====================================================

//=====================================================
// MAIN
//=====================================================

int main (int argc, char **argv) {
  //=====================
  // Variables
  //=====================
  char *in_filename  = NULL;
  char *out_filename = NULL; 

  FILE * fd_in;
  FILE * fd_out;

  int TEST_CASE_NB;

  int c;
  int r;

  //======================
  // Parse input
  //======================
  opterr = 0;

  while ((c = getopt (argc, argv, "i:o:")) != -1)
    switch (c)
      {
      case 'i':
        in_filename = optarg;
        break;
      case 'o':
        out_filename = optarg;
        break;

      case '?':
        if (optopt == 'i' ||
            optopt == 'o')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }


  //======================
  // Open Files
  //======================
  fd_in = fopen(in_filename,"r");
  if (fd_in == NULL) {
    fprintf(stderr, "> ERROR : cannot open %s\n", in_filename);
    exit(EXIT_FAILURE);
  }
  fd_out = fopen(out_filename,"w");
  if (fd_out == NULL) {
    fprintf(stderr, "> ERROR : cannot open %s\n", out_filename);
    exit(EXIT_FAILURE);
  }

  //======================
  // Parse TEST_CASE_CNT
  //======================
  r = fscanf(fd_in,"%d",&TEST_CASE_NB);
  if (r==0) {
    fprintf(stderr,"> ERROR : Wrong input format - TEST_CASE_NB not recognized\n");
    exit(EXIT_FAILURE);
  }

#ifdef DEBUG
  fprintf(stdout,"TEST_CASE_NB=%d\n",TEST_CASE_NB);
#endif

  //======================
  // Malloc
  //======================

  //======================
  // Process
  //======================
  int test_case_cnt;
  int first_answer[4];
  int tmp[4];
  int answer_1;
  int i_0, i_1,i_2;
  int found_cnt;
  int match_value;
  for (test_case_cnt=1; test_case_cnt<=TEST_CASE_NB; test_case_cnt++) {
    found_cnt = 0;
#ifdef DEBUG
  fprintf(stdout,"test_case=%d\n",test_case_cnt);
#endif

    // first answer parsing
    r = fscanf(fd_in,"%d",&answer_1);
    if (r==0) {
      fprintf(stderr,"> ERROR : Wrong input format - answer_1 not recognized\n");
      exit(EXIT_FAILURE);
    }
    for (i_0=1; i_0<=4; i_0=i_0+1) {
      if (i_0 == answer_1) {
	r = fscanf(fd_in,"%d %d %d %d",&first_answer[0],&first_answer[1],&first_answer[2],&first_answer[3]);
      }
      else {
	r = fscanf(fd_in,"%d %d %d %d",&tmp[0],&tmp[1],&tmp[2],&tmp[3]);
      }
      if (r==0) {
        fprintf(stderr,"> ERROR : Wrong input format - line not recognized\n");
        exit(EXIT_FAILURE);
      }
    }

#ifdef DEBUG
  fprintf(stdout,"1rst line %d %d %d %d \n",first_answer[0], first_answer[1], first_answer[2], first_answer[3]);
#endif

    // 2nd answer parsing
    r = fscanf(fd_in,"%d",&answer_1);
    if (r==0) {
      fprintf(stderr,"> ERROR : Wrong input format - answer_2 not recognized\n");
      exit(EXIT_FAILURE);
    }
    for (i_0=1; i_0<=4; i_0=i_0+1) {
      r = fscanf(fd_in,"%d %d %d %d",&tmp[0],&tmp[1],&tmp[2],&tmp[3]);
      if (r==0) {
        fprintf(stderr,"> ERROR : Wrong input format - line not recognized\n");
        exit(EXIT_FAILURE);
      }
      if (i_0 == answer_1) { // matching
#ifdef DEBUG
  fprintf(stdout,"2nd line %d %d %d %d \n",tmp[0], tmp[1], tmp[2], tmp[3]);
#endif

        for (i_1=0; i_1<4; i_1++) {
          for (i_2=0; i_2<4; i_2++) {
            if (tmp[i_1] == first_answer[i_2]) {
              found_cnt = found_cnt + 1;
              match_value = tmp[i_1];
            }
          }
        }
        fprintf(fd_out,"Case #%d: ",test_case_cnt);
        if (found_cnt == 0) fprintf(fd_out,"Volunteer cheated!\n");
        else if (found_cnt == 1) fprintf(fd_out,"%d\n",match_value);
        else fprintf(fd_out,"Bad magician!\n");
      }
    }
    
  } // for test_case_cnt

  //======================
  // Close Files
  //======================
  fclose(fd_in);
  fclose(fd_out); 

  //======================
  // Free
  //======================

  return 0;
}
