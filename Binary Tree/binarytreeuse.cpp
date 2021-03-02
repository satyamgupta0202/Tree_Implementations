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
    binarytreenode<int> * root = takeInput();

    print(root);
    return 0;
}
