// ConsoleApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <functional>
#include <memory>

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

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

void foo(std::function<int( int, int)>  myfunc)
{
    printf("%d", myfunc(1, 2));
}

std::string ArrayToString(std::vector<int>& A)
{
	std::string ret = "{";

	for (size_t i = 0; i < A.size(); i++)
	{
		ret += " ";
		ret += std::to_string(A[i]);
		if (i != (A.size() - 1))
		{
			ret += ",";
		}
	}

	ret += "}";

	return ret;
}


void split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
}


int func(int i)
{
    if (i == 4)
    {
        return 2;
    }
    else
    {
        return 2 * func(i + 1);
    }
}



typedef void(*PFUNC) (void *p);

void AsyncComplete(void *p)
{
    printf("foolam\n");
}

void my_function(PFUNC pfc)
{
    (void)pfc;
    pfc(NULL);
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::string num_one = "11";
	std::string num_two = "11";

	auto ret = AddBinaryNumbers(num_one, num_two);

	printf("%s\n", ret.c_str());

    return 0;
}