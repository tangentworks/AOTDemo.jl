#include <vector>
#include <iostream>
#include "../driver/foo.h"

int main()
{
    std::vector<double> v1 = {1, 2, 3, 4};
    std::vector<double> v2 = {1, 2, 3, 4, 5};

    std::vector<foo::Data> v {
        foo::Data{(wchar_t*)L"α", v1.data(), v1.size()},
        foo::Data{(wchar_t*)L"ω", v2.data(), v2.size()},
    };

    FOO_bar(v.data(), v.size());
    FOO_baz(v.data(), v.size(), (wchar_t*)L"log");

    return 0;
}
