#include<iostream>
using namespace std;

int binarySearch(const int *Array, int start, int end, int key) {
    int left, right;
    int mid;
    left = start;
    right = end;
    mid = (left + right)/2;
    //Recursive Efficiency is not good
    //time of compare log2n + 1
    /*
    if (key == Array[mid]) return mid;
    else if (key < Array[mid]) {
        return (binSearch(Array,left,mid-1,key))
    }
    else if (key > Array[mid]) {
        return binarySearch(Array,mid+1,right,key)
    }
    */
    while (left <= right) {
        mid = (left + right) /2;
        if (key == Array[mid]) return mid;
        if (key < Array[mid]){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}
