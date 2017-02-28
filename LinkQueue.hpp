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




#ifndef LinkQueue_hpp
#define LinkQueue_hpp

#include <stdio.h>


/******************** 用链表实现队列 *******************/


namespace LWTL {
    
    template <typename T>
    class QueueNode {
        
    public:
        
        QueueNode() = default;
        
        QueueNode(const T& t) {
            element = t;
            next = NULL;
        }
        
        QueueNode(const T& t,QueueNode<T>* n) {
            element = t;
            next = n;
        }
        
        T element;
        QueueNode<T>* next;
    };
    
    
    
    
    template <typename T>
    class LinkQueue : public Queue<T> {
    public:
        
        
        LinkQueue() {
            queueSize = 0;
            queueFront = NULL;
            queueBack = NULL;
        };
        
        ~LinkQueue() {
            while (queueSize != 0) {
                pop();
            }
        }
        
        bool empty() const override {
            return queueSize == 0;
        }
        
        
        int size () const override {
            return queueSize;
        }
        
        T& front() const override {
            return queueFront -> element;
        }
        
        T& back() const override {
            return queueBack -> element;
        }
        
        
        void push (const T& theElement) override {
            QueueNode<T>* node = new QueueNode<T>(theElement);
            if (queueSize == 0) {
                queueFront = node;
                queueBack = node;
            } else {
                queueBack -> next = node;
                queueBack = node;
            }
            queueSize++;
        }
        
        void pop () override {
            if (queueSize == 0) {
                throw IllegalParameterValue("the queue is empty");
            }
            QueueNode<T>* node = queueFront;
            queueFront = node -> next;
            delete node;
            queueSize --;
        }
        
    private:
        QueueNode<T>* queueFront;
        QueueNode<T>* queueBack;
        int queueSize;
    };
}

#endif /* LinkQueue_hpp */
