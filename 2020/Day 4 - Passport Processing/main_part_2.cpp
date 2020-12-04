#include <bits/stdc++.h>

using namespace std;

// passport class
class passport {
    // fields
    string byr, iyr, eyr, hgt, hcl, ecl, pid, cid;

  public:
    // reset all fields
    void reset() {
        byr.clear();
        iyr.clear();
        eyr.clear();
        hgt.clear();
        hcl.clear();
        ecl.clear();
        pid.clear();
        cid.clear();
    }

    // set specific field
    void setField(string key, string val) {
        if (key == "byr")
            byr = val;
        if (key == "iyr")
            iyr = val;
        if (key == "eyr")
            eyr = val;
        if (key == "hgt")
            hgt = val;
        if (key == "hcl")
            hcl = val;
        if (key == "ecl")
            ecl = val;
        if (key == "pid")
            pid = val;
        if (key == "cid")
            cid = val;
    }

    // valid if passport has all (cid is optional)
    bool isValid() {
        return !(byr.empty() || iyr.empty() || eyr.empty() || hgt.empty() || hcl.empty() || ecl.empty() || pid.empty());
    }

    // stricter
    bool isValidStrict() {
        // quick check
        if (!isValid())
            return false;

        // byr
        if (byr.empty() || stoi(byr) < 1920 || 2002 < stoi(byr))
            return false;

        // iyr
        if (iyr.empty() || stoi(iyr) < 2010 || 2020 < stoi(iyr))
            return false;

        // eyr
        if (eyr.empty() || stoi(eyr) < 2020 || 2030 < stoi(eyr))
            return false;

        // hgt
        string units = hgt.substr(hgt.size() - 2);
        // stoi automatically stops at non-numerical
        if (units == "cm" && (stoi(hgt) < 150 || 193 < stoi(hgt)))
            return false;
        if (units == "in" && (stoi(hgt) < 59 || 76 < stoi(hgt)))
            return false;
        if (units != "cm" && units != "in")
            return false;

        // hcl
        if (hcl[0] != '#' || hcl.size() != 7)
            return false;
        for (int i = 1; i < hcl.size(); i++)
            // if not 0-9 or a-f
            if (!((48 <= hcl[i] && hcl[i] <= 57) || (97 <= hcl[i] && hcl[i] <= 102)))
                return false;

        // ecl
        if (ecl != "amb" && ecl != "blu" && ecl != "brn" && ecl != "gry" && ecl != "grn" && ecl != "hzl" && ecl != "oth")
            return false;

        // pid
        int digits = 0;
        for (int i = 0; i < pid.size(); i++) {
            // count number of digits and determine if not digit
            if (!(48 <= pid[i] && pid[i] <= 57))
                return false;
            digits++;
        }
        if (digits != 9)
            return false;

        // none of the above, return true
        return true;
    }
};

// read input file, put into vector
vector<passport> readInput(string fileName) {
    // vector of passports and current
    vector<passport> passports;
    passport curr;

    ifstream file(fileName);
    string line;
    while (getline(file, line)) {
        // blank line, restart
        if (line == "") {
            passports.push_back(curr);
            curr.reset();
            continue;
        }

        // loop through line and create passport
        int idx = 0;
        while (idx < line.size()) {
            // field/key is first 3 char
            string key = line.substr(idx, 3);
            idx += 4;

            // get value for field/key
            string value = "";
            while (idx < line.size() && line[idx] != ' ') {
                value += line[idx];
                idx++;
            }

            // iterate last space and set value
            idx++;
            curr.setField(key, value);
        }
    }
    // get last one as well
    passports.push_back(curr);

    // close file and return
    file.close();
    return passports;
}

int main(void) {
    // read input, get vector of passports
    vector<passport> passports = readInput("input.txt");

    // loop through, count, and print
    int ans = 0;
    for (int i = 0; i < passports.size(); i++)
        if (passports[i].isValidStrict())
            ans++;
    cout << ans;

    return 0;
}