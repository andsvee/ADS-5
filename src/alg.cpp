// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

bool Ope(char repo) {
    return (repo == '+' || repo == '-' || repo == '(' ||
        repo == ')' || repo == '/' || repo == '*');
}
bool fir(char b) {
    return (b >= '0' && b <= '9');
}

int Pr(char repo) {
    if (repo == '-' || repo == '+')
        return 1;
    if (repo == '/' || repo == '*')
        return 2;
    return 0;
}
std::string infx2pstfx(std::string inf) {
  std::string stocn;
  int n = 0;
  TStack <char, 100> stack1;
  for (char i : inf) {
    if (Pr(i)) {
      n++;
      if (n == 1) {
        stocn += i;
        continue;
      }
      stocn = stocn + ' ' + i;
    } else if (Ope(i)) {
      if (i == '(') {
        stack1.push(i);
      } else if (stack1.checkEmpty()) {
          stack1.push(i);
        } else if (Pr(i) > Pr(stack1.get())) {
          stack1.push(i);
        } else if (i == ')') {
          while (stack1.get() != '(') {
            stocn = stocn + ' ' + stack1.get();
            stack1.pop();
          }
          stack1.pop();
        } else {
          int l = Pr(i);
          int y = Pr(stack1.get());
          while (!stack1.checkEmpty() && l <= y) {
            stocn = stocn + ' ' + stack1.get();
            stack1.pop();
          }
          stack1.push(i);
        }
      }
    }
    while (!stack1.checkEmpty()) {
      stocn = stocn + ' ' + stack1.get();
      stack1.pop();
    }
  return stocn;
}

int eval(std::string pref) {
  TStack <int, 100> stack2;
  for (char i : pref) {
    if (fir(i)) {
      stack2.push(i - '0');
    } else if (Ope(i)) {
      int l = stack2.get();
      stack2.pop();
      int y = stack2.get();
      stack2.pop();
      switch (i) {
        case '+':
          stack2.push(l + y);
          break;
        case '-':
          stack2.push(y - l);
          break;
        case '*':
          stack2.push(l * y);
          break;
        case '/':
          stack2.push(y / l);
          break;
        default:
          continue;
      }
    } else {
      continue;
    }
  }
  return stack2.get();
}
