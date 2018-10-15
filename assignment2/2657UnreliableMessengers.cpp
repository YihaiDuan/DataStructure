#include <iostream>
#include <algorithm>


using namespace std;
void J (string &str){
   int len = str.length();
   str = str[len-1] + str.substr(0,len-1);
}
void C (string &str){
    str = str.substr(1) + str[0];
}
void E (string &str){
    int len = str.length();
    if(len%2 == 0){
        str = str.substr(len/2) + str.substr(0,len/2);
    }
    else{
        int half = len/2;
        str = str.substr(half+1) + str.substr(half,1) + str.substr(0,half);
    }
}
void A (string &str){
    reverse(str.begin(),str.end());
}
void P (string &str){
    int len = str.length();
    for(int i=0; i<len; i++){
        if(str[i]>='0' && str[i]<='9')
            str[i] = (str[i]-'0' + 10 - 1) % 10 + '0';
    }
}
void M (string &str){
    int len = str.length();
    for(int i=0; i<len; i++){
        if(str[i]>='0' && str[i]<='9')
            str[i] = (str[i]-'0' + 1) % 10 + '0';
    }
}


int main()
{
    int cases;
    cin >> cases;
    while (cases--){
        string order,text;
        cin >> order >> text;
        //cout << text << endl;
        for(int i=order.length()-1;i>=0;i--){
            //cout << order[i] << endl;
            switch (order[i]){
                case 'J': J(text);break;
                case 'C': C(text);break;
                case 'E': E(text);break;
                case 'A': A(text);break;
                case 'P': P(text);break;
                case 'M': M(text);break;
            }
        }
        cout << text  << endl;
    }

    return 0;
}
