//
// Created by Felix on 2022-12-03.
//

#include "Headers/December3rd.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string alphabet = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

void December3rd()
{
    vector<int> getIntSortedRutsack(string);

    int total = 0;
    int count = 1;

    ifstream file("./Inputs/ThirstOfDecember.txt");
    string line;
    vector<string> twoFirst;

    while (file >> line) {
        if (count % 3 == 0) {
            vector<int> rutsack1 = getIntSortedRutsack(twoFirst[0]);
            vector<int> rutsack2 = getIntSortedRutsack(twoFirst[1]);
            for (int i = 0; i < line.length(); i++) {
                int val = (int)alphabet.find(line[i]);
                if (binary_search(rutsack1.begin(), rutsack1.end(), val)
                    && binary_search(rutsack2.begin(), rutsack2.end(), val))
                {
                    total += val;
                    break;
                }
            }
            twoFirst.clear();
        }
        else {
            twoFirst.push_back(line);
        }
        count++;
    }
    cout << total << endl;
}
vector<int> getIntSortedRutsack(string line) {
    vector<int> rutsack;
    for (int i = 0; i < line.length(); i++) {
        int val = (int)(alphabet.find(line[i]));
        rutsack.push_back(val);
    }
    sort(rutsack.begin(), rutsack.end());
    return rutsack;
}