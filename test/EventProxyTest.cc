#include "EventProxyTest.h"

#include <iostream>

EventProxyTest::EventProxyTest(){}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
EventProxyTest::~EventProxyTest(){}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
void EventProxyTest::init(std::vector<std::string> const& iFileNames){

	treeName_ = "SignalT";

	EventProxyBase::init(iFileNames);

	fChain->SetMakeClass(0);

	fChain->Print();

	myPoint = 0;//IMPORTANT

	fChain->SetBranchAddress("x",&x);
	
}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
