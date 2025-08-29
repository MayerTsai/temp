#include <stdio.h>
#include "management.h"

// 初始化 initialization，定義處理物件的具體內容
event_object_t object_arr[] =
    {{"mayer", 55},
     {"binin", 55},
     {"guanfee", 21}};

// 初始化事件描述擋
event_table_t event_table_arr[] =
    {{1, "print name"},
     {2, "print age"}};

// 定義具體事件處理函定
void handler_1(event_object_t *);
void handler_2(event_object_t *);

// 初始化事件處理表，讓事件編號對應到具函式
event_handler_entry_t event_handler_arr[] =
    {{1, handler_1},
     {2, handler_2}};

int main()
{
  int ev = 0;
  print_info();
  printf("please enter you action number:");
  scanf("%d", &ev);
  for (int i = 0; i < (int)(sizeof(object_arr) / sizeof(event_object_t)); i++)
  {
    int ret = perform_action(ev, &object_arr[i]);
    if (ret != 0)
      break;
  }
  return 0;
}

void handler_1(event_object_t *object)
{
  printf("name = %s\n", object->name);
}

void handler_2(event_object_t *object)
{
  printf("age = %d\n", object->age);
}

void print_info()
{
  for (int i = 0; i < (int)(sizeof(event_table_arr) / sizeof(event_table_t)); i++)
    printf("%d: %s\n", event_table_arr[i].ev, event_table_arr[i].description);
}