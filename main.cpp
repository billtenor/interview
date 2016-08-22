#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

#include "BAIDU.h"
#include "HUAWEI.h"
#include "LEETCODE.h"
#include "COURSE.h"
#include "My_Class.h"

using namespace std;

int main() {
    baidu mybaidu;
    leetcode myleetcode;
    huawei myhuawei;
    sort mysort;
    divide_conquer mydivide_conquer;
    max_heap my_max_heap;

    int n;
    int* data;
    int state;

    while(cin>>n){
        int* A=new int[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        my_max_heap.heap_sort(A,n);
        for(int i=0;i<n;i++){
            cout<<A[i]<<" ";
        }
        cout<<endl;
        delete[] A;
    }

    while(1){
        cout<<"input heap size:";
        cin>>n;
        data=new int[n];
        state=-1;
        while(!(state==1||state==2)) {
            cout << "create NULL heap:1\ncreate heap by list:2" << endl;
            cin >> state;
            if (state == 1) {
                my_max_heap.create_heap(data,0,n);
            }
            else if(state==2) {
                for(int i=0;i<n;i++){
                    cin>>*(data+i);
                }
                my_max_heap.create_heap(data,n);
            }
        }
        state=-1;
        while(state!=4){
            cout<<"insert:1\ndelete:2\nget:3\nquit:4"<<endl;
            cin>>state;
            switch (state){
                case 1:
                    int a;
                    cin>>a;
                    cout<<my_max_heap.heap_insert(a)<<endl;
                    break;
                case 2:
                    cout<<my_max_heap.heap_delete()<<endl;
                    break;
                case 3:
                    cout<<my_max_heap.heap_get()<<endl;
                    break;
            }
        }
        delete[] data;
    }



    while(cin>>n){
        int* A=new int[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        cout<<mydivide_conquer.max_subarray(A,n)<<endl;
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