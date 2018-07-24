/**
 *  @file
 *  @copyright defined in VAC/LICENSE.txt
 */

#pragma once

#include <vector>

namespace VACio {

template<typename T>
class consumer_core {
public:
    virtual ~consumer_core() {}
    virtual void consume(const std::vector<T>& elements) = 0;
};

} // namespace


