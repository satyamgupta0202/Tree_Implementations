# include <bits/stdc++.h>
using namespace std;
template<typename v>

class mapnode {
    public:
    string key;
    v value;
    mapnode* next;


    mapnode(string key , v value){
        this->key = key;
        this->value = value;
    }

    ~mapnode(){
        delete next;
    }
};

template<typename v>

class ourmap{
    mapnode** buckets;
    int size;
    int numbuckets;

    public:

    ourmap(){
        count =0;
        numbuckets=5;
        buckets = new mapnode<v>*[numbuckets];
        for(int i=0;i<numbuckets;i++){
            buckets[i]=NULL;
        }
    }

    ~ourmap(){
         for(int i=0;i<numbuckets;i++){
            delete(buckets[i]);
        }
        delete []buckets;
    }

    int size(){
        return count;
    }

};
