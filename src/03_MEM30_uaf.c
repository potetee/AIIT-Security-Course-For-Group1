int main(int argc, const char *argv[]) {
  char *buff;

  buff = (char *)malloc(BUFFERSIZE);
  if (!buff) {
     /* エラー条件の処理 */
  }
  /* ... */
  free(buff);
  /* ... */
  strncpy(buff, argv[1], BUFFERSIZE-1);
}
