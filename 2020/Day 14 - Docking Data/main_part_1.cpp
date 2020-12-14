#include <bits/stdc++.h>

using namespace std;

// set up input
ifstream file("input.txt");
string line;

// variables
string mask, address, val, masked;
size_t found;
map<string, unsigned long long> mp;
unsigned long long ans = 0;

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
        // otherwise set value
        else {
            // get address
            found = line.find("]");
            address = line.substr(4, found - 4);

            // get int to binary string and match mask size
            val = decToBin(stoi(line.substr(found + 3)));
            for (int i = val.size(); i < mask.size(); i++)
                val = '0' + val;

            // mask the value
            masked = "";
            for (int i = mask.size(); i >= 0; i--) {
                if (mask[i] == 'X')
                    masked = val[i] + masked;
                else
                    masked = mask[i] + masked;
            }

            // convert binary to int and add to map
            mp[address] = stoull(masked, 0, 2);
        }
    }
}

void solve() {
    // add all values together
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