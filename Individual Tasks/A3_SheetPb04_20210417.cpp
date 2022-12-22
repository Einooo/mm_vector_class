#include<bits/stdc++.h>

using namespace std;


void getAllCombinations(string ans , string color, int n){
   if(n > 0 ){
      ans += " ";
      ans += color;
   }

   if(n == 1){
       cout << ans;
       cout << endl;
       return ;
   }


    getAllCombinations(ans, "Red",n-1 );
    getAllCombinations( ans,"Green",n-1 );
    getAllCombinations( ans,"yellow",n-1 );


}
void print(vector<string>& data, int n){
    getAllCombinations("",data[0], n);
    getAllCombinations("",data[1], n);
    getAllCombinations( "","yellow",n );
}

int main(){
    vector<string> data = {"Red", "Green", "Yellow"};
    print(data, 3);
}
