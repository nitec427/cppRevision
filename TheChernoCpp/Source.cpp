//#include <iostream>
//#define LOG(x) std::cout << x << std::endl;
//
//// Get the following variable from another file during linker stages
// extern int not_static_var;
// extern int not_static2;
// extern int you_can_use_from_another_file;
//
//
// void changeRef(int& ref_var) {
//	ref_var = 10;
//	return;
// }
//
// int main() {
//	LOG("Hello World");
//	char* buffer = new char[8];
//	memset(buffer, 62, 8);
//	int x = 36;
//	changeRef(x);
//		LOG(x);
//	LOG(not_static_var) // imported from another file
//	LOG(not_static2) // imported from another file
//	LOG(you_can_use_from_another_file) // canpolat cannot be imported from another file, becuase it is static
//	std::cin.get();
// }