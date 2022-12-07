#include <bits/stdc++.h>

using namespace std;

// global vars
ifstream file("input.txt");
vector<string> vec;
string line;

// method declarations
int init();
int part_1();
int part_2();

int main(void) {
    init();
    cout << part_1() << endl;
    cout << part_2() << endl;
    return 0;
}

int init() {
    // read input file, put into vector
    while (getline(file, line)) {
        vec.push_back(line);
    }
    return 0;
}

int part_1() {
    int cnt = 0;
    for (string i : vec) {
        // get intervals
        int split = i.find(',');
        string one = i.substr(0, split);
        string two = i.substr(split + 1, i.size());
        // get numbers
        int split1 = one.find('-');
        int split2 = two.find('-');
        string a = one.substr(0, split1);
        string b = one.substr(split1 + 1, one.size());
        string c = two.substr(0, split2);
        string d = two.substr(split2 + 1, two.size());
        // convert to int
        int p = stoi(a);
        int q = stoi(b);
        int r = stoi(c);
        int s = stoi(d);
        // check interval
        if (((p <= r) && (s <= q)) || ((r <= p) && (q <= s))) 
            cnt++;
    }
    return cnt;
}

int part_2() {
    int cnt = 0;
    for (string i : vec) {
        // get intervals
        int split = i.find(',');
        string one = i.substr(0, split);
        string two = i.substr(split + 1, i.size());
        // get numbers
        int split1 = one.find('-');
        int split2 = two.find('-');
        string a = one.substr(0, split1);
        string b = one.substr(split1 + 1, one.size());
        string c = two.substr(0, split2);
        string d = two.substr(split2 + 1, two.size());
        // convert to int
        int p = stoi(a);
        int q = stoi(b);
        int r = stoi(c);
        int s = stoi(d);
        // check if interval overlaps
        if (max(q, s) - min(p, r) <= (q - p) + (s - r))
            cnt++;
    }
    return cnt;
}
