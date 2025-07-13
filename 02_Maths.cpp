                                                    // 01 Count Digit
// Brute force
/* 
#include<iostream>
using namespace std;
int main(){
    int n ;
    cin>>n;
    int count = 0;
    while(n>0){
        n = n/10;
        count++;
    }
    cout<<count;
} */



//OPTIMAL Soln
/*
#include<iostream>
using namespace std;
int main(){
    int n ;
    cin>>n;
    int count = log10(n)+1;
    cout<<count;
}
 */




        
                                            // 02 Reverse Number and remove trailing Zeroes 
// Brute force using LinkedList
/* 
#include<iostream>
#include<list>
using namespace std;
int main(){

    int n;
    cin>>n;
    list<int> v;

    while(n>0){
        v.push_back(n%10);
        n = n/10;
    }

    while(v.front()==0){
        v.pop_front();
    }
    for(int val:v){
        cout<<val;
    }

} */



// Optimal Soln
/*                           
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int revNum = 0;

	while(n > 0){
		int ld = n % 10;
		revNum = (revNum * 10) + ld;
		n = n / 10;
	}	
	cout << revNum;
}                        
 */                        



//LeetC Q7
/* 
class Solution {
public:
    int reverse(int x) {
        int rev=0;
        while(x!=0){
            int digit = x%10;
            x = x/10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) {
                return 0;
            }
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) {
                return 0;
            }
            rev = (rev*10) + digit;
      
        }
        return rev;
        
    }
}; */





                                                // 03 Palindrome 

//Method 1 -- Comparing digits of number from begining and end by converting number into Vector of integer
/*
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;

    vector<int> v;
    while(n>0){
        int r = n%10;
        v.push_back(r);
        n=n/10;
    }

    bool isPalindrome = true;
    for(int i=0; i<v.size()/2; i++){
        if(v[i]!=v[v.size()-1-i]){
            isPalindrome = false;
        }
    }

    if(isPalindrome){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}
*/



//(Optimal Approach)
//Method 2 -- By reversing the number and comparing the reversed number to original one
/* 
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int original = n;
    int reverse = 0;
    while(n>0){
        int digit = n%10;
        reverse = reverse*10 + digit;
        n = n/10;
    }
    if(original == reverse){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
} 
*/



//LeetC -- Q9
/* 
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;    //x < 0: Negative numbers can't be palindromes   AND   (x % 10 == 0 && x != 0): Numbers ending in 0 can't be palindromes unless the number is 0 (e.g., 10 is not a palindrome)

        int rev = 0;
        while (x > rev)       // only reverse half of the number. This loop continues as long as rev is less than x,  first half should equal the reversed second half
        {                 
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        return x == rev || x == rev / 10;
    }
};
*/





                                            //04 GCD 
//Brute Force 
/* 
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int N1, N2;
    cin>>N1>>N2;
    int gcd = 1;

    for(int i=1; i<=min(N1,N2); i++){
        if(N2%i==0 && N1%i==0){
            gcd = i;
        }
    }
    cout<<gcd;
    
} 
*/


//Enhancing the Time complexity of above code :-   Find the HCF Backward to get the greatest common divisor first 
/* 
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int N1, N2;
    cin>>N1>>N2;
    int i;
    for(i=min(N1,N2); i>0; i--){
        if(N1%i==0 && N2%i==0){
            cout<<i;
            break;
        }
    }
} 
*/



//Optimised method :- Euclidean algo / Euqilateral algo  (HCF by division method)
/* 
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int N1, N2;
    cin>>N1>>N2;

    int d = min(N1,N2);
    int D = max(N1,N2);
    while(d!=0){
        int r = D % d;
        D = d;
        d = r;
    }
    cout<<D;
} 
*/





                                                //05. LCM
// Brute force
/*
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n1,n2;
    cin>>n1>>n2;
    
    for(int i=max(n1,n2); i<=n1*n2; i++){
        if(i % n1 ==0 && i % n2 == 0){
            cout<<i;
            break;
        }
    }
    return 0;
} */

// Optimal :- Find HCF by optimal Approach and then use this formula   {LCM = (Product of 2 numbers) / HCF}





                                            //06 Armstrong Number
/* 
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int n = N;
    int a = 0;
    int digits = log10(N)+1;     //can find no of digits by converting to string also...   "int digit = to_string(n).length();"
    while(n!=0){
        int r = n%10;
        a = pow(r,digits) + a;
        n = n/10;
    }
    if(N==a){
        cout<<"Yes";
    }
    else{cout<<"No";}
    return 0;
} 
*/




                                    //07. Factors
//Brute Force
/* 
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cout<<"[";
    for(int i=0; i<=n; i++){
        if(n%i==0){
            cout<<i<<",";
        }
    }

    cout<<"]";
    return 0;
} 
*/


// Optimal Approach :- instead of iterating upto "n" go upto "sqrt(n)"
/* 
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=1; i<=sqrt(n); i++){
        if(n%i == 0){
            v.push_back(i);
            if(i!=(n/i)){
                v.push_back(n/i);
            }
        }
    }
    for(int val : v){
        cout<<val<<", ";
    }
    return 0;
}
*/



                                //08. Check Prime
//Brute Force
/* 
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int flag=0;
    for(int i=2; i<n; i++){
        if(n%i==0){
            flag++;
        }
    }
    if(flag==0){
        cout<<"Prime";
    }
    else{
        cout<<"Not Prime";
    }
    return 0;
} 
*/



//Optimised Approach
/* 
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int flag = 0;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            flag++;
        }
    }
    if(flag==0){
        cout<<"Prime";
    }
    else{
        cout<<"Not Prime";
    }
    return 0;
} 
*/


                                                //09. Prime between 2 numbers
/* 
#include<iostream>
using namespace std;
int main() {
    int n1, n2;
    cin >> n1 >> n2;

    for (int j = n1; j <= n2; j++) {
        if (j < 2) {
            cout << j << ",";           // 0 and 1 are not prime
            continue;
        }

        bool isPrime = true;
        for (int i = 2; i * i <= j; i++) {
            if (j % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            cout << j << ",";
        }
    }

    return 0;
}
 */



                                                            //10. Prime Factors
/* 
#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        if (n % i == 0 && isPrime(i)) {
            cout << i << " ";
        }
    }
    return 0;
}
 */