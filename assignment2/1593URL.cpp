#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    cin.get();
    int num=1;
    while(cases--){
        string url;
        getline(cin,url);
        string protocal,host,port,path;
        protocal = host = port = path = "<default>";
        int len = url.length();
        int proPos = url.find("://");
        int portPos;
        protocal = url.substr(0,proPos);
        int i;
        for( i=proPos+3;i<len;i++){
            if (url[i]==':' || url[i]=='/')
                break;
        }
        if(proPos+3<len)
            host = url.substr(proPos+3,i-proPos-3);
        int index = i,first = 1;
        for(i=index;i<len;i++){
            if(isdigit(url[i])){
                if(first){
                    portPos = i;
                    first=0;
                }
            }
            else if(url[i] == '/')
                    break;
        }
        //cout << i << url[i] << endl;
        if (i!=index)
            port = url.substr(portPos,i-portPos);
        index = i+1;
        if(index<len)
            path = url.substr(index);


//        if(hostPos != -1){
//            if(pathPos != -1){
//                host = url.substr(proPos+3,hostPos-proPos-3);
//                port = url.substr(hostPos+1,pathPos-hostPos-1);
//                path = url.substr(pathPos+1);
//            }
//            else{
//                host = url.substr(proPos+3,hostPos-proPos-3);
//                port = url.substr(hostPos+1);
//            }
//
//        }
//        else{
//            if(pathPos != -1){
//                host = url.substr(proPos+3,pathPos-proPos-3);
//                path = url.substr(pathPos+1);
//            }
//            else{
//                host = url.substr(proPos+3);
//            }
//        }
        cout << "URL #" << num << endl;
        cout << "Protocol = " << protocal << endl;
        cout << "Host     = " << host <<endl;
        cout << "Port     = " << port <<endl;
        cout << "Path     = " << path <<endl << endl;
        num++;

    }
    return 0;
}
