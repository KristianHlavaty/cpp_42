#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data data;
	data.value = 42;

	uintptr_t raw = Serializer::serialize(&data);

	Data* deserializedData = Serializer::deserialize(raw);

	std::cout << "Original Data pointer: " << &data << std::endl;
	std::cout << "Deserialized DAta pointer: " << deserializedData << std::endl;

	std::cout << "Original Data value: " << data.value << std::endl;
	std::cout << "Deserialized DAta value" << deserializedData->value << std::endl;

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