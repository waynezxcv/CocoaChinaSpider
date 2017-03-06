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




#ifndef InvertBinaryTree_hpp
#define InvertBinaryTree_hpp

#include <stdio.h>


namespace LWTL {
    
    template <typename T>
    class TreeNode {
    public:
        T element;
        TreeNode<T>* leftChild;
        TreeNode<T>* rightChild;
        
        TreeNode(const T& theElement) : element(theElement) {
            leftChild = rightChild = NULL;
        }
    };
    
    
    
    template<typename T>
    TreeNode<T>* invertBinaryTree(TreeNode<T>* root) {
        if (root == NULL) {
            return NULL;
        }
        
        TreeNode<T>* tmp = root -> leftChild;
        root -> leftChild = root -> rightChild;
        root -> rightChild = tmp;
        
        invertBinaryTree(root -> leftChild);
        invertBinaryTree(root -> rightChild);
        return root;
    }
    
}

#endif /* InvertBinaryTree_hpp */
