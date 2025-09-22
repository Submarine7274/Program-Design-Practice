//多項式計算3的5次方 + 2的4次方 - 5的3次方 - 2的2次方 + 7x - 6
#include <stdio.h>
int main (void){
  int x, y;
  scanf("%d", &x);
  //y = (3 * x * x * x * x * x) + (2 * x * x * x * x) - (5 * x * x * x) - (x * x) + (7 * x) - 6; 這種寫法比較難讀
   y = (((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6); //霍納法逐項展開
  printf("%d", y);  //輸出結果
  return 0;
}