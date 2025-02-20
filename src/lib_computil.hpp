

/*

Copyright (c) 2021 Ajay Biswas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <cmath>
#include <exception>

namespace computil {

/**
*  @brief A container to calculate the Arithematic Progression and provides
*  fixed time access of elements.
*
*  @ingroup sequences and series
*
*  @tparam T Type of element.
*
*  An Arithmetic progression (AP) or arithmetic sequence is a sequence of numbers 
*  in which the common difference 'd' of any two consecutive number is constant. This class 
*  provides support of various AP related operations.
*  
*/
template<class T>
class AP {

private:
    T a, d;
    unsigned int n;
    bool status;

public:
    AP();
    AP(T first_term, T common_diff, T no_of_terms);   
    bool isEmpty();
    T getCommonDiff();
    T getFirstTerm();
    T getNthTerm(unsigned int nth);
    T getNthTermFromLast(unsigned int nth);
    unsigned int getNoOfTerms();
    T sumN();
    static inline T sumN(T first_term, T last_term, unsigned int n) {return n*(first_term + last_term)/2.0;}
    void setCommonDiff(T common_diff);
    void setFirstTerm(T first_term);
    void setNoOfTerms(T no_of_terms);
    std::vector<T> getAllTerms();
};

template<class T>
class GP {

private:

public:



};

template<class T>
class Prime {

private:

public:

    static bool isPrime(T num);
    static T nearestPrime(T num);
    static std::vector<T> getPrimeInRange(unsigned int lower_limit, unsigned int upper_limit);
    static std::vector<T> getFirstNPrime(unsigned int n);
    static std::string getType(T num);
    static T randomPrime(unsigned int no_of_digits);
};

template<class T>
class BooleanAlgebra {

private:

};



template<class T>
AP<T>::AP() {
    status = true;
    a = 0;
    d = 0;
    n = 0;
} 

template<class T>
AP<T>::AP(T first_term, T common_diff, T no_of_terms) {
    status = false;
    a = first_term;
    d = common_diff;
    n = no_of_terms;
}

template<class T>
bool AP<T>::isEmpty() {
    return status;
}

/**
*  @brief  Returns the common difference 'd' of an AP.
*  @return The common difference of the AP of the type same as the class.
*  @throws std::logic_error if the status if true, i.e., not initialized.
*
*  Returns the common difference 'd' of an AP which was initialized by the user. 
*/
template<class T>
T AP<T>::getCommonDiff() {
    return d;
}

/**
*  @brief  Returns the First term of an AP.
*  @return The first term of the AP of the type same as the class.
*  @throws std::logic_error if the status if true, i.e., not initialized.
*
*  Returns the first term 'a' of an AP which was initialized by the user.
*/
template<class T>
T AP<T>::getFirstTerm() {
    return a;
}

/**
*  @brief  Returns the nth term of an AP.
*  @param  nth  An unsigned integer denoting the n.
*  @return The nth term of the AP of the type same as the class.
*  @throws std::logic_error if the status if true, i.e., not initialized.
*          std::out_of_range if the nth no. is an invalid term.
           std::domain_error if the nth no. is zero or negative.
*
*  Uses the first term a, common difference d and the user input nth
*  to calculate the nth term. 
*/
template<class T>
T AP<T>::getNthTerm(unsigned int nth) {

    if(status == true) {
        throw std::logic_error("AP not initialized");
    }
    if(nth > n) {
        throw std::out_of_range("Not enough terms in AP");
    }
    if(nth <= 0) {
        throw std::domain_error("Terms cannot be zero or negative");
    }
    return a + (nth-1)*d;
}

/**
*  @brief  Returns the nth term of an AP from the last.
*  @param  nth  An unsigned integer denoting the n.
*  @return The nth term of the AP from the last of the type same as the class.
*  @throws std::logic_error if the status if true, i.e., not initialized.
*          std::out_of_range if the nth no. is an invalid term.
           std::domain_error if the nth no. is zero or negative.
*
*  Uses the getNthTerm(), common difference d and the user input nth
*  to calculate the nth term from the last.  
*/
template<class T>
T AP<T>::getNthTermFromLast(unsigned int nth) {
    return getNthTerm(n) - (nth-1)*d;
}

/**
*  @brief  Returns the total no. of terms of the AP.
*  @return The total no. of terms 'n' of the AP of the type same as the class.
*  @throws std::logic_error if the status if true, i.e., not initialized.
*
*  Returns the total no. of terms 'n' of an AP that was initialized by the user.
*/
template<class T>
unsigned int AP<T>::getNoOfTerms() {
    return n;
}

template<class T>
T AP<T>::sumN() {
    
    return (n/2.0)*(2*a + (n-1)*d);
}

template<class T>
void AP<T>::setCommonDiff(T common_diff) {
    d = common_diff;
}

template<class T>
void AP<T>::setFirstTerm(T first_term) {
    a = first_term;
}

template<class T>
void AP<T>::setNoOfTerms(T no_of_terms) {
    n = no_of_terms;
}

template<class T>
std::vector<T> AP<T>::getAllTerms() {
    
    std::vector<T> v;

    for(unsigned int i = 0; i<n; i++) {
        v.push_back(a+ i*d);
    }

    return v;
}

template<class T>
bool Prime<T>::isPrime(T num) {
    
    try {

        if(num <= 1)
            return false;

        long double v = num - floor(num);
        if(v > 0.0)
            return false;

        unsigned long long int val = num;
        
        for(unsigned long long int i=2; i<=sqrt(val); i++)
        {
            if(val%i == 0)
            {
                return false;
            }
        }
        return true;
    }
    catch(...) {
        throw std::domain_error("Number not valid for checking");
    }
}

}   // namespace ends