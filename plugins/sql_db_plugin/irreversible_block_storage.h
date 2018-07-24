/**
 *  @file
 *  @copyright defined in VAC/LICENSE.txt
 */

#pragma once

#include "consumer_core.h"

#include <memory>
#include <VACio/chain/block_state.hpp>

#include "database.h"

namespace VACio {

class irreversible_block_storage : public consumer_core<chain::block_state_ptr>
{
public:
    irreversible_block_storage(std::shared_ptr<database> db);

    void consume(const std::vector<chain::block_state_ptr>& blocks) override;

private:
    std::shared_ptr<database> m_db;
};

} // namespace

