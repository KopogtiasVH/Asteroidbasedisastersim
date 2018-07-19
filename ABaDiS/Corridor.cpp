#include "stdafx.h"
#include "Corridor.h"


Corridor::Corridor() : Room()
{
	kor = Enumerators::KindOfRoom::street;
	name = NameGenerator::streetName(kor);
}
