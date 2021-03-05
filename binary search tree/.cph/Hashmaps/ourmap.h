# include <bits/stdc++.h>
using namespace std;
template<typename v>    // v denotes type of value

class mapnode {              // create a sort of link list
    public:
    string key;
    v value;
    mapnode* next;


    mapnode(string key , v value){     // constructor
        this->key = key;
        this->value = value;
    }

    ~mapnode(){                        //destructor
        delete next;
    }
};


template<typename v>

class ourmap{          
    mapnode** buckets;     // address of haed of address of bucket
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

 ///////////////////functions/////////////////////

 //1//

    int size(){
        return count;
    }

//2//

    v getValue(string key){
        int bucketIndex = getbucketIndex(string key);
        mapnode<v>*head = bucket[bucketIndex];
        while(head!=NULL){

            if(head->key == key ){
                return key->value;
            }
            head=head->next;
        }
   return 0;
    }

private:
    int getbucketIndex(string key){
        int hashcode=0;
        int currentcoff=1;

        for(int i=k.size()-1;i>=0;i--){
            hashcode+=key[i]*currentcoff;
            hashcode = hashcode%numbuckets;
            currentcoff*=37;
            currentcoff = currentcoff%numbuckets;
        }



        return hashcode%numbuckets;
    }
//3//
    public:
    void insert(string key , v value){
        int bucketIndex = getbucketIndex(string key);
        mapnode<v>*head = bucket[bucketIndex];
        while(head!=NULL){
            if(head->key == key){
            head->value = value;
            return ;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        mapnode<v>* node = new mapnode(key,value);
        node->next = head;
        bucket[bucketIndex]=node;
        count++;
    }

//4//


    v remove(string key){
        int bucketIndex = getbucketIndex(string key);
         mapnode<v>*head = bucket[bucketIndex];
         mapnode<v>*prev = NULL;

         while(head!=NULL){

             if(head->key == key){
                 if(prev==NULL){
                     buckets[bucketIndex]=head->next;
                 }
                 else{
                     prev->next = head->next;
                 }
                 v value = head->value;
                 head->next=NULL;
                 delete head;
                 count--;
                 return value;
             }
             prev = head;
             head = head->next;
         }
         return 0;
    }
};
