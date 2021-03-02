using namespace std;

template <typename t>

class binarytreenode {
    public:
    t data;
    binarytreenode* left;
    binarytreenode* right;

    binarytreenode(t data){
        this->data=data;
        left=null;
        right=null;
    }
    ~binarytreenode(){      //destructor
        delete left;
        delete right;
    }
};
