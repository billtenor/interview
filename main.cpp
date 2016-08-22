#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

#include "BAIDU.h"
#include "HUAWEI.h"
#include "LEETCODE.h"
#include "COURSE.h"

using namespace std;

int main() {
    baidu mybaidu;
    leetcode myleetcode;
    huawei myhuawei;
    sort mysort;
    divide_conquer mydivide_conquer;
    int n;
    while(cin>>n){
        int* A=new int[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        cout<<mydivide_conquer.max_subarray(A,n)<<endl;
        delete[] A;
    }

    while(cin>>n){
        int* A=new int[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        mysort.merge(A,n);
        for(int i=0;i<n;i++){
            cout<<A[i]<<" ";
        }
        cout<<endl;
        delete[] A;
    }

    while(cin>>n){
        for(int i=0;i<n;i++){
            string data;
            cin>>data;
            string target;
            cin>>target;
            cout<<myhuawei.get_cost(data,target)<<endl;
        }
    }
    return 0;
}