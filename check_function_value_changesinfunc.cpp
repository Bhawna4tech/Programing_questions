/* Conclusion:
when we pass an array to a function it is passed as refrence, that means values changed in the function on array will reflect in the original array;
but not in the case of the variables....
*/


#include<iostream>
using namespace std;

void call(int a[],int n,int k,int j){
	int i;
		for(i=0;i<n;i++){
		a[i]=a[i]+100;
	}
	i=200;
	j=300;
}

int main(){
	int i,k=1,j=2;
	int a[]={1,2,3,4,5};
	int n=sizeof(a)/sizeof(a[0]);
	
	for(i=0;i<n;i++){
		cout<<a[i];
		cout<<" ";
	}
	call(a,n,k,j);
	cout<<"after calling function : \n : ";
		for(i=0;i<n;i++){
		cout<<a[i];
		cout<<" ";
	}
	cout<<"k : "<<k;
	cout<<"j : "<<j;
}
