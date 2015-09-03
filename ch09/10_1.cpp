#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct myBox  {
	int h;
	int w;
	int d;
	myBox(int height, int width, int depth) 
		:h(height),w(width),d(depth) { }
};

void solution(const vector<myBox> &boxes) {
	vector<myBox> all_boxes;
	for(const auto &b:boxes) {
		all_boxes.push_back(myBox(b.h,min(b.w,b.d),max(b.w,b.d)));
		all_boxes.push_back(myBox(b.w,min(b.h,b.d),max(b.h,b.d)));
		all_boxes.push_back(myBox(b.d,min(b.h,b.w),max(b.h,b.w)));
	}
	sort(all_boxes.begin(),all_boxes.end(),[](const myBox &b1, const myBox &b2) {
			return b1.w*b1.d < b2.w*b2.d;
			});

	vector<int> results (all_boxes.size(),0);
	for(int i=0; i!=all_boxes.size(); ++i) results[i] = all_boxes[i].h;
	for(int i=1; i!=all_boxes.size(); ++i) {
		for(int j=0; j!=i; ++j) {
			if(all_boxes[j].w<all_boxes[i].w &&
					all_boxes[j].d<all_boxes[i].d &&
					all_boxes[i].h+results[j]>results[i]) {
				results[i] = all_boxes[i].h + results[j];
			}
		}
	}

	for(int i=0; i!=all_boxes.size(); ++i) {
		cout<<all_boxes[i].h<<"x"<<all_boxes[i].w<<"x"<<all_boxes[i].d
			<<"		"<<results[i]<<endl;
	}
}
int main()
{
	vector<myBox> boxes = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
	solution(boxes);
}
