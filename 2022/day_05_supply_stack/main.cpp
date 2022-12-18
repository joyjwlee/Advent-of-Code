#include<vector>
#include<iostream>
#include<fstream>

using namespace std;

// global vars
ifstream file("input.txt");
vector<string> vec;
string line;
int numCrates = 0;
vector<vector<char> > crates, crates_1, crates_2;

// method declarations
int init();
int part_1();
int part_2();
void printCrates();

// use 0-based indexing for everything
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
    // copy crates
    crates_1.insert(crates_1.end(), crates.begin(), crates.end());

    // get number of crates, make vec of stacks
    numCrates = (vec[0].size() - 3) / 4 + 1;
    for (int i = 0; i < numCrates; i++)
        crates_1.push_back(vector<char>());

    // set up crates
    int i = 0;
    for (; i < vec.size(); i++) {
        if (vec[i][1] == '1')
            break;
        for (int j = 1; j < vec[i].size(); j += 4)
            if (vec[i][j] != ' ')
                crates_1[(j - 1) / 4].insert(crates_1[(j - 1) / 4].begin(), vec[i][j]);
    }
    
    // simulate
    string a = "move ";
    string b = " from ";
    string c = " to ";
    for (int j = i + 2; j < vec.size(); j++) {
        int d = vec[j].find(a);
        int e = vec[j].find(b);
        int f = vec[j].find(c);
        string p = vec[j].substr(d + a.size(), e - d - a.size());
        string q = vec[j].substr(e + b.size(), f - e - b.size());
        string r = vec[j].substr(f + c.size(), vec[j].size() - f - c.size());
        
        int amt = stoi(p);
        int from = stoi(q) - 1;
        int to = stoi(r) - 1;
        
        // cout << "> " << amt << " " << from << " " << to << endl;

        for (int k = 0; k < amt; k++) {
            char move = crates_1[from][crates_1[from].size() - 1];
            crates_1[from].pop_back();
            crates_1[to].push_back(move);
        }

        // printCrates();
    }

    for (int i = 0; i < numCrates; i++) {
        cout << crates_1[i].back();
    }
    cout << endl;
    
    return 0;
}

int part_2() {
    // copy crates
    crates_2.insert(crates_2.end(), crates.begin(), crates.end());

    // get number of crates, make vec of stacks
    numCrates = (vec[0].size() - 3) / 4 + 1;
    for (int i = 0; i < numCrates; i++)
        crates_2.push_back(vector<char>());

    // set up crates
    int i = 0;
    for (; i < vec.size(); i++) {
        if (vec[i][1] == '1')
            break;
        for (int j = 1; j < vec[i].size(); j += 4)
            if (vec[i][j] != ' ')
                crates_2[(j - 1) / 4].insert(crates_2[(j - 1) / 4].begin(), vec[i][j]);
    }
    
    // simulate
    string a = "move ";
    string b = " from ";
    string c = " to ";
    for (int j = i + 2; j < vec.size(); j++) {
        int d = vec[j].find(a);
        int e = vec[j].find(b);
        int f = vec[j].find(c);
        string p = vec[j].substr(d + a.size(), e - d - a.size());
        string q = vec[j].substr(e + b.size(), f - e - b.size());
        string r = vec[j].substr(f + c.size(), vec[j].size() - f - c.size());
        
        int amt = stoi(p);
        int from = stoi(q) - 1;
        int to = stoi(r) - 1;
        
        // cout << "> " << amt << " " << from << " " << to << endl;

        for (int k = 0; k < amt; k++) {
            char move = crates_2[from][crates_2[from].size() - amt + k];
            crates_2[to].push_back(move);
        }
        for (int k = 0; k < amt; k++) {
            crates_2[from].pop_back();
        }

        // printCrates();
    }

    for (int i = 0; i < numCrates; i++) {
        cout << crates_2[i].back();
    }
    cout << endl;
    
    return 0;
}

void printCrates() {
    for (int i = 0; i < numCrates; i++) {
        cout << i << ": ";
        for (int j = 0; j < crates[i].size(); j++)
            cout << crates[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
