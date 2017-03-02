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




#ifndef LinkList_hpp
#define LinkList_hpp

#include <iostream>
#include "LinearList.hpp"

#pragma mark - 链式描述的线性表


namespace LWTL {
    
    //链表节点
    template <typename T>
    class ChainNode {
    public:
        ChainNode<T>* next;
        T element;
        
        //构造函数
        ChainNode() {};
        
        ChainNode(const T& t) {
            element = t;
            next = NULL;
        }
        
        ChainNode(const T& t,ChainNode<T>* n) {
            element = t;
            next = n;
        }
    };
    
    
    //单向链表
    template <typename T>
    class Chain : public LinearList<T> {
        
    protected:
        ChainNode<T>* firstNode;
        int ListSize;
        
        void checkIndex (const int& theIndex ) const {
            if (theIndex < 0 || theIndex >= ListSize) {
                throw IllegalParameterValue("the index must between [0,ListSize)");
            }
        }
        
    public:
        //构造函数
        //capacity用于与ArrayList兼容
        Chain(int initCapacity) {
            if (initCapacity < 1) {
                throw IllegalParameterValue("init capacity must be > 0");
            }
            firstNode = NULL;
            ListSize = 0;
        }
        
        
        //拷贝构造函数
        Chain(const Chain<T>& rhs) {
            
            ListSize = rhs.ListSize;
            //链表为空
            if (ListSize == 0) {
                firstNode = NULL;
            } else {
                //需要复制每一个节点
                ChainNode<T>* sourceNode = rhs.firstNode;
                this -> firstNode = new ChainNode<T> (rhs.firstNode -> element);
                sourceNode = sourceNode -> next;
                ChainNode<T>* targetNode = this -> firstNode;
                
                while (sourceNode != NULL) {
                    //复制
                    targetNode -> next = new ChainNode<T> (sourceNode -> element);
                    //指向下一个节点
                    sourceNode = sourceNode -> next;
                    targetNode = targetNode -> next;
                }
                //最后一个节点的next指向NULL
                targetNode -> next = NULL;
            }
        }
        
        
        
        //拷贝赋值运算符
        Chain& operator = (const Chain<T>& rhs) {
            if (this == &rhs) {
                return *this;
            }
            
            while (firstNode != NULL) {
                //清除首节点
                ChainNode<T>* nextNode = firstNode -> next;
                delete firstNode;
                firstNode = nextNode;
            }
            
            ListSize = rhs.ListSize;
            
            //链表为空
            if (ListSize == 0) {
                firstNode = NULL;
            } else {//需要复制每一个节点
                //复制第一个节点
                ChainNode<T>* sourceNode = rhs.firstNode;
                this -> firstNode = new ChainNode<T> (rhs.firstNode);
                
                sourceNode = sourceNode -> next;
                ChainNode<T>* targetNode = this -> firstNode;
                
                while (sourceNode != NULL) {
                    //复制
                    targetNode -> next = new ChainNode<T> (sourceNode -> element);
                    //指向下一个节点
                    sourceNode = sourceNode -> next;
                    targetNode = targetNode -> next;
                }
                //最后一个节点的next指向NULL
                targetNode -> next = NULL;
            }
        }
        
        //析构函数,要逐个清除链表的节点
        //实现策略，重复清除首元素节点，直到链表为空
        ~Chain() {
            while (firstNode != NULL) {
                //清除首节点
                ChainNode<T>* nextNode = firstNode -> next;
                delete firstNode;
                firstNode = nextNode;
            }
        }
        
        //ADT
        //确定线性表是否为空
        virtual bool empty() const override {
            return ListSize == 0;
        }
        
        //确定线性表长度
        virtual int size() const override {
            return ListSize;
        }
        
        
        //按一个给定的索引查找一个元素
        virtual T& get(const int& index) const override {
            
            checkIndex(index);
            
            ChainNode<T>* currentNode = firstNode;
            int count = 0;
            
            while (count != index) {
                currentNode = currentNode -> next;
                count ++;
            }
            
            return currentNode -> element;
        }
        
        //按一个给定的元素查找他的索引
        virtual int indexOf(const T& element) const override {
            ChainNode<T>* currentNode = firstNode;
            int theIndex = 0;
            
            while (currentNode -> next != NULL &&
                   currentNode -> element != element ) {
                
                currentNode = currentNode -> next;
                theIndex ++;
            }
            
            if (currentNode == NULL) {
                return  -1;
            }
            
            return theIndex;
        }
        
        //按一个给定索引删除一个元素
        virtual void erase(const int& theIndex) override {
            checkIndex(theIndex);
            //如果需要删除的节点在开头位置
            if (theIndex == 0) {
                //清除首节点
                ChainNode<T>* nextNode = firstNode -> next;
                delete firstNode;
                firstNode = nextNode;
                
            } else {
                ChainNode<T>* p = firstNode;
                //寻找要删除节点的前驱节点
                for (int i = 0; i < theIndex - 1; i ++) {
                    p = p -> next;
                }
                ChainNode<T>* theNode = p -> next;
                p -> next = p -> next -> next;
                delete theNode;
            }
            ListSize --;
        }
        
        //按一个给定索引插入一个元素
        virtual void insert( const int& theIndex,const T& element) override {
            //检查索引
            if (theIndex < 0 || theIndex > ListSize) {
                throw IllegalParameterValue("insert index must beween [0,ListSize]");
            }
            //在起始位置插入
            if (theIndex == 0) {
                ChainNode<T>* theNode = new ChainNode<T>(element);
                theNode -> next = firstNode;
                firstNode = theNode;
            } else {
                ChainNode<T>* theNode = new ChainNode<T>(element);//创建要插入的节点
                ChainNode<T>* p = firstNode;
                //寻找插入位置的前驱
                for (int i = 0; i < theIndex - 1 ; i ++) {
                    p = p -> next;
                }
                theNode -> next = p -> next;
                p -> next = theNode;
            }
            ListSize ++;
        }
        
        
        
        //链表的成员类iterator
        class iterator {
        public:
            //构造函数
            iterator(ChainNode<T>* theNode = NULL) {
                node = theNode;
            };
            
            //重载运算符
            T* operator & () const {
                return &(node -> element);
            }
            
            T& operator * () const {
                return (node -> element);
            }
            
            iterator& operator ++ () {//前加 ++ it;
                node = node -> next;
                return *this;
            }
            
            iterator operator ++ (int) {//后加 it ++;
                iterator old = *this;
                node = node -> next;
                return old;
            }
            
            bool operator != (const iterator& rightIt) const{
                return node != rightIt.node;
            }
            
            bool operator == (const iterator& rightIt) const{
                return node == rightIt.node;
            }
            
        protected:
            ChainNode<T>* node;
        };
        
        iterator begin() {
            return iterator(firstNode);
        }
        
        iterator end() {
            return iterator(NULL);
        }
    };
}

#endif /* LinkList_hpp */
