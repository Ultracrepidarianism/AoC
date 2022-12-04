//
// Created by Felix on 2022-12-03.
//

#include "Headers/December1st.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <filesystem>

using namespace std;

void December1st()
{
    ifstream file("Inputs/FirstOfDecember.txt");
    string line;
    int topThree[3] = { 0, 0, 0 };
    if (file.is_open()) {
        int temp = 0;
        while (getline(file,line)) {
            if (line.length() == 0) {
                if (topThree[2] < temp) {
                    topThree[2] = temp;
                    sort(topThree,topThree + 3,greater<int>());
                }
                temp = 0;
            }
            else {
                temp += stoi(line);
            }
        }
        int total = 0;
        for (int calorie : topThree) {
            total += calorie;
        }
        cout << total << endl;
    }


}
