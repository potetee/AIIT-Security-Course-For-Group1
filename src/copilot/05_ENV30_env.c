#include <stdlib.h>
#include <stdio.h>

/*
Github copilotに聞いてみる

Q. セキュリティや安定・安全性の観点で問題がある部分はありますか？

A.
このコードにはいくつかのセキュリティと安全性に関する問題があります。

getenv関数から返されるポインタは、環境変数の値を指しています。この値は読み取り専用であり、
書き込みを試みると未定義の動作を引き起こす可能性があります。しかし、このコードではtrstr関数によって環境変数の値が直接変更されています。

getenv関数がNULLを返した場合、つまり"TEST_ENV"という環境変数が存在しない場合、
エラー処理がコメントアウトされており、何も行われません。その後、trstr関数が呼び出されますが、この時点でenvはNULLです。
これはセグメンテーション違反を引き起こし、プログラムがクラッシュする可能性があります。

これらの問題を解決するためには、環境変数の値を直接変更するのではなく、その値のコピーを作成してから変更を行うべきです。
また、環境変数が存在しない場合の適切なエラー処理を実装する必要があります。
*/

// fix handle getenv string

void replace_char(char *str, char orig, char rep) {
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
    printf("TEST_ENV is not set\n");
    return 1;
  }

  char *env_copy = strdup(env);
  if (env_copy == NULL) {
    printf("Failed to allocate memory\n");
    return 1;
  }

  replace_char(env_copy, '"', '_');

  // Do something with env_copy

  free(env_copy);

  return 0;
}
