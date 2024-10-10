#include <iostream>
#include <string>
using namespace std;

template <class T> class stack {
  int top, size;
  T *arr;

public:
  stack(int size) {
    arr = new T[size];
    if (!arr)
      return;
    this->size = size;
    top = -1;
  }

  bool isFull() { return (top == (size - 1)); }

  bool isEmpty() { return (top == -1); }

  void push(T val) {
    if (isFull()) {
      printf("Stack is full, can't push\n");
      return;
    }
    arr[++top] = val;
  }

  T pop() {
    if (isEmpty()) {
      printf("Stack is empty, can't pop\n");
      return 0;
    }
    return arr[top--];
  }

  T Top() {
    if (isEmpty()) {
      return 0;
    }
    return arr[top];
  }
};

bool isOperator(char ch) {
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
  if (ch == '+' || ch == '-') {
    return 1;
  } else if (ch == '*' || ch == '/') {
    return 2;
  }
  return 0;
}

string infixToPostfix(string &s) {
  stack<char> opr(20);
  string postfix;
  int i = 0;

  while (i < s.size()) {
    if (isdigit(s[i])) {
      while (i < s.size() && isdigit(s[i])) {
        postfix += s[i++];
      }
      postfix += ' ';
    } else if (isOperator(s[i])) {
      while (!opr.isEmpty() && precedence(opr.Top()) >= precedence(s[i])) {
        postfix += opr.pop();
        postfix += ' ';
      }
      opr.push(s[i]);
      i++;
    }
  }

  while (!opr.isEmpty()) {
    postfix += opr.pop();
    postfix += ' ';
  }

  return postfix;
}

int main() {
  string infix = "10+20*2";
  string postfix = infixToPostfix(infix);
  cout << "Postfix: " << postfix << "\n";
  return 0;
}
