/*

Given a string, you need to remove all the duplicates. That means,
the output string should contain each character only once. The respective order of characters should remain same.

Input format :
String S


Output format :
Output String

Constraints :
1 <= Length of S <= 50000

Sample Input 1 :
ababacd

Sample Output 1 :
abcd


*/



#include<bits/stdc++.h>
using namespace std;


char* uniqueChar(char *str){
    // Write your code here
    int n = strlen(str);
    
    map<char,int> mp;
    
    
    for(int i=0;i<n;i++){
        mp[str[i]]++;   // add count in hashmaps
    }
        
    char *ans = new char[n];
    int k=0;
    
    for(int i=0;i<n;i++){
        if(mp[str[i]]>=1){
            ans[k++]=str[i];    
            mp[str[i]]=0;  
        }
    }
    
    
    for(int i=0;i<k;i++){
        str[i]=ans[i];
    }   
    
    str[k]='\0';
    return str;
    
    
   
    
}
