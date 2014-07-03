//generate test csv with random chars/ints

#include <stdio.h>
#include <stdlib.h>

double iterations=50000000;

 
int main() {
  int smallc, c, n, n1, nletter;
  char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int num_of_letters = 25;

  //header
  //printf("index,one_char,two_char,three_char,four_char,five_char,six_char,rand_int\n");
 
  for (c = 1; c <= iterations; c++) {


    n = rand()%99999 + 1;
    n1 = rand()%99999 + 1;
    printf("%d,", c);
     
    for (smallc = 0; smallc <= 0; smallc++) {
      nletter = rand() % num_of_letters;
      printf("%c", letters[nletter]);
    }

    printf(",");

    for (smallc = 0; smallc <= 1; smallc++) {
      nletter = rand() % num_of_letters;
      printf("%c", letters[nletter]);
    }
 
    printf(",");

    for (smallc = 0; smallc <= 2; smallc++) {
      nletter = rand() % num_of_letters;
      printf("%c", letters[nletter]);
    }
 
    printf(",");

    for (smallc = 0; smallc <= 3; smallc++) {
      nletter = rand() % num_of_letters;
      printf("%c", letters[nletter]);
    }
 
    printf(",");

    for (smallc = 0; smallc <= 4; smallc++) {
      nletter = rand() % num_of_letters;
      printf("%c", letters[nletter]);
    }

    printf(",");

 for (smallc = 0; smallc <= 5; smallc++) {
      nletter = rand() % num_of_letters;
      printf("%c", letters[nletter]);
    }



    printf(",%d", n);
    printf("%d", n1);
    printf("\n");
  }
 
  return 0;
}
