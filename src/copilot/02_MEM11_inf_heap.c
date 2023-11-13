#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum {MAX_LENGTH=100};

// too use memory, heap, fix it

typedef struct namelist_s {
  char name[MAX_LENGTH];
  struct namelist_s* next;
} *namelist_t;

int main() {
  namelist_t names = NULL;
  char new_name[MAX_LENGTH];

  do {
    /* 未知の数のレコードをリストに追加
       ユーザは好きなだけデータを入力してヒープも使い果たしてしまうおそれがある */
    puts("To quit, enter \"quit\"");
    puts("Enter record:");
    fgets(new_name, MAX_LENGTH, stdin);
    if (strcmp(new_name, "quit") != 0) {
      /* ヒープサイズを気にせずに、名前を追加し続ける */
      unsigned int i = strlen(new_name) - 1;
      if (new_name[i] == '\n') new_name[i] = '\0';
      namelist_t new_entry = (namelist_t) malloc(sizeof( struct namelist_s));
      if (new_entry == NULL) {
        /* エラー処理 */
        printf("Error: Failed to allocate memory for new entry\n");
        exit(1);
      }
      strcpy( new_entry->name, new_name);
      new_entry->next = names;
      names = new_entry;
    }
    puts(new_name);
  } while (strcmp( new_name, "quit") != 0);

  /* リストの全要素を出力 */
  namelist_t current = names;
  while (current != NULL) {
    printf("%s\n", current->name);
    current = current->next;
  }

  /* リストの全要素を解放 */
  current = names;
  while (current != NULL) {
    namelist_t next = current->next;
    free(current);
    current = next;
  }

  return 0;
}
