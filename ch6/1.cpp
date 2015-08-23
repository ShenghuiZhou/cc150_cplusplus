#include <vector>
#include <iostream>
using namespace std;

int solution(const vector<double> &weights) {
	double should_be = 0, cnt = 0;
	for(int i=0; i!=weights.size(); ++i) {
		should_be += (i+1)*1.0;
		cnt += (i+1)*weights[i];
	}
	auto ret = (cnt-should_be)/0.1;
	return int(ret+0.5)-1;
}

int main() {
	vector<double> weights (20,1);
	weights[10] = 1.1;
	cout << solution(weights) << endl;
}
