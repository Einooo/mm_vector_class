#include <bits/stdc++.h>
using namespace std;

vector<int> pile={3,4,5};
int coins = 23;
int pcoin = 0;
int ccoin = 0;

class player{//name and score
public:
    string name;
    player(string name){
        this->name=name;
    }

};
// nim game computer player class
class computer:public player{
public:
    computer(string name):player(name){
        this->name=name;
    }

};

void print_piles(vector<int>piles, int n){
    cout <<"Current Game Status -> ";
    for(int i=0; i<n; i++){
        cout <<" "<< piles[i];
    }
    cout << endl;
}

bool gameOver(vector<int>piles, int n)
{
    int i;
    for (i=0; i<n; i++) {
        if (piles[i] != 0)
            return (false);
    }
    return (true);
}

int minmax(vector <int>vec,bool temp);

void best_move(int &indx,int &n){
    int bestvalue=INT_MIN;
    int num;
    for(int i=0; i<3; i++){
        for(int j=1; j<=min(3,pile[i]); j++){
            pile[i]-=j;
            num = minmax(pile,false);
            if (num>bestvalue){
                bestvalue = num;
                indx=i;
                n=j;
            }
            pile[i]+=j;
        }
    }
}

int minmax(vector <int>vec,bool temp){
    if (vec[0]+vec[1]+vec[2]==0){
        if (temp){
            return 10;
        }
        else
            return -10;
    }
    if (temp){
        int bestvalue=INT_MIN;
        for(int i=0; i<3; i++){
            for(int j=1; j<=min(3,vec[i]); j++){
                vec[i]-=j;
                bestvalue=max(bestvalue,minmax(vec,!temp));
                vec[i]+=j;
            }
        }
        return bestvalue;
    }
    else{
        int bestvalue=INT_MAX;
        for(int i=0; i<3; i++){
            for(int j=1; j<=min(3,vec[i]); j++){
                vec[i]-=j;
                bestvalue=min(bestvalue,minmax(vec,!temp));
                vec[i]+=j;
            }
        }
        return bestvalue;

    }
}


int backtrack(int coins,bool temp,int pcoin,int ccoin);

void bestmv(int &n){
    int bestvalue=INT_MIN;
    int num;
    for(int i=1; i<=min(3,coins); i++){
        num = backtrack(coins-i,false,pcoin,ccoin+i);
        if (num>bestvalue){
            bestvalue = num;
            n=i;
        }
    }
}

int backtrack(int coins,bool temp,int pcoin,int ccoin){
    if (coins==0){
        if (pcoin%2==0&&ccoin%2==1){
            return -10;
        }
        else if (pcoin%2==1&&ccoin%2==0){
            return 10;
        }
        else
            return 0;
    }
    if (temp){
        int num;
        int bestvalue=INT_MIN;
        for(int i=1; i<=min(3,coins); i++){
            num = backtrack(coins-i,false,pcoin,ccoin+i);
            bestvalue=max(bestvalue,num);
        }
        return bestvalue;
    }
    else{
        int num;
        int bestvalue=INT_MAX;
        for(int i=1; i<=min(3,coins); i++){
            num = backtrack(coins-i,true,pcoin+i,ccoin);
            bestvalue=min(bestvalue,num);
        }
        return bestvalue;

    }
}

void variant_1(){
    int n;
    while (coins>0){
        cout << "Enter the number of coins you want to take: ";
        cin >> n;

        if (n>3||n<1){
            cout << "Invalid move" << endl;
            continue;
        }
        coins-=n;
        pcoin+=n;
        cout << "Coins left: " << coins << endl;
        if (coins==0&&pcoin%2==0&&ccoin%2==1){
            cout << "You win" << endl;
            break;
        }
        else if (coins==0&&pcoin%2==1&&ccoin%2==0){
            cout << "You lose" << endl;
            break;
        }
        else if (coins==0){
            cout << "Draw" << endl;
            break;
        }
        bestmv(n);
        cout << "Computer takes " << n <<endl;
        coins-=n;
        ccoin+=n;
        cout << "Coins left: " << coins << endl;
        if (coins==0&&pcoin%2==1&&ccoin%2==0){
            cout << "Computer wins" << endl;
            break;
        }
        else if (coins==0&&pcoin%2==0&&ccoin%2==1){
            cout << "Computer loses" << endl;
            break;
        }
        else if (coins==0){
            cout << "Draw" << endl;
            break;
        }

        cout<<"player coins: "<<pcoin<<" "<<"computer coins: "<<ccoin<<endl;
    }

}

void variant_2(){
    int n=3;
    int Player=1;
    int indx,n1;
    string name;
    cout <<"Enter your name: ";
    cin >> name;
    player player1(name);
    computer computer1("AI_Player");
    print_piles(pile,n);
    while(!gameOver(pile,n)){
        if (Player==1){
            cout <<"Player 1's turn"<<endl;
            cout <<"Enter the pile number and number of stones to remove"<<endl;
            cin >> indx >> n1;
            pile[indx]-=n1;
            print_piles(pile,n);
            Player=2;
        }
        else{
            cout <<"Computer's turn"<<endl;
            best_move(indx,n1);
            pile[indx]-=n1;
            cout <<"Computer removed "<<n1<<" stones from pile "<<indx<<endl;
            print_piles(pile,n);
            Player=1;
        }
    }
    if (Player==2){
        cout <<computer1.name<<" wins"<<endl;
    }
    else{
        cout << player1.name<<" wins"<<endl;
    }
}

int main(){
    cout<<"Welcome to Nim Game"<<endl;
    cout <<"do you want to play Variant1 press 1"<<endl;
    cout <<"do you want to play Variant2 press 2"<<endl;
    int choice;
    cin >> choice;
    if (choice==1){
        variant_1();
    }
    else{
        variant_2();
    }
    return 0;
}

