#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

class Stack {
private:
    int top;
    char* items;
    int maxSize;
public:
    Stack(int size) {
        top = -1;
        maxSize = size;
        items = new char[maxSize];
    }

    ~Stack() {
        delete[] items;
    }

    bool isFull() {
        return top == maxSize - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(char item) {
        if (!isFull()) {
            items[++top] = item;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return items[top--];
        }
        return '\0'; // return null character if stack is empty
    }

    char peek() {
        if (!isEmpty()) {
            return items[top];
        }
        return '\0'; // return null character if stack is empty
    }
};

class ExpressionEvaluator {
public:
    static int getPrecedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        if (op == '^') return 3;
        return 0; // For '(' and ')'
    }

    static bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
    }

    static bool isOperand(char c) {
        return (c >= '0' && c <= '9');
    }

    static int performOperation(char op, int a, int b) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            case '^': return pow(a, b);
            default: return 0; // Invalid operator
        }
    }

    static int evaluatePostfix(string exp) {
        Stack stack(exp.length());
        for (char c : exp) {
            if (isOperand(c)) {
                stack.push(c - '0'); // Convert character to integer
            } else if (isOperator(c)) {
                int b = stack.pop();
                int a = stack.pop();
                int result = performOperation(c, a, b);
                stack.push(result);
            }
        }
        return stack.pop();
    }

    static string infixToPostfix(string exp) {
        string result = "";
        Stack stack(exp.length());
        for (char c : exp) {
            if (isOperand(c)) {
                result += c;
            } else if (isOperator(c)) {
                while (!stack.isEmpty() && getPrecedence(c) <= getPrecedence(stack.peek())) {
                    result += stack.pop();
                }
                stack.push(c);
            }
        }
        while (!stack.isEmpty()) {
            result += stack.pop();
        }
        return result;
    }
};

int main() {
    string infixExpression;
    cout << "Nhap bieu thuc trung to: ";
    getline(cin, infixExpression);

    string postfixExpression = ExpressionEvaluator::infixToPostfix(infixExpression);
    cout << "Bieu thuc hau to: " << postfixExpression << endl;

    int result = ExpressionEvaluator::evaluatePostfix(postfixExpression);
    cout << "Gia tri cua bieu thuc: " << result << endl;

    return 0;
}
