#include <bits/stdc++.h>

using namespace std;

int main(void) {
    // variables
    int row = 0;
    int trees[5] = {0};
    int idx[5] = {0};

    // set slopes
    int right[5] = {1, 3, 5, 7, 1};
    int down[5] = {1, 1, 1, 1, 2};

    // read input file
    ifstream file("input.txt");
    string line;
    while (file >> line) {
        // loop through diff slopes
        for (int i = 0; i < 5; ++i) {
            // mod to skip
            if (row % down[i] == 0) {
                // if at tree, increase
                if (line[idx[i] % line.size()] == '#')
                    trees[i]++;
                // increment
                idx[i] += right[i];
            }
        }
        // increment row
        row++;
    }

    // multiply and return
    unsigned long int ans = 1;
    for (int n : trees)
        ans *= n;
    cout << ans << endl;
}
