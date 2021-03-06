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
using std::integral_constant;
using std::make_index_sequence;
using std::make_tuple;
using std::size_t;
using std::tuple_size;

template <class F, size_t... Is>
constexpr auto index_apply_impl(F f,
                                index_sequence<Is...>) {
    return f(integral_constant<size_t, Is> {}...);
}

template <size_t N, class F>
constexpr auto index_apply(F f) {
    return index_apply_impl(f, make_index_sequence<N>{});
}

template <class Tuple, class F>
constexpr auto apply(Tuple t, F f) {
    return index_apply<tuple_size<Tuple>{}>(
        [&](auto... Is) { return f(get<Is>(t)...); });
}

constexpr auto concat() {
    return make_tuple();
}

template <class Tuple1, class Tuple2>
constexpr auto concat(Tuple1 t1, Tuple2 t2) {
    return apply(t1, [&](auto... args1) {
        return apply(t2, [&](auto... args2) {
            return make_tuple(args1..., args2...);
        });
    });
}

template <class Tuple, class... Tuples>
constexpr auto concat(Tuple t1, Tuples... ts) {
    return concat(t1, concat(ts...));
}

int main() {
    assert(concat() == make_tuple());
    assert(concat(make_tuple(1, 2)) == make_tuple(1, 2));
    assert(concat(make_tuple(1, 2), make_tuple(3, 4)) ==
           make_tuple(1, 2, 3, 4));
    assert(concat(make_tuple(1), make_tuple(),
                  make_tuple(2), make_tuple(3),
                  make_tuple(),
                  make_tuple(4)) == make_tuple(1, 2, 3, 4));
}
