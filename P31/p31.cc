#include <iostream>

using namespace std;

int mySqrt(int x) {
	// Time: O(logx)
	// Space: O(1)
	if(x == 0 || x == 1) return x;

    int start = 0, end = x, res;
	while(start <= end){
		long mid = start + (end - start) / 2;
		if(mid * mid == x) return mid;
		else if(mid * mid > x ){
			res = mid - 1;
			end = res;
		}
		else start = mid + 1;
	}
	return res;
}

int main(int argc, char *argv[]){
	cout << mySqrt(10) << endl;
	return 0;
}