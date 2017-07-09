/*
 Copyright (c) 2017 waynezxcv <liuweiself@126.com>
 
 https://github.com/waynezxcv/Playground
 
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */


#include "_sort.h"


void _swap(int* a,int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//冒泡排序
void BubbleSort(int arr[],int length) {
    
    for (int i = 0; i < length ; i ++) {
        for (int j = length - 1; j > i; j --) {
            if (arr[j] < arr[j - 1]) {
                _swap(&arr[j], &arr[j - 1]);
            }
        }
    }
    
}


//归并排序
void Merge(int sourceArr[],int tempArr[],int startIndex,int midIndex ,int endIndex) {
    
    int i = startIndex;
    int j = midIndex + 1;
    int m = midIndex;
    int n = endIndex;
    int k = 0;
    
    while (i <= m && j <= n) {
        if (sourceArr[i] <= sourceArr[j]) {
            tempArr[k++] = sourceArr[i ++];
        } else {
            tempArr[k ++] = sourceArr[j ++];
        }
    }
    
    while (i <= m) {
        tempArr[k ++] = sourceArr[i ++];
    }
    
    while (j <= n) {
        tempArr[k ++] = sourceArr[j ++];
    }
    
    for (i = 0; i < k; k ++) {
        sourceArr[i] = tempArr[i];
    }
    
}

void MergeSort(int arr[],int temp[],int startIndex,int endIndex) {
    int midIndex;
    if (startIndex < endIndex) {
        midIndex = (startIndex + endIndex) / 2;
        MergeSort(arr, temp, startIndex, midIndex);
        MergeSort(arr, temp, midIndex + 1, endIndex);
        Merge(arr, temp, startIndex, midIndex, endIndex);
    }
}



//堆排序
void heapAdjust(int arr [],int begin,int end) {
    int child;
    int temp = arr[begin];
    
    for (child = 2 * begin; child <= end; child *= 2) {
        if (child < end && arr[child] < arr[child + 1]) {
            child ++;
        }
        
        if (temp >= arr[child]) {
            break;
        }
        
        arr[begin] = arr[child];
        begin = child;
    }
    arr[begin] = temp;
}


void HeapSort(int arr[],int length) {
    int root;
    for (root = length/2; root > 0; root --) {
        heapAdjust(arr, root, length);
    }
    
    for (root = length; root > 1; root -- ) {
        _swap(&arr[1], &arr[root]);
        heapAdjust(arr, 1, root - 1);
    }
}

//快速排序
int partition(int arr[],int low,int high) {
    
    int pivotKey = arr[low];
    while (low < high) {
        
        while (low < high && arr[high] >= pivotKey) {
            high --;
        }
        
        _swap(&arr[low], &arr[high]);
        
        while (low < high && arr[low] <= pivotKey) {
            low ++;
        }
        _swap(&arr[low], &arr[high]);
    }
    return low;
}


void Qsort(int arr[],int low,int high) {
    int pivot;
    
    if (low < high) {
        pivot = partition(arr, low, high);
        Qsort(arr,low,pivot - 1);
        Qsort(arr, pivot + 1, high);
    }
}

void QuickSort(int arr[],int length) {
    Qsort(arr, 0, length - 1);
}


