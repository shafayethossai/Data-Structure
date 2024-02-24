/*
CSE 252
Data Structures and Algorithms I Lab

The purpose of this lab is to understand and perform basic array
operations like traverse, insert, delete
*/

#include <bits/stdc++.h>
using namespace std;

void traverseArray(int a[], int n){
    // Traverses and displays the elements of an array.

    /* Subtask 01
    Write a for loop to display the array elements*/

    for (int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void insertArray(int a[], int n, int value, int pos){
    // Inserts value at index pos of array a.

    /* Subtask 02
    Using for loop, shift the values of a[] to the right till position pos.
    Start from the last element of the array*/

    for (int i=n; i>pos; i--) {
        a[i] = a[i-1];
    }

    /* Subtask 03
    Update the array at index pos*/

    a[pos] = value;
}

void deleteArray(int a[], int n, int pos){
    // Deletes the element at index pos

    /* Subtask 04
    Using for loop, shift the values of a[] to the left,
    starting from index pos. */

    for (int i=pos; i<n; i++) {
        a[i] = a[i+1];
    }

}

void reverseTraverse (int a[], int n) {
    for (int i=n-1; i>=0; i--) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void deleteArrayRange (int a[], int n, int start, int ends) {
    int diff = ends-start;
    for (int i=start; i< n-diff; i++) {
        a[i] = a[ends+1];
        ends++;
    }
}

void reverFullArray(int a[], int n) {
    int last = n;

    for (int i=0; i<n/2; i++) {
        swap(a[i], a[last-1]);
        last--;
    }
}

int main() {
    int arr[100], n;

    /* Copy and paste this input:
    10
    0 1 2 3 4 5 6 7 8 9
    */
    cout << "Array length: ";
    cin >> n;
    cout << "Array: ";

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "Original Array: ";
    traverseArray(arr, n);

    cout << "Array after insertion: ";
    insertArray(arr, n, 11, 5);
    n++;
    traverseArray(arr, n);

    cout << "Array after deletion: ";
    deleteArray(arr, n, 2);
    n--;
    traverseArray(arr, n);

    cout << "after reverseTraverse : ";
    reverseTraverse(arr, n);

    cout << "after deleteArrayRange : ";
    deleteArrayRange(arr, n, 2, 5);
    n-= (5-2)+1;
    traverseArray(arr, n);

    reverFullArray(arr, n);
    cout << "after reverFullArray : ";

    traverseArray(arr, n);

}
