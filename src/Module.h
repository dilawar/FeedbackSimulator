/*
 * ==============================================================================
 *
 *       Filename:  Module.h
 *
 *    Description:  Module is most primitive system in this application.
 *
 *        Version:  1.0
 *        Created:  Saturday 06 September 2014 09:53:57  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dilawar Singh (), dilawars@ncbs.res.in
 *   Organization:  
 *
 * ==============================================================================
 */

#ifndef  MODULE_INC
#define  MODULE_INC

#include <systemc.h>
#include <iostream>
#include <memory>

using namespace std;

class Module
{
    public:
        Module();

        Module(string name);

        ~Module();

    public:
        string name;

    private:
        /* data */
        unique_ptr<sc_module_name> _up_sc_module_;
};

#endif   /* ----- #ifndef MODULE_INC  ----- */
