#include "management.h"
#include <stdio.h>

int register_event_handler_table(thread_event_record_t *record)
{

  return 0;
}

perform_action(int ev, event_object_t *object)
{
  event_handler_t action = NULL;
  for (int i = 0; i < event_handler_arr_count; i++)
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