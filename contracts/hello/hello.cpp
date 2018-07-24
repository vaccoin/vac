#include <VACiolib/VACio.hpp>
using namespace VACio;

class hello : public VACio::contract {
  public:
      using contract::contract;

      /// @abi action 
      void hi( account_name user ) {
         print( "Hello, ", name{user} );
      }
};

VACIO_ABI( hello, (hi) )
