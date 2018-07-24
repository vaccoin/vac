/**
 *  @file
 *  @copyright defined in VAC/LICENSE.txt
 */

#pragma once

#include "consumer_core.h"

#include <VACio/chain/block_state.hpp>

namespace VACio {

class block_storage : public consumer_core<chain::block_state_ptr>
{
public:
    void consume(const std::vector<chain::block_state_ptr>& blocks) override;
};

} // namespace
