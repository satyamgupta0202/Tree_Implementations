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

// counting node 

int countnode(binarytreenode<int>*root){
    if(root== NULL){
        return 0;
    }

    return (1+ countnode(root->left)+countnode(root->right));
}

// height of node
// time complexity n^2 

int height(binarytreenode<int>* root){
    if (root==NULL){
        return 0;
    }
     else
    { 
        /* compute the depth of each subtree */
        int lDepth = height(root->left); 
        int rDepth = height(root->right); 
     
        /* use the larger one */
        if (lDepth > rDepth) 
            return(lDepth + 1); 
        else return(rDepth + 1); 
    } 
}

////////// Diameter of tree
// time complexity n^2 
int diameter(binarytreenode<int>* root){
    if(root==NULL){
        return 0;
    }

   int o3 = height(root->left)+height(root->right);
    int o1 = diameter(root->left);
    int o2 = diameter(root->right);
 
    return (max(o1,max(o2,o3)));
}

pair<int,int> heightDiameter(binarytreenode<int>* root){
    if(root==NULL){
        pair<int,int>p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int,int> leftans = heightDiameter(root->left);
    pair<int,int> rightans = heightDiameter(root->right);
    int lh = leftans.first;
    int rh = rightans.first;
    int ld = leftans.second;
    int rd = rightans.second;

    int h= 1+max(lh,rh);
    int d = max(lh+rh,max(ld,rd));
    pair<int,int>p;
    p.first=h;
    p.second=d;
    return p;
}









// traversal in tree 


void preorder(binarytreenode<int>* root){
    if(root==NULL){
        return ;
    }

    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}

void inorder(binarytreenode<int>* root){
    if(root==NULL){
        return ;
    }
    
        inorder(root->left);
        cout<<root->data;
        inorder(root->right);

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
   // print(root);
  // printLevel(root);

  // int c= countnode(root);
  // cout<<"total nodes "<<c<<endl;
 int h= height(root);
 cout<<"height "<<h<<endl;
  //inorder(root);
 //int d =diameter(root);
 //cout<<d<<endl;
  pair<int,int> p;
  p = heightDiameter(root);
  cout<<"height"<<p.first<<endl;
  cout<<"diameter"<<p.second<<endl;
    return 0;
}
