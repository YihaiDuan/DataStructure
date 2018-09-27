#include <iostream>

using namespace std;

int main()
{
    int n;
    int cases = 0;
    while(cin>>n && n!=0){
        cases++;
        int arr[50];
        int cnt = 0;
        int sum = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
           sum += arr[i];
        }
        for(int i=0;i<n;i++){
            if(arr[i] > sum/n)
                cnt+=(arr[i]-sum/n);
        }
        cout << "Set #" << cases << endl;
        cout << "The minimum number of moves is " << cnt << "." << endl;
        cout << endl;

    }
    return 0;
}
