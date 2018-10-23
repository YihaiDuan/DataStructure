#include <iostream>
#include <math.h>
using namespace std;
struct node{
    double x;
    double y;
    int near;
};
double dist(node n1,node n2){
    double d = (n1.x-n2.x)*(n1.x-n2.x) + (n1.y-n2.y)*(n1.y-n2.y);
    return sqrt(d);
}
int main()
{
    int num;
    int cases = 1;
    cin >> num;
    while(1){
        if (num==0){
            break;
        }
        struct node nodes[3005];
        for(int i=0; i<num; i++){
            cin >> nodes[i].x >> nodes[i].y;
            nodes[i].near = 0;
        }
        //cout << "haha" << endl;
        for(int i=0; i<num; i++){
            for(int j=0; j<num; j++){
                if(dist(nodes[i],nodes[j]) < 20){
                    nodes[i].near++;
                }
            }
        }
        int maxn = 0;
        for(int i=0; i<num; i++){
            if(nodes[i].near>maxn)
                maxn = nodes[i].near;
        }
        if (maxn ==1)
            maxn ++;
        cout << "The towers in case " << cases++ << " can be covered in " << maxn-1 << " frequencies." << endl;
        cin >> num;
    }
    return 0;
}
