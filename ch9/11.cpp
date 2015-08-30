#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

//Key specializes a substring beginning at Key.b and ending at Key.e
struct Key {
	int b;
	int e;

	Key(int beg=0, int end=0)
		:b(beg),e(end) { }

	friend bool operator == (const Key &k1, const Key &k2) {
		return k1.b==k2.b && k1.e==k2.e;
	}
};

//KeyHasher provides the hash method in order to use Key as the key of std::unordered_map
class KeyHasher {
	public:
		size_t operator() (const Key &k) const {
			size_t seed = 0;
			combine_hash(seed,k.b);
			combine_hash(seed,k.e);
			return seed;
		}
	private:
		void combine_hash(size_t &seed, int i) const {
			hash<int> int_hasher;
			seed ^= 0x9e3779b9 + int_hasher(i) + (seed<<6) + (seed>>2);
		}
};

vector<int> solution(int b, int e, unordered_map<Key,vector<int>,KeyHasher> &f, const string &str) {
	if(b==e-1) {
		if(str[b]=='0') return {1,0};
		else return {0,1};
	}
	Key cur_key = Key(b,e);
	if(f.find(cur_key)!=f.end()) return f[cur_key];
	f[cur_key] = {0,0};
	for(int i=b; i!=e; ++i) {
		char c = str[i];
		if(c!='1' && c!='0') {
			auto left = DFS(b,i,f,str);
			auto right = DFS(i+1,e,f,str);

			if(c=='*') {
				f[cur_key][0] += left[0]*right[0] + left[0]*right[1] + left[1]*right[0];
				f[cur_key][1] += left[1]*right[1];
			}

			else if(c=='|') {
				f[cur_key][0] += left[0]*right[0];
				f[cur_key][1] += left[1]*right[1] + left[1]*right[0] + left[0]*right[1];
			}

			else {
				f[cur_key][0] += left[0]*right[0] + left[1]*right[1];
				f[cur_key][1] += left[0]*right[1] + left[1]*right[0];
			}
		}
	}
	return f[cur_key];
}

vector<int> solution(const string &str) {
	if(str.empty()) return {0,0};
	unordered_map<Key,vector<int>,KeyHasher> f;
	return DFS(0,str.size(),f,str);
}

int main() {
	string test = "1^0|0|1";
	auto r = solution(test);
	cout << r[0] << " " << r[1] << endl;
}
