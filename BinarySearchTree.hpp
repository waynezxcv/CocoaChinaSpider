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



#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <stdio.h>
#include "BSTree.hpp"

using namespace std;

namespace LWTL {
    
    
    
    //因为二叉搜索树的元素数量和形状随操作改变，所以用链表来描述
    
    //插入算法：
    //1.先查找key是否存在，如果存在则替换
    //2.如果不存在，则寻找二叉搜索树的中断节点。
    
    
    //删除：考虑三种情况
    //1.要删除的元素没有子树
    //2.要删除的元素有一颗子树，
    //3.要删除的元素有两颗子树：先将要删除的元素替换为『左子树的最大值，或者右子树的最小值』 然后把替换元素的节点删除。
    
    
    template <typename T>
    class BSTreeNode {
    public:
        BSTreeNode(const T& theElement) {
            leftChild = rightChild = NULL;
            element = theElement;
        };
        
        ~BSTreeNode() {
            
        };
        
        BSTreeNode<T>* leftChild;
        BSTreeNode<T>* rightChild;
        T element;
    };
    
    
    
    template <typename K,typename E>
    class BinarySearchTree : public BSTree<K,E> {
    public:
        
        BinarySearchTree() {
            root = NULL;
            treeSize = 0;
        };
        
        
        bool empty() const override {
            return treeSize == 0;
        }
        
        
        int size () const override {
            return treeSize;
        }
        
        
        //返回关键字所对应的数对
        pair<const K,E>* find(const K& theKey) const override {
            
            BSTreeNode<pair<K, E>>* node = root;
            
            while (node != NULL) {
                
                if (theKey > node -> element.first) {
                    node = node -> rightChild;
                    
                } else if (theKey < node -> element.first) {
                    node = node -> leftChild;
                    
                } else {
                    
                    return &node->element;
                }
            }
            return NULL;
        }
        
        
        //插入一个数对
        void insert(const pair<const K,E>& thePair) override {
            
            BSTreeNode<pair<K, E>>* p = root;
            BSTreeNode<pair<K, E>>* pp = NULL;
            
            while (p != NULL) {
                pp = p;
                
                if (thePair.first > p-> element.first) {
                    p = p -> rightChild;
                    
                } else if (thePair.first < p -> element.first) {
                    p = p -> leftChild;
                } else {
                    //若已经存在,替换掉pair的second
                    p -> element.second = thePair.second;
                    return;
                }
            }
            
            //创建新节点
            BSTreeNode<pair<K, E>>* theNewNode = new BSTreeNode<pair<K, E>> (thePair);
            
            if (root != NULL) {
                if (thePair.key > pp -> element.first) {
                    pp -> rightChild = theNewNode;
                } else {
                    pp -> leftChild = theNewNode;
                }
            } else {
                //这是一颗空树
                root = theNewNode;
            }
            
            treeSize ++;
        }
        
        
        //通过key删除一个数对
        void erase(const K& theKey) override {
            BSTreeNode<pair<K, E>>* p = root;
            BSTreeNode<pair<K, E>>* pp = NULL;
            
            
            //先找到这个节点
            while (p != NULL && p->element.first != theKey) {
                pp = p;
                
                if (theKey < p -> element.first) {
                    p = p -> leftChild;
                } else {
                    p = p -> rightChild;
                }
            }
            
            if (p == NULL) {
                return;//不存在与theKey匹配的数对
            }
            
            
            //替换节点,并重新组织树结构
            
            //1.要删除的节点元素有两个子树，则找到它左子树中的最大值
            if (p -> leftChild != NULL && p -> rightChild != NULL) {
                BSTreeNode<pair<K, E>>* maxInLeft = p -> leftChild;
                BSTreeNode<pair<K, E>>* parentOfMaxInLeft = p;
                
                while (maxInLeft -> rightChild != NULL) {
                    parentOfMaxInLeft = maxInLeft;
                    maxInLeft = maxInLeft -> rightChild;
                }
                
                
                //将左子树中的最大值替换掉p,
                BSTreeNode<pair<K, E>>* q = new BSTreeNode<pair<K, E>> (maxInLeft -> element);
                q -> leftChild = p -> leftChild;
                q -> rightCHild = p -> rightChild;
                
                //如果要替换的节点p是搜索二叉树的根节点
                if (pp == NULL) {
                    root = q;
                }
                
                //如果要替换的节点p是它的父节点的左子树
                else if (p == pp -> leftChild) {
                    pp -> leftChild = q;
                }
                
                //如果要替换的节点p是它的父节点的右子树
                
                else {
                    pp -> rightChild = q;
                }
                
                if (parentOfMaxInLeft == p) {
                    pp = q;
                }
                
                else {
                    pp = parentOfMaxInLeft;
                }
                delete p;
                p = maxInLeft;
            }
            
            
            
            //2.要删除的节点元素最多有一个孩子(有一个或者没有)
            
            BSTreeNode<pair<K, E>>* c;
            
            if (p -> leftChild != NULL) {
                c = p -> leftChild;
            } else {
                c = p -> rightChild;
            }
            
            //如果p是树根节点
            if (p == root) {
                root = c;
            } else {
                //p是左子树还是右子树？
                if (p == pp -> leftChild) {
                    pp -> leftChild = c;
                } else {
                    pp -> rightChild = c;
                }
                
                delete p;
                treeSize --;
            }
        }
        
        
        //按关键字升序输出所有数对
        void ascend() const override {
            //由于一个二叉搜索树的key 关系是 leftChild < root < rightChild
            //则使用中序遍历 输出即可
            inOrder(root);
        }
        
        
        
    private:
        
        BSTreeNode<pair<K, E>>* root;
        int treeSize;
        
        void inOrder (BSTreeNode<pair<K, E>>* node) {
            
            if (node == NULL) {
                return;
            }
            
            inOrder(node -> leftChild);
            visit(node);
            inOrder(node -> rightChild);
        }
        
        
        void visit (BSTreeNode<pair<K, E>>* node) {
            cout<<"the key = " << node->element.first <<"the value = " << node -> element.second<<endl;
        }
    };
    
}


#endif /* BinarySearchTree_hpp */
