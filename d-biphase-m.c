#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100

int getInt(char c) { return c - 49; }

int *biM(int in[], int len) {
  int *out = (int *)malloc(sizeof(int) * len);
  int ind = 0;
  for (size_t i = 0; i < len; i++) {
    size_t j = i * 2, k = i * 2 + 1;
    // printf("%i, %i\n", in[j], in[k]);
    if (in[j] == in[k]) {
      out[ind] = 0;
    } else {
      out[ind] = 1;
    }
    printf("%i", out[ind]);
  }
  return out;
}

int strToIntArr(char *in, int len, int *out) {
  int ind = 0;
  for (size_t i = 0; i < len; i++) {
    // printf("%c", in[i]);
    if (in[i] == '0') {
      out[ind] = 0;
      ind++;
    } else if (in[i] == '-' && in[i + 1] == '1') {
      out[ind] = -1;
      ind++;
    } else if (in[i - 1] != '-' && in[i] == '1') {
      out[ind] = 1;
      ind++;
    }
  }
  return ind;
}

int main() {
  char in[MAXLEN];
  char *out;
  int med[MAXLEN];
  // reads the echo

  scanf("%s", in);

  int len = strToIntArr(in, strlen(in), med);
  // printf("%i", len);
  out = biM(med, len / 2);
  /*
  for (size_t i = 0; i < (len / 2) + 1; i++) {
    printf("%c", out[i]);
  }
  */

  return 0;
}
