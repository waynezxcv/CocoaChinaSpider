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





#ifndef LinkedBinaryTree_hpp
#define LinkedBinaryTree_hpp

#include "BinaryTree.hpp"
#include "BinaryTreeNode.hpp"
#include "ArrayQueue.hpp"


/******************** 用链表描述二叉树 *******************/

namespace LWTL {
    
    template <typename T>
    class LinkedBinaryTree : public BinaryTree<BinaryTreeNode<T> > {
        
    public:
        LinkedBinaryTree() {
            root = NULL;
            treeSize = 0;
        }
        
        ~LinkedBinaryTree() {
            erase();
        }
        
        bool empty () const override {
            return treeSize == 0;
        }
        
        int size() const override {
            return treeSize;
        }
        
        
        void preOrder (void (*theVisit) (BinaryTreeNode<T>*)) override {
            visit = theVisit;//设置回调
            preOrder(root);//开始前序遍历
        }
        
        
        void inOrder (void (*theVisit) (BinaryTreeNode<T>*)) override {
            visit = theVisit;
            inOrder(root);
        }
        
        void postOrder (void (*theVisit) (BinaryTreeNode<T> *)) override {
            visit = theVisit;
            postOrder(root);
        }
        
        
        void levelOrder (void (*theVisit) (BinaryTreeNode<T> *) )override {
            visit = theVisit;
            levelOrder(root);
        }
        
        void erase () {
            postOrder(dispose);
            root = NULL;
            treeSize = 0;
        }
        
        
        //返回二叉树的高度
        int height () const {
            return height(root);
        }
        
    private:
        
        BinaryTreeNode<T>* root;//根节点
        int treeSize;//元素个数
        
        static void (*visit) (BinaryTreeNode<T>* t);//访问元素结点回调函数
        
        static void preOrder (BinaryTreeNode<T>* t);
        
        static void inOrder (BinaryTreeNode<T>* t);
        
        static void postOrder (BinaryTreeNode<T>* t);
        
        static void dispose (BinaryTreeNode<T>* t) {
            delete t;
        };
        
        static int height (BinaryTreeNode<T>* t) {
            if (t == NULL) {
                return 0;
            }
            
            int h1 = height(t -> leftChild);//左子树高度
            int h2 = height(t -> rightChild);//右子树高度
            
            if (h1 > h2) {
                return ++ h1;
            } else {
                return ++ h2;
            }
        }
        
        static void levelOrder (BinaryTreeNode<T>* t);
    };
    
    
    //前序遍历
    template <typename T>
    void LinkedBinaryTree<T>::preOrder(BinaryTreeNode<T>* t) {
        if (t != NULL) {
            LinkedBinaryTree<T>::visit(t);//调用函数指针
            
            preOrder(t -> leftChild);
            preOrder(t -> rightChild);
        }
    }
    
    
    //中序遍历
    template<typename T>
    void LinkedBinaryTree<T>::inOrder(BinaryTreeNode<T> *t) {
        if (t != NULL) {
            inOrder(t -> leftChild);
            LinkedBinaryTree<T>::visit(t);
            inOrder(t -> rightChild);
        }
    }
    
    //后序遍历
    template<typename T>
    void LinkedBinaryTree<T>::postOrder(BinaryTreeNode<T> *t) {
        if (t != NULL) {
            postOrder(t->leftChild);
            preOrder(t -> rightChild);
            LinkedBinaryTree<T>::visit(t);
        }
    }
    
    //层序遍历
    template <typename T>
    void LinkedBinaryTree<T>::levelOrder(BinaryTreeNode<T> *t) {
        ArrayQueue<BinaryTreeNode<T> *> q;
        
        while (t != NULL) {
            LinkedBinaryTree<T>::visit(t);//调用函数指针
            
            if (t -> leftChild != NULL) {
                q.push(t -> leftChild);
            }
            
            if (t -> rightChild != NULL) {
                q.push(t -> rightChild);
            }
            
            try {
                t = q.front();
            } catch (...) {
                return;
            }
            q.pop();
        }
    }
}


#endif /* LinkedBinaryTree_hpp */
