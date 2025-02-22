#include <stdio.h>
int main(void)
{
  float r, v, pi;
  scanf("%f", &r);
  pi = 3.14159f;
  v = (4.0f/3.0f)*pi*r*r*r;
  printf("%.2f",v);
  return 0;
}