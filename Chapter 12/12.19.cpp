#include "12.19.h"

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr{*this};
}

StrBlobPtr StrBlob::end()
{
     auto ret = StrBlobPtr{*this, data->size()};
     return ret;
}

