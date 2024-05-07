#include "Login.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>
using namespace std;

tuple<std::string, double, int, int> Login::getPlayer()
{
    int counter = 0, uf = 0;
    vector<string> names;
    vector<double> balance;
    vector<int> wins;
    vector<int> losses;
    string name;
    ifstream fin("playerData.csv");
    if (!fin)
    {
        cerr << "Failed to open file" << endl;
        exit(-1);
    }

    string line;
    getline(fin, line); // Skip header line if present

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

    while(uf!=1){
        cout << "Enter your username:" << endl;
        cin >> name;

        for(int i = 0; i < counter; i++){
            if(names[i] == name){
                fin.close();
                cout << "User found!" << endl;
                return std::make_tuple(names[i], balance[i], wins[i], losses[i]);
            }
        }
        cout << "User not found. try again" << endl;
    }
    exit(-1);
}
