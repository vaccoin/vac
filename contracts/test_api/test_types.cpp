/**
 *  @file
 *  @copyright defined in VAC/LICENSE.txt
 */
#include <VACiolib/VACio.hpp>

#include "test_api.hpp"

void test_types::types_size() {

   VACio_assert( sizeof(int64_t) == 8, "int64_t size != 8");
   VACio_assert( sizeof(uint64_t) ==  8, "uint64_t size != 8");
   VACio_assert( sizeof(uint32_t) ==  4, "uint32_t size != 4");
   VACio_assert( sizeof(int32_t) ==  4, "int32_t size != 4");
   VACio_assert( sizeof(uint128_t) == 16, "uint128_t size != 16");
   VACio_assert( sizeof(int128_t) == 16, "int128_t size != 16");
   VACio_assert( sizeof(uint8_t) ==  1, "uint8_t size != 1");

   VACio_assert( sizeof(account_name) ==  8, "account_name size !=  8");
   VACio_assert( sizeof(table_name) ==  8, "table_name size !=  8");
   VACio_assert( sizeof(time) ==  4, "time size !=  4");
   VACio_assert( sizeof(VACio::key256) == 32, "key256 size != 32" );
}

void test_types::char_to_symbol() {

   VACio_assert( VACio::char_to_symbol('1') ==  1, "VACio::char_to_symbol('1') !=  1");
   VACio_assert( VACio::char_to_symbol('2') ==  2, "VACio::char_to_symbol('2') !=  2");
   VACio_assert( VACio::char_to_symbol('3') ==  3, "VACio::char_to_symbol('3') !=  3");
   VACio_assert( VACio::char_to_symbol('4') ==  4, "VACio::char_to_symbol('4') !=  4");
   VACio_assert( VACio::char_to_symbol('5') ==  5, "VACio::char_to_symbol('5') !=  5");
   VACio_assert( VACio::char_to_symbol('a') ==  6, "VACio::char_to_symbol('a') !=  6");
   VACio_assert( VACio::char_to_symbol('b') ==  7, "VACio::char_to_symbol('b') !=  7");
   VACio_assert( VACio::char_to_symbol('c') ==  8, "VACio::char_to_symbol('c') !=  8");
   VACio_assert( VACio::char_to_symbol('d') ==  9, "VACio::char_to_symbol('d') !=  9");
   VACio_assert( VACio::char_to_symbol('e') == 10, "VACio::char_to_symbol('e') != 10");
   VACio_assert( VACio::char_to_symbol('f') == 11, "VACio::char_to_symbol('f') != 11");
   VACio_assert( VACio::char_to_symbol('g') == 12, "VACio::char_to_symbol('g') != 12");
   VACio_assert( VACio::char_to_symbol('h') == 13, "VACio::char_to_symbol('h') != 13");
   VACio_assert( VACio::char_to_symbol('i') == 14, "VACio::char_to_symbol('i') != 14");
   VACio_assert( VACio::char_to_symbol('j') == 15, "VACio::char_to_symbol('j') != 15");
   VACio_assert( VACio::char_to_symbol('k') == 16, "VACio::char_to_symbol('k') != 16");
   VACio_assert( VACio::char_to_symbol('l') == 17, "VACio::char_to_symbol('l') != 17");
   VACio_assert( VACio::char_to_symbol('m') == 18, "VACio::char_to_symbol('m') != 18");
   VACio_assert( VACio::char_to_symbol('n') == 19, "VACio::char_to_symbol('n') != 19");
   VACio_assert( VACio::char_to_symbol('o') == 20, "VACio::char_to_symbol('o') != 20");
   VACio_assert( VACio::char_to_symbol('p') == 21, "VACio::char_to_symbol('p') != 21");
   VACio_assert( VACio::char_to_symbol('q') == 22, "VACio::char_to_symbol('q') != 22");
   VACio_assert( VACio::char_to_symbol('r') == 23, "VACio::char_to_symbol('r') != 23");
   VACio_assert( VACio::char_to_symbol('s') == 24, "VACio::char_to_symbol('s') != 24");
   VACio_assert( VACio::char_to_symbol('t') == 25, "VACio::char_to_symbol('t') != 25");
   VACio_assert( VACio::char_to_symbol('u') == 26, "VACio::char_to_symbol('u') != 26");
   VACio_assert( VACio::char_to_symbol('v') == 27, "VACio::char_to_symbol('v') != 27");
   VACio_assert( VACio::char_to_symbol('w') == 28, "VACio::char_to_symbol('w') != 28");
   VACio_assert( VACio::char_to_symbol('x') == 29, "VACio::char_to_symbol('x') != 29");
   VACio_assert( VACio::char_to_symbol('y') == 30, "VACio::char_to_symbol('y') != 30");
   VACio_assert( VACio::char_to_symbol('z') == 31, "VACio::char_to_symbol('z') != 31");

   for(unsigned char i = 0; i<255; i++) {
      if((i >= 'a' && i <= 'z') || (i >= '1' || i <= '5')) continue;
      VACio_assert( VACio::char_to_symbol((char)i) == 0, "VACio::char_to_symbol() != 0");
   }
}

void test_types::string_to_name() {

   VACio_assert( VACio::string_to_name("a") == N(a) , "VACio::string_to_name(a)" );
   VACio_assert( VACio::string_to_name("ba") == N(ba) , "VACio::string_to_name(ba)" );
   VACio_assert( VACio::string_to_name("cba") == N(cba) , "VACio::string_to_name(cba)" );
   VACio_assert( VACio::string_to_name("dcba") == N(dcba) , "VACio::string_to_name(dcba)" );
   VACio_assert( VACio::string_to_name("edcba") == N(edcba) , "VACio::string_to_name(edcba)" );
   VACio_assert( VACio::string_to_name("fedcba") == N(fedcba) , "VACio::string_to_name(fedcba)" );
   VACio_assert( VACio::string_to_name("gfedcba") == N(gfedcba) , "VACio::string_to_name(gfedcba)" );
   VACio_assert( VACio::string_to_name("hgfedcba") == N(hgfedcba) , "VACio::string_to_name(hgfedcba)" );
   VACio_assert( VACio::string_to_name("ihgfedcba") == N(ihgfedcba) , "VACio::string_to_name(ihgfedcba)" );
   VACio_assert( VACio::string_to_name("jihgfedcba") == N(jihgfedcba) , "VACio::string_to_name(jihgfedcba)" );
   VACio_assert( VACio::string_to_name("kjihgfedcba") == N(kjihgfedcba) , "VACio::string_to_name(kjihgfedcba)" );
   VACio_assert( VACio::string_to_name("lkjihgfedcba") == N(lkjihgfedcba) , "VACio::string_to_name(lkjihgfedcba)" );
   VACio_assert( VACio::string_to_name("mlkjihgfedcba") == N(mlkjihgfedcba) , "VACio::string_to_name(mlkjihgfedcba)" );
   VACio_assert( VACio::string_to_name("mlkjihgfedcba1") == N(mlkjihgfedcba2) , "VACio::string_to_name(mlkjihgfedcba2)" );
   VACio_assert( VACio::string_to_name("mlkjihgfedcba55") == N(mlkjihgfedcba14) , "VACio::string_to_name(mlkjihgfedcba14)" );

   VACio_assert( VACio::string_to_name("azAA34") == N(azBB34) , "VACio::string_to_name N(azBB34)" );
   VACio_assert( VACio::string_to_name("AZaz12Bc34") == N(AZaz12Bc34) , "VACio::string_to_name AZaz12Bc34" );
   VACio_assert( VACio::string_to_name("AAAAAAAAAAAAAAA") == VACio::string_to_name("BBBBBBBBBBBBBDDDDDFFFGG") , "VACio::string_to_name BBBBBBBBBBBBBDDDDDFFFGG" );
}

void test_types::name_class() {

   VACio_assert( VACio::name{VACio::string_to_name("azAA34")}.value == N(azAA34), "VACio::name != N(azAA34)" );
   VACio_assert( VACio::name{VACio::string_to_name("AABBCC")}.value == 0, "VACio::name != N(0)" );
   VACio_assert( VACio::name{VACio::string_to_name("AA11")}.value == N(AA11), "VACio::name != N(AA11)" );
   VACio_assert( VACio::name{VACio::string_to_name("11AA")}.value == N(11), "VACio::name != N(11)" );
   VACio_assert( VACio::name{VACio::string_to_name("22BBCCXXAA")}.value == N(22), "VACio::name != N(22)" );
   VACio_assert( VACio::name{VACio::string_to_name("AAAbbcccdd")} == VACio::name{VACio::string_to_name("AAAbbcccdd")}, "VACio::name == VACio::name" );

   uint64_t tmp = VACio::name{VACio::string_to_name("11bbcccdd")};
   VACio_assert(N(11bbcccdd) == tmp, "N(11bbcccdd) == tmp");
}
