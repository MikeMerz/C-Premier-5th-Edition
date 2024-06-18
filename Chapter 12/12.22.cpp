
#include "12.22.h"

StrBlobPtr StrBlob::begin() const
{
    return StrBlobPtr{*this};
}

StrBlobPtr StrBlob::end() const
{
    auto ret = StrBlobPtr{*this, data->size()};
    return ret;
}

