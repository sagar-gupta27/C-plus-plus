#include "type_traits.h"
namespace std
{

    template <typename...>
    using __void_t = void;
    /// Implementation of the detection idiom (negative case).
    template <typename _Default, typename _AlwaysVoid,
              template <typename...> class _Op, typename... _Args>
    struct __detector
    {
        using type = _Default;
        using __is_detected = false_type;
    };

    /// Implementation of the detection idiom (positive case).
    template <typename _Default, template <typename...> class _Op,
              typename... _Args>
    struct __detector<_Default, __void_t<_Op<_Args...>>, _Op, _Args...>
    {
        using type = _Op<_Args...>;
        using __is_detected = true_type;
    };

    template <typename _Default, template <typename...> class _Op,
              typename... _Args>
    using __detected_or = __detector<_Default, void, _Op, _Args...>;

    // _Op<_Args...> if that is a valid type, otherwise _Default.
    template <typename _Default, template <typename...> class _Op,
              typename... _Args>
    using __detected_or_t = typename __detected_or<_Default, _Op, _Args...>::type;
}