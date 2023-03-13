// arr = {5, 3, 2, 1}

#include<iostream>
#include <bits/stdc++.h>

using namespace std; 

void merge(vector<int> &arr, int start, int end){
    int mid = start + (end - start) / 2;
    
    int lenOne = mid - start + 1;
    int lenTwo = end - mid;

    int *first = new int[lenOne];
    int *second = new int[lenTwo];

    int mainIndex = start;

    for(int i = 0; i < lenOne; i++){
        first[i] = arr[mainIndex++];
    }

    mainIndex = mid + 1;

    for(int i = 0; i < lenTwo; i++){
        second[i] = arr[mainIndex++];
    }

    int indexOne = 0;
    int indexTwo = 0;
    mainIndex = start;

    while(indexOne < lenOne && indexTwo < lenTwo){
        if(first[indexOne] < second[indexTwo]){
            arr[mainIndex++] = first[indexOne++];
        } else {
            arr[mainIndex++] = second[indexTwo++];
        }
    }

    while(indexOne < lenOne) {
        arr[mainIndex++] = first[indexOne++];
    }

    while(indexTwo < lenTwo) {
        arr[mainIndex++] = second[indexTwo++];
    }
}

void mergeSort(vector<int> &arr, int start, int end) {
    if(start >= end) return;

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, end);
}


int main(){
    // int arr[] = {5, 3, 2, 1};
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);

    
    mergeSort(arr, 0, arr.size() - 1);
    
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " " << endl;
    }

    return 0;
}