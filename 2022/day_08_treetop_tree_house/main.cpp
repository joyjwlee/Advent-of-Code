#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// global vars
ifstream file("input.txt");
vector<string> vec;
string line;
int w, h;

// method declarations
int init();
int part_1();
int part_2();
bool canSee(int i, int j);
int score(int i, int j);

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
    w = vec[0].size();
    h = vec.size();
    return 0;
}

int part_1() {
    int num = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (canSee(i, j))
                num++;
    return num;
}

bool canSee(int i, int j) {
    // vars
    bool up = true, down = true, left = true, right = true;
    int r, c;

    // up
    r = i - 1, c = j;
    while (r >= 0) {
        if (vec[r][c] >= vec[i][j])
            up = false;
        r--;
    }
    // down
    r = i + 1, c = j;
    while (r < h) {
        if (vec[r][c] >= vec[i][j])
            down = false;
        r++;
    }
    // left
    r = i, c = j - 1;
    while (c >= 0) {
        if (vec[r][c] >= vec[i][j])
            left = false;
        c--;
    }
    // right
    r = i, c = j + 1;
    while (c < w) {
        if (vec[r][c] >= vec[i][j])
            right = false;
        c++;
    }

    // or all directions
    return up | down | left | right;
}

int part_2() {
    int maxScore = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            maxScore = max(maxScore, score(i, j));
    return maxScore;
}

int score(int i, int j) {
    // vars
    int up = 0, down = 0, left = 0, right = 0;
    int r, c;

    // up
    r = i - 1, c = j;
    while (r >= 0) {
        if (vec[r][c] >= vec[i][j]) {
            up++;
            break;
        }
        r--;
        up++;
    }
    // down
    r = i + 1, c = j;
    while (r < h) {
        if (vec[r][c] >= vec[i][j]) {
            down++;
            break;
        }
        r++;
        down++;
    }
    // left
    r = i, c = j - 1;
    while (c >= 0) {
        if (vec[r][c] >= vec[i][j]) {
            left++;
            break;
        }
        c--;
        left++;
    }
    // right
    r = i, c = j + 1;
    while (c < w) {
        if (vec[r][c] >= vec[i][j]) {
            right++;
            break;
        }
        c++;
        right++;
    }

    // multiply all directions
    return up * down * left * right;
}
