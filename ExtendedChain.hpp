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





#ifndef ExtendedChain_hpp
#define ExtendedChain_hpp

#include <iostream>
#include "Chain.hpp"


namespace LWTL {
    
    template<typename T>
    
    class ExtendedChain : public ExtendedLinearList<T>, public Chain<T> {
    public:
        //构造函数,调用父类Chain的构造函数
        ExtendedChain(const int& initialCapacity = 10) : Chain<T> (initialCapacity) {
        }
        //拷贝构造函数
        ExtendedChain(const ExtendedChain<T>& rhs) : Chain<T>(rhs) {
            lastNode = rhs.lastNode;
        }
        
        //拷贝赋值运算符
        ExtendedChain& operator = (const ExtendedChain& rhs) {
            if (this == &rhs) {
                return this;
            }
            //调用父类的拷贝赋值运算符
            Chain<T>::operator = (rhs);
            lastNode = rhs.lastNode;
        }
        
        //析构函数
        ~ExtendedChain() {
            clear();
        }
        
        //ADT
        //确定线性表是否为空
        bool empty() const override {
            return this->ListSize == 0;
        }
        
        //确定线性表长度
        int size() const override{
            return this->ListSize;
        }
        
        //按一个给定的索引查找一个元素
        T& get(const int& index) const override{
            return Chain<T>::get(index);
        }
        
        //按一个给定的元素查找他的索引
        int indexOf(const T& element) const override{
            return Chain<T>::indexOf(element);
        }
        
        void output(std::ostream& out) const override{}
        
        //按一个给定索引插入一个元素
        void insert(const int& index,const T& element) override {
            
            if (index < 0 || index > this -> ListSize) {
                throw IllegalParameterValue("insert index must between [0,ListSize]");
            }
            
            if (index == 0) {
                ChainNode<T>* theNode = new ChainNode<T> (element,this -> firstNode);
                this -> firstNode = theNode;
            } else {
                //寻找到前驱节点
                ChainNode<T>* pre = this -> firstNode;
                for (int i = 0;  i < index - 1; i ++) {
                    pre = pre -> next;
                }
                ChainNode<T>* theNode = new ChainNode<T> (element,pre->next);
                pre-> next = theNode;
            }
            this -> ListSize ++;
            
            //设置lastNode
            ChainNode<T>* node = this -> firstNode;
            while (node -> next != NULL) {
                node = node -> next;
            }
            lastNode = node;
            
        }
        
        //按一个给定索引删除一个元素
        void erase(const int& index) override {
            Chain<T>::checkIndex(index);
            if (index == 0) {
                ChainNode<T>* theNode = this -> firstNode;
                this -> firstNode = theNode -> next;
                delete theNode;
                
            } else {
                ChainNode<T>* pre = this -> firstNode;
                //寻找要删除的节点的前向节点
                for (int i = 0; i < index - 1; i ++) {
                    pre = pre -> next;
                }
                ChainNode<T>* theNode = pre -> next;
                pre -> next = pre -> next -> next;
                delete theNode;
            }
            this -> ListSize --;
            
            //设置lastNode
            ChainNode<T>* node = this -> firstNode;
            while (node -> next != NULL) {
                node = node -> next;
            }
            lastNode = node;
        }
        
        //extended method
        //清空链表
        void clear() override {
            while (this -> firstNode != NULL) {
                ChainNode<T>* nextNode = this -> firstNode -> next;
                delete this -> firstNode;
                this -> firstNode = nextNode;
            }
            this -> ListSize = 0;
        }
        
        //在尾部追加一个元素
        void push_back(const T& t) override {
            ChainNode<T>* node = new ChainNode<T>(t);
            if (this -> ListSize == 0) {
                this -> firstNode = node;
                this -> lastNode = node;
            } else {
                this -> lastNode -> next = node;
                this -> lastNode = node;
            }
            this -> ListSize ++;
        }
        
    protected:
        
        //为了方便push_back(),添加一个lastNode成员变量，指向节尾处的Node
        ChainNode<T>* lastNode;
        
    };
}


#endif /* ExtendedChain_hpp */
