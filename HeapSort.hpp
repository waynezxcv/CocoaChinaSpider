//
//  HeapSort.hpp
//  DataStructures
//
//  Created by 刘微 on 2017/3/7.
//  Copyright © 2017年 刘微. All rights reserved.
//

#ifndef HeapSort_hpp
#define HeapSort_hpp

#include "MaxHeap.hpp"



namespace LWTL {
    
    //给数组a[1:n]排序
    template <typename T>
    void heapSort(T* a,int n) {
        
        MaxHeap<T> heap (1);
        heap.initialize(a,n);
        
        for (int i = n - 1; i > 0; i --) {
            T x = heap.top();//查询优先级最高的元素
            heap.pop();//移出队列
            a[i + 1] = x;
        }
        heap.deactivateArray();//将heap指向NULL，防止heap的析构函数将数组a删除
    }
}

#endif /* HeapSort_hpp */
