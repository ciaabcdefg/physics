#include "iostream"
#include "lib/atmosphere.h"
#include "lib/physics.h"
#include "lib/space.h"

using std::cout;
using space::Vector2;

using phys::PhysObj;

int main(void){
	PhysObj obj = PhysObj("My First Object");

	obj.velocity = Vector2(1, 1);

	for (int i = 0; i < 10; i++){
		phys::update();
		phys::status();
	}


	return 0;
}
