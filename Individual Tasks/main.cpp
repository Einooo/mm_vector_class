#include <bits/stdc++.h>
using namespace std;

// 1st we want a func that checks if the guessed word exists in the dictionary.txt
vector<string> vec;

void loaddect(){
    vec.reserve(130000);
    ifstream file("dictionary.txt");
    string line;
    while (getline(file, line)) {
        vec.emplace_back(line);
    }
}

bool checkWord(string word) {
    return binary_search(vec.begin(),vec.end(),word);
}

bool isvalidstentence(string word) {
    string temp ="";
    for (char i : word){
        if (i != ' '){
            temp += i;
        }
        else{
            if (!temp.empty()&&!checkWord(temp)) {
                return false;
            }
            temp="";
        }
    }
    return true;
}

// 2nd we want a recursion function that takes every letter in word and add it to a temp checks if it exists in the dictionary.txt

void findWords(const string& word,int pos, string res) {
     string temp = res;
     if (pos == word.size()) {
         if (isvalidstentence(res)){
             cout<<res<<endl;
         }
         return;
     }
     for(int i=pos; i<word.size(); i++) {
         temp+=word[i];
         findWords(word,i+1,temp+" ");
     }
}

// 3rd we want a main func that takes the input from the user and calls the recursion func
int main(){
    string word,str;
    cin >> word;
    for (auto i : word) {
        str += tolower(i);
    }
    loaddect();
    findWords(str,0,"");
    return 0;
}