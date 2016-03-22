/*******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2015 Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

/*!
 * @copyright   (c) 2015 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @brief       ...
 */

#ifndef CXX_DBAL_QUERY
#define CXX_DBAL_QUERY

#include <initializer_list>
#include <memory>
#include <CXX-DBAL/Field.hpp>
#include <CXX-DBAL/Table.hpp>
#include <XS/PIMPL/Object.hpp>

namespace DBAL
{
    class Connection;
    
    class Query: XS::PIMPL::Object< Query >
    {
        public:
            
            using XS::PIMPL::Object< Query >::impl;
            
            Query( std::shared_ptr< DBAL::Connection > connection = nullptr );
            
            Query & select( std::initializer_list< Field > fields );
            Query & from( std::initializer_list< Table > databases );
            Query & where( void );
            
            bool operator()( void );
            bool execute( void );
    };
}

#endif /* CXX_DBAL_QUERY */
