/**
 *  @file
 *  @copyright defined in VAC/LICENSE.txt
 */

#include <VACio/chain/chain_id_type.hpp>
#include <VACio/chain/exceptions.hpp>

namespace VACio { namespace chain {

   void chain_id_type::reflector_verify()const {
      VAC_ASSERT( *reinterpret_cast<const fc::sha256*>(this) != fc::sha256(), chain_id_type_exception, "chain_id_type cannot be zero" );
   }

} }  // namespace VACio::chain

namespace fc {

   void to_variant(const VACio::chain::chain_id_type& cid, fc::variant& v) {
      to_variant( static_cast<const fc::sha256&>(cid), v);
   }

   void from_variant(const fc::variant& v, VACio::chain::chain_id_type& cid) {
      from_variant( v, static_cast<fc::sha256&>(cid) );
   }

} // fc
