#include "RandomVizualizer.h"
#include "TestGenerator.h"
#include "AllAlgoHeaders.h"
#include "TestExecutor.h"

int main()
{
	TestExecutor TE = TestExecutor();
	StupidSolution stupid = StupidSolution();

	/*TE.RunAllTests(FF, TestExecutor::Strategy::Full);                          Done */
	/*TE.RunAllTests(SFF, TestExecutor::Strategy::Full);                         Done */
	/*TE.RunAllTests(ShFF10, TestExecutor::Strategy::Full);                      Done */
	/*TE.RunAllTests(ShFF100, TestExecutor::Strategy::Partially);                Done */
	/*TE.RunAllTests(ShFF1000, TestExecutor::Strategy::Partially);               Done */
	/*TE.RunAllTests(ShFF10000, TestExecutor::Strategy::SmallOnly);              Done */              
	/*TE.RunAllTests(ShFF100000, TestExecutor::Strategy::SmallOnly);             Done */
	TE.RunAllTests(stupid, TestExecutor::Strategy::SmallOnly);
	
	return 0;
}