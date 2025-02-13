// itsy.bitsy
//
//  Copyright ⓒ 2019-present ThePhD.
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//  See https://github.com/ThePhD/itsy_bitsy#using-the-library for documentation.

// span shim for libraries that have not caught up

#ifndef ITSY_BITSY_EXAMPLE_SPAN_HPP
#define ITSY_BITSY_EXAMPLE_SPAN_HPP

#include <itsy/bitsy.hpp>

#if (defined(__has_include) && __has_include(<version>)) || (__cplusplus >= 202000L)
#include <version>
#endif

#if defined(__cpp_lib_span)

#include <span>

namespace shim
{
	using ::std::span;
}

#elif defined(__has_include) && __has_include(<range/v3/view/span.hpp>)

#include <range/v3/view/span.hpp>

namespace shim
{
	using ::ranges::span;
}

#elif (defined(__has_include) && __has_include(<nonstd/span.hpp>)) || (defined(ITSY_BITSY_USE_NONSTD_SPAN) && ITSY_BITSY_USE_NONSTD_SPAN != 0)

#include <nonstd/span.hpp>

namespace shim
{
	using ::nonstd::span;
}

#else

#error \
     "Cannot use this feature: a span of some sort is required! Please pull in the submodules or provide your own span on the include paths."

#endif // Span bullshit

#endif // ITSY_BITSY_EXAMPLE_SPAN_HPP
