 int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr,arr+n);
        sort(dep,dep+n);
        
        
        int i=0;
        int j=0;
        int platform=0;
        int ans=1;
        while(i<n && j<n)
        {
            if(arr[i]<=dep[j])
            {
                platform++;
                i++;
            }
            else if(arr[i]>dep[j])
            {
                platform--;
                j++;
            }
            ans=max(ans,platform);
        }
        return ans;
    	// Your code here
    }