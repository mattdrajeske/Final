#include <stdio.h>
#include "Qtree.h"

//Point::Point() {
//
//}
//
//Rectangle::Rectangle() {
//	x;
//	y;
//	w;
//	h;
//}
//
//void Rectangle::contains(float point) {
//	return (point.x >= x - w && point.x <= x + w && point.y >= y - h && point.y <= y + h)
//
//}
//
//void Rectangle::intersects(int range) {
//	return (range.x - range.w > x + w || range.x + range.w < x - w || range.y - range.h > y + h || range.y + range.h < y - h);
//}

QuadTree::QuadTree(ofRectangle bound, float cap) {
	bound = boundary;
	cap = capacity;
}

void QuadTree::subdivide() {
	int x = boundary.x;
	int y = boundary.y;
	int w = boundary.w / 2;
	int h = boundary.h / 2;

	float ne = new Rectangle(x + w, y - h, w, h);
	northeast = new QuadTree(ne, capacity);

	float nw = new Rectangle(x - w, y - h, w, h);
	northwest = new QuadTree(nw, capacity);

	float se = new Rectangle(x + w, y + h, w, h);
	southeast = new QuadTree(se, capacity);

	float sw = new Rectangle(x - w, y + h, w, h);
	southwest = new QuadTree(sw, capacity);

	divided = true;
}


void QuadTree::insert(float point) {
	if (!boundary.contains(point)) {
		return false;
	}

	if (points.length() < capacity) {
		points.push(point);
		return true;
	}

	if (!this.divided) {
		subdivide();
	}

	return (northeast.insert(point) || northwest.insert(point) || southeast.insert(point) || southwest.insert(point));
}

void QuadTree::query(range, found) {
	if (!found) {
		found = [];
	}

	if (!range.intersects(boundary)) {
		return found;
	}

	for (let p of points) {
		if (range.contains(p)) {
			found.push(p);
		}
	}
	if (divided) {
		northwest.query(range, found);
		northeast.query(range, found);
		southwest.query(range, found);
		southeast.query(range, found);
	}

	return found;
}