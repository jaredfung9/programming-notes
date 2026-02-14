#include <criterion/criterion.h>

Test(queuetests, create) {
	int a = 5;
	cr_expect (a == 5, "a should equal 5");
}
