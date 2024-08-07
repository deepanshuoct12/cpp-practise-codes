 #include<iostream>
 using namespace std;


 void multiply(int*arr, int&n, int no)
 {   int carry=0;
     int product=1;

     for(int i=0;i<n;i++)
     {
         product=arr[i]*no+carry;
         arr[i]=product%10;
         carry=product/10;
     }

     while(carry)
     {
         arr[n]=carry%10;
         carry=carry/10;
         n++;
     }
 }
 void bigfactorial(int number)
 {

     int *arr = new int[1000]{0};
     arr[0]=1;
     int n=1;// number of digits in the number
     for(int i=2;i<=number;i++)
     {
         multiply(arr,n,i);
     }


     cout<<"\n";
     cout<<"factorial is"<<"\n";
     for(int i=n-1;i>=0;i--)
     {
         cout<<arr[i];
     }
     cout<<"\n"<<n<<" "<<"digits";

 }

 int main()
 {
     int number;
     cin>>number;

     bigfactorial(number);
     return 0;
 }
