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
#include <macro.tests.hpp>
#include <pimpl.test.hpp>

#include <pimpl>

#include <type_traits>

template<>
class test_pimpl::implementation final {
public:
    int value;
public:
    implementation(int value)
        : value(value) {
    }
};

test_pimpl::test_pimpl(int value)
    : pimpl(value) {
}

int test_pimpl::return_value(void) const {
    return (*this)->value;
}

TEST(traits, sizeof) {
    REQUIRE(sizeof(test_pimpl) == 4, "sizeof(test_pimpl) = %ld, expected >= %lld", sizeof(test_pimpl), 1ull);
}

TEST(traits, is_not_pod) {
    REQUIRE(std::is_pod<test_pimpl >::value == false, "Expected std::is_pod to be false.");
}

TEST(traits, is_not_trivial) {
    REQUIRE(std::is_trivial<test_pimpl >::value == false, "Expected std::is_trivial to be false.");
}

TEST(traits, is_trivially_copyable) {
    REQUIRE(std::is_trivially_copyable<test_pimpl >::value == true, "Expected std::is_trivially_copyable to be true.");
}

TEST(traits, is_standard_layout) {
    REQUIRE(std::is_standard_layout<test_pimpl >::value == true, "Expected std::is_standard_layout to be true.");
}

TEST(evaluation, return_value) {
    test_pimpl pimpl(1);
    REQUIRE(pimpl.return_value() == 1);
}