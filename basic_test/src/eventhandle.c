#include <stdio.h>

// 宣告事件所要的處理物件
typedef struct
{
  char *name;
  int age;
} event_object_t, *ptr_event_object_t;

// 宣告事件編號的描述檔，提供事件編號的資訊
typedef struct
{
  int ev;
  char *description;
} event_table_t, *ptr_event_table_t;
void print_info(); // 列印事件編號的描述

// 宣告事件處理寒是的格式，本件無回傳值，輸入為待處理物件
typedef void (*event_handler_t)(event_object_t *);

// 宣告事件編號與事件處理的對應表
typedef struct
{
  int ev;
  event_handler_t handler;
} event_handler_entry_t, *ptr_event_handler_entry_t;

int perform_action(int ev, event_object_t *object); // 宣告呼叫事件處理函式

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

int perform_action(int ev, event_object_t *object)
{
  event_handler_t action = NULL;
  for (int i = 0; i < (int)(sizeof(event_handler_arr) / sizeof(event_handler_entry_t)); i++)
  {
    if (ev == event_handler_arr[i].ev)
    {
      action = event_handler_arr[i].handler;
      break;
    }
  }
  if (action == NULL)
  {
    printf("the event number %d is not supported\n", ev);
    return -1;
  }
  action(object);
  return 0;
}

void print_info()
{
  for (int i = 0; i < (int)(sizeof(event_table_arr) / sizeof(event_table_t)); i++)
    printf("%d: %s\n", event_table_arr[i].ev, event_table_arr[i].description);
}