//
// Created by yanjun on 16-8-21.
//

#ifndef INTERVIEW_MY_CLASS_H
#define INTERVIEW_MY_CLASS_H

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class max_heap{
private:
    int* data;
    int n;
    int size;
    void swap(int* a,int* b){
        int buff=*a;
        *a=*b;
        *b=buff;
    }
    void max_heapify(int start){
        int dad=start;
        int son=dad*2+1;
        while(son<n){
            if(son+1<n)son=data[son]>data[son+1]?son:son+1;
            if(data[son]>data[dad])
            {
                swap(data+son,data+dad);
                dad=son;
                son=dad*2+1;
            }
            else return;
        }
    }
public:
    void heap_sort(int A[],int n){
        create_heap(A,n);
        while(this->n>0){
            heap_delete();
        }
    }
    int heap_get(){
        if(data==NULL)return -1;
        else if(n==0) return -1;
        else return data[0];
    }

    bool heap_delete(){
        if(data==NULL)return false;
        else{
            swap(data,data+n-1);
            n--;
            max_heapify(0);
            return true;
        }
    }
    bool heap_insert(int a){
        if(this->size==this->n){
            return false;
        }
        else{
            this->data[this->n]=a;
            this->n++;
            int son=this->n-1;
            int dad=(son-1)/2;
            while(dad>=0){
                if(data[son]>data[dad]){
                    swap(data+son,data+dad);
                    son=dad;
                    dad=(son-1)/2;
                }
                else return true;
            }
            return true;
        }
    }
    max_heap():data(NULL),n(0),size(0){};
    void create_heap(int* data,int n,int size){
        this->data=data;
        this->n=n;
        this->size=size;
        for(int i=n/2-1;i>=0;i--){
            max_heapify(i);
        }
    }
    void create_heap(int* data,int n){
        this->data=data;
        this->n=n;
        this->size=n;
        for(int i=n/2-1;i>=0;i--){
            max_heapify(i);
        }
    }
};

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
#endif //INTERVIEW_MY_CLASS_H
