/**
 *  @file
 *  @copyright defined in VAC/LICENSE.txt
 */
#pragma once

#include <VACCOINlib/VACCOIN.hpp>
#include <VACCOINlib/token.hpp>
#include <VACCOINlib/reflect.hpp>
#include <VACCOINlib/generic_currency.hpp>

#include <bancor/converter.hpp>
#include <currency/currency.hpp>

namespace bancor {
   typedef VACCOIN::generic_currency< VACCOIN::token<N(other),S(4,OTHER)> >  other_currency;
   typedef VACCOIN::generic_currency< VACCOIN::token<N(bancor),S(4,RELAY)> > relay_currency;
   typedef VACCOIN::generic_currency< VACCOIN::token<N(currency),S(4,CUR)> > cur_currency;

   typedef converter<relay_currency, other_currency, cur_currency > example_converter;
} /// bancor

