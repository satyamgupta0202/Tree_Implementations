using namespace std;
template <typename t>

class binarytreenode {
    public:                       // local structure
    t data;
    binarytreenode* left;
    binarytreenode* right;

    binarytreenode(t data){     // new node with left and right pointer
        this->data=data;
        left= NULL;
        right= NULL;
    }
    ~binarytreenode(){      //destructor
        delete left;
        delete right;
    }
};
