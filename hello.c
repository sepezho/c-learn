#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
  char c[99];
  int top_op = -1;
  int top_num = -1;
  int op[99];
  int num[99];
  int res;
  int i = 0;
  printf("put arithmetical operation (only +-*/ allowed): \n");
  gets(c);
  while (c[i] != '\0') {
    if (isdigit(c[i])) {
      if (top_num == -1) {
        num[0] = c[i];
        top_num = 1;
      } else {
        num[top_num] = c[i];
        top_num++;
      }
    } else {
      if (top_op == -1){
        // printf('test');
        op[0] = c[i];
        top_op = 1;
      } else {
        op[top_op] = c[i];
        top_op++;
      }
    }
    i++;
  }
  while (top_op > 0) {
    char op_char = op[top_op - 1];
    top_op = top_op - 1;
    int a = num[top_num - 1] - '0';
    int b = num[top_num - 2] - '0';
    
    // printf("----------\n");
    // printf("op%d\n", top_op );
    // printf("top_num %d\n", top_num);
    // printf("%s\n", &op_char);
    // printf("a%d\n", a);
    // printf("b%d\n", b);

    top_num = top_num - 2;
    if (op_char == '*') {
      num[top_num] = a * b + '0';
    } else if (op_char == '/') {
      num[top_num] = b / a + '0';
    } else if (op_char == '+') {
      num[top_num] = (a + b) + '0';
    } else {
      num[top_num] = (b - a) + '0';
    }
    top_num++;
  }
  printf("%d\n", num[0] - '0');
  return 0;
}
