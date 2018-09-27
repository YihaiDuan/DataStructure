#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        string str;
        int n;
        cin >> str >> n;
        n = n%26;
        for(int i=0; i<str.length();i++){
//            str[i] += n;
//            if(str[i] > 'z')
//                str[i] -= 26;

			str[i]-='a';
			str[i]=(str[i]+n)%26;
			str[i]+='a';
        }

        cout << str << endl;
    }
    return 0;
}
