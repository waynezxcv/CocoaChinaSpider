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




#ifndef AVLSerach_Tree
#define AVLSerach_Tree

#include <stdio.h>



//AVL树的实现原理:
//在构建二叉搜索树的过程中,每当插入一个节点时,先检查是否因插入而破坏了树的平衡性,若是,则找出最小不平衡树.在保持二叉搜索树特性的情况下,
//调整最小不平衡字数中各个节点的链接关系,进行响应的旋转,使之称为新的平衡子树,从而使插入和删除的时间未O(logn).

//平衡因子BF为正时右旋,平衡因子BF为负时,左旋.
//插入节点后,最小不平衡子树的BF和的子树的BF符号相反时,将需要对节点先进行一次旋转使得符号相同后,再反向旋转一次


using namespace std;

namespace LWTL {
    
    //与二叉搜索树相比,多了一个平衡因子成员变量
    template <typename T>
    class AVLTreeNode {
    public:
        T element;
        int bf;//平衡因子
        AVLTreeNode<T>* leftChild;
        AVLTreeNode<T>* rightChild;
    };
    
    
    
    template <typename K,typename E>
    class AVLSearchTree {
    public:
        
        
    private:
        AVLTreeNode<pair<K, E>>* root;//根节点
        int treeSize;
        
        //一些关键方法
        //对以theTree为根节点的二叉搜索树进行右旋操作
        //处理之后,theTree指向新的树根节点,即旋转之前的左子树节点.
        void rightRotate(AVLTreeNode<pair<K, E>>* theTree);
        
        
        //对以theTree为根节点的二叉搜索树进行左旋操作
        //处理之后,theTree指向新的树根节点,即旋转之前的右子树节点.
        void leftRotate(AVLTreeNode<pair<K, E>>* theTree);
        
        
        //左平衡旋转处理
        void leftBalance(AVLTreeNode<pair<K, E>>* theTree);
        
    };
    
    
    
    
    template<typename K,typename E>
    void AVLSearchTree<K,E>::rightRotate(AVLTreeNode<pair<K, E>>* theTree) {
        AVLTreeNode<pair<K, E>>* L = theTree -> leftChild;
        theTree -> leftChild = L -> leftChild;
        L -> rightChild = theTree;
        theTree = L;
    }
    
    
    template<typename K,typename E>
    void AVLSearchTree<K,E>::leftRotate(AVLTreeNode<pair<K, E>>* theTree) {
        AVLTreeNode<pair<K, E>>* R = theTree -> rightChild;
        R = theTree -> rightChild;
        theTree -> rightChild = R -> leftChild;
        R -> leftChild = theTree;
        theTree = R;
    }
    
    
    
    template <typename K,typename E>
    void AVLSearchTree<K,E>::leftBalance(AVLTreeNode<pair<K, E>>* theTree) {
        AVLTreeNode<pair<K, E>>* L;
        AVLTreeNode<pair<K, E>>* Lr;
        
        L = theTree -> leftChild;
        
        switch (L -> bf) {
            case 1: {//新节点插入在theTree左孩子的左子树上,做右旋处理
                
                theTree -> bf = L -> bf = 0;
                rightRotate(theTree);
            }
                break;
                
            case -1: {//新插入的节点在theTree的做孩子的右子树上,做双旋处理
                Lr = L -> rightChild;
                switch (Lr -> bf) {
                    case 1: {
                        theTree -> bf = -1;
                        L->bf = 0;
                    }break;
                    case 0:{
                        theTree -> bf = L -> bf = 0;
                        
                    }break;
                    case -1:{
                        theTree -> bf = 0;
                        L -> bf = 1;
                    }break;
                }
                Lr -> bf = 0;
                leftRotate(theTree -> leftChild);
                rightRotate(theTree);
            }
        }
    }
    
    
}







#endif /* AVLSerach_Tree */
