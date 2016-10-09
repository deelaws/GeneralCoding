#include "IHttpRequest.h"
#include <functional>



__interface IHttpRequestHandler
{
    HRESULT HandleRequest(IHttpRequest& rRequest, std::function<HRESULT(HttpResponseCode, std::string &response)> callback);
};
