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


/** ---------- printing tree in level order traversal **/
 
void printLevel(treenode<int>* root){
    queue<treenode<int>*>p;
    p.push(root);
    
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


int main(){

   

  treenode<int>* root = Levelinput();

   
    return 0;
}