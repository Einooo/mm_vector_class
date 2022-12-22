#include <bits/stdc++.h>
using namespace std;

int main (){
    map <string, int> m;
    string s;
    s = "doc.txt";
    ifstream file(s.c_str());
    string word;
    while (file >> word)
    {
        for (int i = 0; i < word.length(); i++)
        {
            if (ispunct(word[i]) && word[i] != '-')
            {
                word.erase(i--, 1);
            }
            else if (isalpha(word[i]))
            {
                word[i] = tolower(word[i]);
            }
        }
        m[word]++;
    }
    for (auto & it : m)
    {
        cout << it.first << " " << it.second << endl;
    }
}