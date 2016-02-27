/*
 * Tuple Examples
 * Copyright (c) 2016 Andreas Herrmann
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include <cassert>
#include <functional>
#include <tuple>
#include <utility>

using std::get;
using std::index_sequence;
using std::make_index_sequence;
using std::make_tuple;
using std::plus;
using std::size_t;
using std::tuple_size;

template <class Tuple, size_t... Is>
constexpr auto take_front_impl(Tuple t,
                               index_sequence<Is...>) {
    return make_tuple(get<Is>(t)...);
}

template <size_t N, class Tuple>
constexpr auto take_front(Tuple t) {
    return take_front_impl(t, make_index_sequence<N>{});
}

template <class Tuple, class F, size_t... Is>
constexpr auto apply_impl(Tuple t, F f,
                          index_sequence<Is...>) {
    return f(get<Is>(t)...);
}

template <class Tuple, class F>
constexpr auto apply(Tuple t, F f) {
    return apply_impl(
        t, f, make_index_sequence<tuple_size<Tuple>{}>{});
}

int main() {
    assert(take_front<2>(make_tuple(1, 2, 3, 4)) ==
           make_tuple(1, 2));
    assert(apply(make_tuple(1, 2), plus<>{}) == 3);
}
