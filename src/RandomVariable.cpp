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

/*
 *-------------------------------------------------------------------------------
 *       Class:  RandomVariable
 *      Method:  RandomVariable
 * Description:  constructor
 *-------------------------------------------------------------------------------
 */
template<typename Sample_Type, typename Prob_Type>
RandomVariable<Sample_Type, Prob_Type>::RandomVariable ( string type )
{
    BOOST_LOG_TRIVIAL(info) << "Creating a RandomVariable with type : " << type 
        << endl;
    
    setType(type);

}  /* -----  end of method RandomVariable::RandomVariable  (constructor)  ----- */

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

#ifdef PROB_MAIN_LOCAL

#include <iostream>
using namespace std;

int main()
{
    BOOST_LOG_TRIVIAL(info) << "Creating a random distribution ... " << endl;
    RandomVariable<int, double> rv;

}

#endif
