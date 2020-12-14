#include <bits/stdc++.h>

using namespace std;

// set up input
ifstream file("input.txt");
string line;

// variables
string mask, address, masked;
size_t found;
int val;
long long ans;
map<string, int> mp;

void generateDiffAdd(string str) {
    // if all 0 or 1
    int idx = 0;
    while (idx < str.size() && str[idx] != 'X')
        idx++;
    if (idx == str.size()) {
        mp[str] = val;
    }

    // otherwise recur through
    else {
        generateDiffAdd(str.substr(0, idx) + '0' + str.substr(idx + 1));
        generateDiffAdd(str.substr(0, idx) + '1' + str.substr(idx + 1));
    }
}

string decToBin(int n) {
    string str = "";
    // assume 32 bit int
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            str += '1';
        else
            str += '0';
    }
    return str;
}

void readInput() {
    while (getline(file, line)) {
        // if mask, update
        if (line.substr(0, 4) == "mask")
            mask = line.substr(7);

        // otherwise set values at diff addresses
        else {
            // get int val
            found = line.find("]");
            val = stoi(line.substr(found + 3));

            // get address to binary string and match mask size
            address = decToBin(stoi(line.substr(4, found - 4)));
            for (int i = address.size(); i < mask.size(); i++)
                address = '0' + address;

            // mask the value
            masked = "";
            for (int i = mask.size(); i >= 0; i--) {
                // if 0, unchanged
                if (mask[i] == '0')
                    masked = address[i] + masked;
                // otherwise do what mask has
                else
                    masked = mask[i] + masked;
            }

            // generate different addresses
            generateDiffAdd(masked);
        }
    }
}

void solve() {
    for (auto i : mp)
        ans += i.second;
}

int main(void) {
    // read input
    readInput();

    // solve
    solve();

    // print answer and return
    cout << ans;
    return 0;
}