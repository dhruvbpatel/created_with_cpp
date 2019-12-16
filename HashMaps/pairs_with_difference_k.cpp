/*

You are given with an array of integers and an integer K. Write a program to find and print all pairs which have difference K.

Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Line 3 : K

Output format :
Print pairs in different lines (pair elements separated by space). In a pair, smaller element should be printed first.
(Order of different pairs is not important)


Constraints :
1 <= n <= 5000

Sample Input 1 :
4 
5 1 2 4
3


Sample Output 1 :
2 5
1 4


*/

#include<bits/stdc++.h>
using namespace std;
void printPairs(int *arr, int n, int k) {
	// Write your code here
  
 
    unordered_map<int,int> mp;
    
    
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    
    
    for(int i=0;i<n;i++){
        
        
     if(k==0){
         
        int mul =((mp[arr[i]])*(mp[arr[i]]-1))/2;
         
           
            while(mul!=0){
                cout<<arr[i]<<" "<<arr[i]<<endl;
                mul--;
            }
         
         break;
     }   
         
        
        
        
        
        
        
        if(mp.count(arr[i]-k)>0){
            
            int mul = mp[arr[i]]*mp[arr[i]-k];
            
             
            while(mul!=0){
                cout<<min(arr[i],arr[i]-k)<<" "<<max(arr[i],arr[i]-k)<<endl;
                mul--;
            }
            
        } if(mp.count(arr[i]+k)>0){
            
            
              int mul = mp[arr[i]]*mp[arr[i]+k];
            
             
            while(mul!=0){
                cout<<min(arr[i],arr[i]+k)<<" "<<max(arr[i],arr[i]+k)<<endl;
                mul--;
            }
            
        }
        
        mp[arr[i]]=0;
        
    }
    
    
    
    
}


