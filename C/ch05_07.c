#include <stdio.h>

int main(void)
{
  float commission, value, ns, ps, rb;

  printf("Enter the number of shares: ");
  scanf("%f", &ns);
  printf("Enter price per share: ");
  scanf("%f", &ps);
  value = ns * ps;
  if (value < 2500.00f)
    commission = 30.00f + .017f * value;
  else if (value < 6250.00f)
    commission = 56.00f + .0066f * value;
  else if (value < 20000.00f)
    commission = 76.00f + .0034f * value;
  else if (value < 50000.00f)
    commission = 100.00f + .0022f * value;
  else if (value < 500000.00f)
    commission = 155.00f + .0011f * value;
  else
    commission = 255.00f + .0009f * value;

  if (commission < 39.00f)
    commission = 39.00f;
  
  if (ns < 2000){
    rb = 33.00f + 0.03f * ns;
  }
  else {
    rb = 33.00f + 0.02f * ns;
  }

  printf("Original broker's commission: $%.2f\n", commission);
  printf("Rival broker's commission: $%.2f", rb);

  return 0;
}