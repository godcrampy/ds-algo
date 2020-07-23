#include <cmath>
#include <iostream>
#include <stack>

using namespace std;

bool _isOpeningParen(char c) { return c == '(' || c == '[' || c == '{'; }

bool _isClosingParen(char c) { return c == ')' || c == ']' || c == '}'; }

char _isOperator(char c) {
  return c == '+' || c == '-' || c == '/' || c == '*' || c == '^';
}

int _precedence(char c) {
  switch (c) {
    case '^':
      return 4;
    case '*':
    case '/':
      return 3;
    case '+':
    case '-':
      return 2;
    default:
      return 1;
  }
}

int _operate(int a, int b, char c) {
  switch (c) {
    case '^':
      return pow(a, b);
    case '*':
      return a * b;
    case '/':
      return a / b;
    case '+':
      return a + b;
    case '-':
      return a - b;
    default:
      return 1;
  }
}

string infixToPostfix(const string &i) {
  stack<char> s;
  string p;
  for (char c : i) {
    if (_isOpeningParen(c)) {
      s.push(c);
    } else if (_isClosingParen(c)) {
      if (s.empty())
        throw logic_error("Error: Cannot find opening parenthesis");
      while (!_isOpeningParen(s.top())) {
        if (s.empty())
          throw logic_error("Error: Cannot find opening parenthesis");
        p.push_back(s.top());
        s.pop();
      }
      s.pop();
    } else if (_isOperator(c)) {
      while (!s.empty() && _precedence(s.top()) >= _precedence(c)) {
        p.push_back(s.top());
        s.pop();
      }
      s.push(c);
    } else {
      p.push_back(c);
    }
  }

  while (!s.empty()) {
    if (_isOperator(s.top())) {
      p.push_back(s.top());
    }
    s.pop();
  }

  return p;
}

string postfixToInfix(const string &p) {
  stack<string> s;
  for (char i : p) {
    string c(1, i);
    if (_isOperator(i)) {
      string a = s.top();
      s.pop();
      string b = s.top();
      s.pop();
      s.push("(" + b + c + a + ")");
    } else {
      s.push(c);
    }
  }
  return s.top();
}

string postfixToPrefix(const string &p) {
  stack<string> s;
  for (char i : p) {
    string c(1, i);
    if (_isOperator(i)) {
      string a = s.top();
      s.pop();
      string b = s.top();
      s.pop();
      s.push(c + b + a);
    } else {
      s.push(c);
    }
  }
  return s.top();
}

int evaluatePostfix(const string &p) {
  stack<int> s;
  for (char i : p) {
    string c(1, i);
    if (_isOperator(i)) {
      int a = s.top();
      s.pop();
      int b = s.top();
      s.pop();
      s.push(_operate(b, a, i));
    } else {
      s.push(i - '0');
    }
  }
  return s.top();
}

int main() {
  string infix = "a+b*(c^d-e)^(f+g*h)-i";
  string postfix = infixToPostfix(infix);
  cout << "Infix: " << infix << endl;
  cout << "Postfix: " << postfix << endl;
  cout << "Infix: " << postfixToInfix(postfix) << endl;
  cout << "Prefix: " << postfixToPrefix(postfix) << endl;
  cout << "Evaluate: " << evaluatePostfix("231*+9-") << endl;
  return 0;
}
