#include <bits/stdc++.h>

using namespace std;

int main(void) {
    // read input
    ifstream file("input.txt");
    string line;
    vector<int> ids;
    int l, r, m, row, col;
    while (getline(file, line)) {
        l = 0, r = 128; // [,)
        // get row
        for (int i = 0; i < 7; i++) {
            m = l + (r - l) / 2;
            if (line[i] == 'F') {
                r = m;
            } else {
                l = m;
            }
        }
        row = l;
        // get col
        l = 0, r = 8; // [,)
        // get row
        for (int i = 7; i < 10; i++) {
            m = l + (r - l) / 2;
            if (line[i] == 'L') {
                r = m;
            } else {
                l = m;
            }
        }
        col = l;
        ids.push_back(row * 8 + col);
    }

    // sort and find seat
    sort(ids.begin(), ids.end());
    for (int i = 0; i < ids.size() - 1; i++)
        if (ids[i + 1] - ids[i] == 2)
            cout << ids[i] + 1 << endl;

    return 0;
}