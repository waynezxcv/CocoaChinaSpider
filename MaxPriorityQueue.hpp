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





#ifndef MaxPriorityQueue_hpp
#define MaxPriorityQueue_hpp

#include <stdio.h>



/******************** 最大优先级队列 *******************/

//查找和删除元素都是优先级最大的元素


/*
 ADT
 
 确定队列是否为空
 确定队列元素个数
 返回优先级最大的元素
 删除优先级最大的元素
 插入元素
 
 */


namespace LWTL {
    
    template <typename T>
    class MaxPriorityQueue {
        
        virtual ~MaxPriorityQueue() {};
        
        virtual bool empty() const = 0;
        
        virtual int size() const = 0;
        
        virtual T& pop() = 0;
        
        virtual void erase() = 0;
        
        virtual void push(const T& theElement) = 0;
        
    };
    
    
}

#endif /* MaxPriorityQueue_hpp */
