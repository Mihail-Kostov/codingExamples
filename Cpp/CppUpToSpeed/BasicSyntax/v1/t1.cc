// In C++ this is one way to indicate that text is a comment
// It only marks the remainder of the line as a comment

/*
    This is the other way to indicate a comment.
    All text between the opening an closing markers is a comment.
    Comments made this way do not nest!
    This is sometimes call C-style comments.
 */

// Include some standard C++ headers.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <array>

// The main program starts here
int main() {

  // i is variable whose type is int; it is initiailized to a value of 4.
  int i = 4;

  // This is how to make printout to the screen
  // You must enclose uoted strings in double quotes ", not single quotes ' .
  std::cout << "i = " << i << std::endl;

  // You may assign a new value to a variable:
  i = 5;
  std::cout << "i = " << i << std::endl;

  // j is another variable whose type is int; it is intiailized to 3
  // This syntax is just another way to initialize things.
  //   i is initialized using "assignment style" ( or C style)
  //   j is initialized using "constructor" ( c'tor ) style.
  // The meaning of c'tor style will become clear when you learn about classes.

  int j(3);
  std::cout << "j = " << j << std::endl;

  // k is another variable whose type is int;
  // it is not initialized to any value.  Therefore its value is undefined and
  // it may change from one run of the program to another.
  int k;
  std::cout << "k = " << k << std::endl;

  // m is another variable whose type is int; it is initialized using
  // the "uniform initialization syntax", which is a value enclosed in
  // braces.
  int m { 6 };
  std::cout << "m = " << m << std::endl;

  // a is variable whose type is float.
  float a(1.234);
  std::cout << "a = " << a << std::endl;

  // b is variable whose type is double.
  double b(5.678);
  std::cout << "b = " << b << std::endl;

  // c is a variable whose type is bool (boolean)
  bool c = true;
  std::cout << "c = " << c << std::endl;

  // n is a variable whose type is "const int".
  // This means that it is a compiler error to attempt to change
  // its value at any time.  Try it!
  const int n(5);
  std::cout << "n = " << n << std::endl;

  // Uncomment this line and rebuild to get an error message.
  // n = 7;

  // n2 is a variable whose type is "int const", which means the same as "const int".
  // In most places the position of const is important and changes the meaning.
  // This is one of the few places that it does not.
  int const n2(6);
  std::cout << "n2 = " << n2 << std::endl;

  // l is a variable whose type is an array of int's, of length 5.
  // See below in the discussion of pl to learn more.
  int l[] = {0, 10, 20, 30, 40};

  // sizel is a variable whose type is std::size_t, which is an unsigned
  // integral type that C++ uses to to describe the length, or size,
  // of things that have a length, such as arrays.  "Unsigned integral
  // type" just means that it is an unsigned integer but we have not told
  // you if it is 16 bits long, 32 bits long or 64 bits long: the compiler
  // vendor made that choice and the answer is the type std::size_t.
  //
  // The value of sizel is the length, or size, of the array l
  // The functions sizeof are part of standard C++.
  std::size_t const sizel = sizeof(l)/sizeof(int);

  // Loops and accessing elements of an array using []
  for (std::size_t m = 0; m < sizel; ++m) {
    std::cout << "l[" << m << "] = " << l[m] << std::endl;
  }

  // == is a comparison but = is an assignment
  // Mixing this up is a common mistake.
  if (i == 5) {
    std::cout << "Yes, i is 5" << std::endl;
  }
  else {
    std::cout << "No, i is not 5" << std::endl;
  }

  // Conditionals.
  // if-elseif-else
  if (a >= 1. && a < 2.) {
    std::cout << "a is between 1 and 2." << std::endl;
  }
  else if (a >= 2. && a < 3.) {
    std::cout << "a is between 2 and 3." << std::endl;
  }
  else {
    std::cout << "a not between 1 and 3." << std::endl;
  }
  // ternary operator
  // This operator is especially useful when an expression, rather than
  // a statment, is needed, such as when initializing a variable.
  int status = ( a > 1.0) ? 1 : -1;
  std::cout << "status is: " << status << std::endl;

  // Some types from the C++ standard library

  // s is a variable whose type is "std::string"
  std::string s("this is a string");
  std::cout << "s = " << s << std::endl;

  // std::vector<T> behaves much like is an array of objects of type T.
  // It has the extra capability that its size can change as needed, unlike
  // an normal array, whose size is fixed at creation time.
  //
  // vs is a variable whose type is "std::vector<std::string>"
  // Note the use of the uniform initialization syntax,
  // this form of initialization is new with C++11.
  std::vector<std::string> vs { "zero", "one", "two", "three" };
  vs.push_back("four");

  // This 'size' of a vector is the number of elements it currently
  // contains. The 'extent' of a vector is how many elements it can hold
  // without needing an internal re-allocation of memory. The values are
  // not necessarily the same.
  std::cout << "Number of elments in vs: " << vs.size()     << std::endl;
  std::cout << "Capacity of vs:          " << vs.capacity() << std::endl;

  // std::array (new in C++ 11) is to be preferred to std::vector when
  // the size of the sequence of elements is known at compilation time,
  // and can not change. It is uniformly superior to the C-style array,
  // which should not be used in new code.
  //
  // std::array introduces our first use of non-type template
  // parameters; the second template parameter must be a non-negative
  // integral value.
  std::array<int, 5> betterL {0, 10, 20, 30, 40};
  // An array knows its own size.
  std::size_t sizeBetterL = betterL.size();
  std::cout << "sizeBetterL: " << sizeBetterL << std::endl;
  // Unlike C-style arrays, std::array instances can be copied.
  std::array<int, 5> anotherL(betterL);

  // Pointers

  // pa is a variable whose type is "pointer to float"
  // It points at the variable a.
  float* pa = &a;
  std::cout << "pa  = " << pa  << std::endl;
  std::cout << "*pa = " << *pa << std::endl;

  // This reassigns the value of the pointee:
  // But the value of the pointer is not changed.
  *pa = 5.678;
  std::cout << "a =   " << a   << std::endl;
  std::cout << "*pa = " << *pa << std::endl;
  std::cout << "pa  = " << pa  << std::endl;

  // pl is a variable whose type is "pointer to int"
  // In many contexts, an implicit conversion of type "array of type T"
  // to type "pointer to type T" will be made by the compiler; the
  // resulting value will be a pointer to the first element of the
  // array. So l is really a "pointer to int" So the right and left hand
  // sides of this assignment have the same type.
  int* pl = l;
  for (std::size_t m = 0; m < sizel; ++m) {
    std::cout << "*pl++ = " << *pl++ << std::endl;
  }

  // A variable of type std:string, has a function named size() that tells you
  // how many characters are in the string.  You will learn in the section
  // on classes that size() is properly called a member function.

  // Member selection with operator . (dot).
  std::string const animal { "cow" };
  std::cout << "The size of animal is: " << animal.size() << std::endl;

  // Dereferencing and member selection with operator->().
  std::string const*  panimal = &animal;
  std::cout << "The size of animal is: " << (*panimal).size() << std::endl;
  std::cout << "The size of animal is: " << panimal->size() << std::endl;

  // References

  // ra is variable whose type is "reference to float"
  // This means that ra is a compile-time alias that is equivalent to a.
  // Declaring ra does not allocate new memory; ra is not an object.
  float& ra(a);
  std::cout << "ra  = " << ra  << std::endl;

  // Taking the address of a reference yield the address of the
  // referent, because the reference itself is not an object.
  std::cout << "&a  = " << &a  << std::endl;
  std::cout << "&ra = " << &ra  << std::endl;

  // Assigning a value to a reference changes the value of referent.
  ra = -1.234;
  std::cout << "a   = " <<  a  << std::endl;
  std::cout << "ra  = " << ra  << std::endl;

  // There are various ways to write loops: you should be familiar with
  // them all.

  // Recall that vs is a std::vector<std::string>.
  for (size_t is = 0; is < vs.size(); ++is) {
    std::cout << "element " << is << " of vs is " << vs.at(is) << std::endl;
  }

  // ranged for loop - C++11 only
  for (std::string const&  ss : vs) {
    std::cout << "V2: " << ss << std::endl;
  }

  // ranged for loop with keyword auto - C++11 only
  for (auto const&  ss : vs) {
    std::cout << "V3: " << ss << std::endl;
  }

  // You don't need to understand the following in detail. Just
  // recognize the patterns and bookmark where to look things up when
  // you do need to know them.

  // iterators and the comma operator
  for (std::vector<std::string>::const_iterator is = vs.begin(), es = vs.end();
       is != es; ++is) {
    std::cout << "V4: " << *is << std::endl;
  }

  // iterators and auto (C++11 only)
  for (auto is = begin(vs), es = end(vs); is != es; ++is) {
    std::cout << "V5: " << *is << std::endl;
  }

  return 0;
}
