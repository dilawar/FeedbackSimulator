/*
 * ==============================================================================
 *
 *       Filename:  RandomVariable.hpp
 *
 *    Description:  Class responsible for random-variable.
 *
 *        Version:  1.0
 *        Created:  Sunday 14 September 2014 11:23:30  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dilawar Singh (), dilawars@ncbs.res.in
 *   Organization:  
 *
 * ==============================================================================
 */

#ifndef  RANDOMVARIABLE_INC
#define  RANDOMVARIABLE_INC

/*
 * ==============================================================================
 *        Class:  RandomVariable
 *  Description:  
 * ==============================================================================
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;


/**
 * @brief Types of distribution available.
 */
enum class ProbDistType { NORMAL, POISSON };

std::ostream& operator << (std::ostream& os, const ProbDistType& obj)
{
    switch(obj)
    {
        case ProbDistType::NORMAL: os << "NORMAL";
        case ProbDistType::POISSON: os << "POISSON";
        default:  os << "UNKNOWN DISTRIBUTION";
    }
    return os;
}

/**
 * @brief Class representing RandomVariable in use.
 *
 * @tparam Sample_Type Type of events.
 * @tparam Prob_Type  Type of Probabilities, mostly double.
 */
template<typename Sample_Type, typename Prob_Type>
class RandomVariable
{
    public:
        /* ====================  LIFECYCLE     =================================== */
        RandomVariable ();                             /* constructor      */
        RandomVariable ( ProbDistType type );
        RandomVariable ( ProbDistType type, Prob_Type mean, Prob_Type variance);

        RandomVariable ( const RandomVariable &other );   /* copy constructor */
        ~RandomVariable ();                            /* destructor       */

        /* ====================  ACCESSORS     =================================== */

        /* ====================  MUTATORS      =================================== */
        void setType(ProbDistType type);

        void setMean(double mean);

        void setVariance(double variance);

        void generate(vector<Prob_Type>& result);

        /* ====================  OPERATORS     =================================== */

        RandomVariable& operator = ( const RandomVariable &other ); /* assignment operator */

    protected:
        /* ====================  METHODS       =================================== */

        /* ====================  DATA MEMBERS  =================================== */
        string name_;
        ProbDistType type_;

        unsigned long size_;

        double mean_;
        double variance_;

    private:
        /* ====================  METHODS       =================================== */

        /* ====================  DATA MEMBERS  =================================== */


}; /* -----  end of class RandomVariable  ----- */



#endif   /* ----- #ifndef RANDOMVARIABLE_INC  ----- */
