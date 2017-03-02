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





#ifndef ArrayQueue_hpp
#define ArrayQueue_hpp

#include <stdio.h>
#include "Queue.hpp"
#include "IllegalParameterValue.hpp"




/******************** 用数组实现队列 *******************/


namespace LWTL {
    
    template <typename T>
    class ArrayQueue : public Queue <T> {
        
    public:
        
        ArrayQueue(int capacity = 10) : arrayLength(capacity) , queueSize(0) {
            elements = new T [capacity];
        }
        
        ArrayQueue(const ArrayQueue<T>& rhs) : arrayLength(rhs.arrayLength) ,queueSize(rhs.queueSize) {
            elements = new T [arrayLength];
            memset(elements, 0, arrayLength * sizeof(T));
            memcpy(elements, rhs.elements, sizeof(T) * rhs.arrayLength);
        }
        
        
        ArrayQueue& operator = (const ArrayQueue<T>& rhs) {
            if (this != &rhs) {
                //先创建一个临时实例，再交换原来的实例和临时实例。防止因内存不足时new失败异常
                ArrayQueue<T> tmpQueue (rhs);
                
                T* elementsTmp = tmpQueue.elements;
                int arrayLengthTmp = tmpQueue.arrayLength;
                int queueSizeTmp = tmpQueue.queueSize;
                
                
                tmpQueue.elements = elements;
                tmpQueue.arrayLength = arrayLength;
                tmpQueue.queueSize = queueSize;
                
                
                elements = elementsTmp;
                arrayLength = arrayLengthTmp;
                queueSize = queueSizeTmp;
            }
            return *this;
            //
            //            if (this == &rhs) {
            //                return *this;
            //            }
            //
            //            delete [] elements;
            //            elements = NULL;
            //
            //            arrayLength = rhs.arrayLength;
            //            queueSize = rhs.queueSize;
            //
            //            elements = new T [arrayLength];
            //            memset(elements, 0, sizeof(T) * arrayLength);
            //            memcpy(elements, rhs.elements, sizeof(T) * arrayLength);
            //
            //            return *this;
        }
        
        ~ArrayQueue() {
            delete [] elements;
        }
        
        
        bool empty() const override {
            return queueSize == 0;
        }
        
        int size() const override {
            return queueSize;
        }
        
        T& front() const override {
            if (queueSize == 0) {
                throw IllegalParameterValue("the queue is empty");
            }
            return elements[0];
        }
        
        T& back() const override {
            if (queueSize == 0) {
                throw IllegalParameterValue("the queue is empty");
            }
            return elements[queueSize - 1];
        }
        
        
        void push(const T& t) override {
            //数组满了
            if (queueSize == arrayLength) {
                //将数组容量扩展到原来的2倍
                T* tmp = new T [arrayLength * 2];
                memset(tmp, 0, sizeof(T) * arrayLength * 2);
                memcpy(tmp, elements, queueSize * sizeof(T));
                delete [] elements;
                elements = tmp;
                arrayLength *= 2;
            }
            elements[queueSize ++] = t;
        }
        
        
        void pop() override {
            elements[0].~T();//调用队首元素的析构函数
            for (int i = 0; i < queueSize; i ++) {
                elements[i] = elements [i + 1];
            }
            queueSize --;
        }
        
    private:
        T* elements;
        int queueSize;
        int arrayLength;
    };
}




#endif /* ArrayQueue_hpp */
