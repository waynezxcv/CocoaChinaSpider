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






#ifndef CompleteWinnerTree_hpp
#define CompleteWinnerTree_hpp

#include <stdio.h>
#include "WinnerTree.hpp"
#include "IllegalParameterValue.hpp"





namespace LWTL {
    
    template <typename T>
    class CompleteWinnerTree : public WinnerTree<T> {
        
    public:
        
        CompleteWinnerTree(T* thePlayer,int numberOfPlayers) {
            tree = NULL;
            initialize(thePlayer,numberOfPlayers);
            
        };
        
        //将一个数组初始化为赢者树
        virtual void initialize (T* thePlayer,int theNumberOfPlayers) override {
            int n = theNumberOfPlayers;
            if (n < 2) {
                //最少要有两个参赛者
                throw IllegalParameterValue("must have at least 2 players");
            }
            
            player = thePlayer;
            numberOfPlayers = n;
            delete [] tree;
            tree = new int [n];
            
            //   s = 2^log (n-1) 最底端最左边的内部节点为s
            int i, s;
            for (s = 1; 2 * s <= n - 1; s += s);
            
            lowExt = 2 * (n - s);
            offset = 2 * s - 1;
            
            //竞赛
            for (i = 2; i <= lowExt; i += 2) {
                play((offset + i) / 2, i - 1, i);
            }
            
            //处理剩余的节点
            if (n % 2 == 1) {
                play(n/2, tree[n - 1], lowExt + 1);
                i = lowExt + 3;
            } else {
                i = lowExt + 2;
            }
            
            for (; i <= n; i += 2) {
                play((i - lowExt + n - 1) / 2, i - 1, i);
            }
        }
        
        //返回锦标赛的胜者的索引
        virtual int winner() const override {
            return tree[1];
        }
        
        
        //在参赛者i改变之后重赛
        virtual void rePlay(int thePlayer) override {
            int n = numberOfPlayers;
            if (thePlayer <= 0 || thePlayer > n) {
                throw IllegalParameterValue("Player index is illegal");
            }
            
            int matchNode,
            leftChild,
            rightChild;
            
          
            if (thePlayer <= lowExt) {
                
                matchNode = (offset + thePlayer) / 2;
                leftChild = 2 * matchNode - offset;
                rightChild = leftChild + 1;
                
            } else {
                
                matchNode = (thePlayer - lowExt + n - 1) / 2;
                
                if (2 * matchNode == n - 1) {
                    leftChild = tree[2 * matchNode];
                    rightChild = thePlayer;
                    
                } else {
                    leftChild = 2 * matchNode - n + 1 + lowExt;
                    rightChild = leftChild + 1;
                }
            }
            
            tree[matchNode] = (player[leftChild] <= player[rightChild]) ? leftChild : rightChild;
            
            if (matchNode == n - 1 && n % 2 == 1) {
                matchNode /= 2;
                tree[matchNode] = (player[tree[n - 1]] <= player[lowExt + 1]) ?
                tree[n - 1] : lowExt + 1;
            }
            
            matchNode /= 2;
            
            for (; matchNode >= 1; matchNode /= 2) {
                tree[matchNode] = (player[tree[2 * matchNode]] <= player[tree[2 * matchNode + 1]]) ?
                tree[2 * matchNode] : tree[2 * matchNode + 1];
            }
        }
        
        
    private:
        
        int lowExt;//最底层外外部节点个数
        int offset;//2^log(n-1) - 1
        int* tree;//表示赢者树（完全二叉树）的数组
        int numberOfPlayers;//参赛者个数
        T* player;//参赛者数组
        
        
        void play(int p,int leftChild,int rightChild) {
            tree[p] = (player[leftChild] <= player[rightChild]) ? leftChild : rightChild;
            
            while (p % 2 == 1 && p > 1) {
                tree[p / 2] = (player[tree[p - 1]] <= player[tree[p]]) ?
                tree[p - 1] : tree[p];
                p /= 2;
            }
        }
        
    };
    
    
}

#endif /* CompleteWinnerTree_hpp */
