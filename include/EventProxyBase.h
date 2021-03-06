#ifndef EVENTPROXY_h
#define EVENTPROXY_h

#include <string>
#include <typeinfo>
#include <vector>
#include "boost/shared_ptr.hpp"

#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TROOT.h"

   class EventProxyBase{

   public:

	  EventProxyBase();

      virtual ~EventProxyBase();

      EventProxyBase const& operator++();

      // Go to the very first Event.
      EventProxyBase const& toBegin();
      
      virtual bool atEnd() const;

      ///Reload current event. Can be used if
      ///some tree branches are enebled/disabled
      ///en event by event basis.
      void reloadEvent();

      bool isValid() const;

      operator bool() const;

      TFile* getTFile() const { return fChain->GetFile();}

      virtual void init(std::vector<std::string> const& iFileNames);

      //

      Long64_t size() const{ return accumulatedSize_; }

   protected:

      std::vector<std::string> fileNames_;
      boost::shared_ptr<TChain> fChain;
      std::string treeName_;

      Long64_t eventIndex_;
      Long64_t accumulatedSize_;



};
#endif
