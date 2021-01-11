#include <bits/stdc++.h>

using namespace std;

// set up input
ifstream file("input.txt");
string line;

// variables
vector<int> cards, one, two;
int ans = 0;

void readInput() {
    // get all numbers
    while (getline(file, line)) {
        if (line.size() != 0 && line.size() < 4)
            cards.push_back(stoi(line));
    }

    // split to player 1 and player 2
    for (int i = 0; i < cards.size(); i++) {
        if (i < cards.size() / 2)
            one.push_back(cards[i]);
        else
            two.push_back(cards[i]);
    }
}

void playRound() {
    // get first ones and erase
    int a = one[0], b = two[0];
    one.erase(one.begin(), one.begin() + 1);
    two.erase(two.begin(), two.begin() + 1);

    // append
    if (a > b) {
        one.push_back(a);
        one.push_back(b);
    } else {
        two.push_back(b);
        two.push_back(a);
    }
}

void solve() {
    // simulate game
    while (one.size() != 0 && two.size() != 0) {
        playRound();
    }

    // sum up values
    for (int i = 0; i < one.size(); i++)
        ans += (one.size() - i) * one[i];
    for (int i = 0; i < two.size(); i++)
        ans += (two.size() - i) * two[i];
}

int main(void) {
    // read input
    readInput();

    // solve, print answer, and return
    solve();
    cout << ans;
    return 0;
}