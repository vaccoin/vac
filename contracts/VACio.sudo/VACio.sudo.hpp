#pragma once

#include <VACiolib/VACio.hpp>

namespace VACio {

   class sudo : public contract {
      public:
         sudo( account_name self ):contract(self){}

         void exec();

   };

} /// namespace VACio
