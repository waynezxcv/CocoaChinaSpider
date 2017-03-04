//
//  Dictionary.hpp
//  DataStructures
//
//  Created by 刘微 on 2017/3/4.
//  Copyright © 2017年 刘微. All rights reserved.
//

#ifndef Dictionary_hpp
#define Dictionary_hpp

#include <stdio.h>

/******************** 字典 *******************/

/*
 ADT
 创建一个字典
 撤销一个字典
 确定字典是否为空
 确定字典数对个数
 返回关键字对应的值
 插入一个关键字对
 删除一个关键字对
 */


using namespace std;

namespace LWTL {
    
    template <typename K,typename E>
    
    class Dictionary {
        
        virtual ~Dictionary() {};
        
        virtual bool empty() const = 0;
        
        virtual int size() const = 0;
        
        virtual pair<const K,E>* find(const K&) const = 0;
        
        virtual void insert(const pair<const K,E>&) = 0;
        
        virtual void erase(const K&) = 0;
    };
    
}

#endif /* Dictionary_hpp */
