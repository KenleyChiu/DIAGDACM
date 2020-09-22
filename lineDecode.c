#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char c, d, out;
  char curr = '0', nextBit = '1';
  int cInt, dInt;
  while (1) {
    c = fgetc(stdin);
    if (feof(stdin) || ferror(stdin)) {
      break;
    } else if (c == '|') {
      printf("|");
    } else {
      if (c == '1') {
        cInt = 1;
      } else if (c == '-') {
        cInt = -1;
        c = fgetc(stdin);
      }
      d = fgetc(stdin);
      if (d == '1') {
        dInt = 1;
      } else if (d == '-') {
        dInt = -1;
        d = fgetc(stdin);
      }
      if (cInt == dInt) {
        printf("0");
      } else {
        printf("1");
      }
    }
  }
  return 0;
}