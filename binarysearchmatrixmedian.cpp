int helper(vector<int>&v,int num)
{
    int l=0;
    int h=v.size()-1;
    
    while(l<=h)
    {
        int mid=(l+h)>>1;
        
        if(v[mid]<=num)
        l=mid+1;
        else 
        h=mid-1;
    }
    return l;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int l=1;
    int high=1e9;
    int n=A.size();
    int m=A[0].size();
    int desired=(n*m)/2;
    while(l<=high)
    {
        int mid=(l+high)>>1;
        int cnt=0;
        for(int i=0;i<n;i++)
        cnt+=helper(A[i],mid);
        
        if(cnt<=desired)
        l=mid+1;
        else 
        high=mid-1;
    }
    
    return l;
    // int r=A.size();
    // int c=A[0].size();
    // int mn=INT_MAX,mx=INT_MIN;
    // for(int i=0;i<r;i++)
    // {
    //     mn=min(mn,A[i][0]);
    //     mx=max(mx,A[i][c-1]);
    // }
    // int des=(r*c+1)/2;
    
    //  while(mn<mx)
    //  {
    //      int mid=(mn+mx)/2;
    //       int cnt=0;
    //      for(int i=0;i<r;i++)
    //      cnt+=upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin();
         
    //      if(cnt<des)
    //      mn=mid+1;
    //      else 
    //      mx=mid;
    //  }
     
    //  return mn;
    
    
    
    
    
    
    
    
    //O(R*(CLOGC + C + LOGC);
    // int n=A.size();
    // int m=A[0].size();
    // for(int i=0;i<n-1;i++)
    // {
    //         sort(A[0].begin(),A[0].end());
    //         int x = A[i+1][0];
    //         int st = 0,en=m-1;
    //         while(st<=en)
    //         {
    //             int mid = (st+en)/2;
                
    //             if(A[i][mid]>x)
    //              en=mid-1;
                 
    //              else if(A[i][mid]<x)
    //              st=mid+1;
    //         }
            
    //         int t=A[i][m-1];
    //         int j=m-1;
            
    //         while(j>st)
    //         {
    //             A[i][j]=A[i][j-1];
    //             j--;
    //         }
    //         A[i][st]=x;
    //         A[i+1][0]=t;
  
    // }
    
    //  sort(A[n-1].begin(),A[n-1].end());
    // int med=(n*m)/2;
    // int count=0;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(count==med)
    //         {
    //             return A[i][j];
    //         }
    //         count++;
    //     }
       
    // }
    
    
    
    //Brute 
    // vector<int>v;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         v.push_back(A[i][j]);
    //     }
    // }
    
    // sort(v.begin(),v.end());
    // int s=v.size();
    // return v[s/2];
}
