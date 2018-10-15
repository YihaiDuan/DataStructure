#include <iostream>

using namespace std;

int main()
{
    string plain;
    string sub;
    getline(cin,plain);
    getline(cin,sub);
    cout << sub << endl << plain << endl;
    string str;
    while (getline(cin,str)){
        for(int i=0; i<str.length();i++){
            int index = plain.find(str[i]);
            if (index != -1)
                cout << sub[index];
            else
                cout << str[i];
        }
        cout << endl;
    }
    return 0;
}
