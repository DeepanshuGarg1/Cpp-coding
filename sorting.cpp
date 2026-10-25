#include <iostream>
using namespace std;

void SelectionSort(int arr[],int n){
    int min,temp,i,j;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min])
            min=j;
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}

void BubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        bool flag=true;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                flag=false;
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        if(flag==true)
        break;
    }
}

int partition(int arr[],int p,int q){
    int x=arr[p];
    int i=p;
    for(int j=p+1;j<=q;j++){
        if(arr[j]<x){
            i=i+1;
            int swap=arr[i];
            arr[i]=arr[j];
            arr[j]=swap;
        }
    }
    int temp=arr[i];
    arr[i]=arr[p];
    arr[p]=temp;
    return i;
}

void QuickSort(int arr[],int p,int q){
    if(p<q){
        int m=partition(arr,p,q);
        QuickSort(arr,p,m-1);
        QuickSort(arr,m+1,q);
    }
}

void insertionSort(int arr[],int n){
    int i,j;
    for(i=1;i<n;i++){
        int temp=arr[i];
        for(j=i;j>0&&arr[j-1]>temp;j--){
            arr[j]=arr[j-1];
        }
        arr[j]=temp;
    }
}

int main(){
    int n;
    cout<<"Enter no. of elements in the array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter data: ";
        cin>>arr[i];
    }
    insertionSort(arr,n);
    cout<<"Sorted Array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
}