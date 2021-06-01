#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float wp[3001];

float wallis_pi(int n) {
  if (wp[n] >= 0) return wp[n];
  float p = 4*n*n;
  wp[n] = (p/(p-1))*wallis_pi(n-1);
  return wp[n];
}

int main(void) {
  float pi;
  wp[0] = 0;
  wp[1] = 8.0/3;
  for (int i = 2; i <= 3001; i++) {
    wp[i] = -1;
  }
  for (int i=0; i<5; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) > 0.15)) {
      printf("Estimate with just %d iterations is %f which is too accurate.\n", i, pi);
      abort();
    }
  }

  for (int i=500; i<3000; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) < 0.01)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi);
      abort();
    }
  }
}

