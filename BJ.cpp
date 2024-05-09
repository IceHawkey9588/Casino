#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "BJ.h"
#include "Hand.h"

using namespace std;
BJ::BJ(Player& player)
{
    startGame(player);
}

BJ::~BJ()
{
}

void BJ::startGame(Player& player)
{
    string choice;
    int bet;
    int cards[52];//All cards
    system("chcp 65001");
    system("cls");
    cout << "Welcome to the BlackJack game!" << endl;
    cout << "Your initial balance is: $" << player.getBalance() << endl;
    while (player.getBalance() > 0)
    {
        
        Hand client;
        Hand dealer;
        cout << "\nEnter your bet: $";
        cin >> bet;
        system("cls");
        cout << endl;
        if (bet > player.getBalance())
        {
            cout << "You don't have enough balance to make this bet. Try again." << endl;
            continue;
        }
        giveCards(cards, client, dealer);
        while (1)
        {
            showCards(client, dealer);
            if (client.score > 21)
            {
                client.end = true;
                break;
            }
            cout << "Make a choice:\n";
            cout << "1. Hit\n";
            cout << "2. Stand\n";
            cin >> choice;
            cout << endl;
            if (choice == "hit" || choice == "Hit" || choice == "1") rndCard(cards, client);
            else if (choice == "stand" || choice == "Stand" || choice == "2")
            {
                client.end = true;
                break;
            }
            else cout << "Invalid choice. Please enter 'hit', '1' or 'stand', '2'.\n" << endl;
        }
        if (client.score > 21)
        {
            player.decreaseBalance(bet);
            player.incrementLosses();
            rndCard(cards, dealer);
            showCards(client, dealer);
            cout << "\nSorry, you lost. Your new balance is: $" << player.getBalance() << endl;
            cout << endl;
        }
        else
        {
            dealersMove(cards, client, dealer);
            if (client.end == true)
            {
                if (dealer.end == true)
                {
                    player.decreaseBalance(bet);
                    player.incrementLosses();
                    cout << "Sorry, you lost. Your new balance is: $" << player.getBalance() << endl;
                    cout << endl;
                }
                else
                {
                    player.increaseBalance(bet);
                    player.incrementWins();
                    cout << "Congratulations! You won. +" << bet << "$!\nYour new balance is: $" << player.getBalance() << endl;
                    cout << endl;
                }
            }
            else
            {
                cout << "It's a tie! Your balance remains the same: $" << player.getBalance()<< endl;
                cout << endl;
            }
        }
        if (player.getBalance() == 0)
        {
            cout << "Game over! You've run out of balance. :3" << endl;
            break;
        }
    }

    cout << "Thank you for playing!" << endl;
    cout << "Total Wins: " << player.getWins() << endl;
    cout << "Total Losses: " << player.getLosses() << endl;
}
void BJ::giveCards(int cards[], Hand& client, Hand& dealer)
{
    for (int i = 0; i < 52; i++) cards[i] = 0;

    rndCard(cards, client);
    rndCard(cards, client);
    rndCard(cards, dealer);
}
void BJ::rndCard(int allCards[], Hand& unknown)
{
    int card;
    while (1)
    {
        card = rand() % 52;
        if (allCards[card] == 0)
        {
            allCards[card] = 1;
            unknown.nCards[unknown.n] = card;
            unknown.n++;
            break;
        }
    }
}
void BJ::showCards(Hand& client, Hand& dealer)
{
    system("cls");
    cout << "Dealers's cards:\n";
    for (int i = 0; i < dealer.n; i++)
    {
        printCard(dealer.nCards[i]);
        cout << " ";
    }
    if (client.end == false)cout << "X" << endl;
    else cout << endl;
    calculateScore(dealer);
    cout << "Your cards:\n";
    for (int i = 0; i < client.n; i++)
    {
        printCard(client.nCards[i]);
        cout << " ";
    }
    cout << endl;
    calculateScore(client);
    cout << endl;
}
void BJ::printCard(int card)
{
    if (card / 13 == 0)//♠
    {
        if (card % 13 < 8) cout << "♠" << card % 13 + 2;
        else if (card % 13 == 9) cout << "♠J";
        else if (card % 13 == 10) cout << "♠Q";
        else if (card % 13 == 11) cout << "♠K";
        else cout << "♠A";
    }
    else if (card / 13 == 1)//♥
    {
        if (card % 13 < 8) cout << "♥" << card % 13 + 2;
        else if (card % 13 == 9) cout << "♥J";
        else if (card % 13 == 10) cout << "♥Q";
        else if (card % 13 == 11) cout << "♥K";
        else cout << "♥A";
    }
    else if (card / 13 == 2)//♣
    {
        if (card % 13 < 8) cout << "♣" << card % 13 + 2;
        else if (card % 13 == 9) cout << "♣J";
        else if (card % 13 == 10) cout << "♣Q";
        else if (card % 13 == 11) cout << "♣K";
        else  cout << "♣A";
    }
    else //♦
    {
        if (card % 13 < 8) cout << "♦" << card % 13 + 2;
        else if (card % 13 == 9) cout << "♦J";
        else if (card % 13 == 10) cout << "♦Q";
        else if (card % 13 == 11) cout << "♦K";
        else  cout << "♦A";
    }
}
void BJ::calculateScore(Hand& unknown)
{
    unknown.score = 0;
    unknown.altScore = 0;
    unknown.aces = 0;
    for (int i = 0; i < unknown.n; i++)
    {
        int card = unknown.nCards[i];
        if (card % 13 < 8)
        {
            unknown.score += (card % 13) + 2;
            unknown.altScore += (card % 13) + 2;
        }
        else if (card % 13 == 12)
        { 
            unknown.altScore += 11;
            unknown.score += 1; 
            unknown.aces++; 
        }
        else
        {
            unknown.score += 10;
            unknown.altScore += 10;
        }
    }
    while (1)
    {
        if (unknown.aces > 0)
        {
            if (unknown.altScore > 21)
            {
                unknown.aces--;
                unknown.altScore -= 10;
            }
            else break;
        }
        break;
    }
    if (unknown.aces == 0) cout << "Score: " << unknown.score << endl;
    else cout << "Score: " << unknown.score<<"/"<< unknown.altScore << endl;
}
void BJ::dealersMove(int cards[], Hand& client, Hand& dealer)
{
    rndCard(cards, dealer);
    showCards(client, dealer);
    if (client.altScore<22 && client.altScore>client.score) client.score = client.altScore;
    while (dealer.score < 17 && (dealer.altScore < client.score) && (dealer.score < client.score))
    {
        rndCard(cards, dealer);
        showCards(client, dealer);
        if (client.altScore<22 && client.altScore>client.score) client.score = client.altScore;
    }
    if (dealer.altScore<22 && dealer.altScore>dealer.score) dealer.score = dealer.altScore;
    if(dealer.score>21) {}
    else if (dealer.score > client.score)
    {
        dealer.end = true;
    }
    else if (dealer.score == client.score)
    {
        client.end = false;
    }
}




