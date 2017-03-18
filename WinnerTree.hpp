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




#ifndef WinnerTree_hpp
#define WinnerTree_hpp

#include <stdio.h>

//为了方便计算机的实现，我们把赢者树限制为完全二叉树。
//有n个选手的一颗赢者树是一颗完全二叉树，它有n个外部节点和n-1个内部节点，每个内部节点记录在该节点比赛的赢者。


/*
 ADT
 
 实例：
 完全二叉树，每一个节点指向比赛的胜者。外部节点表示参赛者。
 
 操作：
 
 initialize（a）:为数组a的参赛者初始化为赢者树
 
 winner（）：返回锦标赛的胜者
 
 rePlay（i）：在参赛者i改变之后重赛
 
 */


namespace LWTL {
    
    template <typename T>
    class WinnerTree {
    public:
        
        ~WinnerTree () {};
        
        //将一个数组初始化为赢者树
        virtual void initialize (T* thePlayers,int theNumberOfPlayer) = 0;
        
        //返回锦标赛的胜者的索引
        virtual int winner() const = 0;
        
        //在参赛者i改变之后重赛
        virtual void rePlay(int thePlayer) = 0;
        
    };
}



#endif /* WinnerTree_hpp */
