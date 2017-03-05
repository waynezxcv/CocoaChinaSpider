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


#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>




/******************** 二叉树 *******************/

/*
 ADT
 
 确定二叉树是否为空
 确定二叉树元素个数
 前序遍历二叉树
 中序遍历二叉树
 后序遍历二叉树
 层次遍历二叉树
 
 */



namespace LWTL {
    
    template <typename T>
    class BinaryTree {
    public:
        
        virtual ~BinaryTree () {};
        
        virtual bool empty () const = 0;
        
        virtual int size () const = 0;
        
        // 前序遍历二叉树
        
        virtual void preOrder(void (*) (T*)) = 0;
        
        
        //中序遍历二叉树
        virtual void inOrder (void (*) (T*)) = 0;
        
        //后序遍历二叉树
        virtual void postOrder (void (*) (T*)) = 0;
        
        //层次遍历二叉树
        virtual void levelOrder (void (*) (T*)) = 0;
        
    };
    
}

#endif /* BinaryTree_hpp */
