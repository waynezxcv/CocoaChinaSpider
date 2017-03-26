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


#include "HeapSort.h"


void swap(int* a,int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void heapAdjust(int* a,int begin,int end) {
    int temp ,j;

    temp = a[begin];


    //沿着关键字较大的孩子向下筛选,选出最大的放在起始位置

    for (j = 2 * begin; j <= end; j *= 2) {

        //选出孩子中较大的那个
        if (j < end && a[j] < a[j + 1]) {
            ++j;
        }

        //根节点大于孩子节点,则无需调整
        if (temp >= a[j]) {
            break;
        }

        //交换目前最大的放在起始位置
        a[begin] = a[j];
        begin = j;
    }


    a[begin] = temp;
}


void heapSort(int* a,int length) {

    int root;

    //初始化为大根堆,从最后一个有孩子的元素开始,从后往前遍历
    for (root = length/2; root > 0; root --) {
        heapAdjust(a,root,length);
    }

    //循环将堆顶元素(最大值)跟数组最后的元素交换,然后调整还未交换的元素为大根堆
    for (root = length; root > 1; root --) {
        swap(&a[1], &a[root]);
        heapAdjust(a, 1, root - 1);
    }
}
