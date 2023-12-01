#include "iostream"
#include "lib/atmosphere.h"
#include "lib/physics.h"
#include "lib/space.h"

using std::cout;
using space::Vector2;

using phys::PhysObj;

int main(void){
	PhysObj obj = PhysObj("My First Object");
	
	Vector2 v1 = Vector2(5, 2);
	Vector2 v2 = Vector2(-1, 1);

	v1 -= v2;

	cout << v1;


	return 0;
}
