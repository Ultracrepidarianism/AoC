//
// Created by Felix on 2022-12-04.
//

#include "Headers/December4th.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void December4th() {
    int total = 0;

    ifstream file("Inputs/FourstOfDecember.txt");
    string line;
    vector<int> lowests;
    vector<int> greatests;
    while (getline(file, line)) {
        stringstream pair(line);
        string assignment;
        while (getline(pair, assignment, ',')) {
            stringstream sectors(assignment);
            string currentSector;

            getline(sectors, currentSector, '-');
            lowests.push_back(std::stoi(currentSector));

            getline(sectors, currentSector, '-');
            greatests.push_back(std::stoi(currentSector));
        }
        if((greatests[0] >= lowests[1] && lowests[0] <= lowests[1]) || (greatests[1] >= lowests[0] && lowests[1] <= lowests[0])){
            total++;
        }
        lowests.clear();
        greatests.clear();
    }
    cout << total;
}