 vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,[&](Job &a,Job &b){
            return a.profit>b.profit;
        });
        int ans=0,cnt=0;
        vector<int>res(2);
        int mx=0;
        for(int i=0;i<n;i++)
        mx=max(mx,arr[i].dead);
        vector<int>visited(mx+1,-1);
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead;j>0;j--)
            {
                if(visited[j]==-1)
                {
                    visited[j]=arr[i].id;
                    cnt++;
                    ans+=arr[i].profit;
                    break;
                }
            }
        }
        res[0]=cnt;
        res[1]=ans;
        return res;
        // your code here
    } 