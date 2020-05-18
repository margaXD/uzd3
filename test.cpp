#include "head.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

double galutinisTEST(double egz, double nd)
{
	return 0.4 * nd + 0.6 * egz;
}
bool vargsiukasTEST(double vid)
{
	if (vid <= 5)
		return true;
	else return false;
}

TEST_CASE("ar teisingas galutinis")
{
	REQUIRE(galutinisTEST(7.1, 8.4) == 7.62);
	REQUIRE(galutinisTEST(2.1, 5.9) == 3.62);
}
TEST_CASE("ar palyginimas teisingas")
{
	REQUIRE(vargsiukasTEST(2) == false);
		REQUIRE(vargsiukasTEST(7) == true);
}