#include<iostream>
#include<vector>
using namespace std;

class heap
{
    vector<int>v;
    bool minheap;

    bool compare(int a,int b)
    {
         if(minheap==true)
            return a<b;
         else
            return a>b;

    }

    void heapify(int i)
    {
        int min=i;
        int left=2*i+1;
        int right =2*i+2;

        if(left<v.size() && compare(v[left],v[i]))
            min=left;
        if(right<v.size() && compare(v[right],v[min]))
            min=right;
        if(min!=i)
        swap(v[i],v[min]);
        heapify(v[min]);
    }
public:
    heap(bool type=true)
    {

        minheap=type;
    }

    void insert(int data)
    {
        v.push_back(data);
        int child=v.size()-1;
         int parent =(child-1)/2;
        while(child>0 && compare(v[child],v[parent]))
        {
            swap(v[child],v[parent]);
            child=parent;
            parent=(child-1)/2;
        }

    }

    void pop()
    {  int last=v.size()-1;
        swap(v[0],v[last]);
        v.pop_back();
        heapify(0);
    }
    bool isempty()
    {

        return v.size()==0;
    }
    int top()
    {

        return v[0];
    }

};
int main()
{
    heap h;

    for(int i=0;i<10;i++)
        h.insert(i);


    for(int i=0;i<5;i++)
    {

        cout<<h.top();
        h.pop();
    }
    cout<<h.isempty();
    return 0;
}
