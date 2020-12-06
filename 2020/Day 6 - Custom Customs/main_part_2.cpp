#include <bits/stdc++.h>

using namespace std;

int main(void) {
    // read input and calculate
    ifstream file("input.txt");
    string line;
    map<char, int> mp;
    int ans = 0, groupSize = 0, temp = 0;
    while (getline(file, line)) {
        // if we reach end of group, see which ones are good
        if (line.size() == 0) {
            temp = 0;
            for (auto itr = mp.begin(); itr != mp.end(); itr++)
                if (itr->second == groupSize)
                    temp++;
            ans += temp;
            mp.clear();
            groupSize = 0;
        } else {
            // enumerate chars and inc size
            for (char c : line)
                mp[c]++;
            groupSize++;
        }
    }
    // don't forget last
    temp = 0;
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
        if (itr->second == groupSize)
            temp++;
    ans += temp;

    // print ans
    cout << ans;
    return 0;
}