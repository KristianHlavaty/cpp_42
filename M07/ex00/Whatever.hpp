#ifndef WHATEVER_HPP
#define WHATEVER_HPP

// probably delete 
// your CLASSES must be designed in the Orthodox Canonical Form
class Whatever
{
	private:
	// change later to public based on what i need
		Whatever(); // default constructor
		Whatever(const Whatever &other); // copy constructor
		Whatever &operator=(const Whatever &other); // copy assignement operator
		~Whatever(); // destructor

	public:
	// min max swap later
	// errors
};

template <typename T>
void swap(T &a, T &b)
{
		T temp = a;
		a = b;
		b = temp;
}

template <typename T>
const T &min(const T &a, const T &b)
{
	return (a < b) ? a : b;
}

template <typename T>
const T &max(const T &a, const T &b)
{
	return (a > b) ? a : b;
}

#endif