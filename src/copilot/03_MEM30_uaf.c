#include <stdlib.h>
#include <string.h>

// fix

const size_t BUFFERSIZE = sizeof(int) * 10;

int main(int argc, const char *argv[]) {
  char *buff;

  buff = (char *)malloc(BUFFERSIZE);
  if (!buff) {
     /* エラー条件の処理 */
  }
  /* ... */
  if (argc > 1) {
    strncpy(buff, argv[1], BUFFERSIZE-1);
  }
  /* ... */
  free(buff);
}
