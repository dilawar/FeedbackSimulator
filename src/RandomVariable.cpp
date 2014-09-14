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
 *   COMPILE_COMMAND: g++ -std=c++11 -DBOOST_LOG_DYN_LINK -DPROB_MAIN_LOCAL -Wall RandomVariable.cpp
 *
 * ==============================================================================
 */


#include <type_traits>
#include "RandomVariable.hpp"
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/poisson_distribution.hpp>

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
RandomVariable<Sample_Type, Prob_Type>::RandomVariable ( ProbDistType type )
{
    setType(type);
}  /* -----  end of method RandomVariable::RandomVariable  (constructor)  ----- */

template<typename Sample_Type, typename Prob_Type>
RandomVariable<Sample_Type, Prob_Type>::RandomVariable( ProbDistType type
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
void RandomVariable<Sample_Type, Prob_Type>::setType(ProbDistType type)
{
    BOOST_LOG_TRIVIAL(debug) << " + Type of distribution " << toString(type);
    type_ = type;
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
    mean_ = mean;
}

template<typename Sample_Type, typename Prob_Type>
void RandomVariable<Sample_Type, Prob_Type>::setVariance(double variance)
{
    BOOST_LOG_TRIVIAL(debug) << "+ Setting variance to " << variance;
    variance_ = variance;
}

/**
 * @brief Generate n numbers.
 *
 * @tparam Sample_Type
 * @tparam Prob_Type
 * @param result
 */
template<typename Sample_Type, typename Prob_Type>
void RandomVariable<Sample_Type, Prob_Type>::generate(vector<Prob_Type>& result)
{

    if(type_ == ProbDistType::NORMAL)
    {
        BOOST_LOG_TRIVIAL(debug) << "NORMAL distribution with mean " 
            << mean_ 
            << " and variance (sigma) " 
            << variance_ 
            ;

        /* Create a Normal distribution with given mean */
        boost::normal_distribution<Prob_Type> nd(mean_, variance_);
        boost::variate_generator<boost::mt19937, boost::normal_distribution<Prob_Type>>
            generator(boost::mt19937(time(0)), nd);
        for(auto& i : result) i = generator();
    }
    else if(type_ == ProbDistType::POISSON)
    {
        BOOST_LOG_TRIVIAL(debug) << "POISSON distribution with mean " 
            << mean_ 
            ;
        boost::poisson_distribution<Sample_Type, Prob_Type> pd(mean_);
        boost::variate_generator<boost::mt19937
            , boost::poisson_distribution<Sample_Type, Prob_Type>>
            generator(boost::mt19937(time(0)), pd);
        for(auto& i : result) i = generator();
    }
    else
    {
        BOOST_LOG_TRIVIAL(error) << "Unknown/unimplemented distribution : " 
            << toString(type_) 
            << " defaulting to UNIFORM";

    }
}

/**
 * @brief Calculate the entropy of a given vector of distribution.
 *
 * @tparam Sample_Type
 * @tparam Prob_Type
 * @param log_base
 *
 * @return 
 */
template<typename Sample_Type, typename Prob_Type>
double RandomVariable<Sample_Type, Prob_Type>::entropy(const vector<Prob_Type>& dist
        , unsigned binSize
        , unsigned log_base
        )
{
    BOOST_LOG_TRIVIAL(debug) << "Calculating entropy : bin size " << binSize;

}


#ifdef PROB_MAIN_LOCAL
#include <iostream>
using namespace std;

int main()
{
    BOOST_LOG_TRIVIAL(info) << "Creating a random distribution ... ";
    RandomVariable<int, double> rv(ProbDistType::NORMAL);
    rv.setMean(0.0);
    rv.setVariance(10);
    vector<double> result;
    result.resize(100);
    rv.generate(result);
    for(auto i : result) cerr << i << ", ";
    rv.entropy(result, 10, 2);
}

#endif
