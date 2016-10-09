// ConsoleApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <functional>


#include <memory>


using namespace DataStructs;
using namespace std;


class FileDeleter
{
    typedef FILE filePtr;

public:
    void operator()(filePtr *fp)
    { 
        printf("Closing file");
        if (NULL != fp)
        {
            fclose(fp);
        }
    }
};

class FileHandler
{ 
public:
    FileHandler(char *fName)
    {
        mFName = fName;
    }

    HRESULT Initialize()
    {
        FILE *pf;
        ::fopen_s(&pf,this->mFName, "w+");
        if (NULL == pf)
        {
            return E_FAIL;
        }

        printf("File opened\n");
        this->m_upFile.reset(pf);

        return S_OK;
    }

private:
    char *mFName;
    std::unique_ptr<FILE, FileDeleter> m_upFile;

};

void TestFileCode()
{
    FileHandler  fh("C:\\Users\\washahid\\Documents.txt");
    if (FAILED(fh.Initialize()))
    {
        printf("Unable to initialize file\n");
    }
}

#pragma region Inheritence
class Base
{
public:
    Base()
    {
        printf("Base Constructor\n");
    }
    virtual  ~Base()
    {
        printf("Base Destructor\n");
    }

    virtual void SomeFunction()
    {
        printf("Base some funciton\n");
    }
};

class Derived : public Base
{
private:
    typedef Base super;

public:
    Derived()
    {
        printf("Derived Constructor\n");
    }
    virtual ~Derived()
    {
        printf("Derived de Constructor\n");
    }
    void SomeFunction()
    {
        printf("Derived some funciton\n");
    }
};

class SecondDerived : public Derived
{
public:
    SecondDerived()
    {
        printf("Second Dervied constructor\n");
    }
    ~SecondDerived()
    {
        printf("Second Derived de constructor\n");
    }

};

#pragma endregion 

using namespace std;


void foo(std::function<int( int, int)>  myfunc)
{
    printf("%d", myfunc(1, 2));
}

int _tmain(int argc, _TCHAR* argv[])
{
    vector<int> numbers = { 1, 2, 3, 4, 5,6,7 };
    int extra = 5;
    auto myfunc = [=](int a, int b)->int{return a + b + extra; };
     foo(myfunc );
     

	return 0;
}