#include "Login.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>
using namespace std;

tuple<std::string, double, int, int> Login::getPlayer()
{
    string name;
    ifstream fin("playerData.csv");
    if (!fin)
    {
        cerr << "Failed to open file" << endl;
        exit(-1);
    }

    string line;
    getline(fin, line);

    while (getline(fin, line))
    {
        stringstream ss(line);
        string token;
        vector<string> data;
        while (getline(ss, token, ','))
        {
            data.push_back(token);
        }
        if (data.size() == 4)
        {
            names.push_back(data[0]);
            balance.push_back(stod(data[1]));
            wins.push_back(stoi(data[2]));
            losses.push_back(stoi(data[3]));
            counter++;
        }
    }

    while(true){
        cout << "Enter your username:" << endl;
        cin >> name;

        for(int i = 0; i < counter; i++){
            if(names[i] == name){
                fin.close();
                cout << "User found!" << endl;
                playerNum = i;
                return std::make_tuple(names[i], balance[i], wins[i], losses[i]);
            }
        }
        cout << "User not found. try again" << endl;
    }
    exit(-1);
}

void Login::changeCSV(double bet, int additionW, int additionL){
    balance[playerNum] = bet;
    wins[playerNum] = additionW;
    losses[playerNum] = additionL;
    printList();
}

void Login::printList(){
    fstream fin, fout;
    fout.open("Temp.csv", ios::out);
    fin.open("playerData.csv", ios::in);
    fout << "Player,Balance,Wins,Loses" << endl;
    for(int i = 0; i < counter; i++){
        fout << names[i] << "," << balance[i] << "," << wins[i] << "," << losses[i] << endl;
    }
    fin.close();
    fout.close();

    remove("playerData.csv");
    rename("Temp.csv", "playerData.csv");
}