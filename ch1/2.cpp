/*----------------------------------------------------
> File Name:    2.cpp
> Author:       Shenghui Zhou
> Mail:         shzhouus@gmail.com 
> Created Time: Fri 17 Apr 2015 11:02:47 AM CDT
----------------------------------------------------*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <unordered_map>
#include <utility>
#include <iterator>

using namespace std;

void swap(char &a, char &b) {
	a = a^b;
	b = a^b;
	a = a^b;
}

void reverse(char *str) {
	const int N = strlen(str);
	for(int i=0, j=N-1; i<j; ++i,--j) {
		swap(str[i],str[j]);
	}
}
