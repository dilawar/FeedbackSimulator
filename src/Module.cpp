/*
Copyright (C) 2014 Dilawar Singh

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see <http://www.gnu.org/licenses/>.

*/

#include "Module.h"

Module::Module()
{
}


Module::~Module()
{
}

Module::Module(string name)
{
    cerr << "Creating a module with name " << name << endl;

    // Putting a new sc_module in unique_ptr.
    _up_sc_module_.reset(new sc_module_name(name.c_str()));
    
    // 
}

#if PYTHON
    
#endif
