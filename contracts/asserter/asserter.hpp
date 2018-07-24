/**
 *  @file
 *  @copyright defined in VAC/LICENSE.txt
 */

#include <VACiolib/VACio.hpp>

namespace asserter {
   struct assertdef {
      int8_t      condition;
      std::string message;

      VACLIB_SERIALIZE( assertdef, (condition)(message) )
   };
}
