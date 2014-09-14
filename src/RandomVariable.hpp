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

using namespace std;

template<typename Sample_Type, typename Prob_Type>
class RandomVariable
{
    public:
        /* ====================  LIFECYCLE     =================================== */
        RandomVariable ();                             /* constructor      */
        RandomVariable ( string type );
        RandomVariable ( string type, Prob_Type mean, Prob_Type variance);

        RandomVariable ( const RandomVariable &other );   /* copy constructor */
        ~RandomVariable ();                            /* destructor       */

        /* ====================  ACCESSORS     =================================== */

        /* ====================  MUTATORS      =================================== */
        void setType(string type);

        void setMean(double mean);

        void setVariance(double variance);

        /* ====================  OPERATORS     =================================== */

        RandomVariable& operator = ( const RandomVariable &other ); /* assignment operator */

    protected:
        /* ====================  METHODS       =================================== */

        /* ====================  DATA MEMBERS  =================================== */
        string name;
        string type;
        double mean;
        double variance;

    private:
        /* ====================  METHODS       =================================== */

        /* ====================  DATA MEMBERS  =================================== */

}; /* -----  end of class RandomVariable  ----- */



#endif   /* ----- #ifndef RANDOMVARIABLE_INC  ----- */
