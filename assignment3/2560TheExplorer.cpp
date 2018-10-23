#include <iostream>
#include <queue>
#define MAXN 100
#define INF 100000
using namespace std;
typedef pair<int,int> p;
queue <p> que;
int x,y,sx,sy,ex,ey;
int maps[MAXN][MAXN];
int dist[MAXN][MAXN];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
void initdist(int x, int y){
    for (int i=0; i<y; i++){
            for (int j=0; j<x; j++){
                dist[i][j] = INF;
            }
        }
}
int bfs(int n, int m){
    initdist(x,y);
    dist[m][n] = 0;
    que.push(p(n,m));
    while(que.size()){
        p cut = que.front();
        que.pop();
        for(int i=0; i<4; i++){
            int cx = cut.first + dx[i];
            int cy = cut.second + dy[i];
            if(cx>=0 && cx<x && cy>=0 && cy<y && maps[cy][cx]!=1 &&  dist[cy][cx] == INF){
                dist[cy][cx] = dist[cut.second][cut.first] + 1;
                que.push(p(cx,cy));
            }
        }
    }
    return dist[ey][ex];
}
int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        int shortest;
        cin >> x >> y;
        for (int i=0; i<y; i++){
            for (int j=0; j<x; j++){
                cin >> maps[i][j];
            }
        }
        cin >> sx >> sy;
        cin >> ex >> ey;
        shortest = bfs(sx,sy) + 1;
        cout << shortest << endl;
    }
    return 0;
}
