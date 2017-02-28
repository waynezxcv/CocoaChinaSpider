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

#include "TowersOfHanoi.hpp"


using namespace LWTL;


void TowersOfHanoi::start() {
    move(count, 1, 2, 3);
}


void TowersOfHanoi::move(int n, int x, int y, int z) {
    
    if (n > 0) {
        move(n-1, x, z, y);
        int d = towers[x].top();
        towers[x].pop();
        towers[y].push(d);
        move(n-1, z, y, x);
        
    }
}

void TowersOfHanoi::show() {
    ArrayStack<int> tower1 = towers[1];
    printf("tower1 :\n");
    tower1.show();
    
    ArrayStack<int> tower2 = towers[2];
    printf("tower2 :\n");
    tower2.show();
    
    ArrayStack<int> tower3 = towers[3];
    printf("tower3 :\n");
    tower3.show();
}
