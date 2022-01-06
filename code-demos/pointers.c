//libraries
//files that we need to include
#include <stdio.h>
#include <math.h>
#include <ctype.h>

void change_num (int * nump);

int main(void) {
  int num = 5;
  int * nump;
  nump = &num;
  printf("Contents of num: %d\n", num);
  printf("num is stored at memory location %p\n", &num);
  //scanf("%d", &num);
  printf("Value of nump = &num: %p\n", nump);
  printf("nump has its own address through %p\n", &nump);
  printf("getting the value of num via nump: %d\n", *nump);

  change_num(&num);
  printf("Contents of num: %d\n", num);
  printf("getting the value of num via nump: %d\n", *nump);
  change_num(nump);
  printf("Contents of num: %d\n", num);
  printf("getting the value of num via nump: %d\n", *nump);

  return 0; 
}

void change_num (int * nump){
  *nump = 18;
  printf("Enter a new number");
  scanf("%d", nump);
}
