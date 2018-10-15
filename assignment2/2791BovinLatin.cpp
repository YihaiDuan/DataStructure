#include <iostream>

using namespace std;
string str = "aeiou";
int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        string name;
        cin >> name;
        int f = str.find(name[0]);
        if(f != -1)
            name += "cow";
        else{
            name = name.substr(1) + name[0] + "ow";
        }
        cout << name << endl;
    }
    return 0;
}
