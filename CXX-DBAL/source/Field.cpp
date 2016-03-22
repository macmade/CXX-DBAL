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
class XS::PIMPL::Object< DBAL::Field >::IMPL
{
    public:
        
        IMPL( void );
        IMPL( const std::string & name );
        IMPL( const IMPL & o );
        ~IMPL( void );
        
        std::string _name;
        std::string _databaseName;
};

#define XS_PIMPL_CLASS DBAL::Field
#include <XS/PIMPL/Object-IMPL.hpp>

namespace DBAL
{
    Field::Field( const char * name ): Field( ( name ) ? std::string( name ) : std::string( "" ) )
    {}
    
    Field::Field( const std::string & name ): XS::PIMPL::Object< Field >( name )
    {}
    
    bool Field::operator ==( const Field & o ) const
    {
        return this->impl->_name == o.impl->_name && this->impl->_databaseName == o.impl->_databaseName;
    }
    
    bool Field::operator !=( const Field & o ) const
    {
        return !operator ==( o );
    }
    
    std::string Field::name( void ) const
    {
        return this->impl->_name;
    }
    
    std::string Field::databaseName( void ) const
    {
        return this->impl->_databaseName;
    }
}

XS::PIMPL::Object< DBAL::Field >::IMPL::IMPL( void )
{}

XS::PIMPL::Object< DBAL::Field >::IMPL::IMPL( const std::string & name )
{
    std::size_t pos;
    
    pos = name.find( "." );
    
    if( pos == std::string::npos )
    {
        this->_name = name;
        
        return;
    }
    
    this->_databaseName = name.substr( 0, pos );
    this->_name         = name.substr( pos + 1 );
}

XS::PIMPL::Object< DBAL::Field >::IMPL::IMPL( const IMPL & o ):
    _name( o._name ),
    _databaseName( o._databaseName )
{}

XS::PIMPL::Object< DBAL::Field >::IMPL::~IMPL( void )
{}
