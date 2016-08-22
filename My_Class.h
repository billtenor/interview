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
class heep{
private:
    int* data;
    int n;
public:
    heep():data(NULL),n(0){};
    heep(int* data,int n){

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
