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



#ifndef BSTree_hpp
#define BSTree_hpp

#include <iostream>

/*
 二叉搜索树
 
 1.每个元素有一个关键字，并且任意两个元素的关键字都不同。因此，所有的关键字都是唯一的
 2.在根节点的左子树中，元素的关键字（如果有的话）都小于根节点的关键字
 3.在根节点的右子树中，元素的关键字（如果有的话）都大于根节点的关键字
 4.根节点的左右子树都是二叉搜索树
 
 */


/* 有重复值的二叉搜索树
 
 1.在根节点的左子树中，元素的关键字（如果有的话）都小于等于根节点的关键字
 2.在根节点的右子树中，元素的关键字（如果有的话）都大于等于根节点的关键字
 3.根节点的左右子树都是二叉搜索树
 
 */



/* ADT
 
 BSTree 二叉搜索树
 
 实例：二叉树，每一个节点都有一个数对，一个是关键字，另一个是值。
 所有关键字都不相同，任何一个节点的左子树的关键字小于该节点的关键字
 任何一个节点的右子树的关键字都大于该节点的关键字
 
 操作：
 
 find(k) 在返回关键字为k的数对
 insert(p) 插入数对p
 erase(k) 删除关键字为k的数对
 ascend();按关键字升序输出所有数对
 
 */


using namespace std;

namespace LWTL {
    
    template <typename K,typename E>
    class BSTree {
    public:
        
        virtual ~BSTree() {};
        
        //判断此二叉搜索树是否为空
        virtual bool empty() const = 0;
        
        
        //返回此二叉搜索书的元素个数
        virtual int size() const = 0;
        
        //返回关键字所对应的数对
        virtual pair<const K,E>* find(const K&) const = 0;
        
        //插入一个数对
        virtual void insert(const pair<const K,E>&) = 0;
        
        //删除一个数对
        virtual void erase(const K&) = 0;
        
        //按关键字升序输出所有数对
        virtual void ascend() const = 0;
    };
    
}














#endif /* BSTree_hpp */
