//
//  SortedChain.hpp
//  DataStructures
//
//  Created by 刘微 on 2017/3/4.
//  Copyright © 2017年 刘微. All rights reserved.
//

#ifndef SortedChain_hpp
#define SortedChain_hpp

#include <stdio.h>
#include "Dictionary.hpp"
#include "PairNode.hpp"






namespace LWTL {
    
    
    //用链表描述的字典
    template <typename K,typename E>
    
    
    class SortedChain : public Dictionary<K,E> {
    public:
        
        SortedChain() {
            firstNode = NULL;
            chainSize = 0;
        }
        
        SortedChain(int capacity = 10) {
            firstNode = NULL;
            chainSize = 0;
        }
        
        SortedChain(const SortedChain& rhs) {
            chainSize = rhs.chainSize;
            
            if (chainSize == 0) {
                firstNode = NULL;
            } else {
                
                PairNode<K, E>* sourceNode = rhs.firstNode;
                PairNode<K, E>* targetNode;
                
                firstNode = new PairNode<K, E>(sourceNode -> element);
                
                targetNode = firstNode;
                
                while (sourceNode -> next != NULL) {
                    sourceNode = sourceNode -> next;
                    targetNode -> next = new PairNode<K, E>(sourceNode -> element);
                    targetNode = targetNode -> next;
                }
            }
        }
        
        
        
        SortedChain& operator = (const SortedChain& rhs) {
            while (firstNode) {
                PairNode<K, E>* node = firstNode;
                firstNode = node -> next;
                delete node;
            }
            
            chainSize = rhs.chainSize;
            if (chainSize == 0) {
                firstNode = NULL;
            } else {
                
                PairNode<K, E>* sourceNode = rhs.firstNode;
                PairNode<K, E>* targetNode;
                
                firstNode = new PairNode<K, E>(sourceNode -> element);
                targetNode = firstNode;
                
                while (sourceNode -> next != NULL) {
                    sourceNode = sourceNode -> next;
                    targetNode -> next = new PairNode<K, E>(sourceNode -> element);
                    targetNode = targetNode -> next;
                }
            }
            
        }
        
        ~SortedChain() {
            while (firstNode) {
                PairNode<K, E>* node = firstNode;
                firstNode = node -> next;
                delete node;
            }
        }
        
        bool empty () const override {
            return chainSize == 0;
        }
        
        int size() const override {
            return chainSize;
        }
        
        
        pair<const K,E>* find(const K& theKey) const override {
            PairNode<K, E>* currentNode = firstNode;
            while (currentNode != NULL && currentNode-> element.first != theKey) {
                currentNode = currentNode -> next;
            }
            if (currentNode != NULL && currentNode -> element.first == theKey) {
                return currentNode->element;
            }
            return NULL;
        }
        
        
        void insert(const pair<K, E>& thePair) override {
            //往字典中插入pair，如果key已经存在就覆盖。
            //1.先查找
            PairNode<K, E>* currentNode = firstNode;
            PairNode<K, E>* nodeTrails ;//遍历时currentNode的前一个结点
            
            while (currentNode != NULL && currentNode -> element.first < thePair.first) {
                nodeTrails = currentNode;
                currentNode = currentNode -> next;
            }
            
            //2.已经存在key
            if (currentNode != NULL && currentNode -> element.first == thePair.first) {
                currentNode -> element.second = thePair.second;
                return;
            }
            
            
            //3.key还不存在，插入新的pair
            PairNode<K, E>* newPairNode = new PairNode<K, E>(thePair,currentNode);
            
            if (nodeTrails == NULL) {
                newPairNode = firstNode;
            } else {
                nodeTrails -> next = newPairNode;
            }
            chainSize ++;
        }
        
        void erase(const K& theKey) override {
            
            PairNode<K, E>* currentNode = firstNode;
            PairNode<K, E>* nodeTrails;
            
            while (currentNode != NULL && currentNode -> element.first < theKey) {
                nodeTrails = currentNode;
                currentNode = currentNode -> next;
            }
            
            if (currentNode != NULL && currentNode -> element.first == theKey) {
                if (nodeTrails == NULL) {
                    //currentNode是第一个结点
                    firstNode  = currentNode -> next;
                    delete currentNode;
                    
                } else {
                    //不是第一个结点
                    nodeTrails -> next = currentNode -> next;
                    delete currentNode;
                }
                
                chainSize --;
            }
            
        }
        
        
        
        //迭代器
        class iterator {
            iterator(PairNode<K, E>* theNode) {
                node = theNode;
            }
            
            
            pair<K, E>& operator *(const iterator& it) {
                return node -> element;
            }
            
            
            pair<K, E>* operator & (const iterator& it) {
                return &(node -> element);
            }
            
            bool operator == (const iterator& rightIt) {
                return node == rightIt.node;
            }
            
            bool operator != (const iterator& rightIt) {
                return node != rightIt.node;
            }
            
            iterator& operator ++ () {//++ it
                node = node -> next;
                return *this;
            }
            
            iterator& operator ++ (int) { //it ++
                iterator oldIt = *this;
                node = node -> next;
                return oldIt;
            }
            
        private:
            PairNode<K, E>* node;
        };
        
        
        iterator begin() {
            return iterator(firstNode);
        }
        
        iterator end() {
            return iterator(NULL);
        }
        
        
        
    private:
        PairNode<K, E>* firstNode;
        int chainSize;
    };
    
}

#endif /* SortedChain_hpp */
