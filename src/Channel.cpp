/*
 * ==============================================================================
 *
 *       Filename:  Channel.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 06 September 2014 04:02:00  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dilawar Singh (), dilawars@ncbs.res.in
 *   Organization:  
 *
 * ==============================================================================
 */


#include "Channel.h"

#ifdef PYTHON
#include <boost/python.hpp>
using namespace boost::python;
#endif



Channel::Channel()
{
    id_ = 0;
}

Channel::~Channel()
{
}

unsigned int Channel::getId()
{
    return id_;
}

void Channel::setId(unsigned int id)
{
    id_ = id;
}

#ifdef PYTHON
BOOST_PYTHON_MODULE(channel)
{
    class_<Channel>("Channel")
        .def_readonly("id", &Channel::id_)
    ;
}
#endif
