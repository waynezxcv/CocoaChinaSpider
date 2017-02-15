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





#ifndef DoublelyLinkedList_hpp
#define DoublelyLinkedList_hpp

#include <stdio.h>
#include "LinearList.hpp"




#pragma mark - 双向链表

/*
 用两个成员变量firstNode和lastNode分别指向链表最左端和最右端的结点
 当双向链表只有一个元素p时，firstNode = lastNode = p
 当双向链表没有元素时，firstNode = lastNode = NULL
 在双向链表中查找，当theIndex < listSize/2时，从左往右查找，否则从右往左查找
 */



namespace LWTL {
    
    //双向链表节点
    template <typename T>
    class DoublelyLinkNode {
    public:
        
        T element;
        DoublelyLinkNode<T>* next;
        DoublelyLinkNode<T>* previous;
        
        DoublelyLinkNode() {};
        DoublelyLinkNode(const T& e) {
            element = e;
            next = NULL;
            previous = NULL;
        }
        
        DoublelyLinkNode(const T& e,DoublelyLinkNode<T>* previous,DoublelyLinkNode<T>* next) {
            element = e;
            next = next;
            previous = previous;
        }
    };
    
    
    //双向链表
    template <typename T>
    class DoublelyLinkedList : public LinearList<T> {
        
    public:
        //构造函数
        DoublelyLinkedList() : listSize(0) {
        }
        
        //拷贝构造函数
        DoublelyLinkedList(const DoublelyLinkedList<T>& rhs) {
            
        }
        
        //拷贝赋值运算符
        
        //析构函数
        
        //ADT
        
        //确定线性表是否为空
        bool empty() const override {
            
        }
        
        //确定线性表长度
        int size() const override {
            
        }
        
        //按一个给定的索引查找一个元素
        T& get(const int& index) const override {
            
        }
        
        //按一个给定的元素查找他的索引
        int indexOf(const T& element) const override {
            
        }
        
        //按一个给定索引删除一个元素
        void erase(const int& index) override {
            
        }
        
        //按一个给定索引插入一个元素
        void insert( const int& index,const T& element) override {
            
        }
        
        //把线性表插入输出流
        void output(std::ostream& out) const override {
            
        }
        
    protected:
        int listSize;
        DoublelyLinkNode<T>* firstNode;
        DoublelyLinkNode<T>* lastNode;
    };
    
}


#endif /* DoublelyLinkedList_hpp */
