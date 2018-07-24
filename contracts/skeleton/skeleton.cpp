#include <VACCOINlib/VACCOIN.hpp>

using namespace VACCOIN;

class hello : public VACCOIN::contract {
  public:
      using contract::contract;

      /// @abi action 
      void hi( account_name user ) {
         print( "Hello, ", name{user} );
      }
};

VACCOIN_ABI( hello, (hi) )
