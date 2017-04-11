//
//  BigNum.cpp
//  BigNum
//
//  Created by 黄琛垚 on 2017/4/9.
//  Copyright © 2017年 黄琛垚. All rights reserved.
//

#include "BigNum.hpp"

// default
BigNum::BigNum() {
    this->len = 0;
    this->neg = false;
    memset(this->num, 0, sizeof(this->num));
}

// int2bn
BigNum::BigNum(const int num) {
    this->neg = (num < 0);
    this->len = 0;
    memset(this->num, 0, sizeof(this->num));
    if (num == 0) {
        this->num[0] = 0;
        this->len = 1;
    }
    for (int tmp = abs(num); tmp != 0; ++this->len, tmp /= 10000) {
        this->num[this->len] = tmp % 10000;
    }
}

// char*2bn
BigNum::BigNum(const char *str) {
    this->len = 0;
    memset(this->num, 0, sizeof(this->num));
    // 字符串为空时，赋值为0
    if (strlen(str) == 0) {
        this->len = 1;
        this->neg = false;
        // 默认初始化为0
        this->num[0] = 0;
    } else {
        this->neg = (str[0] == '-');
        int len = (int)strlen(str);
        for (int i = len - 1, weight = 1; i >= this->neg; --i, weight *= 10) {
            if (weight == 10000) {
                weight = 1;
                ++this->len;
            }
            this->num[this->len] += ((str[i] - '0') * weight);
        }
        ++this->len;
    }
}

// string2bn
BigNum::BigNum(const string str) {
    this->len = 0;
    memset(this->num, 0, sizeof(this->num));
    // 字符串为空时，赋值为0
    if (str.length() == 0) {
        this->len = 1;
        this->neg = false;
        // 默认初始化为0
        this->num[0] = 0;
    } else {
        this->neg = (str[0] == '-');
        int len = (int)str.length();
        for (int i = len - 1, weight = 1; i >= this->neg; --i, weight *= 10) {
            if (weight == 10000) {
                weight = 1;
                ++this->len;
            }
            this->num[this->len] += ((str[i] - '0') * weight);
        }
        ++this->len;
    }
}

// bn2bn
BigNum::BigNum(const BigNum &bn) {
    this->len = 0;
    memset(this->num, 0, sizeof(this->num));
    this->len = bn.len;
    this->neg = bn.neg;
    for (int i = 0; i < bn.len; ++i) {
        this->num[i] = bn.num[i];
    }
}

// ~function
BigNum::~BigNum() {
    
}

// overload input operator
istream & operator >> (istream & is, BigNum &bn) {
    
    return is;
}

// overload output operator
ostream & operator << (ostream & os, BigNum &bn) {
    if (bn.neg == true) {
        os << '-';
    }
    os << bn.num[bn.len - 1];
    for (int i = bn.len - 2; i >= 0; --i) {
        os.width(4);
        os.fill('0');
        os << bn.num[i];
    }
    return os;
}

// 转化为字符串
void BigNum::toString(char *str) const {
    int len = 0;
    BigNum bn = (*this);
    if (bn.neg == true) {
        str[len++] = '-';
    }
    if (bn.num[bn.len - 1] / 1000) {
        str[len++] = (bn.num[bn.len - 1] / 1000 + '0');
    }
    if (bn.num[bn.len - 1] % 1000 / 100) {
        str[len++] = (bn.num[bn.len - 1] % 1000 / 100 + '0');
    }
    if (bn.num[bn.len - 1] % 100 / 10) {
        str[len++] = (bn.num[bn.len - 1] % 100 / 10 + '0');
    }
    if (bn.num[bn.len - 1] % 10 / 1) {
        str[len++] = (bn.num[bn.len - 1] % 10 / 1 + '0');
    }
    for (int i = bn.len - 2; i >= 0; --i) {
        str[len++] = (bn.num[i] / 1000 + '0');
        str[len++] = (bn.num[i] % 1000 / 100 + '0');
        str[len++] = (bn.num[i] % 100 / 10 + '0');
        str[len++] = (bn.num[i] % 10 / 1 + '0');
    }
    str[len++] = '\0';
}

void BigNum::toString(string &str) const {
    str = "";
    BigNum bn = (*this);
    if (bn.neg == true) {
        str += '-';
    }
    if (bn.num[bn.len - 1] / 1000) {
        str += (bn.num[bn.len - 1] / 1000 + '0');
    }
    if (bn.num[bn.len - 1] % 1000 / 100) {
        str += (bn.num[bn.len - 1] % 1000 / 100 + '0');
    }
    if (bn.num[bn.len - 1] % 100 / 10) {
        str += (bn.num[bn.len - 1] % 100 / 10 + '0');
    }
    if (bn.num[bn.len - 1] % 10 / 1) {
        str += (bn.num[bn.len - 1] % 10 / 1 + '0');
    }
    for (int i = bn.len - 2; i >= 0; --i) {
        str += (bn.num[i] / 1000 + '0');
        str += (bn.num[i] % 1000 / 100 + '0');
        str += (bn.num[i] % 100 / 10 + '0');
        str += (bn.num[i] % 10 / 1 + '0');
    }
}

// overload assignment operator bn
BigNum & BigNum::operator = (const BigNum &bn) {
    this->len = 0;
    memset(this->num, 0, sizeof(this->num));
    this->len = bn.len;
    this->neg = bn.neg;
    for (int i = 0; i < bn.len; ++i) {
        this->num[i] = bn.num[i];
    }
    return (*this);
}

// overload assignment operator int
BigNum & BigNum::operator = (const int &bn) {
    (*this) = BigNum(bn);
    return (*this);
}

// absolute
BigNum BigNum::abso() const {
    BigNum res((*this));
    res.neg = false;
    return res;
}

//// 进制转换
//void BigNum::conversion(char * con, long d1 = 10, long d2 = 2) const {
//    if (d1 == 10 && d2 == 2) {
//        BigNum num = (*this);
//        for (int i = 0; num != 0; ++i) {
//            con[i] = (num % 2 != 0) + '0';
//            num /= 2;
//        }
//        //        for (int i = 0, len = (int)strlen(con) - 1; i < len / 2; ++i) {
//        //            char tmp = con[i];
//        //            con[i] = con[len - i];
//        //            con[len - i] = tmp;
//        //        }
//    } else {
//        cout << "no" << endl;
//    }
//}

// 右移1位
BigNum BigNum::right1() const {
    BigNum res = (*this);
    for (int i = res.len - 1; i > 0; --i) {
        res.num[i - 1] += 10000 * (res.num[i] & 1);
        res.num[i] >>= 1;
    }
    res.num[0] >>= 1;
    // 清除高位的0
    for (int i = res.len - 1; i > 0 && res.num[i] == 0; --i) {
        --res.len;
    }
    return res;
}

// BigNum with BigNum
// overload add operator bn
BigNum BigNum::operator + (const BigNum & bn) const {
    BigNum res;
    if (this->neg == bn.neg) {
        res.neg = this->neg;
        int len = this->len > bn.len? this->len: bn.len;
        int carry = 0;
        for (int i = 0; i < len; ++i, ++res.len) {
            res.num[i] = this->num[i] + bn.num[i] + carry;
            if (res.num[i] >= 10000) {
                res.num[i] -= 10000;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        if (carry) {
            res.num[res.len++] += carry;
        }
    } else if (!this->neg && bn.neg) {
        res = (*this) - bn.abso();
    } else {
        res = bn - (*this).abso();
    }
    return res;
}

// overload sub operator bn
BigNum BigNum::operator - (const BigNum & bn) const {
    BigNum res;
    // 同号时
    if (this->neg == bn.neg) {
        res.neg = this->neg;
        int len = this->len > bn.len? this->len: bn.len;
        int carry = 0;
        // 被减数绝对值大于减数绝对值时，直接相减
        if ((*this).abso() >= bn.abso()) {
            for (int i = 0; i < len; ++i, ++res.len) {
                res.num[i] = this->num[i] - bn.num[i] - carry;
                
                if ((int)res.num[i] < 0) {
                    res.num[i] += 10000;
                    carry = 1;
                } else {
                    carry = 0;
                }            }
            // 清除高位的0
            for (int i = res.len - 1; i > 0 && res.num[i] == 0; --i) {
                --res.len;
            }
        } else { // 减数绝对值大于被减数绝对值，用减数减去被减数再取负
            res = bn - (*this);
            res.neg = !res.neg;
        }
    } else if (!this->neg && bn.neg) {
        res = (*this) + bn.abso();
    } else {
        res = (*this).abso() + bn;
        res.neg = true;
    }
    return res;
}

// overload mult operator bn
BigNum BigNum::operator * (const BigNum & bn) const {
    BigNum res;
    if ((*this) == 0 || bn == 0) {
        res = 0;
        return res;
    }
    res.neg = this->neg ^ bn.neg;
    for (int i = 0; i < this->len; ++i) {
        for (int j = 0; j < bn.len; ++j) {
            res.num[i + j] += this->num[i] * bn.num[j];
        }
        for (int k = 0; k < this->len + bn.len; ++k) {
            if (res.num[k] >= 10000) {
                res.num[k + 1] += res.num[k] / 10000;
                res.num[k] %= 10000;
            }
        }
    }
    int i;
    for (i = this->len + bn.len - 1; res.num[i] == 0; --i);
    for (; i >= 0; --i, ++res.len);
    return res;
}


// overload div operator bn
BigNum BigNum::operator / (const BigNum &bn) const {
    if (bn == 0) {
        cout << "除数不能为0！" << endl;
        return BigNum(0);
    }
    if (this->abso() < bn.abso()) {
        return BigNum(0);
    }
    
    BigNum ten(1);
    int len = this->len - bn.len;
    for (int i = 0; i < len; ++i) {
        ten *= 10000;
    }
    
    BigNum res;
    res.neg = this->neg ^ bn.neg;
    
    BigNum tmp = this->abso();
    BigNum abs_bn = bn.abso();
    while (ten.len) {
        int low = 0, high = 9999, mid = 0;
        while (low <= high) {
            mid = (low + high) / 2;
            if (ten * mid * abs_bn == tmp || (ten * mid * abs_bn < tmp && ten * (mid + 1) * abs_bn > tmp)) {
                break;
            } else if (ten * mid * abs_bn < tmp) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        tmp -= ten * mid * abs_bn;
        res.num[ten.len - 1] = mid;
        ++res.len;
        ten.num[ten.len - 1] = 0;
        --ten.len;
        if (ten.len) {
            ten.num[ten.len - 1] = 1;
        }
    }
    
    // 清除高位的0
    for (int i = res.len - 1; i > 0 && res.num[i] == 0; --i) {
        --res.len;
    }
    
    return res;
}

// overload mod operator bn
BigNum BigNum::operator % (const BigNum & bn) const {
    if (bn == 0) {
        cout << "除数不能为0！" << endl;
        return BigNum(0);
    }
    
    BigNum ten(1);
    int len = this->len - bn.len;
    for (int i = 0; i < len; ++i) {
        ten *= 10000;
    }
    
    BigNum tmp = this->abso();
    BigNum abs_bn = bn.abso();
    while (ten.len) {
        int low = 0, high = 9999, mid = 0;
        while (low <= high) {
            mid = (low + high) / 2;
            if (ten * mid * abs_bn == tmp || (ten * mid * abs_bn < tmp && ten * (mid + 1) * abs_bn > tmp)) {
                break;
            } else if (ten * mid * abs_bn < tmp) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        tmp -= ten * mid * abs_bn;
        ten.num[ten.len - 1] = 0;
        --ten.len;
        if (ten.len) {
            ten.num[ten.len - 1] = 1;
        }
    }
    
    return tmp;
}

// overload pow operator bn
BigNum BigNum::operator ^ (const BigNum &bn) const {
    BigNum res(1), base = (*this);
    
    for (BigNum p = bn; p != 0; p = p.right1()) {
        if (p.num[0] & 1) {
            res = base * res;
        }
        base = base * base;
    }
    
    return res;
}

// overload add equal operator bn
BigNum BigNum::operator += (const BigNum &bn) {
    (*this) = (*this) + bn;
    return (*this);
}

// overload sub equal operator bn
BigNum BigNum::operator -= (const BigNum &bn) {
    (*this) = (*this) - bn;
    return (*this);
}

// overload mult equal operator bn
BigNum BigNum::operator *= (const BigNum &bn) {
    (*this) = (*this) * bn;
    return (*this);
}

// overload div equal operator bn
BigNum BigNum::operator /= (const BigNum &bn) {
    (*this) = (*this) / bn;
    return (*this);
}

// overload mod equal operator bn
BigNum BigNum::operator %= (const BigNum &bn) {
    (*this) = (*this) % bn;
    return (*this);
}

// overload pow equal operator bn
BigNum BigNum::operator ^= (const BigNum &bn) {
    (*this) = (*this) ^ bn;
    return (*this);
}

// BigNum with int
// overload add operator int
BigNum BigNum::operator + (const int &n) const {
    BigNum res = (*this);
    return res + BigNum(n);
}

// overload sub operator int
BigNum BigNum::operator - (const int &n) const {
    BigNum res = (*this);
    return res - BigNum(n);
}

// overload mult operator int
BigNum BigNum::operator * (const int &n) const {
    BigNum res = (*this);
    return res * BigNum(n);
}

// overload div operator int
BigNum BigNum::operator / (const int &n) const {
    BigNum res = (*this);
    return res / BigNum(n);
}

// overload mod operator int
BigNum BigNum::operator % (const int &n) const {
    BigNum res = (*this);
    return res % BigNum(n);
}

// overload pow operator int
BigNum BigNum::operator ^ (const int &n) const {
    BigNum res = (*this);
    return res ^ BigNum(n);
}

// overload add equal operator int
BigNum BigNum::operator += (const int &n) {
    (*this) = (*this) + n;
    return (*this);
}

// overload sub equal operator bn
BigNum BigNum::operator -= (const int &n) {
    (*this) = (*this) - n;
    return (*this);
}

// overload mult equal operator bn
BigNum BigNum::operator *= (const int &n) {
    (*this) = (*this) * n;
    return (*this);
}

// overload div equal operator bn
BigNum BigNum::operator /= (const int &n) {
    (*this) = (*this) / n;
    return (*this);
}

// overload mod equal operator bn
BigNum BigNum::operator %= (const int &n) {
    (*this) = (*this) % n;
    return (*this);
}

// overload pow equal operator bn
BigNum BigNum::operator ^= (const int &n) {
    (*this) = (*this) ^ n;
    return (*this);
}

BigNum BigNum::pow_mod(const BigNum &pow, const BigNum &mod) const {
    BigNum res(1), base = (*this) % mod;
    
    for (BigNum p = pow; p != 0; p = p.right1()) {
        if (p.num[0] & 1) {
            res = (base * res) % mod;
        }
        base = (base * base) % mod;
    }
    
    return res;
}

BigNum BigNum::pow_mod(const BigNum & pow, const int & mod) const {
    return this->pow_mod(pow, BigNum(mod));
}

BigNum BigNum::pow_mod(const int & pow, const BigNum & mod) const {
    return this->pow_mod(BigNum(pow), mod);
}

BigNum BigNum::pow_mod(const int & pow, const int & mod) const {
    return this->pow_mod(BigNum(pow), BigNum(mod));
}

// 自增前缀
BigNum BigNum::operator ++ () {
    (*this) += 1;
    return (*this);
}
// 自增后缀
BigNum BigNum::operator ++ (int) {
    BigNum res = (*this);
    (*this) += 1;
    return res;
}
// 自减前缀
BigNum BigNum::operator -- () {
    (*this) -= 1;
    return (*this);
}
// 自减后缀
BigNum BigNum::operator -- (int) {
    BigNum res = (*this);
    (*this) -= 1;
    return res;
}

// compare function
// overload less than operator bn
bool BigNum::operator < (const BigNum &bn) const {
    // 同号
    if (this->neg == bn.neg) {
        // 都为负数时
        if (this->neg == true) {
            if (this->len > bn.len) {
                return true;
            } else if (this->len < bn.len) {
                return false;
            } else {
                // 位数相同时
                for (int i = this->len - 1; i >= 0; --i) {
                    if (this->num[i] > bn.num[i]) {
                        return true;
                    } else if (this->num[i] < bn.num[i]) {
                        return false;
                    }
                }
            }
        } else { // 都为正数时
            if (this->len < bn.len) {
                return true;
            } else if (this->len > bn.len) {
                return false;
            } else {
                // 位数相同时
                for (int i = this->len - 1; i >= 0; --i) {
                    if (this->num[i] < bn.num[i]) {
                        return true;
                    } else if (this->num[i] > bn.num[i]) {
                        return false;
                    }
                }
            }
        }
    } else { // 异号
        if (this->neg) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

// overload greater than operator bn
bool BigNum::operator > (const BigNum &bn) const {
    return !((*this) < bn) && !((*this) == bn);
}

// overload less than or equal to operator bn
bool BigNum::operator <= (const BigNum &bn) const {
    return ((*this) < bn) || ((*this) == bn);
}

// overload greater than or equal to operator bn
bool BigNum::operator >= (const BigNum &bn) const {
    return !((*this) < bn);
}

// overload equal to operator bn
bool BigNum::operator == (const BigNum &bn) const {
    if (this->neg == bn.neg && this->len == bn.len) {
        for (int i = 0; i < this->len; ++i) {
            if (this->num[i] != bn.num[i]) {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

// overload not equal to operator bn
bool BigNum::operator != (const BigNum &bn) const {
    return !((*this) == bn);
}

// overload less than operator int
bool BigNum::operator < (const int &num) const {
    return (*this) < BigNum(num);
}

// overload greater than operator int
bool BigNum::operator > (const int &num) const {
    return (*this) > BigNum(num);
}

// overload less than or equal to operator int
bool BigNum::operator <= (const int &num) const {
    return (*this) <= BigNum(num);
}

// overload greater than or equal to operator int
bool BigNum::operator >= (const int &num) const {
    return (*this) >= BigNum(num);
}

// overload equal to operator int
bool BigNum::operator == (const int &num) const {
    return (*this) == BigNum(num);
}

// overload not equal to operator int
bool BigNum::operator != (const int &num) const {
    return (*this) != BigNum(num);
}
