#include<iostream>
using namespace std;

void print(int a[],int n)
{
	for(int i=0;i<n;i++){
		cout<<a[i];
		cout<<" ";
	}
}

swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int a[],int start,int end){
	int i;
	int pindex=start;
	
	for(i=start;i<end;i++){
		if(a[i]<a[end]){  //pivot=end
			swap(a[i],a[pindex]);
			pindex++;
		}
	}
	swap(a[pindex],a[end]);
	return pindex;
}


quick_sort(int a[],int start,int end){
	if(start<end){
		int pindex = partition(a,start,end);
		quick_sort(a,start,pindex-1);
		quick_sort(a,pindex+1,end);
	}
}

int main(){
	int i,n;
	int a[]={5,2,4,1,8,0,3};
	n=sizeof(a)/sizeof(a[0]);
	
	print(a,n);
	
	quick_sort(a,0,n-1);
	
	cout<<"Quick Sorted array is \n :";
	print(a,n);
}
