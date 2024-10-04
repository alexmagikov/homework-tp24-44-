#include <stdbool.h>
bool isNormalInputData(unsigned int base,unsigned int degree) {
	return base > 0 && degree > 0 && base < 31 && degree < 31	;
}