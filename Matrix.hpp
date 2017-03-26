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




#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include "IllegalParameterValue.hpp"


namespace LWTL {
    /*
     数组
     
     ADT
     实例:
     形如(index,value)的数对结合,任意两个数对的索引都不同
     操作:
     get(index),返回索引为index的数对中的值
     set(index,value),加入一个新数对,若数对索引已存在,则用新数对覆盖
     */
    
    
    //行主映射, map(i1,i2) = i1 * u2 + u2
    //列主映射
    
    
    template <typename T>
    class Array {
    public:
        
        ~Array() {};
        
        virtual void set(const int& index,const T& value) = 0;
        
        virtual T& get(const int& index) = 0;
    };
    
    
    /********************* 矩阵 ********************************/
    /*
     一个M * N的矩阵是一个M行,N列的表,M和N是矩阵的维数.
     
     矩阵的常见操作:
     矩阵的转置:M是一个m * n的矩阵,转置后得到MT是一个n*m的矩阵
     
     
     矩阵相加:仅当两个矩阵的维数相同时,才能相加.C(i,j) = A(i,j) + B(i,j)
     
     矩阵相乘:一个m * n的矩阵A和一个p * q的矩阵B,只有A的列数等于B的行数即n = p时,才可以相乘.
     A*B的结果是一个m * p 的矩阵 C:
     C(i,j) = A(i,1) * B (1,j) + A(i,2) * B (2,j) + .... + A(i,k) * B (k,j)
     
     
     */
    
    
    
    //用一个行主次序的一位数组T* elements来存储矩阵.
    
    template <typename T>
    class Matrix {
    public:
        
        //构造函数(行,列)
        Matrix(int theRow = 0,int theColumns = 0);
        
        //拷贝构造函数
        Matrix(const Matrix<T>& rhs);
        
        //析构函数
        ~Matrix() {
            delete [] elements;
        }
        
        //Getter
        int rows() const {
            return theRows;
        }
        
        int columns() const {
            return theColumns;
        }
        
        //重载类运算符 返回(i,j)对应元素的值
        T& operator() (int i,int j) const;
        
        //拷贝赋值运算符
        Matrix<T>& operator = (const Matrix<T>& rhs);
        
        //两个矩阵相加
        Matrix<T> operator + (const Matrix<T>& theMatrix) const;
        
        
        //两个矩阵相减
        Matrix<T> operator - (const Matrix<T>& theMatrix) const;
        
        
        //两个矩阵相乘
        Matrix<T> operator * (const Matrix<T>& theMatrix) const ;
        
    private:
        int theRows;
        int theColumns;
        T* elements;
    };
    
    
    template <typename T>
    Matrix<T>::Matrix(int theRow,int theColumn) {
        
        if (theRow < 0 || theColumn < 0) {
            throw IllegalParameterValue("the row and the column must be >= 0 ");
        }
        
        if ((theRow == 0 || theColumn == 0 ) &&(theRow != 0 || theColumn != 0)) {
            //行列不能同时为0
            throw IllegalParameterValue("either both or neither rows and columns should be 0");
        }
        
        theRows = theRow;
        theColumns = theColumn;
        T* elements = new T [theRows * theColumns];
    };
    
    //拷贝构造函数
    template <typename T>
    Matrix<T>::Matrix(const Matrix<T>& rhs) {
        theRows = rhs.theRows;
        theColumns = rhs.theColumns;
        elements = new T [theRows * theColumns];
        memset(elements, 0 , sizeof(T) * theRows * theColumns);
        memcpy(elements, rhs.elments, sizeof(T) * theRows * theColumns);
    };
    
    template <typename T>
    Matrix<T>& Matrix<T>::operator=(const Matrix<T> &rhs) {
        if (this == &rhs) {
            return *this;
        }
        
        theRows = rhs.theRows;
        theColumns = rhs.theColumns;
        
        delete [] elements;
        elements = new T[theRows * theColumns];
        memset(elements, 0,sizeof(T) * theRows * theColumns);
        memcpy(elements, rhs.elements, sizeof(T) * theRows * theColumns);
        return *this;
    }
    
    template <typename T>
    T& Matrix<T>::operator() (int i,int j)const {
        if (i < 1 || i > theRows || j < 1 || j > theColumns) {
            throw IllegalParameterValue("the matrix index out of bounds");
        }
        
        return elements[(i - 1) * theColumns + (j -1)];
    }
    
    
    template <typename T>
    Matrix<T> Matrix<T>::operator+(const Matrix<T> &theMatrix) const {
        if (theRows != theMatrix.theRows || theColumns != theMatrix.theColumns) {
            throw IllegalParameterValue("can't add a diffrent size matrix");
        }
        
        Matrix<T> theNewOne (theRows,theColumns);
        
        for (int i = 0; i < theRows * theColumns; i ++) {
            theNewOne.elements[i] = elements[i] + theMatrix.elements[i];
        }
        return theNewOne;
    }
    
    
    template <typename T>
    Matrix<T> Matrix<T>:: operator-(const Matrix<T> &theMatrix) const {
        if (theRows != theMatrix.theRows || theColumns != theMatrix.theColumns) {
            throw IllegalParameterValue("can't minute a difrrent size matrix");
        }
        
        Matrix<T> theNewOne (theRows,theColumns);
        
        for (int i = 0; i < theRows * theColumns; i ++) {
            theNewOne.elements[i] = elements[i] - theMatrix.elements[i];
        }
        return theNewOne;
    }
    
    /*
     矩阵相乘:一个m * n的矩阵A和一个p * q的矩阵B,只有A的列数等于B的行数即n = p时,才可以相乘.
     A*B的结果是一个m * p 的矩阵 C:
     C(i,j) = A(i,1) * B (1,j) + A(i,2) * B (2,j) + .... + A(i,k) * B (k,j)
     */
    
    template <typename T>
    Matrix<T> Matrix<T>::operator*(const Matrix<T> &theMatrix) const {
        
        if (theColumns != theMatrix.theRows) {
            throw IllegalParameterValue("matrix size mismatch");
        }
        
        Matrix<T> theNewOne = Matrix<T> (theRows,theMatrix.theColumns) ;
        
        int ct = 0,cm = 0,cw = 0;
        
        //对所有i和j计算w(i,j)
        
        
        //计算结果矩阵的第i行
        for (int i = 1; i <= theRows; i ++) {
            
            
            //计算theNewOne(i,j)第一项
            for (int j = 1; j <= theMatrix.theColumns; i ++) {
                
                T sum = elements[ct] * theMatrix.elements[cm];
                
                //累加其余所有项
                for (int k = 2; k <= theColumns; k ++) {
                    ct ++;
                    cm += theMatrix.theColumns;
                    sum += elements[ct] * theMatrix.elements[cm];
                }
                theNewOne.elements[cw ++] = sum;
                
                ct -= theColumns - 1;
                cm = j;
                
            }
            
            ct += theColumns;
            cm = 0;
        }
        return theNewOne;
    }
}





#endif /* Matrix_hpp */
