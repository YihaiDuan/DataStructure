#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    while(cin >> n ){
        int num = pow(3,n);
        string sub= "@";
        while(n--){
            string blank;
            for(int i=0; i<sub.length();i++)
                blank+=" ";
            sub = sub + blank + sub;
        }
        cout << sub << endl;

    }
    return 0;
}
