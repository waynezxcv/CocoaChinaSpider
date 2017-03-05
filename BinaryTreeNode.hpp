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



#ifndef BinaryTreeNode_hpp
#define BinaryTreeNode_hpp

#include <stdio.h>

namespace LWTL {
    
    
    /******************** 用链表描述二叉树的元素结点 *******************/
    
    
    template<typename T>
    class BinaryTreeNode {
    public:
        
        BinaryTreeNode () {
            leftChild = rightChild = NULL;
        }
        
        BinaryTreeNode(const T& theElement) {
            leftChild = rightChild = NULL;
            element = theElement;
        }
        
        BinaryTreeNode(const T& theElement,BinaryTreeNode<T>* theLeft,BinaryTreeNode<T>* theRight) {
            element = theElement;
            leftChild = theLeft;
            rightChild = theRight;
        }
        
        ~BinaryTreeNode() {
            
        }
        
        BinaryTreeNode<T>* leftChild;//左孩子
        BinaryTreeNode<T>* rightChild;//右孩子
        T element;//数据域
    };
    
}

#endif /* BinaryTreeNode_hpp */

