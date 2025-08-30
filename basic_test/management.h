#ifndef MANAGEMENT_H
#define MANAGEMENT_H

// 宣告事件所要的處理物件
typedef struct
{
  int id;
  char *name;
  int age;
} event_object_t;

typedef void (*event_handler_t)(event_object_t *); // 宣告事件處理寒是的格式，本件無回傳值，輸入為待處理物件

// 宣告事件編號與事件處理的對應表
typedef struct
{
  int ev;
  char *description;
  event_handler_t handler;
} event_handler_entry_t;

typedef struct
{
  int id;
  event_object_t *object;
  event_handler_entry_t *event_handler;
} thread_object_t;

// int register_event_handler_table(thread_event_record_t *);
void *perform_action(void *object); // 宣告呼叫事件處理函式

#endif // MANAGEMENT_H
