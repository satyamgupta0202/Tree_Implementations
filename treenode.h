#include<vector>
using namespace std;

template <typename t>

class treenode {
    public:
    t data;
    vector<treenode*>children;

    treenode(t data){
        this->data = data;
    }
};