#include <fstream>
#include <iostream>
#include <vector>

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
    while (getline(file, line))
        vec.push_back(line);
    return 0;
}

int part_1() {
    // vars
    int ans = 0, x = 1, cycle = 1;
    int arr[] = {20, 60, 100, 140, 180, 220};
    vector<int> signals(arr, arr + sizeof(arr) / sizeof(arr[0])); // rip compiler

    // loop through
    for (string s : vec) {
        // simulate instr
        if (s == "noop")
            cycle++;
        else {
            x += stoi(s.substr(s.find(" ") + 1));
            cycle += 2;
        }

        // check signals
        for (int i : signals) {
            if (cycle == i || cycle == i - 1) {
                ans += x * i;
                signals.erase(signals.begin());
                break;
            }
        }
    }

    // return
    return ans;
}

int part_2() {
    return 0;
}
