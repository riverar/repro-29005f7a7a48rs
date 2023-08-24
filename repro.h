#include <type_traits>

template <typename T>
struct XyzIsFunctionPointer : std::false_type
{
};

template <typename T>
struct XyzIsFunctionPointer<T *> : std::is_function<typename std::remove_pointer<T>::type>
{
};

template <
    typename T,
    typename std::enable_if<XyzIsFunctionPointer<T>::value, int>::type = 0>
void Test()
{
};
