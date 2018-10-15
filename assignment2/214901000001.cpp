#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int cases;
    int num = 1;
    cin >> cases;
    while(cases--){
        string num1,num2;
        cin >> num1 >> num2;
        int carryBit = 0;
        int len1 = num1.length();
        int len2 = num2.length();
        int len = len1>len2? len1-len2:len2-len1;
        for (int i=0;i< len;i++){
            if(len1>len2)
                num2 = "0" + num2;
            else
                num1 = "0" + num1;
        }
        len1 = num1.length();
        string result;
        for(int i=len1-1;i>=0;i--){
            int a = num1[i] - '0';
            int b = num2[i] - '0';
            int ans = a+b+carryBit;
            carryBit = 0;
            if (ans==0)
                result = "0" + result;
            else if(ans == 1)
                result = "1" + result;
            else if (ans == 2){
                result = "0" + result;
                carryBit = 1;
            }
            else if (ans == 3){
                result = "1" + result;
                carryBit = 1;
            }
        }
        if (carryBit == 1)
            result = "1" + result;
        int j;
        for(j=0;j<result.length();j++){
            if(result[j] != '0')
                break;
        }
        result = result.substr(j);
        if (result == "")
            result = "0";
        cout << num << " " << result << endl;
        num++;
    }
    return 0;
}
