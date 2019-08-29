// itsy.bitsy
//
//  Copyright ⓒ 2019-present ThePhD.
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//  See http://www.boost.org/libs/out_ptr/ for documentation.

#include <itsy_tests/shared_insert_erase_tests.hpp>

#include <catch2/catch.hpp>

#include <itsy/bitsy.hpp>

#include <vector>
#include <deque>
#include <list>
#include <string>

TEMPLATE_TEST_CASE("dynamic_bitset bulk insert/erase/clear test, small unsigned",
  "[dynamic_bitset][bulk][insert][erase][clear][unsigned]", std::uint64_t, std::uint32_t,
  std::uint16_t, std::uint8_t, std::byte, char32_t, char16_t, unsigned char, std::size_t)
{
	SECTION("vector")
	{
		bitsy::bit_sequence<std::vector<TestType>> storage;
		dynamic_bitset_insert_erase_test_bulk_small<TestType>(storage);
	}
	SECTION("std::basic_string")
	{
		bitsy::bit_sequence<std::basic_string<TestType>> storage;
		dynamic_bitset_insert_erase_test_bulk_small<TestType>(storage);
	}
	SECTION("deque")
	{
		bitsy::bit_sequence<std::deque<TestType>> storage;
		dynamic_bitset_insert_erase_test_bulk_small<TestType>(storage);
	}
	SECTION("list")
	{
		bitsy::bit_sequence<std::list<TestType>> storage;
		dynamic_bitset_insert_erase_test_bulk_small<TestType>(storage);
	}
}
