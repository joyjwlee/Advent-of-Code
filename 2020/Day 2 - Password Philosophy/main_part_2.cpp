#include <bits/stdc++.h>

using namespace std;

int main(void) {
    // read input file, put into vector
    ifstream file("input.txt");
    string content, temp;

    // variables
    int lower, upper;
    char c;
    int number;

    int ans = 0, cnt = 0;
    while (file >> content) {
        // ranges
        if (cnt % 3 == 0) {
            // get lower
            temp = "";
            int i = 0;
            while (content[i] != '-') {
                temp += content[i];
                i++;
            }
            lower = stoi(temp);
            // get upper
            temp = "";
            i++;
            while (i < content.size()) {
                temp += content[i];
                i++;
            }
            upper = stoi(temp);
        }
        // letter
        if (cnt % 3 == 1) {
            c = content[0];
        }
        // password
        if (cnt % 3 == 2) {
            // determine if good or not
            number = 0, lower--, upper--;
            if (content[lower] == c)
                number++;
            if (content[upper] == c)
                number++;
            if (number == 1)
                ans++;
        }
        cnt++;
    }
    cout << ans;
}
