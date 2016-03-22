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

#include <CXX-DBAL.hpp>

template<>
class XS::PIMPL::Object< DBAL::Table >::IMPL
{
    public:
        
        IMPL( void );
        IMPL( const std::string & name );
        IMPL( const IMPL & o );
        ~IMPL( void );
        
        std::string _name;
};

#define XS_PIMPL_CLASS DBAL::Table
#include <XS/PIMPL/Object-IMPL.hpp>

namespace DBAL
{
    Table::Table( const char * name ): Table( ( name ) ? std::string( name ) : std::string( "" ) )
    {}
    
    Table::Table( const std::string & name ): XS::PIMPL::Object< Table >( name )
    {}
    
    bool Table::operator ==( const Table & o ) const
    {
        return this->impl->_name == o.impl->_name;
    }
    
    bool Table::operator !=( const Table & o ) const
    {
        return !operator ==( o );
    }
    
    std::string Table::name( void ) const
    {
        return this->impl->_name;
    }
}

XS::PIMPL::Object< DBAL::Table >::IMPL::IMPL( void )
{}

XS::PIMPL::Object< DBAL::Table >::IMPL::IMPL( const std::string & name ):
    _name( name )
{}

XS::PIMPL::Object< DBAL::Table >::IMPL::IMPL( const IMPL & o ):
    _name( o._name )
{}

XS::PIMPL::Object< DBAL::Table >::IMPL::~IMPL( void )
{}
