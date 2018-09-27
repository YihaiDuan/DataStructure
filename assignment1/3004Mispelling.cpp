#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    int temp = 0;
    while(cases--){
        temp++;
        int n;
        string str;
        cin >> n;
        cin >> str;
        string s;
        s = str.substr(0,n-1) + str.substr(n,str.length()-n);
        cout << temp << " " << s<< endl;
    }
    return 0;
}
