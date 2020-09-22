#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char c, out;
  char curr = '0', nextBit = '1';
  int currInt = 0, nextInt = 1;
  while (1) {
    c = fgetc(stdin);
    if (feof(stdin) || ferror(stdin)) {
      break;
    } else if (c == '|') {
      printf("|");
    } else {
      if (c == '1') {
        currInt = 1;
      } else if (c == '0') {
        currInt = 0;
      }
      printf("%i", nextInt);
      if (currInt == 1) {
        nextInt *= -1;
        printf("%i", nextInt);
      } else if (currInt == 0) {
        printf("%i", nextInt);
      }
      nextInt *= -1;
    }
  }

  return 0;
}

/*
int *biM(int in[], int len) {
  int *out = (int *)malloc(sizeof(int) * len * 2);
  int nextBit = 1;
  int curr = 0;
  for (size_t i = 0; i < len; i++) {
    curr = in[i];
    out[i * 2] = nextBit;
    if (curr == 1) {
      nextBit *= -1;
      out[i * 2 + 1] = nextBit;
    } else if (curr == 0) {
      out[i * 2 + 1] = nextBit;
    }
    nextBit *= -1;
  }
  return out;
}
 */