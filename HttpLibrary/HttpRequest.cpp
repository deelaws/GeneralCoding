#include "Precompiled.h"

HttpRequest::HttpRequest()
    : mHSession(NULL)
{

}

HttpRequest::~HttpRequest()
{
}

HRESULT HttpRequest::InitializeSession()
{
    HRESULT hr = S_OK;
    this->mHSession = WinHttpOpen(L"WinHTTP Example/1.0",
        WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
        WINHTTP_NO_PROXY_NAME,
        WINHTTP_NO_PROXY_BYPASS, 0);

    if (!this->mHSession)
    {
        hr = E_FAIL;
    }

    return hr;
}

HRESULT HttpRequest::Connect(std::wstring &server)
{
    HRESULT hr = S_OK;

    this->mHConnect = ::WinHttpConnect(this->mHSession,
        server.c_str(),
        INTERNET_DEFAULT_HTTPS_PORT,
        0);

    return hr;
}
