#include <iostream>
using namespace std;
struct Point {
	float x, y;
};
struct Rect {
	Point leftBottom, rightTop;
	bool contain(const Point& pt) {
		return pt.x > leftBottom.x&& pt.x<rightTop.x && pt.y>leftBottom.y&& pt.y < rightTop.y;
	}
	void cut(Point& pt, const Point& dir) {		//根据方向向量将点裁剪到矩形上
		if (contain(pt))						//如果点在矩形内，则不需要对它裁剪
			return;
		Point offset = { 1,dir.y / dir.x };		//确定水平方向，计算垂直方向的偏移
		if (pt.x > rightTop.x)
			pt = { rightTop.x,pt.y + offset.y * (rightTop.x - pt.x) };
		else if (pt.x < leftBottom.x)
			pt = { leftBottom.x,pt.y + offset.y * (leftBottom.x - pt.x) };
		offset = { dir.x / dir.y,1 };			//确定垂直方向，计算水平方向的偏移
		if (pt.y > rightTop.y)
			pt = { pt.x + offset.x * (rightTop.y - pt.y), rightTop.y };
		else if (pt.y < leftBottom.y)
			pt = { pt.x + offset.x * (leftBottom.y - pt.y), leftBottom.y };
	}
};

istream& operator>>(istream& in, Point& pt) {
	in >> pt.x >> pt.y;
	return in;
}

int main() {
	Rect rect;
	Point p1, p2;
	Point dir;  //直线的方向向量

	cin >> rect.leftBottom >> rect.rightTop;
	cin >> p1 >> p2;
	dir = { p2.x - p1.x,p2.y - p1.y };
	rect.cut(p1, dir);
	rect.cut(p2, dir);
	if (p1.x == p2.x && p1.y == p2.y)
		printf("-1");
	else
		printf("(%0.2f,%0.2f)\n(%0.2f,%0.2f)", p1.x, p1.y, p2.x, p2.y);
	return 0;
}