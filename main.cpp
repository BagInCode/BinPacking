#include "RandomVizualizer.h"
#include "TestGenerator.h"
#include "AllAlgoHeaders.h"
#include "TestExecutor.h"

int main()
{
	TestExecutor TE = TestExecutor();
	AWFAlgo AWF = AWFAlgo();
	ASWFAlgo ASWF = ASWFAlgo();
	AShWFAlgo AShWF10 = AShWFAlgo(10);
	AShWFAlgo AShWF100 = AShWFAlgo(100);
	AShWFAlgo AShWF1000 = AShWFAlgo(1000);
	AShWFAlgo AShWF10000 = AShWFAlgo(10000);
	AShWFAlgo AShWF100000 = AShWFAlgo(100000);

	AFFAlgo AFF = AFFAlgo();
	ASFFAlgo ASFF = ASFFAlgo();
	AShFFAlgo AShFF10 = AShFFAlgo(10);
	AShFFAlgo AShFF100 = AShFFAlgo(100);
	AShFFAlgo AShFF1000 = AShFFAlgo(1000);
	AShFFAlgo AShFF10000 = AShFFAlgo(10000);
	AShFFAlgo AShFF100000 = AShFFAlgo(100000);

	ABFAlgo ABF = ABFAlgo();
	ASBFAlgo ASBF = ASBFAlgo();
	AShBFAlgo AShBF10 = AShBFAlgo(10);
	AShBFAlgo AShBF100 = AShBFAlgo(100);
	AShBFAlgo AShBF1000 = AShBFAlgo(1000);
	AShBFAlgo AShBF10000 = AShBFAlgo(10000);
	AShBFAlgo AShBF100000 = AShBFAlgo(100000);

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
	/*TE.RunAllTests(SWF, TestExecutor::Strategy::Full);                         Done */
	/*TE.RunAllTests(ShWF10, TestExecutor::Strategy::Full);                      Done */
	/*TE.RunAllTests(ShWF100, TestExecutor::Strategy::Partially);                Done */
	/*TE.RunAllTests(ShWF1000, TestExecutor::Strategy::Partially);               Done */
	/*TE.RunAllTests(ShWF10000, TestExecutor::Strategy::SmallOnly);              Done */
	/*TE.RunAllTests(ShWF100000, TestExecutor::Strategy::SmallOnly);             Done */

	/*TE.RunAllTests(AWF, TestExecutor::Strategy::Full);                         Done */
	/*TE.RunAllTests(ASWF, TestExecutor::Strategy::Full);                        Done */ 
	/*TE.RunAllTests(AShWF10, TestExecutor::Strategy::Full);                     Done */
	/*TE.RunAllTests(AShWF100, TestExecutor::Strategy::Partially);               Done */ 
	/*TE.RunAllTests(AShWF1000, TestExecutor::Strategy::Partially);              Done */ 
	/*TE.RunAllTests(AShWF10000, TestExecutor::Strategy::SmallOnly);             Done */
	/*TE.RunAllTests(AShWF100000, TestExecutor::Strategy::SmallOnly);            Done */

	/*TE.RunAllTests(ABF, TestExecutor::Strategy::Full);                         Done */
	/*TE.RunAllTests(ASBF, TestExecutor::Strategy::Full);                        Done */
	/*TE.RunAllTests(AShBF10, TestExecutor::Strategy::Full);                     Done */
	/*TE.RunAllTests(AShBF100, TestExecutor::Strategy::Partially);               Done */
	TE.RunAllTests(AShBF1000, TestExecutor::Strategy::Partially, 50, 15);
	TE.RunAllTests(AShBF10000, TestExecutor::Strategy::SmallOnly);
	TE.RunAllTests(AShBF100000, TestExecutor::Strategy::SmallOnly);

	TE.RunAllTests(AFF, TestExecutor::Strategy::Full);
	TE.RunAllTests(ASFF, TestExecutor::Strategy::Full);
	TE.RunAllTests(AShFF10, TestExecutor::Strategy::Full);
	TE.RunAllTests(AShFF100, TestExecutor::Strategy::Partially);
	TE.RunAllTests(AShFF1000, TestExecutor::Strategy::Partially);
	TE.RunAllTests(AShFF10000, TestExecutor::Strategy::SmallOnly);
	TE.RunAllTests(AShFF100000, TestExecutor::Strategy::SmallOnly);


	
	return 0;
}