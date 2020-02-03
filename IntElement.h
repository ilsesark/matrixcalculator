/**
 * \file "IntElement.h"
 * \brief Header for IntElement class
 */
#ifndef HT3_INTELEMENT_H
#define HT3_INTELEMENT_H


#include <ostream>

/**
 * \class IntElement
 * \brief A class for wrapping a matrix item
 */
class IntElement {
public:
    /**
     * \brief Constructor for IntElement class
     */
    IntElement() = default;

    /**
     * \brief Paramatric constructor for IntElement class
     * \param v Value of IntElement
     */
    IntElement(int v);

    /**
    * \brief Deconstructor for IntElement class
    *
    */
    virtual ~IntElement() = default;

    /**
    * \bried Get method for val attribute
    * \return Returns val attribute of IntElement
    */
    int getVal() const;

    /**
    * \brief Set method for val attribute
    * \param v Value to be set as val attribute
    */
    void setVal(int v);

    /**
     * \brief += operator
     * \param i IntElement to be added
     * \return i added to the value of calling object
     */
    IntElement& operator+=(const IntElement& i);

    /**
     * \brief -= operator
     * \param i IntElement to be subtracted
     * \return i subtracted from the value of calling object
     */
    IntElement& operator-=(const IntElement& i);

    /**
     * \brief *= operator
     * \param i IntElement to be multiplied
     * \return value of calling object multiplied by i
     */
    IntElement& operator*=(const IntElement& i);
    /**
     * \brief == comparison operator
     * \param i IntElement to be compared
     * \return boolean value depending on whether the comparison is true or false
     */
    bool operator==(const IntElement& i) const;


private:
    int val;
};

/**
 * \brief Add operator for IntElement
 * \param i1 First IntElement to be added
 * \param i2 Second IntElement to be added
 * \return Addition of i1 and i2
 */
IntElement operator+(const IntElement& i1, const IntElement& i2);

/**
 * \brief Subtract method for IntElement
 * \param i1 IntElement that gets subtracted from
 * \param i2 IntElement that gets subtracted
 * \return Subtraction of i1 and i2
 */
IntElement operator-(const IntElement& i1, const IntElement& i2);

/**
 * \brief Multiplication method for IntElement
 * \param i1 IntElement to be multiplied
 * \param i2 IntElement multiplier
 * \return i1 multiplied by i2
 */
IntElement operator*(const IntElement& i1, const IntElement& i2);

/**
 * \brief Output operator for IntElement
 * \param os Output stream
 * \param i IntElement to be outputted
 * \return Modified output stream
 */
std::ostream& operator<<(std::ostream& os, const IntElement& i);

#endif //HT3_INTELEMENT_H
