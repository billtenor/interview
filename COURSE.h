//
// Created by LYJ on 2016/8/22.
//

#ifndef INTERVIEW_COURSE_H
#define INTERVIEW_COURSE_H

class divide_conquer{
private:
    int max(int a,int b){
        return a>b?a:b;
    }
    int max_subarray_helper(int A[],int start,int end){
        if(start>=end){
            return A[start];
        }
        int mid=(start+end)/2;
        int t1=max_subarray_helper(A,start,mid);
        int t2=max_subarray_helper(A,mid+1,end);
        int t3=A[mid]+A[mid+1];
        int k=mid;
        while(--k>=0 && A[k]>=0)t3+=A[k];
        k=mid+1;
        while(++k<=end && A[k]>=0)t3+=A[k];
        return max(t1,max(t2,t3));
    }
public:
    int max_subarray(int A[],int n){
        return max_subarray_helper(A,0,n-1);
    }
};
class sort{
private:
    void merge_helper(int A[],int buff[],int start,int end){
        if(start>=end){
            return;
        }
        int mid=(start+end)/2;
        merge_helper(A,buff,start,mid);
        merge_helper(A,buff,mid+1,end);
        int start1=start;int end1=mid;
        int start2=mid+1;int end2=end;
        int k=start;
        while(start1 <= end1 && start2 <= end2){
            buff[k++]=A[start1]<A[start2]?A[start1++]:A[start2++];
        }
        while(start1 <= end1){
            buff[k++]=A[start1++];
        }
        while(start2 <= end2){
            buff[k++]=A[start2++];
        }
        for(int i=start;i<=end;i++){
            A[i]=buff[i];
        }
    }
public:
    void insert(int A[],int n){
        for(int i=1;i<n;i++){
            int key=A[i];
            int index=i-1;
            while(index>=0 && key<A[index]){
                A[index+1]=A[index];
                index--;
            }
            A[index+1]=key;
        }
    }
    void bubble(int A[],int n){
        int buff;
        for(int i=n-1;i>0;i--){
            for(int j=0;j<i;j++){
                if(A[j]>A[j+1]){
                    buff=A[j];
                    A[j]=A[j+1];
                    A[j+1]=buff;
                }
            }
        }
    }
    void merge(int A[],int n){
        int* buff=new int[n];
        merge_helper(A,buff,0,n-1);
        delete [] buff;
    }
};

#endif //INTERVIEW_COURSE_H
