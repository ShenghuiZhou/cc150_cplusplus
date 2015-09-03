#include <cmath>
#include <limits>
#include <iostream>

using namespace std;

constexpr double EPSILON = 0.000001;
bool areSame(double a, double b) {
	return fabs(a-b) < EPSILON;
	//return fabs(a-b) < numeric_limits<double>::epsilon();
}

class MyLine {
	private:
		double slope;
		double y_intersect;
	public:
		MyLine(double k, double b)
			:slope(k),y_intersect(b) { }
		~MyLine() { }

		friend bool operator == (const MyLine &l1, const MyLine &l2) {
			return areSame(l1.slope, l2.slope) && areSame(l1.y_intersect, l2.y_intersect); 
		}

		bool solution(const MyLine &rhs) {
			return *this==rhs || !areSame(slope,rhs.slope);
		}
};
