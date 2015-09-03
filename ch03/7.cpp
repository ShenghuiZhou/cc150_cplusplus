#include <iostream>
#include <list> 
#include <string>
#include <algorithm>

using namespace std;

enum AnimalType {Dog, Cat};

struct AnimalInfo {
	string name;
	AnimalType type;

	AnimalInfo(const string &n="NULL", AnimalType t=Dog)
		:name(n),type(t) { }
};

class Animals {
	private:
		list<AnimalInfo> data;

		bool empty() const {
			return data.empty();
		}
	public:
		void enqueue (const string &name, AnimalType t) {
			data.push_back(AnimalInfo(name,t));
		}

		AnimalInfo dequeueAny() {
			if(empty()) {
				cerr << "Error: no dog/cat left" << endl;
				return AnimalInfo();
			}	
			auto ret = data.front();
			data.pop_front();
			return ret;
		}

		AnimalInfo dequeueDog() {
			if(empty()) {
				cerr << "Error: no dog/cat left" << endl;
				return AnimalInfo();
			}	
			auto iter = find_if(data.begin(),data.end(),[](const AnimalInfo &a) {
						return a.type == Dog;
					});
			if(iter==data.end()) {
				cerr << "Error: no dog left" << endl;
				return AnimalInfo();
			}
			auto ret = *iter;
			data.erase(iter);
			return ret;
		}
};
