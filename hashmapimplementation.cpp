#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
#define test ll t;cin>>t;while(t--)
#define f first
#define s second
#define pb push_back
#define pop pop_back
#define int long long int
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define mod 1000000007
#define inf 1LL<<60
void init_code(){
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
class MapNode{
    public :
    string key;
    int value;
    MapNode *next;

    MapNode (string key, int value){
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode(){
        delete next;
    }
};

class OurMap{
    MapNode** buckets;
    int numBuckets;
    int size;

    public :
    OurMap(){
        size = 0;
        numBuckets = 5;
        buckets = new MapNode*[numBuckets];
        for (int i=0;i<numBuckets;i++){
            buckets[i]=NULL;
        }
    }
    //destructor
    ~OurMap(){
        for (int i=0;i<numBuckets;i++){
            delete buckets[i];
        }
        delete []buckets;
    }

    double getLoadFactor(){
        return (1.0*size)/numBuckets;
    }

    int getSize(){
        return size;
    }

    int getValue(string key){
        int bukcetIndex = getBucketIndex(key);
        MapNode *head = buckets[bukcetIndex];

        while(head){
            if(head->key==key){
                return head->value;
            }
            head=head->next;
        }

        return -1;
    }

    void insert(string key, int value){
        int bukcetIndex = getBucketIndex(key);
        MapNode *head = buckets[bukcetIndex];
        while(head){
            if(head->key==key){
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bukcetIndex];
        MapNode *node = new MapNode(key,value);
        node->next = head;
        buckets[bukcetIndex] = node;
        size++;
        double loadFactor = (1.0*size)/numBuckets;
        if(loadFactor>0.7){
            //Rehash
            rehash();
        }
    }

    int remove(string key){
        int bukcetIndex = getBucketIndex(key);
        MapNode* head = buckets[bukcetIndex];
        MapNode* prev = NULL;

        while(head){
            if(head->key==key){
                if(prev!=NULL){
                prev->next = head->next;
                }
                else{
                    buckets[bukcetIndex] = head->next; //delete 1st node in bucket
                }
                int value = head->value;
                head->next = NULL;
                delete head;
                if(size>0)
                size--;
                return value;
            }
            prev = head;
            head=head->next;
        }
 
        return -1;
    }

    private:
    int getBucketIndex(string key){
        int hashCode = 0;
        int p = 37;
        int currentCoeff = 1;
        for(int i=key.length()-1;i>=0;i--){
            hashCode+=(key[i]*currentCoeff);
            //prevent from out of range
            hashCode%=numBuckets;
            currentCoeff*=p;
            //prevent from out of range
            currentCoeff = currentCoeff%numBuckets;
        }
        //compressor
        return hashCode%numBuckets;
    }

    void rehash(){
        MapNode **temp = buckets;
        buckets = new MapNode*[2*numBuckets];
        for(int i=0;i<2*numBuckets;i++){
            buckets[i] = NULL;
        }
        int oldBucketCount = numBuckets;
        numBuckets = 2*numBuckets;
        size=0;
        for(int i=0;i<oldBucketCount;i++){
            MapNode*head = temp[i];
            while(head){
                string key = head->key;
                int value = head->value;
                insert(key,value);
                head=head->next;
            }
        }
        for(int i=0;i<oldBucketCount;i++){
            MapNode*head = temp[i];
            delete head;
        }
        delete []temp;
    }

};


int32_t main()
{
   fast;
   init_code();
   int n;
   test
   {
    
   }
    return 0;
}