#include <stdio.h>

typedef struct
{
  char *name;
  int age;
} event_object_t, *ptr_event_object_t;

typedef struct
{
  int ev;
  char *description;
} event_table_t, *ptr_event_table_t;
void print_info();

typedef void (*event_handler_t)(event_object_t *);

typedef struct
{
  int ev;
  event_handler_t handler;
} event_handler_entry_t, *ptr_event_handler_entry_t;

int perform_action(int ev, event_object_t *object);

// 初始化 initialization
event_object_t object_arr[] =
    {{"mayer", 55},
     {"binin", 55},
     {"guagfee", 21}};

event_table_t event_table_arr[] =
    {{1, "print name"},
     {2, "print age"}};

void handler_1(event_object_t *);
void handler_2(event_object_t *);
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