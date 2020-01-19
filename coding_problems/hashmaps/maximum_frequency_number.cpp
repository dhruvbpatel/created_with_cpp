/*
Description:
You are given with an array of integers that contain numbers in random order. Write a program to find and return the number which occurs maximum times in the given input.
If more than one element occurs same number of times in the input, return the element which is present in the input first.

Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces

Output Format :
Most frequent element

Constraints :
1 <= N <= 10^5

Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 

Sample Output 1 :
2

*/
#include<bits/stdc++.h>

int highestFrequency(int *input, int n){	 
		
	unordered_map<int,int> map;

	for(int i=0;i<n;i++){

		int key = input[i];

		if(map.count(key)==0){
			map[key] = 1;
		}else{
			map[key]++;
		}

	}

        int max = map[input[0]];  // taking 1st input's count as max
        int ans = input[0]; // and ans as 1st input as we have set it's count as max;

     	int j=1;

     	while(j<n){
     		if(map[input[j]] > max){
     			max = map[input[j]];
     			ans = input[j];
     		}
     		j++;
     	}
     	return ans;
     	
 	}
