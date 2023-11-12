#include <stdio.h>

// fix more secure

int main() {
  char *file_name = "example.txt"; // Initialize file_name with the name of the file you want to open
  FILE *fp;

  fp = fopen_s(&fp, file_name, "w");
  if (fp == NULL) {
    /* エラー処理 */
    printf("Failed to open file %s\n", file_name);
    return 1;
  }

  /* ファイルに書き込み */
  fprintf_s(fp, "Hello, world!\n");

  fclose(fp);

  return 0;
}
