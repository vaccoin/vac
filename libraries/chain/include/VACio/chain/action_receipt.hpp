/**
 *  @file
 *  @copyright defined in VAC/LICENSE.txt
 */
#pragma once

#include <VACio/chain/types.hpp>

namespace VACio { namespace chain {

   /**
    *  For each action dispatched this receipt is generated
    */
   struct action_receipt {
      account_name                    receiver;
      digest_type                     act_digest;
      uint64_t                        global_sequence = 0; ///< total number of actions dispatched since genesis
      uint64_t                        recv_sequence   = 0; ///< total number of actions with this receiver since genesis
      flat_map<account_name,uint64_t> auth_sequence;
      fc::unsigned_int                code_sequence = 0; ///< total number of setcodes
      fc::unsigned_int                abi_sequence  = 0; ///< total number of setabis

      digest_type digest()const { return digest_type::hash(*this); }
   };

} }  /// namespace VACio::chain

FC_REFLECT( VACio::chain::action_receipt, (receiver)(act_digest)(global_sequence)(recv_sequence)(auth_sequence)(code_sequence)(abi_sequence) )
