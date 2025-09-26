#include <iostream>

template<typename T>
class Vector2 {
	public:
		T x, y;
};

template<typename T>
void display( Vector2<T> v) {
	std::cout << v.x << '/' << v.y << std::endl;
}

int main() {
	display( Vector2<int>{2*2*2, -3*3});
}

