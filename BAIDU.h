//
// Created by yanjun on 16-8-21.
//

#ifndef INTERVIEW_BAIDU_H
#define INTERVIEW_BAIDU_H
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
#endif //INTERVIEW_BAIDU_H
