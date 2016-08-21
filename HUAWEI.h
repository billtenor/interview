//
// Created by yanjun on 16-8-21.
//

#ifndef INTERVIEW_HUAWEI_H
#define INTERVIEW_HUAWEI_H

#include "My_Class.h"
#include <iostream>
#include <string>
using namespace std;

class huawei{
private:
    int min(int a,int b) {
        return a < b ? a : b;
    }
    int get_cost_helper(string a,int a_start,int a_end,string b,int b_start,int b_end,int state){
        if(a_start>a_end){
            if(b_start>b_end)return 0;
            else{
                if(state==1){
                    return b_end-b_start+1;
                }
                else{
                    return b_end-b_start+1+2;
                }
            }
        }
        if(b_start>b_end){
            if(a_start>a_end)return 0;
            else{
                if(state==0)return 0;
                else return 2;
            }
        }
        if(a[a_start]==b[b_start]){
            int t1=get_cost_helper(a,a_start+1,a_end,b,b_start+1,b_end,2);
            int t2=get_cost_helper(a,a_start+1,a_end,b,b_start,b_end,0);
            if(state!=0)t2+=2;
            return min(t1,t2);
        }
        else{
            if(state==0)
                return get_cost_helper(a,a_start+1,a_end,b,b_start,b_end,0);
            if(state==1)
                return get_cost_helper(a,a_start,a_end,b,b_start+1,b_end,1)+1;
            else{
                int t1=get_cost_helper(a,a_start+1,a_end,b,b_start,b_end,0)+2;
                int t2=get_cost_helper(a,a_start,a_end,b,b_start+1,b_end,1)+3;
                return min(t1,t2);
            }
        }
    }
public:
    int get_cost(string a,string b)
    {
        return get_cost_helper(a,0,a.size()-1,b,0,b.size()-1,2);
    }
};

#endif //INTERVIEW_HUAWEI_H
