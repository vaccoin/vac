/**
 *  @file
 *  @copyright defined in VAC/LICENSE.txt
 */

#include <VACCOINlib/VACCOIN.hpp>

namespace VACCOIN {

   class noop: public contract {
      public:
         noop( account_name self ): contract( self ) { }
         void anyaction( account_name from,
                         const std::string& /*type*/,
                         const std::string& /*data*/ )
         {
            require_auth( from );
         }
   };

   VACCOIN_ABI( noop, ( anyaction ) )

} /// VACCOIN     
