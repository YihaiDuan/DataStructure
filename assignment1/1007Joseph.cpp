//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int arr[30];
//    int k;
//    while(cin>>k && k!=0){
//        int m = 1;
//        bool flag = false;
//        while(!flag){
//            int dead = 0;
//            int index = 0;
//            int cnt=0;
//            for(int i=0;i<2*k+1 ;i++)
//                arr[i] = i;
//            while(dead<k){
//                index++;
//                cnt++;
//
//                if(arr[index] == 0)
//                    cnt--;
//                if(index > 2*k)
//                    index = 1;
//                if(cnt == m){
//                    if(index<=k){
//                        m++;
//                        cout << m<< endl;
//                        break;
//                    }
//                    arr[index] = 0;
//                    cnt=0;
//                    dead++;
//                }
//            }
//            if(dead==k){
//               flag = true;
//            }
//
//        }
//        cout << m << endl;
//    }
//}

#include <iostream>
#include <time.h>
using namespace std;
int arr[14];
int main()
{

    int k;

    while(cin>>k && k!=0){
        if(arr[k]){
            cout << arr[k] << endl;
            continue;
    }
        //clock_t start = clock();
        int m = k+1;
        bool flag = false;
        while(!flag){
            int index = 0;
            int sum = 2*k;
            while(sum>k){
                index = (index+m-1)%sum;
                if(index<k){
                    m++;
                    break;
                }
                sum--;
            }
            //cout << "ha" << sum << " " << m << endl;
            if(sum==k){
               flag = true;
            }
        }
        //clock_t ends = clock();
        arr[k] = m;
        cout << arr[k] << endl;
    }
}

//#include <stdio.h>
//#include <time.h>
//#include <iostream>
//using namespace std;
//int res[15];
//
//int fun(int k)
//{
//	int sum;
//	int m;
//	bool flag;
//	if(res[k])
//		return res[k];
//	for(m = k + 1; ;m++)	//m不可能小于k
//	{
//		sum = 2 * k;
//		int j = 0;
//		while(1)
//		{
//			j = (j + m - 1) % sum;
//			sum--;
//			if(j < k)	//编号小于k说明是好人
//			{
//				flag = false;
//				break;
//			}
//			if(sum == k)	//sum等于k说明只剩好人
//			{
//				flag = true;
//				break;
//			}
//		}
//		if(flag == true)
//		{
//			res[k] = m;
//			return res[k];
//		}
//	}
//
//}
//
//int main()
//{
//	int k;
//	while(scanf("%d",&k) != EOF && k)
//	{
//		clock_t start = clock();
//		printf("%d\n", fun(k));
//		clock_t ends = clock();
//		cout <<(double)(ends - start)/ CLOCKS_PER_SEC << endl;
//
//	}
//	return 0;
//}
