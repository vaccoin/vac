#include <VACCOINlib/VACCOIN.hpp>
#include <VACCOINlib/print.hpp>
using namespace VACCOIN;

class payloadless : public VACCOIN::contract {
  public:
      using contract::contract;

      void doit() {
         print( "Im a payloadless action" );
      }
};

VACCOIN_ABI( payloadless, (doit) )
