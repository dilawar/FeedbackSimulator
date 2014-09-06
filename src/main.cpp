/*
 * ==============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Entry point of this application.
 *
 *        Version:  1.0
 *        Created:  Wednesday 27 August 2014 01:43:05  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dilawar Singh (), dilawars@ncbs.res.in
 *   Organization:  
 *
 * ==============================================================================
 */


#include <iostream>
#include "Module.h"

using namespace std;

int main(int argc, const char *argv[])
{
    cerr << "I am here" << endl;
    string name = "modA";
    Module*  module = new Module(name);
    return 0;
}
