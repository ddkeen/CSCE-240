#include <stdio.h>
int main()
{
   //~ #pragma omp parallel for 
  for(int i=0;i<100000000000000;i++)
  {
    printf("%i\n",i);
  }
  return 0;
}
