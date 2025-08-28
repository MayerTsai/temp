#include <stdio.h>
#include <string.h>

typedef struct
{
  char *name;
  int age;
} test_t, *ptr_test_t;

int main()
{
  printf("sizeof(char) = %d    sizeof(int) = %d    sizeof(test_t) = %d\n",
         (int)sizeof(char), (int)sizeof(int), (int)sizeof(test_t));

  int ptr_i[] = {1, 2, 3};

  for (int i = 0; i < (int)(sizeof(ptr_i) / sizeof(int)); i++)
    printf("ptr_i[%d] = %d : %p\n", i, ptr_i[i], (void *)&ptr_i[i]);

  char *ptr_a = "mayer";
  for (int i = 0; i < (int)strlen(ptr_a); i++)
    printf("ptr_a[%d] = %c : %p\n", i, ptr_a[i], (void *)&ptr_a[i]);

  test_t my_test_arr[] =
      {{"mayer", 55},
       {"binin", 55},
       {"guagfee", 21}};

  for (int i = 0; i < (int)(sizeof(my_test_arr) / sizeof(test_t)); i++)
    printf("my_test_arr[%d].name = %s    my_test_arr[%d].age = %d\n",
           i, my_test_arr[i].name, i, my_test_arr[i].age);

  return 0;
}
