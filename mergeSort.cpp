#include<iostream>
using namespace std;

void print(int a[],int n)
{
	for(int i=0;i<n;i++){
		cout<<a[i];
		cout<<" ";
	}
}

merge(int l[],int r[],int a[],int nl,int nr){
	int i,j,k;
	i=j=k=0;
	//nl=sizeof(l)/sizeof(l[0]);
	//nr=sizeof(r)/sizeof(r[0]);	
	while(i<nl && j<nr ){
		if(l[i]<r[j]){
			a[k]=l[i];
			k++; i++;
		}
		else {
			a[k]=r[j];
			k++;j++;
		}
	}
	
	while(i<nl){
			a[k]=l[i];
			k++; i++;
    	}
	while(j<nr){
			a[k]=r[j];
			k++;j++;
		}	
}

void mergesort(int a[],int n){
	if(n<2)
		return;

	int mid,i;
	mid=n/2;
	
	int l[mid];
	int r[n-mid];
	
	for(i=0;i<mid;i++){
		l[i]=a[i];		
	}
	for(i=mid;i<n;i++){
		r[i-mid]=a[i];		
	}
	
	mergesort(l,mid);
	mergesort(r,n-mid);
	merge(l,r,a,mid,n-mid);	
}

int main(){
	int i,n;
	int a[]={5,2,4,1,8,0,3};
	n=sizeof(a)/sizeof(a[0]);
	
	print(a,n);
	
	//mergesorting
	mergesort(a,n);
	cout<<"\n Sorted array is : ";
	print(a,n);
}
