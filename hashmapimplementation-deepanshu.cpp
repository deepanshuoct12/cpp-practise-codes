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
class Mapnode
{
   public:
   	string key;
   	int value;
    Mapnode *next;
   	Mapnode(string key, int value)
   	{
      this->key=key;
      this->value=value;
      next=nullptr;
   	}
   	~Mapnode()
   	{
   		delete next;
   	}
};
class OurMap{
    Mapnode** buckets;
    int size;
    int bucketsize;
	OurMap()
	{
      size=0;
      bucketsize=5;
      buckets=new Mapnode*[bucketsize];
      for(int i=0;i<bucketsize;i++)
      {
      	buckets[i]=nullptr;
      }

	}
	~OurMap()
	{
		for(int i=0;i<bucketsize;i++)
		{
			delete buckets[i];
		}
		delete [] buckets;
	}
   
    void insert(string key,int value)
    {
    	int bucketindex = findbucketindex(key);
    	Mapnode* head = buckets[bucketindex];
    	while(head)//if already exist update
    	{
    		if(head->key==key)
    		{
    			head->value=value;
    			return;
    		}
    		head=head->next;
    	}

    	head=buckets[bucketindex];
    	Mapnode* node = new Mapnode(key,value);
    	node->next=head;
    	buckets[bucketindex]=node;  //if not already exist, then insert new value
    	size++;

    	double loadfactor = (1.0*size)/(bucketsize);
    	if(loadfactor>0.7)
    	{
    		rehash();
    	}
    }
    
     int getvalue(string key)
     {
        int bucketindex=findbucketindex(key);
        Mapnode* head=buckets[bucketindex];
        while(head)
        {
        	if(head->key==key)
        	{
        		return head->value;
        	}
        	head=head->next;
        }
        return -1;
     }
      
     int getsize()
     {
     	return size;
     } 

     double getloadfactor()
     {
     	return size*(1.0)/bucketsize;
     }

    int deletekey(string key)
    {
    	int bucketindex = findbucketindex(key);
    	Mapnode *head=buckets[bucketindex];

    	Mapnode* prev=nullptr;

    	while(head)
    	{
    		if(key==head->key)
    		{
    			if(prev!=nullptr)
    			{
    				prev->next=head->next;
    			}
    			else{
    				buckets[bucketindex]=head->next;
    			}

    			int val=head->value;
    			if(size>0)
    			size--;
    			head->next=nullptr;
    			delete head;
                return val;
    		}
    		prev=head;
    		head=head->next;
    	}
    	return -1;
    }

    private:
    	int findbucketindex(string key)
    	{
           int hashcode=0;
           int currcoff=1;
           int p=37;
           for(int i=key.length();i>=0;i--)
           {
           	hashcode+=(key[i]*currcoff);
           	hashcode%=bucketsize;
           	currcoff*=p;
           	currcoff%=bucketsize;
           }

           return hashcode%bucketsize;//compress
    	}
    	void rehash()
    	{
           Mapnode** temp=buckets;
           buckets = new Mapnode*[2*bucketsize];
           for(int i=0;i<2*bucketsize;i++)
           	buckets[i]=nullptr;

           int oldbucketsize=bucketsize;
           bucketsize=2*oldbucketsize;
           size=0;
           for (int i = 0; i <oldbucketsize; ++i)
           {
           	Mapnode* head=temp[i];
           	while(head)
           	{ 
              string key=head->key;
              int val=head->value;
              insert(key,val);
              head=head->next;
           	}
           }

          for(int i=0;i<oldbucketsize;i++)
          {
          	Mapnode* head=temp[i];
          	delete head;
          }
           delete [] temp;
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