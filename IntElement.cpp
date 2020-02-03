#include "IntElement.h"
#include "SquareMatrix.h"


IntElement::IntElement(int v) {
    val = v;

}

int IntElement::getVal() const {
    return val;
}


void IntElement::setVal(int v) {
    val = v;
}


IntElement& IntElement::operator+=(const IntElement& i) {
    val += i.val;
    return *this;

}

IntElement& IntElement::operator-=(const IntElement& i) {
    val -= i.val;
    return *this;
}

IntElement& IntElement::operator*=(const IntElement& i) {
    val *= i.val;
    return *this;
}


bool IntElement::operator==(const IntElement& i) const {
   return val == i.val;
}



IntElement operator+(const IntElement& i1, const IntElement& i2) {
    IntElement tulos = i1;
    tulos += i2;
    return  tulos;
}

IntElement operator-(const IntElement& i1, const IntElement& i2) {
    IntElement tulos = i1;
    tulos -= i2;
    return  tulos;
}

IntElement operator*(const IntElement& i1, const IntElement& i2) {
    IntElement tulos = i1;
    tulos *= i2;
    return  tulos;
}

std::ostream& operator<<(std::ostream& os, const IntElement& i) {
    os << i.getVal();
    return os;

}
