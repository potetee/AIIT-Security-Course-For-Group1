#include <string.h>
#include <assert.h>

// fix

enum {ARR_LEN = 100};

void clear(int a[], size_t size) {
  memset(a, 0, size * sizeof(int));
}

int main(void) {
  int b[ARR_LEN];
  clear(b, ARR_LEN);
  assert(b[ARR_LEN / 2]==0);
  return 0;
}
