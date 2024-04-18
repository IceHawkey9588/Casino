#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Player{
    float balance;
    string name;
    string password;
    public:
    void Player(string name, string password){
        this.name = name;
        this.password = password;
    }
    float getBalance(){
        // todo:
        // get balance from a saved spreadsheet,
        // if is a new player give some moner.
        balance = 5000; // starting moner 5000
        return balance;
    }
}