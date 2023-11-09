void main() {
  char *file_name;
  FILE *fp;

  /* file_name を初期化 */

  fp = fopen(file_name, "w");
  if (!fp) {
    /* エラー処理 */
  }
}
