#include "RandomVizualizer.h"
#include "TestGenerator.h"
#include "AllAlgoHeaders.h"
#include "TestExecutor.h"

int main()
{
	TestExecutor TE = TestExecutor();
	WFAlgo WF = WFAlgo();
	SWFAlgo SWF = SWFAlgo();
	ShWFAlgo ShWF10 = ShWFAlgo(10);
	ShWFAlgo ShWF100 = ShWFAlgo(100);
	ShWFAlgo ShWF1000 = ShWFAlgo(1000);
	ShWFAlgo ShWF10000 = ShWFAlgo(10000);
	ShWFAlgo ShWF100000 = ShWFAlgo(100000);

	/*TE.RunAllTests(FF, TestExecutor::Strategy::Full);                          Done */
	/*TE.RunAllTests(SFF, TestExecutor::Strategy::Full);                         Done */
	/*TE.RunAllTests(ShFF10, TestExecutor::Strategy::Full);                      Done */
	/*TE.RunAllTests(ShFF100, TestExecutor::Strategy::Partially);                Done */
	/*TE.RunAllTests(ShFF1000, TestExecutor::Strategy::Partially);               Done */
	/*TE.RunAllTests(ShFF10000, TestExecutor::Strategy::SmallOnly);              Done */              
	/*TE.RunAllTests(ShFF100000, TestExecutor::Strategy::SmallOnly);             Done */

	/*TE.RunAllTests(stupid, TestExecutor::Strategy::SmallOnly);                 Done */

	/*TE.RunAllTests(BF, TestExecutor::Strategy::Full);                          Done */
	/*TE.RunAllTests(SBF, TestExecutor::Strategy::Full);                         Done */
	/*TE.RunAllTests(ShBF10, TestExecutor::Strategy::Full);                      Done */
	/*TE.RunAllTests(ShBF100, TestExecutor::Strategy::Partially);                Done */
	/*TE.RunAllTests(ShBF1000, TestExecutor::Strategy::Partially, 50, 14);       Done */
	/*TE.RunAllTests(ShBF10000, TestExecutor::Strategy::SmallOnly);              Done */
	/*TE.RunAllTests(ShBF100000, TestExecutor::Strategy::SmallOnly);             Done */

	/*TE.RunAllTests(WF, TestExecutor::Strategy::Full);                          Done */
	TE.RunAllTests(SWF, TestExecutor::Strategy::Full);                         
	TE.RunAllTests(ShWF10, TestExecutor::Strategy::Full);                      
	TE.RunAllTests(ShWF100, TestExecutor::Strategy::Partially);                
	TE.RunAllTests(ShWF1000, TestExecutor::Strategy::Partially);       
	TE.RunAllTests(ShWF10000, TestExecutor::Strategy::SmallOnly);              
	TE.RunAllTests(ShWF100000, TestExecutor::Strategy::SmallOnly);             
	
	return 0;
}