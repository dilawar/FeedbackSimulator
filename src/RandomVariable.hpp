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
class RandomVariable
{
    public:
        /* ====================  LIFECYCLE     =================================== */
        RandomVariable ();                             /* constructor      */
        RandomVariable ( const RandomVariable &other );   /* copy constructor */
        ~RandomVariable ();                            /* destructor       */

        /* ====================  ACCESSORS     =================================== */

        /* ====================  MUTATORS      =================================== */

        /* ====================  OPERATORS     =================================== */

        RandomVariable& operator = ( const RandomVariable &other ); /* assignment operator */

    protected:
        /* ====================  METHODS       =================================== */

        /* ====================  DATA MEMBERS  =================================== */

    private:
        /* ====================  METHODS       =================================== */

        /* ====================  DATA MEMBERS  =================================== */

}; /* -----  end of class RandomVariable  ----- */



#endif   /* ----- #ifndef RANDOMVARIABLE_INC  ----- */
