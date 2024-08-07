int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m)
        {
            return kthElement(arr2,arr1,m,n,k);
        }
        
        int low=max(0,k-m);
        int hi=min(n,k);
        
        while(low<=hi)
        {
            int cut1=(low+hi)>>1;
            int cut2=k-cut1;
            
            int l1=cut1==0?INT_MIN:arr1[cut1-1];
            int l2=cut2==0?INT_MIN:arr2[cut2-1];
            int r1=cut1==n?INT_MAX:arr1[cut1];
            int r2=cut2==m?INT_MAX:arr2[cut2];
            
            
           if(l1<=r2 && l2<=r1)
            {
                return max(l1,l2);
            }
            if(l1>r2)
            hi=cut1-1;
            else
            low=cut1+1;
        }
        
        return -1;
    }

//brute 
    /*
     int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i=0;
        int j=0;
        int cnt=0;
        while(i<n && j<m)
        {
            if(arr1[i]<=arr2[j])
            {
                 cnt++;
                 if(cnt==k)
                 return arr1[i];
                  i++;
                 
            }
            else if(arr1[i]>arr2[j])
            {
                cnt++;
                 if(cnt==k)
                 return arr2[j];
                  j++;
            }
           
        }
        
        while(i<n)
        {
            cnt++;
            if(cnt==k)
            return arr1[i];
            i++;
        }
        while(j<m)
        {
            cnt++;
            if(cnt==k)
            return arr2[j];
            j++;
        }
        return -1;
    }
    */