#ifndef MANAGEMENT_H
#define MANAGEMENT_H

// 宣告事件所要的處理物件
typedef struct
{
  char *name;
  int age;
} event_object_t;

// 宣告事件編號的描述檔，提供事件編號的資訊
typedef struct
{
  int ev;
  char *description;
} event_t;

event_t *event_table;

void print_event_info(); // 列印事件編號的描述

// 宣告事件處理寒是的格式，本件無回傳值，輸入為待處理物件
typedef void (*event_handler_t)(event_object_t *);

// 宣告事件編號與事件處理的對應表
typedef struct
{
  int ev;
  event_handler_t handler;
} event_handler_entry_t, *ptr_event_handler_entry_t;

typedef struct
{
  event_object_t *object;
  event_handler_entry_t *event_handler_arr;
} thread_event_record_t;

int register_event_handler_table(thread_event_record_t *);
int perform_action(int ev, event_object_t *object); // 宣告呼叫事件處理函式

#endif // MANAGEMENT_H
