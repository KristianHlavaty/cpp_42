#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data data;
	data.value = 42;

	// uintptr_t
	// is an unsigned integer type such that any valid (void *) value can be converted
	// to this type and then converted back.  It is capable of storing values in  the  range  [0,
	// INTPTR_MAX].
	uintptr_t raw = Serializer::serialize(&data);

	Data* deserializedData = Serializer::deserialize(raw);

	std::cout << "Original Data pointer: " << &data << std::endl;
	std::cout << "Deserialized Data pointer: " << deserializedData << std::endl;

	std::cout << "Original Data value: " << data.value << std::endl;
	std::cout << "Deserialized Data value: " << deserializedData->value << std::endl;

	if(&data == deserializedData)
	{
		std::cout << "Pointers match! Serialization and deserialization worked :O, or did it? :O" << std::endl;
	}
	else
	{
		std::cerr << "Pointers do not match!" << std::endl;
	}

	return 0;
}