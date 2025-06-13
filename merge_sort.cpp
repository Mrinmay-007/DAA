#include<iostream>
using namespace std;

void show(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void merge (int arr[],int l,int r,int m){
    int n1 = m-l+1;
    int n2 =r-m;

    int L[n1] ,R[n2]; //create temp array

    //copy data to temp arrays
    for (int i=0;i<n1;i++) L[i] =arr[l+i];
    for (int i=0;i<n2;i++) R[i] =arr[m + 1 +i ];

    //merge temp arr into main arr

    int i=0 ,j=0 ,k =l;

    while(i<n1 && j<n2){
        if (L[i]<= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] =R[j++]; 
    }
    //remainig elements
    while(i <n1)
        arr[k++] = L[i++];

    while(j <n2)
        arr[k++] = R[j++];

}

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);

         cout << "Merged (" << l << " to " << r << "): ";
        show(arr + l, r - l + 1);
    }
}

int main() {
    int arr[] = {4, 5, 3, 1, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    show(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted array: ";
    show(arr, n);

    return 0;
}