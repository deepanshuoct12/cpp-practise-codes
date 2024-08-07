// C++ implementation to find nCr
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int ncr(int n, int k)
{
    int res = 1;

    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;

    // Calculate value of
    // [n * (n-1) --- (n-k+1)] / [k * (k-1) ---- 1]
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}
/*
// Function to find the nCr
void printNcR(int n, int r)
{

	// p holds the value of n*(n-1)*(n-2)...,
	// k holds the value of r*(r-1)...
	long long p = 1, k = 1;

	// C(n, r) == C(n, n-r),
	// choosing the smaller value
	if (n - r < r)
		r = n - r;

	if (r != 0) {
		while (r) {
			p *= n;
			k *= r;

			// gcd of p, k
			long long m = __gcd(p, k);

			// dividing by gcd, to simplify product
			// division by their gcd saves from the overflow
			p /= m;
			k /= m;

			n--;
			r--;
		}

		// k should be simplified to 1
		// as C(n, r) is a natural number
		// (denominator should be 1 ) .
	}

	else
		p = 1;

	// if our approach is correct p = ans and k =1
	cout << p << endl;
}

// Driver code
int main()
{
	int n = 50, r = 25;

	printNcR(n, r);

	return 0;
}
*/
