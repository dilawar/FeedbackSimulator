/*
 * ==============================================================================
 *
 *       Filename:  RandomVariable.cpp
 *
 *    Description:  Random variable class.
 *
 *        Version:  1.0
 *        Created:  Sunday 14 September 2014 11:24:22  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dilawar Singh (), dilawars@ncbs.res.in
 *   Organization:  
 *
 *   COMPILE_COMMAND: g++ -DBOOST_LOG_DYN_LINK -DPROB_MAIN_LOCAL -Wall RandomVariable.cpp
 *
 * ==============================================================================
 */


#include "RandomVariable.hpp"
#include "boost/log/core.hpp"
#include "boost/log/trivial.hpp"

using namespace boost;

/*
 *-------------------------------------------------------------------------------
 *       Class:  RandomVariable
 *      Method:  RandomVariable
 * Description:  constructor
 *-------------------------------------------------------------------------------
 */
template<typename Sample_Type, typename Prob_Type>
RandomVariable<Sample_Type, Prob_Type>::RandomVariable ()
{
    
}  /* -----  end of method RandomVariable::RandomVariable  (constructor)  ----- */

template<typename Sample_Type, typename Prob_Type>
RandomVariable<Sample_Type, Prob_Type>::RandomVariable ( string type )
{
    BOOST_LOG_TRIVIAL(info) << "Creating a RandomVariable with type : " << type;
    setType(type);

}  /* -----  end of method RandomVariable::RandomVariable  (constructor)  ----- */

template<typename Sample_Type, typename Prob_Type>
RandomVariable<Sample_Type, Prob_Type>::RandomVariable( string type
        , Prob_Type mean
        , Prob_Type variance
        )
{
    setType(type);
    setMean(mean);
    setVariance(variance);
}

/*
 *-------------------------------------------------------------------------------
 *       Class:  RandomVariable
 *      Method:  RandomVariable
 * Description:  copy constructor
 *-------------------------------------------------------------------------------
 */

template<typename Sample_Type, typename Prob_Type>
RandomVariable<Sample_Type, Prob_Type>::RandomVariable ( const RandomVariable &other )
{
}  /* -----  end of method RandomVariable::RandomVariable  (copy constructor)  ----- */

/*
 *-------------------------------------------------------------------------------
 *       Class:  RandomVariable
 *      Method:  ~RandomVariable
 * Description:  destructor
 *-------------------------------------------------------------------------------
 */
template<typename Sample_Type, typename Prob_Type>
RandomVariable<Sample_Type, Prob_Type>::~RandomVariable ()
{
}  /* -----  end of method RandomVariable::~RandomVariable  (destructor)  ----- */

/*
 *-------------------------------------------------------------------------------
 *       Class:  RandomVariable
 *      Method:  operator =
 * Description:  assignment operator
 *-------------------------------------------------------------------------------
 */
template<typename Sample_Type, typename Prob_Type>
RandomVariable<Sample_Type, Prob_Type>& RandomVariable<Sample_Type, Prob_Type>::operator = ( const RandomVariable &other )
{
    if ( this != &other )
    {
    }
    return *this;
}  /* -----  end of method RandomVariable::operator =  (assignment operator)  ----- */

/**
 * @brief Set the type of RandomVariable.
 *
 * @tparam Sample_Type
 * @tparam Prob_Type
 * @param type
 */
template<typename Sample_Type, typename Prob_Type>
void RandomVariable<Sample_Type, Prob_Type>::setType(string type)
{
    type = type;
}

/**
 * @brief Set the mean of the random variable.
 *
 * @tparam Sample_Type
 * @tparam Prob_Type
 * @param mean
 */
template<typename Sample_Type, typename Prob_Type>
void RandomVariable<Sample_Type, Prob_Type>::setMean(double mean)
{
    BOOST_LOG_TRIVIAL(debug) << "+ Setting mean to " << mean;
    mean = mean;
}

template<typename Sample_Type, typename Prob_Type>
void RandomVariable<Sample_Type, Prob_Type>::setVariance(double variance)
{
    BOOST_LOG_TRIVIAL(debug) << "+ Setting variance to " << variance;
    variance = variance;
}

#ifdef PROB_MAIN_LOCAL

#include <iostream>
using namespace std;

int main()
{
    BOOST_LOG_TRIVIAL(info) << "Creating a random distribution ... ";
    RandomVariable<int, double> rv("Guassian");
    rv.setMean(0.0);
    rv.setVariance(1.0);
}

#endif
