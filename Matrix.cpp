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



#include "Matrix.hpp"


int main(int argc, const char * argv[]) {
    
    //一个不规则二维数组的创建和使用
    int numberOfRows = 5;
    //定义每一行的长度
    int length [5] = {6,3,4,2,7};
    
    
    /*
     irregularArray[0] : int[0],int[1],int[2],int[3],int[4],int[5]
     irregularArray[1] : int[0],int[1],int[2]
     irregularArray[2] : int[0],int[1],int[2],int[3]
     irregularArray[3] : int[0],int[1]
     irregularAraay[4] : int[0],int[1],int[2],int[3],int[4],int[5],int[6]
     
     */
    
    int** irregularArray = new int* [numberOfRows];
    
    for (int i = 0; i < numberOfRows; i ++) {
        irregularArray[i] = new int [length[i]];
    }
    
    
    return 0;
}
