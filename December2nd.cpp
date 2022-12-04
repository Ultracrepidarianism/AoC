//
// Created by Felix on 2022-12-03.
//

#include "Headers/December2nd.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Rock  'A' or 'X'
// Paper 'B' or 'Y'
// Scissor 'C' or 'Z'
const int WIN = 6;
const int DRAW = 3;

void December2nd()
{
    void addBattleResultScore(char , char, int&);
    void addChoiceScore(char, int&);

    ifstream file("Inputs/TwostOfDecember.txt");
    string line = "";
    int score = 0;
    while (getline(file, line)) {
        stringstream splitLine(line);
        string segment;
        vector<char> seglist;
        while (getline(splitLine, segment, ' '))
        {
            seglist.push_back(segment[0]);
        }
        switch (seglist[1]) {
            case 'X':
                seglist[1] = seglist[0] == 'A' ? 'Z' : seglist[0] == 'B' ? 'X' : 'Y';
                break;
            case 'Y':
                seglist[1] = seglist[0] == 'A' ? 'X' : seglist[0] == 'B' ? 'Y' : 'Z';
                break;
            case 'Z':
                seglist[1] = seglist[0] == 'A' ? 'Y' : seglist[0] == 'B' ? 'Z' : 'X';
                break;
        }
        addBattleResultScore(seglist[0], seglist[1],score);
        addChoiceScore(seglist[1], score);
    }
    cout << score << endl;
}



void addChoiceScore(char playerChoice, int& score) {
    switch (playerChoice)
    {
        case 'X':
            score += 1;
            break;
        case 'Y':
            score += 2;
            break;
        case 'Z':
            score += 3;
            break;
    }
}
void addBattleResultScore(char elve, char player,int& score) {
    switch (elve) {
        case 'A':
            if (player == 'Y')
                score += WIN;
            else if (player == 'X')
                score += DRAW;
            break;
        case 'B':
            if (player == 'Z')
                score += WIN;
            else if (player == 'Y')
                score += DRAW;
            break;
        case 'C':
            if (player == 'X')
                score += WIN;
            else if (player == 'Z')
                score += DRAW;
            break;

    }
}