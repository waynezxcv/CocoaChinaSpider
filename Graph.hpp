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



#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>


/*
 ADT
 实例:
 定点集合V和边集合E
 
 操作:
 numberOfVertices(); 返回图的定点数
 numberOfEdge(); 返回图的边数
 existsEdge(i,j) 如果边(i,j)存在返回true,否则false
 insertEdge(theEdge) 插入边
 eraseEdge(theEdge) 删除边
 degress(i) 返回定点i的度
 inDegress(i) 返回顶点i的入度
 outDegress(i) 返回顶点i的出度
 
 
 
 */

namespace LWTL {
    
    
    template<class T>
    class vertexIterator {
    public:
        virtual ~vertexIterator() {}
        virtual int next() = 0;
        virtual int next(T&) = 0;
    };
    
    
    
    template<typename T>
    class Edge {
        
    public:
        
        
        virtual ~Edge() {};
        
        virtual int vertex1() const = 0;//返回一个边的第一个顶点
        
        virtual int vertex2() const = 0;//返回一个边的第二个顶点
        
        virtual T weight() const = 0;//返回边的加权值
        
    private:
        
        
        
    };
    
    
    template<typename T>
    class Graph {
    public:
        virtual ~Graph() {};
        
        //ADT
        virtual int numberOfVertices() const = 0;
        
        virtual int numberOfEdges() const = 0;
        
        virtual bool existsEdge(int,int) const = 0;
        
        virtual void insertEdge(Edge<T>*) = 0;
        
        virtual void eraseEdge(int,int) = 0;
        
        virtual int degress(int) const = 0;
        
        virtual int inDegress(int)  const = 0;
        
        virtual int outDegress(int) const = 0;
        
        
        //其他方法
        
        virtual bool directed() const = 0;//当是有向图时返回ture,否则false
        
        virtual bool weighted() const = 0;//当是加权图时返回ture,否则false
        
        virtual vertexIterator<T>* iterator(int) = 0;//访问指定顶点的相邻顶点
        
    };
}

#endif /* Graph_hpp */
