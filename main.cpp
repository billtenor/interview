#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
using namespace std;

struct binary_tree{
    int val;
    binary_tree *left;
    binary_tree *right;
    binary_tree(): left(NULL), right(NULL), val(0) {}
    binary_tree(int val): left(NULL), right(NULL){
        this->val=val;
    }
    binary_tree(int val,binary_tree *left,binary_tree *right){
        this->val=val;
        this->left=left;
        this->right=right;
    }
};

class baidu{
private:
    void bracket_helper(int a){
        if(a==1&&bracket_left+a<=bracket_N){
            bracket_left+=a;
            bracket_right+=a;
            *(bracket_A+bracket_index)=a;
            bracket_index++;
        }
        else if(a==-1&&bracket_right+a>=0){
            bracket_right+=a;
            *(bracket_A+bracket_index)=a;
            bracket_index++;
        }
        else {
            if(a==-1&&bracket_index==bracket_N*2){
                bracket_print();
            }
            return;
        }
        bracket_helper(1);
        bracket_helper(-1);
        if(a==1){
            bracket_left-=a;
            bracket_right-=a;
        }
        else bracket_right-=a;
        bracket_index--;
    }
    void bracket_print(){
        for(int i=0;i<bracket_N*2;i++){
            if(*(bracket_A+i)==1)cout<<"(";
            else cout<<")";
        }
        cout<<endl;
    }
    int *bracket_A;
    int bracket_index;
    int bracket_left;
    int bracket_right;
    int bracket_N;
public:
    void print_binary_tree(binary_tree *root)
    {
        queue<int> print_queue;
        queue<binary_tree*> binary_queue;
        binary_tree* special;
        int special_int=(1<<31);
        binary_queue.push(root);
        binary_queue.push(special);
        while(!binary_queue.empty()){
            binary_tree* top=binary_queue.front();
            binary_queue.pop();
            if(top==special){
                if(binary_queue.back()!=special)binary_queue.push(special);
                print_queue.push(special_int);
            }
            else{
                print_queue.push(top->val);
                if(top->left!=NULL)binary_queue.push(top->left);
                if(top->right!=NULL)binary_queue.push(top->right);
            }
        }
        while(!print_queue.empty()){
            int top=print_queue.front();
            if(top==special_int)
                cout<<endl;
            else
                cout<<top<<' ';
            print_queue.pop();
        }
    }
    void bracket_main(int N){
        bracket_A = new int[N*2];
        bracket_index=0;
        bracket_left=0;
        bracket_right=0;
        bracket_N=N;
        bracket_helper(1);
        delete[] bracket_A;
    }
};

class Solution {
private:
    Interval judge_merge(Interval a,Interval b){
        Interval result;
        if(a.end<b.start || b.end<a.start){
            result.start=1;
            result.end=0;
            return result;
        }
        else {
            int min=a.start;
            int max=a.end;
            if(b.start<min)min=b.start;
            if(b.end>max)max=b.end;
            result.start=min;
            result.end=max;
            return result;
        }
    }
public:
    bool test(){
        std::vector<int> a;
        a.push_back(1);
    }
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int index=0;
        int n=intervals.size();
        vector<Interval> result;
        Interval merge(2,1);
        if(n==0)result.push_back(newInterval);
        while(index<n){
            Interval buff=judge_merge(newInterval,intervals[index]);
            if(buff.start>buff.end){
                if(newInterval.end<intervals[index].start){
                    result.push_back(newInterval);
                    for(int i=index;i<n;i++){
                        result.push_back(intervals[i]);
                    }
                    return result;
                }
                else{
                    result.push_back(intervals[index]);
                    if(index==n-1)result.push_back(newInterval);
                    index++;
                }
            }
            else{
                merge=buff;
                index++;
                break;
            }
        }
        if(index==n){
            if(!(merge.start>merge.end))result.push_back(merge);
        }
        while(index<n){
            Interval buff=judge_merge(merge,intervals[index]);
            if(buff.start>buff.end){
                result.push_back(merge);
                for(int i=index;i<n;i++){
                    result.push_back(intervals[i]);
                }
                break;
            }
            else{
                merge=buff;
                if(index==n-1)result.push_back(merge);
                index++;
            }
        }
        return result;
    }
    bool isMatch(string s, string p) {
        int num_s=s.length();
        int num_p=p.length();
        int index_s=0;int index_p=0;
        int star=-1;int match;int add_p=1;
        bool result=true;

        while(index_s<num_s || index_p<num_p){
            char s_now=index_s<num_s?s[index_s]:0;
            char p_now=index_p<num_p?p[index_p]:0;

            if(p_now=='*'){
                if(index_p==num_p-1)break;
                else{
                    star=index_p;
                    add_p=0;
                    index_s--;
                    index_p++;
                }
            }
            else if(s_now==p_now || (s_now!=0 && p_now=='?')){
                if(add_p==0)match=index_s;
                add_p=1;
            }
            else {
                if(star==-1 || (add_p==0 && s_now==0)){
                    result=false;
                    break;
                }
                else if(star!=-1 && add_p==1){
                    index_p=star+1;
                    index_s=match;
                    add_p=0;
                }
            }
            index_s++;
            index_p+=add_p;
        }
        return result;
    }
    bool isPerfectSquare(int num) {
        unsigned int root=0;
        unsigned int bit=1<<15;
        while(bit>0){
            root|=bit;
            if(root>num/root){
                root^=bit;
            }
            bit>>=1;
        }
        return root*root==num;
    }
    int sqrt(int x){
        int left = 1;
        int right= x;
        int mid = (left+right)/2;
        while(left<right-1){
            mid = (left+right)/2;
            if(x / mid == mid){
                return mid;
            }
            else if(x/mid<mid){
                right=mid;
            }
            else{
                left=mid;
            }
        }
        return left;
    }
};

int main() {
    std::cout << std::endl;
    return 0;
}