//Program to implement insertion sort

#include<bits/stdc++.h>
using namespace std;
void InsertionSort(int arr[], int n){
 int key;
 for(int i=1;i<=n;i++){
 key=arr[i];
 int j=i-1;
 while(j>=0 && arr[j]>key){
 arr[j+1]=arr[j];
 j--;
 }
 arr[j+1]=key;
 }
}
int main(){
 int arr[10];
 int n;
 cout <<"Enter the size of array";
 cin >> n;
 cout <<"Enter the array";
 for(int i=0;i<n;i++){
 cin >> arr[i];
 }
 InsertionSort(arr,n);
 cout << "Sorted array is \n";
 for(int i=0;i<n;i++){
 cout << arr[i] << " ";
 }
 return 0;
}

//End of program
