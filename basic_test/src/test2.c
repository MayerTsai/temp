#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

typedef struct
{
  char *string;
  pthread_t tid;
} thread_object_t;

void *process_print(void *);

int main()
{
  pthread_t tid_1;
  pthread_t tid_2;

  thread_object_t *object_1 = malloc(sizeof(thread_object_t));
  if (object_1 == NULL)
  {
    perror("malloc for object_1 failed");
    return -1;
  }
  object_1->string = "object_1";

  thread_object_t *object_2 = malloc(sizeof(thread_object_t));
  if (object_2 == NULL)
  {
    perror("malloc for object_2 failed");
    free(object_1);
    return -1;
  }
  object_2->string = "object_2";

  int ret = pthread_create(&tid_1, NULL, process_print, (void *)object_1);
  if (ret != 0)
  {
    fprintf(stderr, "pthread_create for object_1 failed: %s\n", strerror(ret));
    free(object_1);
    free(object_2);
    return -1;
  }
  object_1->tid = tid_1;

  ret = pthread_create(&tid_2, NULL, process_print, (void *)object_2);
  if (ret != 0)
  {
    fprintf(stderr, "pthread_create for object_2 failed: %s\n", strerror(ret));
    free(object_1);
    free(object_2);
    return -1;
  }
  object_2->tid = tid_2;

  pthread_join(tid_1, NULL);
  pthread_join(tid_2, NULL);
  free(object_1);
  free(object_2);

  return 0;
}

void *process_print(void *object)
{
  thread_object_t *x = (thread_object_t *)object;
  for (int i = 0; i < 10; i++)
  {
    printf("thread: %s\n", x->string);
    if (strcmp(x->string, "object_1") == 0)
      sleep(1);
    else
      sleep(3);
  }
  return NULL;
}
