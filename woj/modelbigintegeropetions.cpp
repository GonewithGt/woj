#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
 
class BIGINTEGEROPERATIONS
{
private:
    static int COMPARE(string number1, string number2)
    {
        int j;
 
        int length1 = number1.size();
        int length2 = number2.size();
 
        if(number1.size() == 0) number1 = "0";
        if(number2.size() == 0) number2 = "0";
 
        j = 0;
        for(int i = 0; i < length1; ++i)
        {
            if(number1[i] == '0') ++j;
            else break;
        }
        number1 = number1.substr(j);
 
        j = 0;
        for(int i = 0; i < length2; ++i)
        {
            if(number2[i] == '0') ++j;
            else break;
        }
        number2 = number2.substr(j);
 
        length1 = number1.size();
        length2 = number2.size();
 
        if(length1 > length2)
        {
            return 1;
        }
        else if(length1 == length2)
        {
            if(number1.compare(number2) > 0)
            {
                return 1;
            }
            else if(number1.compare(number2) == 0)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }
        else 
        {
            return -1;
        }
 
        return 0;
    }
 
public:
    static string PLUS(string number1,string number2)
    {
        int i;
        int length1 = number1.size();
        int length2 = number2.size();
 
        string result="";
 
        reverse(number1.begin(), number1.end());
        reverse(number2.begin(), number2.end());
 
        for(i = 0; i < length1 && i < length2; i++)
        {
            char c = (char)(number1[i] + number2[i] - 48);
            result = result + c;
        }
 
        while(i < length1)
        {
            result = result + number1[i]; 
            ++i;
        }
 
        while(i < length2)
        {
            result = result + number2[i]; 
            ++i;
        }
    
        int carry = 0;
        for(i = 0; i < (int)result.size(); ++i)
        {
            int value = result[i] - 48 + carry;
            result[i] = (char)(value % 10 + 48);
            carry = value / 10;
        }
    
        if(carry !=0 ) 
        {
            result = result + (char)(carry + 48);
        }
 
        for(i = result.size() - 1; i >= 0; i--)
        {
            if(result[i] != '0') break;
        }
 
        result = result.substr(0, i + 1);
 
        reverse(result.begin(), result.end());
        if(result.length() == 0) result = "0";
        return result;
    }
 
 
    static string MINUS(string number1,string number2)
    {
        int i;
        string result = "";
 
        int length1 = number1.size();
        int length2 = number2.size();
 
        if(COMPARE(number2,number1) > 0)
        {
            return "-" + MINUS(number2, number1);
        }
 
        reverse(number1.begin(),number1.end());
        reverse(number2.begin(),number2.end());
     
        for(i = 0; i < length1 && i < length2; i++)
        {
            char c = number1[i] - number2[i] + 48;
            result = result + c;
        }
 
        if(i < length1)
        {
            for(; i < length1; i++)
            {
                result = result + number1[i];
            }
        }
    
        int carry = 0;
        for(i = 0; i < (int)result.length(); i++)
        {
            int value = result[i] - 48 + carry;
            if(value < 0)
            {
                value = value + 10;
                carry = -1;
            }
            else carry = 0;
            result[i]=(char)(value + 48);
        }
 
        for(i = result.size() - 1; i >= 0; i--)
        {
            if(result[i] != '0')break;
        }
 
        result = result.substr(0, i+1);
 
        reverse(result.begin(), result.end());
        if(result.length()==0) result = "0";
        return result;
    }
 
 
    static string MULTIPLY(string number1, string number2)
    {
        int i, j;
        int *iresult;
        int length1 = number1.size();
        int length2 = number2.size();
        string result = "";
 
        reverse(number1.begin(), number1.end());
        reverse(number2.begin(), number2.end());
 
        iresult = (int*)malloc(sizeof(int) * (length1 + length2 + 1));
        memset(iresult, 0, sizeof(int) * (length1 + length2 + 1));
 
        for(i = 0; i < length1; i++)
        {
            for(j = 0; j < length2; j++)
            {
                iresult[i+j] += ((number1[i] - 48) * (number2[j] - 48));
            }
        }
 
        int carry = 0;
        for(i = 0; i < length1 + length2; i++)
        {
            int value = iresult[i] + carry;
            iresult[i] = value % 10;
            carry = value / 10;
        }
    
        for(i = length1 + length2 - 1; i >= 0; i--)
        {
            if(iresult[i] != 0)break;
        }
 
        for(; i >= 0; i--)
        {
            result = result + (char)(iresult[i]+48);
        }
 
        free(iresult);
 
        if(result == "") result = "0";
        return result;
    }
 
 
    // 缺省地，商数向下取整， floatpoint用于指定保留小数点的位数
    static string DIVIDE(string number1, string number2, int floatpoint = 0)
    {
        int i, j, pos;
        string result = "";
        string tempstr = "";
        int length1 = number1.size();
        int length2 = number2.size();
 
        if((COMPARE(number2, number1) > 0) && (floatpoint == 0))
        {
            return "0";
        }
 
        tempstr = number1.substr(0, length2);
        pos = length2 - 1;
    
        while(pos < length1)
        {
            int quotient = 0;
            while(COMPARE(tempstr, number2) >= 0)
            {
                quotient++;
                tempstr = MINUS(tempstr, number2);
            }
        
            result = result + (char)(quotient + 48);
            pos++;
            if(pos < length1)
            {
                tempstr += number1[pos];
            }
        }
 
        if(floatpoint > 0)
        {
            result += '.';
            string stmp = "1";
            int itmp = 0;
            for(int k = 0; k < floatpoint; ++k)
            {
                stmp += '0';
                if(COMPARE(MULTIPLY(MINUS(number1, MULTIPLY(DIVIDE(number1, number2), number2)), stmp), number2) < 0)
                {
                    result += '0';
                    ++itmp;
                }
            }
 
            string temp = DIVIDE(MULTIPLY(MINUS(number1, MULTIPLY(DIVIDE(number1, number2), number2)), stmp), number2);
            if(temp[0] != '0') result += temp;
        }
 
        j = result.size();
        for(i = 0; i < j; i++) 
        {
            if(result[i] != '0') break;
        }
 
        result = result.substr(i, j);
 
        return result;
    }
 
    static string MOD(string number1, string number2)
    {
        if(COMPARE(number2, number1) > 0)
        {
            return number1;
        }
        else if(COMPARE(number2, number1) == 0)
        {
            return "0";
        }
        else
        {
            return MINUS(number1, MULTIPLY(DIVIDE(number1, number2), number2));
        }
    }
};
 
int main(int argc, char* argv[])
{
    string str1 = "9999999999999999999999999999999999999999";
    string str2 = "9998999899989998999899989998999899989998";
 
    cout << BIGINTEGEROPERATIONS::PLUS(str1, str2) << endl;
    cout << "===============" << endl;
    cout << BIGINTEGEROPERATIONS::MINUS(str1, str2) << endl;
    cout << "===============" << endl;
    cout << BIGINTEGEROPERATIONS::MULTIPLY(str1, str2) << endl;
    cout << "===============" << endl;
    cout << BIGINTEGEROPERATIONS::DIVIDE(str1, str2, 4) << endl;
    cout << "===============" << endl;
    cout << BIGINTEGEROPERATIONS::MOD(str1, str2) << endl;
 
    return 0;
}

