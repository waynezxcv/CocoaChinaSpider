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



#ifndef IndexedBSTree_hpp
#define IndexedBSTree_hpp

#include <stdio.h>


/* 索引二叉搜索树
 源于普通的二叉搜索树。只是在每个节点中，添加一个leftSize域，用来表示这个节点左子树的元素个数。
 leftSize同时给出了一个元素的索引。
 
 
 */




/* ADT
 
 IndexedBSTree 索引二叉搜索树
 
 实例：二叉树，每一个节点都有一个数对，一个是关键字，另一个是值。
 所有关键字都不相同，任何一个节点的左子树的关键字小于该节点的关键字
 任何一个节点的右子树的关键字都大于该节点的关键字
 
 还有一个leftSize表示每一个节点的左子树的个数
 
 操作：
 
 find(k) 在返回关键字为k的数对
 insert(p) 插入数对p
 erase(k) 删除关键字为k的数对
 ascend();按关键字升序输出所有数对
 
 */







#endif /* IndexedBSTree_hpp */
