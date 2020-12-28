#include <bits/stdc++.h>

using namespace std;

// set up input
ifstream file("input.txt");
string line;

// variables
vector<string> expressions;
int ans = 0, a, b;
stack<int> nums;
stack<char> ops;

void readInput() {
    while (getline(file, line)) {
        expressions.push_back(line);
    }
}

void doOp() {
    // get top 2 values
    a = nums.top();
    nums.pop();
    b = nums.top();
    nums.pop();

    // do one of four operations
    if (ops.top() == '*')
        b *= a;
    else if (ops.top() == '+')
        b += a;
    else if (ops.top() == '/')
        b /= a;
    else
        b -= a;

    // put back and remove operator
    nums.push(b);
    ops.pop();
}

int calculate(string s) {
    // loop through the expression
    for (char c : s) {
        // if open paren
        if (c == '(')
            ops.push(c);
        // if number
        else if ('0' <= c && c <= '9') {
            // if empty, add to stack
            if (nums.empty())
                nums.push((int)(c - '0'));
            // otherwise add to stack and do operation
            else {
                nums.push((int)(c - '0'));
                doOp();
            }
        }
        // if operator
        else if (c == '*' || c == '+' || c == '/' || c == '-')
            ops.push(c);
        // if closing paren
        else if (c == ')') {
            // do until we hit open paren
            while (ops.top() != '(')
                doOp();
            // then remove the paren
            ops.pop();
        }
    }
    // return what's at the stack
    return nums.top();
}

void solve() {
    for (string s : expressions)
        ans += calculate(s);
}

int main(void) {
    // read input
    readInput();

    // solve, print answer, and return
    solve();
    cout << ans;
    return 0;
}