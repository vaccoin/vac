/**
 *  @file
 *  @copyright defined in VAC/LICENSE.txt
 */
#pragma once

#include <VACio/chain/types.hpp>
#include <VACio/chain/contract_types.hpp>

namespace VACio { namespace chain {

   class apply_context;

   /**
    * @defgroup native_action_handlers Native Action Handlers
    */
   ///@{
   void apply_VACio_newaccount(apply_context&);
   void apply_VACio_updateauth(apply_context&);
   void apply_VACio_deleteauth(apply_context&);
   void apply_VACio_linkauth(apply_context&);
   void apply_VACio_unlinkauth(apply_context&);

   /*
   void apply_VACio_postrecovery(apply_context&);
   void apply_VACio_passrecovery(apply_context&);
   void apply_VACio_vetorecovery(apply_context&);
   */

   void apply_VACio_setcode(apply_context&);
   void apply_VACio_setabi(apply_context&);

   void apply_VACio_canceldelay(apply_context&);
   ///@}  end action handlers

} } /// namespace VACio::chain
