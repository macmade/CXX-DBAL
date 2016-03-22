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
class XS::PIMPL::Object< DBAL::Query >::IMPL
{
    public:
        
        IMPL( void );
        IMPL( std::shared_ptr< DBAL::Connection > connection );
        IMPL( const IMPL & o );
        ~IMPL( void );
        
        std::shared_ptr< DBAL::Connection > _connection;
};

#define XS_PIMPL_CLASS DBAL::Query
#include <XS/PIMPL/Object-IMPL.hpp>

namespace DBAL
{
    Query::Query( std::shared_ptr< DBAL::Connection > connection ): XS::PIMPL::Object< Query >( connection )
    {}
    
    Query & Query::select( std::initializer_list< Field > fields )
    {
        ( void )fields;
        
        return *( this );
    }
    
    Query & Query::from( std::initializer_list< Table > databases )
    {
        ( void )databases;
        
        return *( this );
    }
    
    Query & Query::where( void )
    {
        return *( this );
    }
    
    bool Query::operator()( void )
    {
        return this->execute();
    }
    
    bool Query::execute( void )
    {
        if( this->impl->_connection == nullptr )
        {
            throw std::runtime_error( "Cannot execute query - connection not set" );
        }
        
        return this->impl->_connection->executeQuery( *( this ) );
    }
}

XS::PIMPL::Object< DBAL::Query >::IMPL::IMPL( void ):
    _connection( nullptr )
{}

XS::PIMPL::Object< DBAL::Query >::IMPL::IMPL( std::shared_ptr< DBAL::Connection > connection ):
    _connection( connection )
{}

XS::PIMPL::Object< DBAL::Query >::IMPL::IMPL( const IMPL & o ):
    _connection( o._connection )
{}

XS::PIMPL::Object< DBAL::Query >::IMPL::~IMPL( void )
{}
