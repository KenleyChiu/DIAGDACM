#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100

int getInt(char c) { return c - 49; }

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

void intArrToStr(int *in, int len, char out[]) {
  for (size_t i = 0; i < len; i++) {
    if (in[i] == 1) {
      strncat(out, "1", 2);
    } else if (in[i] == -1) {
      strncat(out, "-1", 3);
    }
  }
  out += 3;
}

int main() {
  char in[MAXLEN];
  char med[MAXLEN];
  char *out;
  strncat(med, " ", 1);

  scanf("%s", in);
  int sum = 0, len = strlen(in);
  int *arr;
  arr = (int *)malloc(sizeof(int) * len);
  for (size_t i = 0; i < strlen(in); i++) {
    arr[i] = in[i] - '0';
  }

  int *encode = biM(arr, len);
  intArrToStr(encode, len * 2, med);
  out = med + 4;
  puts(out);
  return 0;
}
