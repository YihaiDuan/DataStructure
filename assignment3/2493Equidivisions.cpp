#include <iostream>
#include <string.h>
#include <stdio.h>
#define MAXN 105
using namespace std;
int maps[MAXN][MAXN];
int visit[MAXN][MAXN];
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int cnt,n;
void dfs (int x, int y, int number){
    if (visit[x][y] == 1)
        return;
    if (x<0 || x>=n || y<0 || y>=n)
        return;
    if(number != maps[x][y])
        return;
    cnt++;
    visit[x][y] = 1;
    for(int i=0; i<4; i++){
        dfs(x+dir[i][0],y+dir[i][1],number);
    }
}
int main()
{
    while(cin >> n && n){
        int i,j;
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                maps[i][j] = 0;
                visit[i][j] = 0;
            }
        }
        int x,y;
        int h = n*(n-1);
        for(i=0; i<h; i++){
            cin >> x >> y;
            maps[x-1][y-1] = (i/n +1);
        }
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                cnt=0;
                if(visit[i][j] == 1)
                    continue;
                dfs(i,j,maps[i][j]);
                if (cnt!=n){
                     //cout << "haha " << cnt << " " << maps[i][j] << endl;
                     break;
                }

            }
            if(j<n)
                break;
        }
        if(i<n)
            cout << "wrong" << endl;
        else
            cout << "good" << endl;
    }

    return 0;
}
