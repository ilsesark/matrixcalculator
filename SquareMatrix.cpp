#include <sstream>
#include "SquareMatrix.h"
#include <string>
#include <ostream>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <random>
#include <thread>
#include <functional>
#include <numeric>
#include <chrono>
#include <algorithm>
#include "IntElement.h"


SquareMatrix::SquareMatrix(const std::string& s) {

    n = 0;

    std::stringstream ss;
    ss << s;

    int num;
    char c;
    int dim = -1;
    int rivit = 0;
    int sarakkeet = 0;

    if (s == "[[]]")
        return;


    ss >> c;

    if (c != '[')
        throw std::invalid_argument("Invalid init string");

    ss >> c;

    while (c != ']') {
        //lue rivi kerrallaan
        std::vector<IntElement> rowvec;
        if (c != '[')
            throw std::invalid_argument("Invalid init string");
        sarakkeet = 0;

        do {

            ss >> num;

            if(!ss.good())
                throw std::invalid_argument("Invalid init string");

            ss>> c;

            if(c != ',' && c != ']')
                throw std::invalid_argument("Invalid init string");

            sarakkeet++;

            rowvec.push_back(num);

        } while (c != ']');


        if(rivit == 0) {
            dim = sarakkeet;
        } else if(sarakkeet != dim){
            throw std::invalid_argument("Invalid init string");
        }

        elements.push_back(rowvec);

        ss >> c;

        rivit++;

    }
    if (rivit != dim)
        throw std::invalid_argument("Invalid init string");
    if(!ss.good())
        throw std::invalid_argument("Invalid init string");

    std::string loppu;

    ss >> loppu;

    if(loppu != "")
        throw std::invalid_argument("Invalid init string");

    n = rivit;

    return;

}

SquareMatrix::SquareMatrix(const SquareMatrix& m) {
    elements = m.elements;
    n = m.n;
}


SquareMatrix& SquareMatrix::operator=(const SquareMatrix& m) {
        if (n != m.n) {
            throw std::invalid_argument("Invalid init string");
        }
        auto m_rivi = m.elements.begin();

        for (auto& rivi : elements) {

            auto m_elem = m_rivi->begin();

            for(auto& elem : rivi) {
                elem = *m_elem;
                m_elem++;
            }

            m_rivi++;
        }

        return *this;
        
}

//Returns the transpose of this matrix
SquareMatrix SquareMatrix::transpose() const{
    SquareMatrix sq;
    sq.n = n;
    sq.elements = std::vector<std::vector<IntElement>>(n);

    for(auto row = elements.begin(); row != elements.end(); row++) {
        auto trans_row = sq.elements.begin();
        for(auto elem = row->begin(); elem != row->end(); elem++) {
            trans_row->push_back(*elem);
            trans_row++;

        }
    }

    return sq;

}

SquareMatrix& SquareMatrix::operator+=(const SquareMatrix& m) {
    if (n != m.n) {
        throw std::invalid_argument("Invalid init string");
    }
    std::vector<std::thread> threads;
    for(int i= 0; i <n; i++) {
        //subVectorsplus(elements[i], m.elements[i]);
        threads.push_back(std::thread(subVectorsplus, std::ref(elements[i]), std::ref(m.elements[i])));
    }

    for(auto& tr:threads) {
        tr.join();
    }
    return *this;

}

void subVectorsplus(std::vector<IntElement>& vec1, const std::vector<IntElement>& vec2) {
    auto iter = vec2.begin();
    for (auto& elem : vec1) {
        elem += *iter;
        iter++;
    }
}

SquareMatrix& SquareMatrix::operator-=(const SquareMatrix& m) {

    if (n != m.n) {
        throw std::invalid_argument("Invalid init string");
    }
    std::vector<std::thread> threads;
    for(int i= 0; i <n; i++) {
        //nothreads
        //subVectorsminus(elements[i], m.elements[i]);
        threads.push_back(std::thread(subVectorsminus, std::ref(elements[i]), std::ref(m.elements[i])));
    }

    for(auto& tr:threads) {
        tr.join();
    }
    return *this;
}

void subVectorsminus(std::vector<IntElement>& vec1, const std::vector<IntElement>& vec2) {
    auto iter = vec2.begin();
    for (auto& elem : vec1) {
        elem -= *iter;
        iter++;
    }
}

SquareMatrix& SquareMatrix::operator*=(const SquareMatrix& m) {
    if (n != m.n) {
        throw std::domain_error("Dimension mismatch!");
    }

    std::vector<std::vector<IntElement>> newelements(n);
    SquareMatrix mt = m.transpose();

    std::vector<std::thread> threads;
    for(int i = 0; i <n; i++) {
        threads.push_back(std::thread(productRow, i, std::ref(newelements), std::ref(elements[i]), std::ref(mt.elements)));
    }

    for(auto& tr:threads) {
        tr.join();
    }
    return *this;


}

void productRow(int index, std::vector<std::vector<IntElement>>& result, const std::vector<IntElement>& multiplier, const std::vector<std::vector<IntElement>>& transmat){
    std::vector<IntElement> newrow;

    for (auto& trans_row : transmat) {
        IntElement sum = std::inner_product(multiplier.begin(), multiplier.end(), trans_row.begin(), IntElement(0), std::plus<IntElement>(), std::multiplies<IntElement>());
        newrow.push_back(sum);
    }
    std::swap(result[index], newrow);
}

bool SquareMatrix::operator==(const SquareMatrix& m) const {
    if (n != m.n) {
        return false;
    }

    auto m_row = m.elements.begin();
    for(auto& row : elements) {
        auto m_elem = m_row->begin();
        for(auto& elem : row) {
            if (!(elem==*m_elem))
                return false;
            m_elem++;
        }
        m_row++;
    }
    return true;
}


//outputs the matrix into the stream os in the form [[a11,...,a1n]...[an1,...,ann]]
void SquareMatrix::print(std::ostream& os) const {
    os << toString();
}

//returns string representation of the matrix in the form [[a11,...,a1n]...[an1,...,ann]]
std::string SquareMatrix::toString() const {
    std::stringstream ss;
    ss << "[";
    for (auto& rivi : elements) {
        ss << "[";
        bool eka = true;
        for(auto& elem : rivi)  {
            if (!eka)
                ss << ",";
            ss << elem;
            eka = false;

        }
        ss << "]";
    }
    ss << "]";
    return ss.str();
}

SquareMatrix::SquareMatrix(int dim) : n{dim} {
    unsigned seed_num = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator;
    generator.seed(seed_num);
    std::uniform_int_distribution<int> distribution{-100,100};
    int c;

    for(int i = 0; i < n; i++) {
        std::vector<IntElement> vec;
        for(int j = 0; j < n; j++) {
            c = distribution(generator);
            IntElement elem{c};
            vec.push_back(elem);
        }
        elements.push_back(vec);


    }

}


SquareMatrix operator+(const SquareMatrix& m1, const SquareMatrix& m2) {
    SquareMatrix tulos = m1;
    tulos += m2;
    return tulos;

}

SquareMatrix operator-(const SquareMatrix& m1, const SquareMatrix& m2) {
    SquareMatrix tulos = m1;
    tulos -= m2;
    return tulos;
}

SquareMatrix operator*(const SquareMatrix& m1, const SquareMatrix& m2) {
    SquareMatrix tulos = m1;
    tulos *= m2;
    return tulos;
}

std::ostream& operator<<(std::ostream& os, const SquareMatrix& m1) {
    os << m1.toString();
    return os;
}