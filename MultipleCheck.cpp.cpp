#include<iostream>
#include<string>
using namespace std;


void computeLPS(string str, int* lps)
{
    int j = 0;
    lps[0] = 0;
    int i = 1;

    while(i < str.size())
    {
        if(str[i] == str[j])
        {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if( j!= 0)
            {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

bool isPeriodic(string periodic_string, int K)
{
    int m = periodic_string.size();
    
    if(m%K == 0)
    {
        int* lps;
        computeLPS(periodic_string, lps);
        if(lps[m - 1] == (m - K)) {return true;}
        else {return false;}
    }
    else {return false;}

}

int main()
{   
    string stroka = "ababababababab";
    cout << isPeriodic(stroka, 2);
    getchar();
}



