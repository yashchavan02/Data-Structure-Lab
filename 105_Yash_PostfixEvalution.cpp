#include <climits>
#include <cstdio>
using namespace std;

class stack {
  int top, size, *arr;

public:
  stack(int size) {
    arr = new int[size];
    if (!arr)
      return;
    this->size = size;
    top = -1;
  }

  bool isFull() { return (top == (size - 1)); }

  bool isEmpty() { return (top == -1); }

  void push(int val) {
    if (isFull()) {
      printf("Stack is full, can't push\n");
      return;
    }
    arr[++top] = val;
  }

  int pop() {
    if (isEmpty()) {
      printf("Stack is empty, can't pop\n");
      return INT_MIN;
    }
    return arr[top--];
  }

  int Top() {
    if (!isEmpty()) {
      return arr[top];
    }
    return INT_MIN;
  }
};

bool isDigit(char ch) { return (ch >= '0' && ch <= '9'); }

bool isOperator(char ch) {
  return (ch == '+' || ch == '-' || ch == 'x' || ch == '/');
}

int eval(int op1, int op2, char opr) {
  switch (opr) {
  case '+':
    return (op1 + op2);
  case '-':
    return (op1 - op2);
  case 'x':
    return (op1 * op2);
  case '/':
    if (op2 != 0) {
      return (op1 / op2);
    } else {
      printf("division by zero is not possible \n");
      return 0;
    }
  default:
    return 0;
  }
}

int main(int argc, char **argv) {
  stack s(20);

  for (int i = 1; i < argc; i++) {
    int n = 0;
    if (isDigit(argv[i][0])) {
      int j = 0;
      while (argv[i][j] != '\0') {
        n = n * 10 + (argv[i][j] - '0');
        j++;
      }
      s.push(n);
    } else if (isOperator(argv[i][0])) {
      int op2 = s.pop();
      int op1 = s.pop();
      char opr = argv[i][0];
      s.push(eval(op1, op2, opr));
    }
  }

  printf("%d\n", s.Top());
  return 0;

  /*

  PS C:\Users\chava\OneDrive\Desktop\GitHub\DSA-LAB> g++
  105_Yash_PostfixEvalution.cpp

  PS C:\Users\chava\OneDrive\Desktop\GitHub\DSA-LAB> ./a.exe 12 12 +
  24
  PS C:\Users\chava\OneDrive\Desktop\GitHub\DSA-LAB> ./a.exe 12 12 -
  0
  PS C:\Users\chava\OneDrive\Desktop\GitHub\DSA-LAB> ./a.exe 13 12 -
  1
  PS C:\Users\chava\OneDrive\Desktop\GitHub\DSA-LAB> ./a.exe 12 13 + 4 3 x  -
  13

  */
}
