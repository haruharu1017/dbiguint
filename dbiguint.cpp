#include "dbiguint.h"

#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

dbiguint::dbiguint():data_(nullptr),capacity_(0){};
dbiguint::dbiguint(const string & s):data_(nullptr),capacity_(0)
{
    unsigned short *temp = new unsigned short[capacity_+1];
    int num = stoi(s);
    while(num > 0)
    {
        temp[capacity_] = num%10;
        num /= 10;
        capacity_++;
    }
    delete[] data_;
    data_ = temp;
};

dbiguint::~dbiguint()
{
    delete [] data_;
}

int dbiguint::size() const
{
    return capacity_;
}

unsigned short dbiguint::operator[](int pos) const
{
    return data_[pos];
}

void dbiguint::reserve(int newcapacity)
{
    if (newcapacity > capacity_)
    {
        capacity_ = newcapacity;
    }
}

void dbiguint::operator+=(const dbiguint &b)
{
    for (int i = 0; i < capacity_; i++)
    {
        if (data_[i] + b[i] < 10)
        data_[i] += b[i];
        else
        {
            data_[i+1]++;
            data_[i] = (data_[i] + b[i]) % 10;
        }
    }
}

ostream & operator << (ostream & out, const dbiguint & b)
{
    for(int i = 0; i < b.size();i++)
    { out << b[i] << " "; }
    return out;
}

#include <iostream>

int main()
{
    dbiguint b("1235");
    dbiguint d("3399");
    cout << b << endl;
    b += d;
    cout << b << endl;
    return 0;
}