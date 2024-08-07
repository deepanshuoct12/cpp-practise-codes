	double calc(double no,double p)
	{
	    double ans=1;
	    for(int i=1;i<=p;i++)
	    ans*=no;
	    return ans;
	}
	int NthRoot(int n, int m)
	{
	    
	    double l=1;
	    double hi=m;
	    double esp=1e-6;
	    while(hi-l>esp)
	    {
	     double mid=(l+hi)/2.0;
	     if(calc(mid,n)>m)
	     hi=mid;
	     else 
	     l=mid;
	    }
	//    cout<<l<<" "<<hi;
	    return l;
	    // Code here.
	}  