#include "management.h"
#include <stdio.h>

// int register_event_handler_table(thread_event_record_t *record)
//{
// return 0;
//}

void *perform_action(void *arg)
{
  thread_object_t *thread_object = (thread_object_t *)arg;
  event_object_t *ev_object = thread_object->object;
  if (ev_object->id != thread_object->id)
  {
    perror("Error the object is wrong\n");
    return NULL;
  }
  event_handler_entry_t *ev_handler = thread_object->event_handler;
  if (ev_handler == NULL)
  {
    perror("Error fails to start the handler\n");
    return NULL;
  }
  event_handler_t handler = ev_handler->handler;
  handler(ev_object);
  return NULL;
}