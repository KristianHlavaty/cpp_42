#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	try
	{	
		Data data;
		data.value = 42;

		// Data *wrong = NULL; // UNCOMMENT FOR EVAL TO TEST ERROR

		// uintptr_t
		// is an unsigned integer type such that any valid (void *) value can be converted
		// to this type and then converted back.  It is capable of storing values in  the  range  [0,
		// INTPTR_MAX].
		// uintptr_t wrongRaw = Serializer::serialize(wrong); // UNCOMMENT FOR EVAL TO TEST ERROR
		uintptr_t raw = Serializer::serialize(&data);


		Data* deserializedData = Serializer::deserialize(raw);
		// Data* deserializedDataWrong = Serializer::deserialize(wrongRaw); // UNCOMMENT FOR EVAL TO TEST ERROR
		// (void)deserializedDataWrong; // UNCOMMENT FOR EVAL TO TEST ERROR

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
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}