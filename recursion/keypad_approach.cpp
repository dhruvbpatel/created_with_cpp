/*
Question:
Return Keypad Code

Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.

Return empty string for numbers 0 and 1.

Note : The order of strings are not important.

Input Format :
Integer n
Output Format :
All possible strings in different lines

Constraints :
1 <= n <= 10^6

Sample Input:
23

Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf


*/

#include<iostream>
#include<string>
using namespace std;

string getString(int n)    // for getting the respective string 
{
    if (n == 2)
    {
        return "abc";
    }
    if (n == 3)
    {
        return "def";
    }
    if (n == 4)
    {
        return "ghi";
    }
    if (n == 5)
    {
        return "jkl";
    }
    if (n == 6)
    {
        return "mno";
    }
    if (n == 7)
    {
        return "pqrs";
    }
    if (n == 8)
    {
        return "tuv";
    }
    if (n == 9)
    {
        return "wxyz";
    }
    return " ";
}

int keypad(int num,string output[]){

    if(num==0){    // base case
        output[0]="";  
        return 1;   // return 1 if num is 0

    }

    int ld =  num%10;   // get the last digit
    int sn = num/10;   // get the remaining number

    int smallOutputSize = keypad(sn,output);   //  fill the output array with sn subsequence;

    string option = getString(ld);  // get the respective string of last digit


    for(int i=0;i<option.length()-1;i++){   // len -1 because we just want to create 1 less copy as 1st copy we have
        for(int j=0;j<smallOutputSize;j++ ){    
            output[j+(i+1)*smallOutputSize]=output[j];    // for copying each element of output till smallOutput size and repeating till len-1 times
        }
    }

    int k=0;   // take k index =0
    for(int i=0;i<option.length();i++){    // now we have to append individual character of option
        for(int j=0;j<smallOutputSize;j++){
            output[k]=output[k]+option[i];    // append at last   
            k++;   // increase index
        }
    }
 
    return smallOutputSize*option.length();    // returm the final size of output array
}

