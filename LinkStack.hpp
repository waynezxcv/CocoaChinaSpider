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



#ifndef LinkStack_hpp
#define LinkStack_hpp

#include "Stack.hpp"
#include "IllegalParameterValue.hpp"



/******************** 用链表描述栈 *******************/


namespace LWTL {
    
    template <typename T>
    class StackNode {
    public:
        StackNode(){};
        StackNode(const T& t) {
            element = t;
            next = NULL;
        }
        
        StackNode(const T& t,Stack<T>* n) {
            element = t;
            next = n;
        }
        
        StackNode<T>* next;
        T element;
    };
    
    
    
    
    template <typename T>
    class LinkStack : public Stack<T> {
        
    public:
        
        //构造函数
        LinkStack() :stackSize(0) ,stackTop(NULL) {}
        
        //拷贝构造函数
        LinkStack(const LinkStack<T>& rhs) {
            stackSize = rhs.stackSize;
            //遍历依次拷贝
            StackNode<T>* soruceNode = rhs.stackTop;
            StackNode<T>* destinationNode = new StackNode<T>(rhs.top());
            
            stackTop = destinationNode;
            while (soruceNode -> next != NULL) {
                soruceNode = soruceNode -> next;
                destinationNode -> next = new StackNode<T> (soruceNode -> element);
                destinationNode = destinationNode -> next;
            }
        }
        
        //重载拷贝赋值运算符
        LinkStack& operator = (const LinkStack<T>& rhs) {
            if (this == &rhs) {
                return *this;
            }
            
            stackSize = rhs.stackSize;
            //遍历依次拷贝
            StackNode<T>* soruceNode = rhs.stackTop;
            StackNode<T>* destinationNode = new StackNode<T>(rhs.top());
            
            stackTop = destinationNode;
            while (soruceNode -> next != NULL) {
                soruceNode = soruceNode -> next;
                destinationNode -> next = new StackNode<T> (soruceNode -> element);
                destinationNode = destinationNode -> next;
            }
            return *this;
        }
        
        
        //析构函数
        ~LinkStack() {
            //遍历一次delete
            while (stackTop != NULL) {
                StackNode<T>* node = stackTop;
                stackTop = stackTop -> next;
                delete node;
            }
        }
        
        //是否为空
        bool empty () const override {
            return stackSize == 0;
        }
        
        //获取栈顶的长度
        int size () const override {
            return stackSize;
        }
        
        //获取栈顶的元素
        T& top () const override {
            if (stackSize == 0) {
                throw IllegalParameterValue("the stack is empty");
            }
            return stackTop->element;
        }
        
        //入栈
        void push (const T& theElement) override {
            if (stackSize == 0) {
                stackTop = new StackNode<T>(theElement);
            } else {
                StackNode<T>* tmp = new StackNode<T>(theElement);
                tmp->next = stackTop;
                stackTop = tmp;
            }
            stackSize ++;
        }
        
        //出栈
        void pop () override {
            if (stackSize == 0) {
                throw IllegalParameterValue("the stack is empty");
            }
            StackNode<T>* next = stackTop -> next;
            delete stackTop;
            stackTop = next;
            stackSize --;
        }
        
    private:
        StackNode<T>* stackTop;//指向栈顶元素的指针
        int stackSize;//栈中的元素个数
        
    };
}
#endif /* LinkStack_hpp */
