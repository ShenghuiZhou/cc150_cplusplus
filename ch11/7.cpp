#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Person {
	int height;
	int weight;

	Person(int h=0, int w=0)
		:height(h),weight(w) { }
};

int largestNumber(vector<Person> &team) {
	auto cmp = [](const Person &x, const Person &y) {
		if(x.height!=y.height) return x.height<y.height;
		return x.weight<y.weight;
	};
	sort(team.begin(),team.end(),cmp); //nlog(n)
	
	vector<int> ret(team.size(),1);
	//n^2
	for(int i=0; i!=team.size(); ++i) {
		for(int j=0; j!=i; ++j) {
			if(team[i].height>team[j].height && team[i].weight>team[j].weight) {
				ret[i] = max(ret[i],ret[j]+1);
			} 
		}
	}
	return ret.back(); 
}

int main() {
	vector<Person> team = {
		{65,100}, {70,150}, {56,90},
		{75,190}, {60,95}, {68,110}
	};
	cout << largestNumber(team) << endl;
}
