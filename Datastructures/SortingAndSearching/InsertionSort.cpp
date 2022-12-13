#include <bits/stdc++.h>
 using namespace std;
 void swap(int *a,int *b){
     int temp = *a;
     *a = *b;
     *b = temp;
 }
 void insertionSort(int arr[],int size){
     for(int i=0;i<=size;i++){		// Here i acts as sorted till flag
         for(int j=(i+1);j>0;j--){
             if(arr[j]<arr[j-1]) {swap(arr[j],arr[j-1]);}
         }
     }
 }
 int main()
 {
 	int k[] = { 7,12,3,4,1 };
 	insertionSort(k,5);
 	for(int i=0;i<5;i++)
 	    cout << k[i] << " ";
  
 	return 0;
 }
