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




#ifndef CircularArrayQueue_hpp
#define CircularArrayQueue_hpp

#include <stdio.h>
#include "Queue.hpp"
#include "IllegalParameterValue.hpp"

//0.把数组视为一个环，每一个位置都有其下一个位置和前一个位置，位置arrayLength - 1的下一个位置是0，0的前一个位置是arrayLength - 1
//1.location(i) = (location(队列首元素) + i) % arrayLength
//2.队列不能插满，否则无法通过queuefront == queueBack判断队列为空还是队列满了



namespace LWTL {
    
    template <typename T>
    class CircularArrayQueue : public Queue<T> {
        
    public:
        
        CircularArrayQueue(int capacity = 10) : arrayLength (capacity) {
            elements = new T [arrayLength];
            queueFront = 0;
            queueBack = 0;
        }
        
        
        ~CircularArrayQueue() {
            delete [] elements;
        }
        
        
        bool empty () override {
            return queueFront == queueBack;
        }
        
        
        int size () override {
            return queueBack - queueFront;
        }
        
        
        T& front () override {
            if (empty()) {
                throw IllegalParameterValue("the queue is empty");
            }
            return elements[queueFront];
        }
        
        T& back () override {
            if (empty()) {
                throw IllegalParameterValue("the queue is empty");
            }
            return elements[queueBack];
        }
        
        void push (const T& theElement) override {
            if (size() + 1 == arrayLength) {
                changeArrayLength();
            }
            queueBack = (queueBack + 1) % arrayLength;
            elements[queueBack] = theElement;
        }
        
        void pop () override {
            if (empty()) {
                throw IllegalParameterValue("the queue is empty");
            }
            
            queueFront = (queueFront + 1) % arrayLength;
            elements[queueFront].~T();
        }
        
    private:
        
        //数组长度加倍
        void changeArrayLength () {
            T* newQueue = new T [2 * arrayLength];
            
            //复制原来的数组
            int start = (queueFront + 1) % arrayLength;
            
            //没有形成环状
            if (start < 2) {
                std::copy(elements + start, elements + start + arrayLength - 1, newQueue);
            } else {//形成环状
                std::copy(elements + start, elements + arrayLength, newQueue);
                std::copy(elements , elements + queueBack + 1, newQueue + arrayLength - start);
            }
            
            
            //设置新队列的首尾元素位置
            queueFront = 2 * arrayLength - 1;
            queueBack = arrayLength - 2;
            arrayLength *= 2;
            delete [] elements;
            elements = newQueue;
        }
        
        int queueFront;
        int queueBack;
        int arrayLength;
        T* elements;
        
    };
    
}

#endif /* CircularArrayQueue_hpp */
