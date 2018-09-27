#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        int arr[10];
        int arr2[10];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        for (int i=0;i<n; i++){
            cin >> arr2[i];
        }
        int sum=0;
        for(int i=0; i<n; i++){
            sum += arr[i] * arr2[i];
        }
        cout << sum << endl;
    }
    return 0;
}
