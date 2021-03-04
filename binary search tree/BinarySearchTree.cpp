# include <bits/stdc++.h>
# include "binarytreenode2.h"
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

// print input Level wise

void printLevel(binarytreenode<int>* root){
    queue<binarytreenode<int>*>level;
    if(root==NULL){
        return;
    }

    level.push(root);
    while(level.size()!=0){

        int temp = level.size();
        while(temp>0){
        binarytreenode<int>* front = level.front();
        cout<<front->data;
        if(front->left!=NULL){
            level.push(front->left);
        }
        if(front->right!=NULL){
            level.push(front->right);
        }
    
        level.pop();
        temp--;
        
        }
        
    }

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

 ////////////////////////////////////////////////////

  int minimum(binarytreenode<int>* root){
     if(root==NULL){
         return INT_MAX;
     }
     return (min(root->data,min(minimum(root->left),minimum(root->right))));
 }
 int maximum(binarytreenode<int>* root){
     if(root==NULL){
         return INT_MIN;
     }
     return (max(root->data,max(maximum(root->left),maximum(root->right))));
 }


 bool isBst(binarytreenode<int>* root){
    if(root==NULL){
        return true;
    }
    int left1 =  maximum(root->left);
    int right1 = minimum(root->right);

    bool output= (((root->data)>left1) && ((root->data)<=right1) && (isBst(root->left)) && (isBst(root->right)));
    return(output);
}





int main(){


  binarytreenode<int>* root = takeinputLevelwise();
   cout<<isBst(root);
  
    return 0;
}
