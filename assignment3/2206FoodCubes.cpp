#include <iostream>
#include <queue>
#define MAXN 105
using namespace std;
int maps[MAXN][MAXN][MAXN];
int d[6][3] = {-1,0,0,1,0,0,0,-1,0,0,1,0,0,0,-1,0,0,1};
int maxNum,minNum;
bool unreach;
struct Triple
{
    int x,y,z;
    Triple( int a,int b, int c )
        :x(a), y(b), z(c)
    {
    }
};
queue <Triple> q;
void bfs(int x, int y,int z){
    //cout << x << y << z << endl;
      unreach = true;
      q.push(Triple(x,y,z));
      while(q.size()){
        Triple top = q.front();
        //cout << top.x << " " << top.y << " " << top.z<< endl;
        q.pop();
        for(int m=0; m<6; m++){
            int dx = top.x+d[m][0];
            int dy = top.y+d[m][1];
            int dz = top.z+d[m][2];
            if(maps[dx][dy][dz] == 1) continue;
            else {
                if (dx==minNum || dx==maxNum || dy==minNum || dy==maxNum ||dz==minNum || dz==maxNum)
                  unreach = false;
                  else{
                    maps[dx][dy][dz] = 1;
                    q.push(Triple(dx,dy,dz));
                  }
            }



        }
      }


}
int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        int num;
        int cnt = 0;
        cin >> num;
        for(int i=0; i<101; i++){
            for (int j=0; j<101; j++){
                for (int k=0; k<101; k++){
                    maps[i][j][k] = 0;
                }
            }
        }
        int x,y,z;
        maxNum = 1;
        minNum = 100;
        while(num--){
            cin >> x >> y >> z;
            if (x>maxNum) maxNum = x;
            if (y>maxNum) maxNum = y;
            if (z>maxNum) maxNum = z;
            if (minNum>x) minNum =x;
            if (minNum>y) minNum =y;
            if (minNum>z) minNum =z;
            maps[x][y][z] = 1;
        }
        maxNum;
        minNum;

        for(int i=minNum+1; i<maxNum; i++){
            for (int j=minNum+1; j<maxNum; j++){
                for (int k=minNum+1; k<maxNum; k++){
                    if(maps[i][j][k] == 0){
                        bfs(i,j,k);
                        if(unreach) cnt++;
                    }

                }
            }
        }
        cout << cnt << endl;

    }
    return 0;
}

