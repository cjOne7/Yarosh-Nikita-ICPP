#include <iostream>

using namespace std;

struct Triangle {
	int a;
	int b;
	int c;
};

bool lzeSestrojit(Triangle t) {
	return t.a + t.b > t.c && t.a + t.c > t.b && t.b + t.c > t.a;
}

bool lzeSestrojit(Triangle *t) {
	return t->a + t->b > t->c && t->a + t->c > t->b && t->b + t->c > t->a;
}

void tasks() {
//	Triangle triangle{};
//	cout << "Enter a: " << endl;
//	cin >> triangle.a;
//	cout << "Enter b: " << endl;
//	cin >> triangle.b;
//	cout << "Enter c: " << endl;
//	cin >> triangle.c;
//
//	if (lzeSestrojit(triangle)) {
//		cout << "Perimeter: " << triangle.a + triangle.b + triangle.c << endl;
//	} else {
//		cout << "Triangle can't be created with sides: "
//			 << triangle.a << " "
//			 << triangle.b << " "
//			 << triangle.c << endl;
//	}
//	//The third task
//	Triangle *triangle1 = &triangle;
//	cout << "Enter a: " << endl;
//	cin >> triangle1->a;
//	cout << "Enter b: " << endl;
//	cin >> triangle1->b;
//	cout << "Enter c: " << endl;
//	cin >> triangle1->c;
//
//	if (lzeSestrojit(triangle1)) {
//		cout << "Perimeter: " << triangle1->a + triangle1->b + triangle1->c << endl;
//	} else {
//		cout << "Triangle can't be created with sides: "
//			 << triangle1->a << " "
//			 << triangle1->b << " "
//			 << triangle1->c << endl;
//	};
//	delete triangle1;
//
//	//The forth task
//	auto *triangle2 = new Triangle;
//	delete triangle2;

	//The fifth task
	int numberOfTriangles;
	cout << "Enter number of triangles: " << endl;
	cin >> numberOfTriangles;
	auto *triangles = new Triangle[numberOfTriangles];
	for (int i = 0; i < numberOfTriangles; i++) {
		cout << "Enter a: " << endl;
		cin >> triangles[i].a;
		cout << "Enter b: " << endl;
		cin >> triangles[i].b;
		cout << "Enter c: " << endl;
		cin >> triangles[i].c;

		if (lzeSestrojit(triangles[i])) {
			cout << "Perimeter of triangle number " << i + 1 << " is "
				 << triangles[i].a + triangles[i].b + triangles[i].c;
		} else {
			cout << "Triangle can't be created with sides: "
				 << triangles[i].a << " "
				 << triangles[i].b << " "
				 << triangles[i].c << endl;
		}
	}

	delete[] triangles;

}


int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
