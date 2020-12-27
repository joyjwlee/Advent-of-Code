#include <bits/stdc++.h>

using namespace std;

// set up input
ifstream file("input.txt");
string line;

// variables
vector<string> expressions;
int ans = 0, n;
stack<int> nums;
stack<char> ops;

void readInput() {
    while (getline(file, line)) {
        expressions.push_back(line);
    }
}

int calculate(string s) {
    // loop through the expression
    for (char c : s) {
        // if open parenthesis
        if (c == '(')
            ops.push(c);
        // if empty
        else if (nums.empty())
            nums.push((int)(c - '0'));
        // if just number, do operation
        else if ('0' <= c && c <= '9') {
            // get last value
            n = nums.top();
            nums.pop();

            // do one of four operations
            if (ops.top() == '*')
                n *= (int)(c - '0');
            else if (ops.top() == '+')
                n += (int)(c - '0');
            else if (ops.top() == '/')
                n /= (int)(c - '0');
            else
                n -= (int)(c - '0');

            // put back and remove operator
            nums.push(n);
            ops.pop();
        }
        // if operator, add to ops
        else if (c == '*' || c == '+' || c == '/' || c == '-')
            ops.push(c);
        // if closing parenthesis
        else if (c == ')') {
            // repeat above until reach open
            while (ops.top() != '(') {
                // get last value
                n = nums.top();
                nums.pop();

                // do one of four operations
                if (ops.top() == '*')
                    n *= (int)(c - '0');
                else if (ops.top() == '+')
                    n += (int)(c - '0');
                else if (ops.top() == '/')
                    n /= (int)(c - '0');
                else
                    n -= (int)(c - '0');

                // put back and remove operator
                nums.push(n);
                ops.pop();
            }
            // remove open paren
            ops.pop();
        }
    }
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