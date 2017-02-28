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


#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>


/******************** 队列 *******************/

/*
 ADT
 创建一个队列
 撤销一个队列
 确定队列是否为空
 确定队列长度
 确定队首的元素front
 确定队尾的元素back
 添加一个元素到队列队尾
 从队列队首删除一个元素
 */




namespace LWTL {
    
    template <typename T>
    
    class Queue {
    public:
        
        virtual ~Queue() {};
        
        virtual bool empty() const = 0;
        
        virtual int size() const = 0;
        
        virtual T& front() const = 0;
        
        virtual T& back() const = 0;
        
        virtual void push(const T& t) = 0;
        
        virtual void pop() = 0;
    };
}

#endif /* Queue_hpp */
