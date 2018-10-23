#include <iostream>
#include <string.h>
#include <stdio.h>
#define MAXN 205
using namespace std;
char str[80];
int maps[MAXN][MAXN];
int main()
{
    int num,x,y;
    cin >> num;
    while(num ){
        cin >> x >> y;
        memset(maps,0,sizeof(maps));
        while( x || y){
            cin >> str;
            int i=0;
            while(str[i]){
                maps[x][y] |= 1 << (str[i++]-'a');
            }
            cin >> x >> y;

        }
        for(int k=1; k<=num; k++)
            for(int i=1; i<=num; i++)
                for(int j=1; j<=num; j++)
                    if(maps[i][k]&maps[k][j])
                        maps[i][j]|=maps[i][k]&maps[k][j];

        int m,n;
        cin >> m >> n;
        while(m || n){
            if(maps[m][n] != 0){
                int i=0,cmps=maps[m][n];
                while(cmps)
                {
                    if(cmps&1)
                    putchar(i+'a');
                    cmps>>=1;
                    i++;
                }

                //cout << "haha";
            }
            else
                putchar('-');
            putchar('\n');
            cin >> m >> n;
        }
        putchar('\n');
        cin >> num;
    }
    return 0;
}
