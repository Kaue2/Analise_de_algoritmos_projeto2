#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#define MAX 2048
int vec[MAX][MAX];

bool helperMatch(char *s, char *p, int i, int j) {
  if (vec[i][j] == -1)
    return false;
  
  if (s[i] == '\0' && p[j] == '\0')
    return true; 

  
  if (p[j] == '*') {
    int k = i;
    while (s[k] != '\0') {
      bool ret = helperMatch(s, p, k, j + 1);      
      vec[k][j] = ret ? 1 : -1;
      if (ret)
        return true;
      k++;
    }
    i = k;

    if (helperMatch(s, p, i, j + 1))
      return true;
  }

  if ((s[i] == '\0' && p[j] != '\0') || (s[i] != '\0' && p[j] == '\0')) {
    vec[i][j] = -1;
    return false;
  }

  if (s[i] == p[j]) {
    bool ret = helperMatch(s, p, i + 1, j + 1);
    vec[i][j] = ret ? 1 : -1; 
    return ret;
  }

  if (p[j] == '?'){
    bool ret = helperMatch(s, p, i + 1, j + 1);
    vec[i][j] = ret ? 1 : -1;
    return ret;
  }

  return false;
}


bool isMatch(char *s, char *p) {
  memset(vec, 0, sizeof(vec));
  return helperMatch(s, p, 0, 0);
}

