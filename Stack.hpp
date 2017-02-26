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


#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>


/******************** 栈 *******************/

/*
 ADT
 创建一个线性表
 撤销一个线性表
 确定线性表是否为空
 确定线性表长度
 确定栈顶的元素
 入栈
 出栈
 
 */

namespace LWTL {
    
    //栈抽象类
    
    template <typename T>
    
    class Stack {
        
    public:
        
        virtual ~Stack() {};
        
        virtual bool empty() const = 0;//判断是否为空
        
        virtual int size() const = 0;//获取栈的长度
        
        virtual T& top() const = 0;//返回栈顶的元素
        
        virtual void push(const T& theElement) = 0;//入栈
        
        virtual void pop() = 0;//出栈
        
    };
    
}


#endif /* Stack_hpp */
