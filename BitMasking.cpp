#include<bits/stdc++.h>
using namespace std;


//This fn find a number in array which is present only one time while rest are present twice
void UniqueNoI(){
	int n,x,ans;
	cin>>n;
	cin>>x;
	ans=x;
	for(int i=1;i<n;i++){
		cin>>x;
		ans = ans^x;
	}
	cout<<ans;
}

// This fn find two numbers in array which is present only one time while rest are present twice
void UniqueNoII(){
	int a[]={1,3,5,6,3,2,1,2};
	int n = sizeof(a)/sizeof(int);
	int res=0;
	for(int i=0;i<n;i++){
		res=res^a[i];
	}
	int i=0;
	int temp=res;
	while(temp>0){
		if(temp&1){
			break;
		}
		i++;
		temp = temp>>1;
	}
	int mask = (1<<i);
	int firstNo=0;
	for(int i=0;i<n;i++){
		if((mask&a[i])!=0){
			firstNo = firstNo^a[i];
		}
	}
	int secondNo = res^firstNo;
	cout<<firstNo<<endl;
	cout<<secondNo<<endl;
}
// This fn find one number in array which is present only one time while rest are present thrice
int UniqueNoIII(int *a,int n){
     int cnt[64] = {0};

     for(int j=0;j<n;j++){
        ///Extract Bits of Every Number and update the count array

        int i=0;
        int no = a[j];
        while(no>0){
            cnt[i] += (no&1);
            i++;
            no = no>>1;
        }

     }
     /// Take mod of cnt array with 3
     int p = 1;
     int ans = 0;
     for(int i=0;i<64;i++){
        cnt[i] %= 3;

        ans += cnt[i]*p;
        p = p<<1;
     }
    return ans;
    
}



// Counting number of set bits in a number
int countSetBits(int n){
	int count =0;
	while(n>0){
		count += (n&1);
		n = n>>1;
	}
	return count;
}
// Also known as n&(n-1) hack
int countSetBitsFast(int n){
	int count =0;
	while(n){
		count++;
		n = n&(n-1);
	}
	return count;
}

// XOR Swap
void XorSwap(int &a,int &b){
	a=a^b;
	b=a^b;
	a=a^b;
}

// Extract ith bit of a number from right starting rightmost bit as 0th bit
int getIthBit(int n,int i){
	return (n&(1<<i))!=0?1:0;
}

// Set ith bit i.e. change ith bit to 1
void SetIthBit(int &n,int i){
	int mask = 1<<i;
	n = (n|mask);
}

// Clear ith bit i.e. change ith bit to 0
void clearBit(int &n,int i){
	int mask = ~(1<<i);
	n = n&mask;
}

// Finding subsequences of a string using bitmasking
void filterChars(char *a,int no){
	// a = "abc" no = 5 = 101 --> output should be ac
	int i= 0;
	while(no>0){
		(no&1)?cout<<a[i]:cout<<"";
		i++;
		no = no>>1;
	}
	cout<<endl;
}
void generateSubsequences(char *a){
	// Generate a range of numbers from 0 to 2^n -1
	int n = strlen(a);
	int range = (1<<n)-1;
	for(int i=0;i<=range;i++){
		filterChars(a,i);
	}
}





int main(){
	int n,i;
	char a[100];
//	cin>>a;
//	cin>>n>>i;	
//	cout<<countSetBitsFast(1)<<endl;
//	cout<<getIthBit(13,2)<<endl;
//	SetIthBit(n,i);
//	cout<<n<<endl;
//	clearBit(n,i);
//	cout<<n<<endl;
//	generateSubsequences(a);
//	UniqueNoII();

	return 0;
}
