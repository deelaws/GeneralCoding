#include "Winhttp.h"


class HttpRequest
{
public:
    HttpRequest();
    ~HttpRequest();
    HRESULT InitializeSession();
    HRESULT Connect(std::wstring &server);

private:
    HINTERNET  mHSession;
    HINTERNET  mHConnect;
};