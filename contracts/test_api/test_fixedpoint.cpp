#include <VACiolib/fixedpoint.hpp>
#include <VACiolib/VACio.hpp>

#include "test_api.hpp"

void test_fixedpoint::create_instances()
{
    {
        // Various ways to create fixed_point128
       VACio::fixed_point128<18> a(12345667);
       VACio::fixed_point128<18> b(12345667);
       VACio::fixed_point128<16> c(12345667);
       VACio_assert(b == a, "fixed_point128 instances comparison with same number of decimals");
       VACio_assert(c == a, "fixed_point128 instances with different number of decimals");
    }

    {
        // Various ways to create fixed_point64
       VACio::fixed_point64<5> a(12345667);
       VACio::fixed_point64<5> b(12345667);
       VACio::fixed_point64<5> c(12345667);
       VACio_assert(b == a, "fixed_point64 instances comparison with same number of decimals");
       VACio_assert(c == a, "fixed_point64 instances with different number of decimals");
    }

    {
        // Various ways to create fixed_point32
       VACio::fixed_point32<18> a(12345667);
       VACio::fixed_point32<18> b(12345667);
       VACio::fixed_point32<16> c(12345667);
       VACio_assert(b == a, "fixed_point32 instances comparison with same number of decimals");
       VACio_assert(c == a, "fixed_point32 instances with different number of decimals");
    }
}

void test_fixedpoint::test_addition()
{
    {
       // Various ways to create fixed_point32
       VACio::fixed_point32<0> a(100);
       VACio::fixed_point32<0> b(100);
       VACio::fixed_point32<0> c = a + b;
       VACio::fixed_point32<0> d = 200;
       VACio_assert(c == d, "fixed_point32 instances addition with zero decmimals");
    }
    {
       // Various ways to create fixed_point64
       VACio::fixed_point64<0> a(100);
       VACio::fixed_point64<0> b(100);
       VACio::fixed_point64<0> c = a + b;
       VACio::fixed_point64<0> d = 200;
       VACio_assert(c == d, "fixed_point64 instances addition with zero decmimals");
    }
};

void test_fixedpoint::test_subtraction()
{
    {
       // Various ways to create fixed_point64
       VACio::fixed_point64<0> a(100);
       VACio::fixed_point64<0> b(100);
       VACio::fixed_point64<0> c = a - b;
       VACio::fixed_point64<0> d = 0;
       VACio_assert(c == d, "fixed_point64 instances subtraction with zero decmimals");

       VACio::fixed_point64<0> a1(0);
       VACio::fixed_point64<0> c1 = a1 - b;
       VACio::fixed_point64<0> d1 = -100;
       VACio_assert(c1 == d1, "fixed_point64 instances subtraction with zero decmimals");
    }
    {
       // Various ways to create fixed_point32
       VACio::fixed_point32<0> a(100);
       VACio::fixed_point32<0> b(100);
       VACio::fixed_point32<0> c = a - b;
       VACio::fixed_point32<0> d = 0;
       VACio_assert(c == d, "fixed_point32 instances subtraction with zero decmimals");

       // Various ways to create fixed_point32
       VACio::fixed_point32<0> a1(0);
       VACio::fixed_point32<0> c1 = a1 - b;
       VACio::fixed_point32<0> d1 = -100;
       VACio_assert(c1 == d1, "fixed_point32 instances subtraction with zero decmimals");

    }
};

void test_fixedpoint::test_multiplication()
{
    {
       // Various ways to create fixed_point64
       VACio::fixed_point64<0> a(100);
       VACio::fixed_point64<0> b(200);
       VACio::fixed_point128<0> c = a * b;
       VACio::fixed_point128<0> d(200*100);
       VACio_assert(c == d, "fixed_point64 instances multiplication result in fixed_point128");
    }

    {
       // Various ways to create fixed_point32
       VACio::fixed_point32<0> a(100);
       VACio::fixed_point32<0> b(200);
       VACio::fixed_point64<0> c = a * b;
       VACio::fixed_point64<0> d(200*100);
       VACio_assert(c == d, "fixed_point32 instances multiplication result in fixed_point64");
    }
}

void test_fixedpoint::test_division()
{
    {
        uint64_t lhs = 10000000;
        uint64_t rhs = 333;

        VACio::fixed_point64<0> a((int64_t)lhs);
        VACio::fixed_point64<0> b((int64_t)rhs);
        VACio::fixed_point128<5> c = a / b;

        VACio::fixed_point128<5> e = VACio::fixed_divide<5>(lhs, rhs);
        print(e);
        VACio_assert(c == e, "fixed_point64 instances division result from operator and function and compare in fixed_point128");

    }

    {
        uint32_t lhs = 100000;
        uint32_t rhs = 33;

        VACio::fixed_point32<0> a((int32_t)lhs);
        VACio::fixed_point32<0> b((int32_t)rhs);
        VACio::fixed_point64<5> c = a / b;

        VACio::fixed_point64<5> e = VACio::fixed_divide<5>(lhs, rhs);
        VACio_assert(c == e, "fixed_point64 instances division result from operator and function and compare in fixed_point128");

    }
}

void test_fixedpoint::test_division_by_0()
{
    {
        uint64_t lhs = 10000000;
        uint64_t rhs = 0;

        VACio::fixed_point64<0> a((int64_t)lhs);
        VACio::fixed_point64<0> b((int64_t)rhs);

        VACio::fixed_point128<5> e = VACio::fixed_divide<5>(lhs, rhs);
        // in order to get rid of unused parameter warning
        e = 0;
        VACio_assert(false, "should've thrown an error");

    }

 }
