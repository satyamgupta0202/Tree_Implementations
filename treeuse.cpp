# include <bits/stdc++.h>
# include "treenode.h"
using namespace std;
int l;
/**----------- printing in tree------------------------**/

void print(treenode<int>* root){
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        print(root->children[i]);
    }
}

/** printing in preorder traversal format-----------**/

void preorder(treenode<int>* root){

    cout<<root->data<<" "<<endl;

    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }

}

void postorder(treenode<int>* root){

    for(int i=0;i<root->children.size();i++){
        postorder(root->children[i]);
    }
    cout<<root->data<<" "<<endl;

}


/** ---------- printing tree in level order traversal **/
 
void printLevel(treenode<int>* root){
    queue<treenode<int>*>p;
    p.push(root);
    //for(int i=1;i<=root->children.size();i++){
        //p.push(root->children[i]);
   // }
    while(p.size()!=0){
        cout<<p.front()->data<<" ";
        for(int i=0;i<p.front()->children.size();i++){
            p.push(p.front()->children[i]);
        }
        p.pop();
    }
}


///***--- taking input from user in level order treaversal manner**/

treenode<int>* Levelinput(){
    cout<<"enter root data"<<endl;
    int rootdata;
    cin>>rootdata;

    treenode<int>* root = new treenode<int>(rootdata);
    queue<treenode<int>*>pending;
    pending.push(root);

    while(pending.size()!=0){
        treenode<int>* front = pending.front();
        pending.pop();

        cout<<"Enter the no of childern of"<<front->data<<endl;
        int nc;
        cin>>nc;

        for(int i=1;i<=nc;i++){
            int childdata;
            cin>>childdata;

            treenode<int>* child = new treenode<int>(childdata);
            front->children.push_back(child);
            pending.push(child);
        }
    }
    return root;

}


////--------- taking input of tree directly from the user

treenode<int>* input(){
    cout<<"enter root"<<endl;
    int data;
    cin>>data;
    treenode<int>* root = new treenode<int>(data);

    cout<<"enter total children of the node"<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        treenode<int>* child = input();
        root->children.push_back(child);
    }
    return root;
}



/** -- counting total nodes -------**/

int countnodes(treenode<int>*root){
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans+= countnodes(root->children[i]);
    }
    return ans;
}

/** ---- counting sum of all nodes ** ----**/

int sumofnodes( treenode<int>* root){
    int sum_node = root->data;

    for(int i=0;i<root->children.size();i++){
        sum_node+= sumofnodes(root->children[i]);
    }
    return sum_node;
}

///////////////////////////////////////
/**--------- height of the tree----------- **/

int height (treenode<int>* root){
    int h=1;

    for(int i=0;i<root->children.size();i++){
      h =max( h ,1+height(root->children[i]));
    }
    return h;
}

/////////////////////////////////////////////////////
/** printing all nodes at the depth h **/

void depth (treenode<int>* root ,int d){

    if(d==1){
        cout<<root->data<<"===";
    }

    for(int i=0;i<root->children.size();i++){

        depth(root->children[i],d-1);
    }
    }

/** ---- cout total leaf nodes ---------**/

int leaf(treenode<int>* root){

    if(root->children.size()==0){
        l=l+1;
    }

    for(int i=0;i<root->children.size();i++){
        leaf(root->children[i]);
    }
    return l;
}

/////////////////////////////////////////////////////////

int main(){

   /* ---------predefined tree----------
    treenode<int>* root = new treenode<int>(1);
    treenode<int>* node1 = new treenode<int>(22);
    treenode<int>* node2 = new treenode<int>(11);

    root->children.push_back(node1);
    root->children.push_back(node2);
    */
  // treenode<int>* root= input();

  treenode<int>* root = Levelinput();

   // print(root);

  // printLevel(root);

/*
   int totalnodes = countnodes(root);
   cout<<" total nodes ="<<totalnodes<<endl;
*/

/*
   int sum_of_node = sumofnodes(root);
   cout<<"sum of all nodes "<<sum_of_node<<endl;
*/

/*
int high  = height(root);
cout<<"height of the tree is"<<high<<endl; 
*/

//depth(root , 2);

int l = leaf(root);
cout<<"total leafs = "<<l<<endl;

///postorder(root);
///preorder(root);

    return 0;
}