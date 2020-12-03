#include <bits/stdc++.h>

using namespace std;

int main(void) {
    // variables
    int idx = 0, ans = 0;

    // read input file, put into vector
    ifstream file("input.txt");
    string content;
    while (file >> content) {
        if (content[idx % content.size()] == '#')
            ans++;
        idx += 3;
    }
    cout << ans;
}
