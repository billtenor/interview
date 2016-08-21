//
// Created by yanjun on 16-8-21.
//

#ifndef INTERVIEW_LEETCODE_H
#define INTERVIEW_LEETCODE_H
class leetcode {
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
#endif //INTERVIEW_LEETCODE_H
