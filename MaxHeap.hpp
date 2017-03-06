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


#ifndef MaxHeap_hpp
#define MaxHeap_hpp

#include "MaxPriorityQueue.hpp"
#include "IllegalParameterValue.hpp"




/******************** 用堆实现最大优先级队列，大根堆 *******************/


//堆是一个完全二叉树，完全二叉树用数组表示效率最高。大根堆，根节点大于等于他的子节点，如果有的话


namespace LWTL {
    
    template<typename T>
    class MaxHeap : public MaxPriorityQueue<T> {
        
    public:
        
        MaxHeap(int capacity = 10) {
            arrayLength = 10;
            heapSize = 0;
            heap = new T [arrayLength];
        }
        
        ~MaxHeap() {
            delete [] heap;
        }
        
        
        void deactivateArray() {
            heap = NULL;
            arrayLength = heapSize = 0;
        }
        
        bool empty() const override {
            return heapSize == 0;
        }
        
        int size() const override {
            return heapSize;
        }
        
        T& top() const override {
            if (heapSize == 0 ) {
                throw IllegalParameterValue("the heap is empty");
            }
            return heap[1];
        }
        
        
        void push (const T& theElement) override {
            //如果需要的话，扩展数组的空间
            if (heapSize + 1 == arrayLength) {
                T* tmp = new T [arrayLength * 2];
                memset(tmp, 0, sizeof(T) * arrayLength * 2);
                memcpy(tmp, heap, sizeof(T) * heapSize);
                delete [] heap;
                heap = tmp;
            }
            
            int currentNode = ++heapSize;//现在堆的尾部插入一个新结点。heapSize 自增1
            
            //完全二叉树的性质：根节点i = 1.一个标号为i的节点，他的父节点是i/2
            //如果当前结点小于他的根节点,则交换他们
            while (currentNode != 1 && heap[currentNode/2] < heap[currentNode] ) {
                heap[currentNode] = heap[currentNode/2];
                currentNode = currentNode/2;
            }
            heap[currentNode] = theElement;
        }
        
        
        void pop() override {
            
            if (heapSize == 0) {
                throw IllegalParameterValue("the heap is empty");
            }
            
            //先删除根，将最后一个元素放在根部，使堆还是一个完全二叉树
            heap[1].~T();
            
            T theLastElement = heap[heapSize --];//将最后一个元素放在根部，然后heapSize自减1
            
            //从根部向下遍历，将根节点与它的左右孩子比较，将较大者放在根部
            
            int currentNode = 1;
            
            int child = 2;//currentNode的左孩子
            
            while (child <= heapSize) {
                if (child < heapSize && heap[child] < heap[child + 1]) {
                    child ++;
                }
                if (theLastElement < heap[child]) {
                    heap[currentNode] = heap[child];
                    
                    currentNode = child;
                    child = child * 2;
                }
                
            }
            heap[currentNode] = theLastElement;
        }
        
        
        //初始化一个非空大根堆
        void initialize(T* theHeap,int theSize) {
            
            delete [] heap;
            
            heap = theHeap;
            heapSize = theSize;
            
            //堆化,从最后一个具有孩子的结点开始检查。即heapSize/2。检查以这个元素为根的子树是不是大根堆，如果不是则调整。
            //接着减产 heapSize/2 -1.直到根
            for (int root = heapSize/2; root >= 1; root --) {
                
                T rootElement = heap[root];
                
                int child = root * 2;
                
                while (child <= heapSize) {
                    
                    if (child < heapSize && heap[child] < heap[child + 1]) {
                        child ++;
                    }
                    
                    if (rootElement > heap[child]) {
                        break;
                    }
                    
                    heap[child / 2] = heap[child];
                    
                    child *= 2;
                }
                heap[child/2] = rootElement;
            }
        }
        
        
    private:
        
        T* heap;//一个一维数组，保存结点
        int arrayLength;//数组长度
        int heapSize;//堆的大小
        
    };
    
    
}



#endif /* MaxHeap_hpp */
