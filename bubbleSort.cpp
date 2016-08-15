#include<iostream>
using namespace std;
#define MAX 10

void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int main()
{
	int i,k;
	int a[MAX];
	int flag=0;
	//int a[]={5,2,4,1,8,0,3};
		for(i=0;i<MAX;i++){
		cin>>a[i];
	}
	int n=sizeof(a)/sizeof(a[0]);
	
	
	for(i=0;i<n;i++){
		cout<<a[i];
		cout<<" ";
	}
	for(i=0;i<n;i++){
		for(k=0;k<n-i;k++){
			if(a[k]>a[k+1]){
				swap(a[k],a[k+1]);
				flag=1;
			}
			if(flag==0)
				break;
		}
	}
	cout<<"\n Sorted array is :";
	
		for(i=0;i<n;i++){
		cout<<a[i];
		cout<<" ";
	}
}

