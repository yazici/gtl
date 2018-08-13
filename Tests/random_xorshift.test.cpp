/*
The MIT License
Copyright (c) 2018 Geoffrey Daniels. http://gpdaniels.com/
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE
*/

#include <main.tests.hpp>
#include <benchmark.tests.hpp>
#include <macro.tests.hpp>

#include <random_xorshift>

#include <cmath>
#include <type_traits>

TEST(traits, standard) {
    REQUIRE(sizeof(gtl::random_xorshift) >= 8ull, "sizeof(gtl::random_xorshift) = %ld, expected >= %lld", sizeof(gtl::random_xorshift), 8ull);

    REQUIRE(std::is_pod<gtl::random_xorshift>::value == false, "Expected std::is_pod to be false.");

    REQUIRE(std::is_trivial<gtl::random_xorshift>::value == false, "Expected std::is_trivial to be false.");

    REQUIRE(std::is_trivially_copyable<gtl::random_xorshift>::value == true, "Expected std::is_trivially_copyable to be true.");

    REQUIRE(std::is_standard_layout<gtl::random_xorshift>::value == true, "Expected std::is_standard_layout to be true.");
}

TEST(constructor, empty) {
    gtl::random_xorshift random_xorshift;
    DoNotOptimiseAway(random_xorshift);
}

TEST(constructor, seed) {
    gtl::random_xorshift random_xorshift(0x01234567);
    DoNotOptimiseAway(random_xorshift);
}

TEST(function, seed) {
    gtl::random_xorshift random_xorshift;
    random_xorshift.seed(0x01234567);
}

TEST(function, get_random_raw) {
    gtl::random_xorshift random_xorshift;
    random_xorshift.seed(0x01234567);
    unsigned int random_raw = random_xorshift.get_random_raw();
    REQUIRE(random_raw == 514137109, "Pseudo-random number 1 was %u, expected %u", random_raw, 514137109u);
    random_raw = random_xorshift.get_random_raw();
    REQUIRE(random_raw == 2827593414, "Pseudo-random number 2 was %u, expected %u", random_raw, 2827593414u);
    random_raw = random_xorshift.get_random_raw();
    REQUIRE(random_raw == 416909229, "Pseudo-random number 3 was %u, expected %u", random_raw, 416909229u);
    random_raw = random_xorshift.get_random_raw();
    REQUIRE(random_raw == 1502090661, "Pseudo-random number 4 was %u, expected %u", random_raw, 1502090661u);
    random_raw = random_xorshift.get_random_raw();
    REQUIRE(random_raw == 367073627, "Pseudo-random number 5 was %u, expected %u", random_raw, 367073627u);
}

TEST(function, get_random_exclusive) {
    auto round = [](double value) -> double { return std::round(value * 1000000.0) / 1000000.0; };
    gtl::random_xorshift random_xorshift;
    random_xorshift.seed(0x01234567);
    double random_exclusive = round(random_xorshift.get_random_exclusive());
    REQUIRE(random_exclusive == 0.119707, "Pseudo-random number 1 was %lf, expected %lf", random_exclusive, 0.119707);
    random_exclusive = round(random_xorshift.get_random_exclusive());
    REQUIRE(random_exclusive == 0.658350, "Pseudo-random number 2 was %lf, expected %lf", random_exclusive, 0.658350);
    random_exclusive = round(random_xorshift.get_random_exclusive());
    REQUIRE(random_exclusive == 0.097069, "Pseudo-random number 3 was %lf, expected %lf", random_exclusive, 0.097069);
    random_exclusive = round(random_xorshift.get_random_exclusive());
    REQUIRE(random_exclusive == 0.349733, "Pseudo-random number 4 was %lf, expected %lf", random_exclusive, 0.349733);
    random_exclusive = round(random_xorshift.get_random_exclusive());
    REQUIRE(random_exclusive == 0.085466, "Pseudo-random number 5 was %lf, expected %lf", random_exclusive, 0.085466);
}

TEST(function, get_random_exclusive_top) {
    auto round = [](double value) -> double { return std::round(value * 1000000.0) / 1000000.0; };
    gtl::random_xorshift random_xorshift;
    random_xorshift.seed(0x01234567);
    double random_exclusive_top = round(random_xorshift.get_random_exclusive_top());
    REQUIRE(random_exclusive_top == 0.119707, "Pseudo-random number 1 was %lf, expected %lf", random_exclusive_top, 0.119707);
    random_exclusive_top = round(random_xorshift.get_random_exclusive_top());
    REQUIRE(random_exclusive_top == 0.658350, "Pseudo-random number 2 was %lf, expected %lf", random_exclusive_top, 0.658350);
    random_exclusive_top = round(random_xorshift.get_random_exclusive_top());
    REQUIRE(random_exclusive_top == 0.097069, "Pseudo-random number 3 was %lf, expected %lf", random_exclusive_top, 0.097069);
    random_exclusive_top = round(random_xorshift.get_random_exclusive_top());
    REQUIRE(random_exclusive_top == 0.349733, "Pseudo-random number 4 was %lf, expected %lf", random_exclusive_top, 0.349733);
    random_exclusive_top = round(random_xorshift.get_random_exclusive_top());
    REQUIRE(random_exclusive_top == 0.085466, "Pseudo-random number 5 was %lf, expected %lf", random_exclusive_top, 0.085466);
}

TEST(function, get_random_inclusive) {
    auto round = [](double value) -> double { return std::round(value * 1000000.0) / 1000000.0; };
    gtl::random_xorshift random_xorshift;
    random_xorshift.seed(0x01234567);
    double random_inclusive = round(random_xorshift.get_random_inclusive());
    REQUIRE(random_inclusive == 0.119707, "Pseudo-random number 1 was %lf, expected %lf", random_inclusive, 0.119707);
    random_inclusive = round(random_xorshift.get_random_inclusive());
    REQUIRE(random_inclusive == 0.658350, "Pseudo-random number 2 was %lf, expected %lf", random_inclusive, 0.658350);
    random_inclusive = round(random_xorshift.get_random_inclusive());
    REQUIRE(random_inclusive == 0.097069, "Pseudo-random number 3 was %lf, expected %lf", random_inclusive, 0.097069);
    random_inclusive = round(random_xorshift.get_random_inclusive());
    REQUIRE(random_inclusive == 0.349733, "Pseudo-random number 4 was %lf, expected %lf", random_inclusive, 0.349733);
    random_inclusive = round(random_xorshift.get_random_inclusive());
    REQUIRE(random_inclusive == 0.085466, "Pseudo-random number 5 was %lf, expected %lf", random_inclusive, 0.085466);
}

TEST(function, get_random_bounded_long) {
    gtl::random_xorshift random_xorshift;
    random_xorshift.seed(0x01234567);
    unsigned int random = random_xorshift.get_random(0u, 1u);
    REQUIRE(random == 1, "Pseudo-random number 1 was %u, expected %u", random, 1u);
    random = random_xorshift.get_random(0u, 1u);
    REQUIRE(random == 0, "Pseudo-random number 2 was %u, expected %u", random, 0u);
    random = random_xorshift.get_random(0u, 1u);
    REQUIRE(random == 1, "Pseudo-random number 3 was %u, expected %u", random, 1u);
    random = random_xorshift.get_random(0u, 1u);
    REQUIRE(random == 1, "Pseudo-random number 4 was %u, expected %u", random, 1u);
    random = random_xorshift.get_random(0u, 1u);
    REQUIRE(random == 1, "Pseudo-random number 5 was %u, expected %u", random, 1u);
}

TEST(function, get_random_bounded_double) {
    auto round = [](double value) -> double { return std::round(value * 1000000.0) / 1000000.0; };
    gtl::random_xorshift random_xorshift;
    random_xorshift.seed(0x01234567);
    double random = round(random_xorshift.get_random(-1.0, 0.0));
    REQUIRE(random == -0.880293, "Pseudo-random number 1 was %lf, expected %lf", random, -0.880293);
    random = round(random_xorshift.get_random(-1.0, 0.0));
    REQUIRE(random == -0.341650, "Pseudo-random number 2 was %lf, expected %lf", random, -0.341650);
    random = round(random_xorshift.get_random(-1.0, 0.0));
    REQUIRE(random == -0.902931, "Pseudo-random number 3 was %lf, expected %lf", random, -0.902931);
    random = round(random_xorshift.get_random(-1.0, 0.0));
    REQUIRE(random == -0.650267, "Pseudo-random number 4 was %lf, expected %lf", random, -0.650267);
    random = round(random_xorshift.get_random(-1.0, 0.0));
    REQUIRE(random == -0.914534, "Pseudo-random number 5 was %lf, expected %lf", random, -0.914534);
}

TEST(evaluation, random_numbers) {
    gtl::random_xorshift random_xorshift;
    random_xorshift.seed(0x01234567);
    int random_bias = 0;
    for (unsigned int iteration = 0; iteration < 1000000; ++iteration) {
        random_bias += (random_xorshift.get_random(0u, 1u) == 0) ? +1 : -1;
    }
    REQUIRE(random_bias == 736, "Pseudo-random number generator bias was %d, expected %d", random_bias, 736);
}