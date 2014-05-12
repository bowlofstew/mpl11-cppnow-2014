#include <boost/mpl11/detail/left_folds/until_naive.hpp>
#include <boost/mpl11/list.hpp>


struct f {
    using type = f;
    template <typename, typename>
    struct apply { struct type; };
};

template <int> struct x { struct type; };
<% xs = (1..n).map { |i| "x<#{i}>" }.join(', ') %>

struct state { struct type; };

using xs = boost::mpl11::list<
    <%= xs %>
>;

using go = boost::mpl11::detail::left_folds::until_naive<
    boost::mpl11::is_empty,
    f::type::apply,
    state,
    xs
>::type;