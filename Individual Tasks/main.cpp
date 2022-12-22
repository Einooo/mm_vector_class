#include <bits/stdc++.h>
using namespace std;

#define  N 9

bool is_safe(auto mz[N][N],int x, int y){// this to check if the cell is safe 'not negative' and the cell == 1
    if (x>=0&&x<N&&y>=0&&y<N&&mz[x][y]==1)
        return true;
    return false;
}

bool maze_backtrack(int mz[N][N],int x,int y,int res[N][N]){
    if (x==N-1&&y==N-1&&mz[x][y]==1){//base case if it reaches the end of the maze and the cell = 1 return true
        res[x][y]=1;
        return true;
    }
    res[x+1][y]=1;// mark the cell as 1
    if (is_safe(mz,x+1,y)&&maze_backtrack(mz,x+1,y,res))// go down
        return true;
    res[x+1][y]=0;
    res[x][y+1]=1;
    if (is_safe(mz,x,y+1)&&maze_backtrack(mz,x,y+1,res))// go right
        return true;
    res[x][y+1]=0;
    return false;
}

void solve(int mz[N][N],int res[N][N]){

    if (!(maze_backtrack(mz,0,0,res))){
        cout<<"no solution";
    }
    else{
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) {
                cout << " " <<res[i][j];
            }cout<<endl;
        }
    }
}

int main() {
    int temp[N][N];
    int res[N][N]= {
                     {1, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 1}
    };
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) {
            cin >> temp[i][j];
        }
    }
    solve(temp,res);
}
// 1 0 0 0
// 1 1 0 1
// 0 1 0 0
// 1 1 1 1


/*
1 0 0 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1
1 1 1 0 0 1 0 0 1
0 1 1 1 0 0 0 0 0
1 1 0 1 1 0 0 0 0
1 0 0 1 1 1 1 1 1
1 1 0 1 0 1 0 0 1
1 1 0 1 0 1 1 1 1
0 0 0 1 0 1 0 0 1
 */