#include<bits/stdc++.h>

using namespace std;

// Function to get the index of an element in an array
int getIndex(const vector<string>& arr, const string& pattern) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == pattern) return static_cast<int>(i);
    }
    return -1;
}

// Function to check if a pairing is stable
bool isStable(const map<string, string>& pairings, const vector<string>& boys,
              const vector<string>& girls, const vector<vector<string>>& boyPrefer,
              const vector<vector<string>>& girlPrefer) {
    map<string, string> reversePairings;
    for (const auto& entry : pairings) {
        reversePairings[entry.second] = entry.first;
    }

    for (const auto& man : boys) {
        string woman = pairings.at(man);
        int manIndex = getIndex(boys, man);
        int womanIndex = getIndex(girls, woman);

        for (const auto& preferredWoman : boyPrefer[manIndex]) {
            if (preferredWoman == woman) break;
            string herFiance = reversePairings[preferredWoman];
            int herIndex = getIndex(girls, preferredWoman);
            if (getIndex(girlPrefer[herIndex], man) < getIndex(girlPrefer[herIndex], herFiance)) {
                return false;
            }
        }

        for (const auto& preferredMan : girlPrefer[womanIndex]) {
            if (preferredMan == man) break;
            string hisFiance = pairings.at(preferredMan);
            int hisIndex = getIndex(boys, preferredMan);
            if (getIndex(boyPrefer[hisIndex], woman) < getIndex(boyPrefer[hisIndex], hisFiance)) {
                return false;
            }
        }
    }
    return true;
}

// Function to generate all permutations of a list
void permute(vector<string>& elements, int start, vector<vector<string>>& result) {
    if (start == elements.size() - 1) {
        result.push_back(elements);
        return;
    }
    for (size_t i = start; i < elements.size(); i++) {
        swap(elements[start], elements[i]);
        permute(elements, start + 1, result);
        swap(elements[start], elements[i]);
    }
}

vector<vector<string>> generatePermutations(const vector<string>& elements) {
    vector<vector<string>> result;
    vector<string> temp = elements;
    permute(temp, 0, result);
    return result;
}

// Function to find all stable matches
vector<map<string, string>> findStableMatches(int n, const vector<string>& boys,
                                              const vector<string>& girls,
                                              const vector<vector<string>>& boyPrefer,
                                              const vector<vector<string>>& girlPrefer) {
    vector<map<string, string>> stableMatches;
    vector<vector<string>> allPermutations = generatePermutations(girls);

    for (const auto& girlAssignment : allPermutations) {
        map<string, string> pairings;
        for (int i = 0; i < n; i++) {
            pairings[boys[i]] = girlAssignment[i];
        }
        if (isStable(pairings, boys, girls, boyPrefer, girlPrefer)) {
            stableMatches.push_back(pairings);
        }
    }
    return stableMatches;
}

int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n;
    cin >> n;
    if (n == 0) return 0;

    cin.ignore(); // Ignore the newline after n
    string boysLine, girlsLine;
    getline(cin, boysLine);
    getline(cin, girlsLine);

    vector<string> boys;
    vector<string> girls;
    stringstream boysStream(boysLine);
    stringstream girlsStream(girlsLine);
    string name;

    while (boysStream >> name) {
        boys.push_back(name);
    }
    while (girlsStream >> name) {
        girls.push_back(name);
    }

    vector<vector<string>> boyPreferences(n);
    vector<vector<string>> girlPreferences(n);

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        while (ss >> name) {
            boyPreferences[i].push_back(name);
        }
    }

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        while (ss >> name) {
            girlPreferences[i].push_back(name);
        }
    }

    vector<map<string, string>> stableMatches = findStableMatches(n, boys, girls, boyPreferences, girlPreferences);

    if (!stableMatches.empty()) {
        for (const auto& match : stableMatches) {
            for (const auto& boy : boys) {
                cout << boy << " " << match.at(boy) << endl;
            }
            cout << "-------" << endl;
        }
    }

    return 0;
}