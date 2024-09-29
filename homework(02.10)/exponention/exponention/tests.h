#include <stdbool.h>
bool isNormalInputData(unsigned int base,unsigned int degree) {
	return base > 0 && degree > 0 && base < 2147483647 && degree < 2147483647;
}