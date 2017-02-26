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



#ifndef ArrayStack_hpp
#define ArrayStack_hpp

#include "Stack.hpp"
#include "IllegalParameterValue.hpp"

/******************** 用数组描述栈 *******************/


namespace LWTL {
    
    
    template <typename T>
    
    class ArrayStack : public Stack<T> {
        
    public:
        
        //构造函数
        ArrayStack(int capacity = 10) : stackTop(-1),arrayLength(capacity) {
            if (capacity < 1) {
                throw IllegalParameterValue("capacity must > 0 ");
            }
            elements = new T [arrayLength];
        }
        
        //拷贝构造函数
        ArrayStack(const ArrayStack& rhs) {
            printf("test2\n");
            arrayLength = rhs.arrayLength;
            stackTop = rhs.stackTop;
            elements = new T [arrayLength];
            memcpy(elements, rhs.elements, sizeof(T) * arrayLength);
        }
        
        
        //拷贝赋值运算符
        ArrayStack& operator = (const ArrayStack& rhs) {
            printf("test1\n");
            if (this == &rhs) {
                return *this;
            }
            arrayLength = rhs.arrayLength;
            stackTop = rhs.stackTop;
            elements = new T [arrayLength];
            memcpy(elements, rhs.elements, sizeof(T) * arrayLength);
            return *this;
        }
        
        //析构函数
        ~ArrayStack() {
            delete [] elements;
        }
        
        //判断是否为空
        bool empty () const override {
            return stackTop == -1;
        }
        
        //获取栈长度
        int size() const override {
            return stackTop + 1;
        }
        
        //获取栈顶元素
        T& top() const override {
            if (stackTop == -1) {
                throw IllegalParameterValue("the stack is empty");
            }
            return  elements[stackTop];
        }
        
        //入栈
        void push (const T& theElement) override {
            
            if (stackTop + 1 == arrayLength) {
                T* tmp = new T [arrayLength * 2];
                memcpy(tmp, elements, sizeof(T) * arrayLength);
                delete [] elements;
                elements = tmp;
                arrayLength *= 2;
            }
            
            elements[stackTop + 1] = theElement;
            stackTop ++;
        }
        
        
        //出栈
        void pop () override {
            
            if (stackTop == -1) {
                throw IllegalParameterValue("the stack is empty");
            }
            
            //如果栈长度为stackTop为数组长度的四分之一时，将数组缩短到原来的二分之一
            if (stackTop < arrayLength/4) {
                T* tmp = new T [arrayLength/2];
                memcpy(tmp, elements,arrayLength/2 * sizeof(T));
                delete [] elements;
                elements = tmp;
                arrayLength = arrayLength/2;
            }
            
            elements[stackTop].~T();//调用栈顶元素的析构函数
            stackTop --;
        }
        
    private:
        
        int stackTop;//当前栈顶
        T* elements;//保存元素的素组
        int arrayLength;//数组的长度
        
    };
}



#endif /* ArrayStack_hpp */
