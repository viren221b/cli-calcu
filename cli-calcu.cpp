#include <iostream>
#include <string>
// #include <sstream>
// #include <cmath>
#include <stack>

// Goal:
//  - create a CLI calcu that can calculate any mathematical problem
//  with infinite amount of a user inputs (e.g. 2+2(4/5) or 2^3)

/* - user types input
     - getline stores it as a string
         - tokenizer reads it character by character
             - evaluator applies math rules
                 - result prints to screen */

using namespace std;

string input_op() {
  // put all basic arithmetic function and rules
  string math_op;

  cout << ">> ";
  getline(cin, math_op);
  return math_op;
}

double apply_op(double a, double b, char op) {
  if (op == '+')
    return a + b;
  if (op == '-')
    return a - b;
  if (op == '*')
    return a * b;
  if (op == '/')
    return a / b;
  return 0;
}

int precedence(char op) {

  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;

  return 0;
}

double eval_op(string expression) {
  // reference input_op and evaluate

  stack<double> values;
  stack<char> ops;

  for (size_t i = 0; i < expression.length(); i++) {
    char c = expression[i];
    // c is now one character at a time

    if (isdigit(c)) {
      string num = "";
      while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
        num += expression[i];
        i++;
      }
      i--;

      if (!num.empty() && num != ".") {
          double value = stod(num);
          values.push(value);
      }
    }

    else if (c == '+' || c == '-') {

      while (!ops.empty() && ops.top() != '(' &&
             precedence(ops.top()) >= precedence(c)) {

        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(apply_op(a, b, op));
      }
      ops.push(c);
    }

    else if (c == '*' || c == '/') {
      while (!ops.empty() && ops.top() != '(' &&
             precedence(ops.top()) >= precedence(c)) {

        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = ops.top();
        ops.pop();
        values.push(apply_op(a, b, op));
      }
      ops.push(c);

    }

    else if (c == '(') {
      ops.push(c);
    }

    else if (c == ')') {
      while (!ops.empty() && ops.top() != '(') {

        double b = values.top();
        values.pop();
        double a = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(apply_op(a, b, op));
      }
      ops.pop();
    }

    else if (isspace(c)) {
    }
  }

  while (!ops.empty()) {
    double b = values.top(); values.pop();
    double a = values.top(); values.pop();
    char op = ops.top();
    ops.pop();
    values.push(apply_op(a, b, op));
  }

  return values.top();
}

int main() {
    while (true) {
        string result = input_op();
        double answer = eval_op(result);
        cout << answer << endl;
    }
  return 0;
}
