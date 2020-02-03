/**
 * \file "SquareMatrix.h"
 * \brief Header for SquareMatrix class
 */
#ifndef HT3_SQUAREMATRIX_H
#define HT3_SQUAREMATRIX_H


#include <ostream>
#include <vector>
#include "IntElement.h"


/**
 * \class SquareMatrix
 * \brief A class for a square matrix
 */
class SquareMatrix {
public:
    /**
     * \brief Constructor for SquareMatrix
     */
    SquareMatrix() = default;
    /**
     * \brief Random matrix constructor
     * \param n
     */
    SquareMatrix(int dim);

    /**
     * \brief Parametric constructor for SquareMatrix
     * \param s Matrix in a string
     * \throw std::invalid_argument if string is not a square matrix
     */
    // Constructs a matrix from the string of the form [[a11,...,a1n]...[an1,...,ann]]
    SquareMatrix(const std::string& s);

    /**
     * \bried Copy constructor
     * \param m Square Matrix to be copied
     */
    SquareMatrix(const SquareMatrix& m);

    /**
     * \brief Decostructor
     */
    ~SquareMatrix() = default;


    /**
     * \brief Assignment operator for SquareMatrix
     * @param m SquareMatrix to be assigned
     * @return SquareMatrix with assigned values
     */
    SquareMatrix& operator=(const SquareMatrix& m);


    /**
     * \brief Transposes a matrix
     * @return Transposed matrix
     */
    SquareMatrix transpose() const;

    /**
     * \brief += operator for SquareMatrix
     * \param m matrix to be added
     * \return matrix m values added to the calling objects values
     */
    SquareMatrix& operator+=(const SquareMatrix& m);

    /**
     * \brief -= operator for SquareMatrix
     * \param m matrix to be subtracted
     * \return m values subtracted from the calling object's values
     */
    SquareMatrix& operator-=(const SquareMatrix& m);

    /**
     * \brief *= operator for SquareMatrix
     * \param m multiplier matrix
     * \return calling object's values multiplied by m
     */
    SquareMatrix& operator*=(const SquareMatrix& m);

    /**
     * \brief Comaprison operator for SquareMatrix
     * @param m Matrix to be compared
     * @return boolean value depending on whether the comparison is true or false
     */
    bool operator==(const SquareMatrix& m) const;

    /**
     * \brief Print method for an ostream
     * \param os Output stream
     */
    void print(std::ostream& os) const;

    /**
     * \brief To string method, makes an object into a string
     * \return Matrix in a string
     */
    std::string toString() const;



private:
    int n;
    std::vector<std::vector<IntElement>> elements;


};

/**
 * \brief Add operator for SquareMatrix
 * \param m1 First SquareMatrix to be added
 * \param m2 Second SquareMatrix to be added
 * \return New SquareMatrix containing addition of m1 and m2
 */
SquareMatrix operator+(const SquareMatrix& m1, const SquareMatrix& m2);
/**
 * \brief Subtract operator for SquareMatrix
 * \param m1 First SquareMatrix to be subtracted
 * \param m2 Second SquareMatrix to be subtracted
 * \return New SquareMatrix containing subtraction of m1 and m2
 */
SquareMatrix operator-(const SquareMatrix& m1, const SquareMatrix& m2);
/**
 * \brief Multiplication operator for SquareMatrix
 * \param m1 First SquareMatrix to be multiplied
 * \param m2 Second SquareMatrix to be multiplied
 * \return New SquareMatrix containing multiplication of m1 and m2
 */
SquareMatrix operator*(const SquareMatrix& m1, const SquareMatrix& m2);
/**
 * \brief Output operator for SquareMatrix
 * \param os Output stream
 * \param m SquareMatrix to be outputted
 * \return Modified output stream
 */
std::ostream& operator<<(std::ostream& os, const SquareMatrix& m);

void subVectorsminus(std::vector<IntElement>& vec1, const std::vector<IntElement>& vec2);
void subVectorsplus(std::vector<IntElement>& vec1, const std::vector<IntElement>& vec2);
void productRow(int index, std::vector<std::vector<IntElement>>& result, const std::vector<IntElement>& multiplier, const std::vector<std::vector<IntElement>>& transmat);

#endif //HT3_SQUAREMATRIX_H
