#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int memo[MAX][MAX];

int helper(char *ring, char *key, int i, int j, int n) {
  if (key[j] == '\0')
    return 0;

  if (memo[i][j] != -1)
    return memo[i][j];
  
  int custo_min = INT_MAX;
    
  for (int k = 0; k < n; k++) {
    if (ring[k] == key[j]) {
      int diff = abs(i - k);
      int dist = diff < (n - diff) ? diff : (n - diff);
      int h = helper(ring, key, k, j + 1, n);
      memo[k][j + 1] = h;
      int total = dist + 1 + h;
      if (total < custo_min)
        custo_min = total;
    }
  }

  return custo_min;
}

int findRotateSteps(char *ring, char *key) {
  memset(memo, -1, sizeof(memo));
  return helper(ring, key, 0, 0, strlen(ring));
}
