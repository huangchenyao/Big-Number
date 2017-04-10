//
//  main.cpp
//  BigNum
//
//  Created by 黄琛垚 on 2017/4/9.
//  Copyright © 2017年 黄琛垚. All rights reserved.
//

#include <iostream>
#include "BigNum.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    clock_t start, finish;
    double duration;
    
    string tmp = "77777";
    
    BigNum a(67);
    BigNum b(tmp);
    cout << "a: " << a << endl << "b: " << b << endl;
    cout << "len of tmp: " << tmp.length() << endl;
    
    start = clock();
    BigNum c = a.pow_mod(b, 37);
    finish = clock();
    
    cout << "a ^ b mod 37 = " << c << endl;
    
    
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "用时：" << duration << 's' << endl;

    return 0;
}
