#include <bits/stdc++.h>

using namespace std;

int main(void) {
    // read input
    ifstream file("input.txt");
    string line;
    vector<pair<int, int>> seats;
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
        seats.push_back(make_pair(row, col));
    }

    int ans = 0;
    for (int i = 0; i < seats.size(); i++)
        if (seats[i].first * 8 + seats[i].second > ans)
            ans = seats[i].first * 8 + seats[i].second;
    cout << ans;

    return 0;
}