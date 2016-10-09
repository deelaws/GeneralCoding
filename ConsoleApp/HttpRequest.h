#include <string>


enum HttpConnectionType
{
    HTTP,
    HTTPS
};

interface IHttpRequestCallback
{
    virtual void OnResponseReceived(std::string &response) = 0;
};

class HttpConnection
{
public:
    HttpConnection();

    // used to check if the connection is valid/open.
    bool operator()();


private:
    SOCKET mSocket;

};



class HttpRequest
{
    HttpRequest();

    HRESULT Initialize(std::string& uri);

private:
    IHttpRequestCallback *pHttpCallback;
};