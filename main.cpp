//Miguel Jiménez Padilla  A01423189
//Marco Antonio Gardida Cortés  A01423221

#include <iostream>
using namespace std;

void merge(double arr[], int p, int q, int r) { 
 
    // Create L ← A[p..q] and M ← A[q+1..r] 
    int n1 = q - p + 1; 
    int n2 = r - q; 
    double L[n1], M[n2]; 
    for (int i = 0; i < n1; i++) 
        L[i] = arr[p + i]; 
    for (int j = 0; j < n2; j++) 
        M[j] = arr[q + 1 + j]; 

    // Maintain current index of sub-arrays and main array 
    int i, j, k; 
    i = 0; 
    j = 0; 
    k = p; 
 
    // Until we reach either end of either L or M, pick larger among 
    // elements L and M and place them in the correct position at A[p..r] 
    while (i < n1 && j < n2) { 
        if (L[i] >= M[j]) { 
            arr[k] = L[i]; 
            i++; 
        } else { 
            arr[k] = M[j]; 
            j++; 
        } 
        k++; 
    } 
 
    // When we run out of elements in either L or M, 
    // pick up the remaining elements and put in A[p..r] 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
 
    while (j < n2) { 
        arr[k] = M[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(double arr[], int left, int right){
    if(left>=right){
        return;
    }
    else{
//      int middle = (left+(right-left))/2;
        int middle = (left+(right))/2;
        //cout<<"middle: "<<middle<<endl;
        mergeSort(arr,left,middle);
        mergeSort(arr,middle+1,right);
        merge(arr,left,middle,right);

        //return arr;
    }

}

void printVector(double vec[], int arrlen){
        for (int y=0; y<arrlen;y++){
        if(y==0){cout<<"[ ";}

        cout<<vec[y]<<" ";

        if(y==arrlen-1){cout<<"]";}
    }
}

int main(){
    int arrlen=0;
    
    cout<<"Enter the lenght of your array: "; cin>>arrlen; cout<<endl;
    double vec[arrlen];

    for(int x=0; x<arrlen;x++){
        double num=0;
        cout<<"Enter the "<<x+1<<" number: "; cin>>num;
        vec[x] = num;
    }

    cout<<"unsorted array: "<<endl;
    printVector(vec,arrlen); cout<<endl<<endl;

    mergeSort(vec,0,arrlen-1);
    
    cout<<"sorted array using merge sort alghoritm: "<<endl;
    printVector(vec,arrlen);
}