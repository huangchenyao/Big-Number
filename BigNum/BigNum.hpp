//
//  BigNum.hpp
//  BigNum
//
//  Created by 黄琛垚 on 2017/4/9.
//  Copyright © 2017年 黄琛垚. All rights reserved.
//

#ifndef BigNum_hpp
#define BigNum_hpp

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define MAX 2500 // 10000进制，每个int保存4位10进制数，4*2500总共10000位

class BigNum {
private:
    int num[MAX];
    int len; // 当前位数
    bool neg; // 符号，是否负数
    
public:
    BigNum();
    BigNum(const int);
    BigNum(const char *);
    BigNum(const string);
    BigNum(const BigNum &);
    ~BigNum();
    
    // 重载输入输出
    friend istream & operator >> (istream &, BigNum &);
    friend ostream & operator << (ostream &, BigNum &);
    // 转化为字符串
    void toString(char *) const;
    void toString(string &) const;
    // 赋值操作符
    BigNum & operator = (const BigNum &);
    BigNum & operator = (const int &);
    
    // 求绝对值
    BigNum abso() const;
    // 进制转换，用来快速幂
//    void conversion(char *, long, long) const;
    // 右移1位
    BigNum right1() const;
    
    // 重载四则运算，取模，幂运算
    // BigNum与BigNum进行运算
    BigNum operator + (const BigNum &) const;
    BigNum operator - (const BigNum &) const;
    BigNum operator * (const BigNum &) const;
    BigNum operator / (const BigNum &) const;
    BigNum operator % (const BigNum &) const;
    BigNum operator ^ (const BigNum &) const;
    BigNum operator += (const BigNum &);
    BigNum operator -= (const BigNum &);
    BigNum operator *= (const BigNum &);
    BigNum operator /= (const BigNum &);
    BigNum operator %= (const BigNum &);
    BigNum operator ^= (const BigNum &);
    // BigNum与int进行运算
    BigNum operator + (const int &) const;
    BigNum operator - (const int &) const;
    BigNum operator * (const int &) const;
    BigNum operator / (const int &) const;
    BigNum operator % (const int &) const;
    BigNum operator ^ (const int &) const;
    BigNum operator += (const int &);
    BigNum operator -= (const int &);
    BigNum operator *= (const int &);
    BigNum operator /= (const int &);
    BigNum operator %= (const int &);
    BigNum operator ^= (const int &);
    //    // int与BigNum进行运算
    //    friend BigNum operator + (const int &, const BigNum &);
    //    friend BigNum operator - (const int &, const BigNum &);
    //    friend BigNum operator * (const int &, const BigNum &);
    //    friend BigNum operator / (const int &, const BigNum &);
    //    friend BigNum operator % (const int &, const BigNum &);
    //    friend BigNum operator ^ (const int &, const BigNum &);
    //    friend BigNum operator += (const int &, const BigNum &);
    //    friend BigNum operator -= (const int &, const BigNum &);
    //    friend BigNum operator *= (const int &, const BigNum &);
    //    friend BigNum operator /= (const int &, const BigNum &);
    //    friend BigNum operator %= (const int &, const BigNum &);
    //    friend BigNum operator ^= (const int &, const BigNum &);
    // 快速幂取模
    BigNum pow_mod(const BigNum &, const BigNum &) const;
    BigNum pow_mod(const BigNum &, const int &) const;
    BigNum pow_mod(const int &, const BigNum &) const;
    BigNum pow_mod(const int &, const int &) const;
    
    // 自增自减
    BigNum operator ++ (); // 前缀
    BigNum operator ++ (int); // 后缀
    BigNum operator -- (); // 前缀
    BigNum operator -- (int); // 后缀
    
    // 比较
    // BigNum与BigNum进行比较
    bool operator < (const BigNum &) const;
    bool operator > (const BigNum &) const;
    bool operator <= (const BigNum &) const;
    bool operator >= (const BigNum &) const;
    bool operator == (const BigNum &) const;
    bool operator != (const BigNum &) const;
    // BigNum与int进行比较
    bool operator < (const int &) const;
    bool operator > (const int &) const;
    bool operator <= (const int &) const;
    bool operator >= (const int &) const;
    bool operator == (const int &) const;
    bool operator != (const int &) const;
    // int与BigNum进行比较
    friend bool operator < (const int &, const BigNum &);
    friend bool operator > (const int &, const BigNum &);
    friend bool operator <= (const int &, const BigNum &);
    friend bool operator >= (const int &, const BigNum &);
    friend bool operator == (const int &, const BigNum &);
    friend bool operator != (const int &, const BigNum &);
    
};

#endif /* BigNum_hpp */
