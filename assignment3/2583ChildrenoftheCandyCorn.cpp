#include <iostream>
#include <queue>
#define MAXN 40
#define INF 100000
using namespace std;
typedef pair<int,int> p;
queue<p> que;
int x,y,sx,sy,ex,ey;
int leftS = 0;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
char maps[MAXN][MAXN];
int dist[MAXN][MAXN];
void initdist(int d[MAXN][MAXN]){
    for (int i=0; i<x; i++){
            for (int j=0; j<y; j++){
                d[i][j] = INF;
            }
    }
}
int leftSearch(int n, int m, int step,int d){
    //cout << "exey" << ex <<" " << ey << endl;
    if (n==ex && m==ey){
            //cout << step << "hahaha";
        return step;
    }
    for(int i=0; i<4; i++){
        int cx = n + dx[(i+d+3)%4];
        int cy = m + dy[(i+d+3)%4];
        if(cx>=0 && cx<x && cy>=0 && cy<y && maps[cx][cy]!='#'){
            //cout << step << " " ;
            //cout << cx <<" " << cy << " " << i+d+3 << endl;
            return leftSearch(cx,cy,step+1,(i+d+3)%4);
        }
    }
}
int rightSearch(int n, int m, int step,int d){
    //cout << "exey" << ex <<" " << ey << endl;
    if (n==ex && m==ey){
            //cout << step << "hahaha";
        return step;
    }
    for(int i=3; i>=0; i--){
        int cx = n + dx[(i+d+2)%4];
        int cy = m + dy[(i+d+2)%4];
        if(cx>=0 && cx<x && cy>=0 && cy<y && maps[cx][cy]!='#'){
            //cout << step << " " ;
            //cout << cx <<" " << cy << " " << i+d+2 << endl;
            return rightSearch(cx,cy,step+1,(i+d+2)%4);
        }
    }
}

int bfs (int n, int m){
    dist[n][m] = 0;
    que.push(p(n,m));
    while(que.size()){

        p cut = que.front();
        que.pop();
        for(int i=0; i<4; i++){
            //cout << "haha";
            int cx = cut.first + dx[i];
            int cy = cut.second + dy[i];
            //cout << cx << " " << cy << endl;
            if(cx>=0 && cx<x && cy>=0 && cy<y && maps[cx][cy]!='#' &&  dist[cx][cy] == INF){
                dist[cx][cy] = dist[cut.first][cut.second] + 1;
                que.push(p(cx,cy));
            }
        }
    }
    return dist[ex][ey];
}
int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        int left,right,shortest;
        cin >> y >> x;
        for (int i=0; i<x; i++){
            for (int j=0; j<y; j++){
                cin >> maps[i][j];
                dist[i][j] = INF;
                if (maps[i][j] == 'S'){
                    sx = i;
                    sy = j;
                }
                if (maps[i][j] == 'E'){
                    ex = i;
                    ey = j;
                }
            }
        }
        left = leftSearch(sx,sy,1,0);
        right = rightSearch(sx,sy,1,0);
        shortest = bfs(sx,sy)+1;

        //cout << sx << sy;
        //cout << right << endl;
        cout << left << " " << right << " " << shortest << endl;

    }
    return 0;
}
