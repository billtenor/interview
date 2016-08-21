#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

#include "BAIDU.h"
#include "HUAWEI.h"
#include "LEETCODE.h"

using namespace std;

int main() {
    baidu mybaidu;
    leetcode myleetcode;
    huawei myhuawei;
    int n;
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