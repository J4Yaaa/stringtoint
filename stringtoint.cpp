#include <iostream>
using namespace std;
#include <string>

enum Status
{
    invalid,
    valid
};

enum Status sta = invalid;

bool IsNumber(char c)
{
    return (c >= '0' && c < '9');
}

int stringtoint(const string& str)
{
    int num = 0;
    int flag = 1;
    int index = 0;
    //1.首先排除有一串空格的情况
    while(str[index] == ' ')
    {
        ++index;
    }
    //2.判断遇到+/-号的情况
    if(str[index] == '-')
    {
        flag = -1;
        ++index;
    }
    else if(str[index] == '+')
    {
        ++index;
    }
    //3.当前判断是数字的情况
    while(IsNumber(str[index]))
    {
        num *= 10;
        num += str[index] - '0';
        ++index;
    }
    if(str[index] == '\0')
    {
        sta = valid;
        return flag*num;
    }
    return 0;
}

int main()
{
    string str("           +12a345");
    int ret = stringtoint(str);
    if(sta == invalid)
    {
        cout<<"error str"<<endl;
    }
    else
    {
        cout<<ret<<endl;
    }
    return 0;
}
