#include <stdlib.h>
#include <stdio.h>

void trstr(char *str, char orig, char rep) {
  while (*str != '\0') {
    if (*str == orig) {
      *str = rep;
    }
    str++;
  }
}

int main() {
  char *env = getenv("TEST_ENV");
  if (env == NULL) {
    /* エラー処理 */
  }

  trstr(env,'"', '_');

  return 0;
}
