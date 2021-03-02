# include <bits/stdc++.h>
# include "binarytreenode.h"
using namespace std;

//print
void print(binarytreenode<int>* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<":";
    if(root->left){
        cout<< "left:" << root->left->data;
    }
     if(root->right){
        cout<< "Right:" << root->right->data;
    }
    cout<<endl;
    print(root->left);
    print(root->right);
}
// take input 

binarytreenode <int>* takeInput(){
    int rootdata;
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }

    binarytreenode<int>* root = new binarytreenode<int>(rootdata);
    binarytreenode<int>* leftchild = takeInput();
    binarytreenode<int>* rightchild = takeInput();
    root->left = leftchild;
    root->right=rightchild;
    
    return root;
}

//** take input level wise **//
 binarytreenode<int>* takeinputLevelwise(){
     cout<<"enter root data"<<endl;
     int rootdata;
     cin>>rootdata;
     if(rootdata == -1){
         return NULL;
     }
    binarytreenode<int>* root = new binarytreenode<int>(rootdata);
     queue<binarytreenode<int>*> pending;
     pending.push(root);

     while(pending.size()!=0){
         binarytreenode<int>* front = pending.front();
         pending.pop();
         front->left = takeinputLevelwise();
         front->right = takeinputLevelwise();
     }
     return root;
 }



int main(){

/*----------------------------------------------------------------*/
   /* predifined
    binarytreenode<int>* root = new binarytreenode<int>(1);
    binarytreenode<int>* node1 = new binarytreenode<int>(2);
    binarytreenode<int>* node2 = new binarytreenode<int>(3);
    root->left = node1;
    root->right = node2;
    */

   /* user input */
   // binarytreenode<int> * root = takeInput();
// input level wise
    binarytreenode<int>* root = takeinputLevelwise();
    print(root);
    return 0;
}
