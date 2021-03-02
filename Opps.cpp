////// node.h//////

# include <vector>
using namespace std;
template <typename t>

class treenode {
    public:
    t data;
    vector<treenode*>children;

    treenode(t data){
        this->data = data;
    }
}


////// implentation

#include <treenode.h>
# include <bits/stdc++.h>
using namespace std;
int main(){
    treenode* root = new treenode(5);
    treenode* node1 = new treenode(2);
    treenode* node2 = new treenode(3);

    root->children.push_back(node1);
    root->children.push_back(node2);

}





