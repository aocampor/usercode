#!/bin/tcsh
#set a1 = `tail -100 lista.dat`
set a1 = "a1_t"

set pl = "5"
set wheel = "wheel_t"
set casa = `pwd`
set pos = "MergeStandAlone${pl}"
set me = `whoami`
set prefix = "prefix_t"
set GRN = "GRN_t"
set cmsversio = "cmsversion_t"

rfcp /castor/cern.ch/user/c/ccmuon/RPC/GlobalRuns/${GRN}/${prefix}/${a1}/StandAlonePlane${pl}/Merge_${a1}.root /tmp/${me}/

foreach fls ( $a1[*] )
	cd ~/scratch0/${cmsversio}/src
	eval `scramv1 runtime -csh`
	setenv CORAL_AUTH_USER ""
	setenv CORAL_AUTH_PASSWORD ""

	cd $casa
	cp HistoExtraction.cc_source HistoExtraction.cc
	replace "RUN" "$fls" -- HistoExtraction.cc
	replace "my_self" "${me}" -- HistoExtraction.cc
	replace "w0" "$wheel" -- HistoExtraction.cc

	make
	./HistoExtraction
end


set wheel = "w1"

foreach fls ( $a1[*] )
	cd ~/scratch0/${cmsversio}/src
	eval `scramv1 runtime -csh`
	setenv CORAL_AUTH_USER ""
	setenv CORAL_AUTH_PASSWORD ""
 
	cd $casa
	cp HistoExtraction.cc_source HistoExtraction.cc
	replace "RUN" "$fls" -- HistoExtraction.cc
	replace "my_self" "${me}" -- HistoExtraction.cc
	replace "w0" "$wheel" -- HistoExtraction.cc

	make
	./HistoExtraction
end

set wheel = "w2"

foreach fls ( $a1[*] )
	cd ~/scratch0/${cmsversio}/src
	eval `scramv1 runtime -csh`
	setenv CORAL_AUTH_USER ""
	setenv CORAL_AUTH_PASSWORD ""
 
	cd $casa
	cp HistoExtraction.cc_source HistoExtraction.cc
	replace "RUN" "$fls" -- HistoExtraction.cc
	replace "my_self" "${me}" -- HistoExtraction.cc
	replace "w0" "$wheel" -- HistoExtraction.cc

	make
	./HistoExtraction
end

set wheel = "wm1"

foreach fls ( $a1[*] )
	cd ~/scratch0/${cmsversio}/src
	eval `scramv1 runtime -csh`
	setenv CORAL_AUTH_USER ""
	setenv CORAL_AUTH_PASSWORD ""
 
	cd $casa
	cp HistoExtraction.cc_source HistoExtraction.cc
	replace "RUN" "$fls" -- HistoExtraction.cc
	replace "my_self" "${me}" -- HistoExtraction.cc
	replace "w0" "$wheel" -- HistoExtraction.cc

	make
	./HistoExtraction
end

set wheel = "wm2"

foreach fls ( $a1[*] )
	cd ~/scratch0/${cmsversio}/src
	eval `scramv1 runtime -csh`
	setenv CORAL_AUTH_USER ""
	setenv CORAL_AUTH_PASSWORD ""
 
	cd $casa
	cp HistoExtraction.cc_source HistoExtraction.cc
	replace "RUN" "$fls" -- HistoExtraction.cc
	replace "my_self" "${me}" -- HistoExtraction.cc
	replace "w0" "$wheel" -- HistoExtraction.cc

	make
	./HistoExtraction
end

rfcp /tmp/${me}/RPC_w1_Merge_${a1}.root  /castor/cern.ch/user/c/ccmuon/RPC/GlobalRuns/${GRN}/${prefix}/${a1}/StandAlonePlane${pl}/RPC_w1_Merge_${a1}.root
rfcp /tmp/${me}/RPC_w2_Merge_${a1}.root /castor/cern.ch/user/c/ccmuon/RPC/GlobalRuns/${GRN}/${prefix}/${a1}/StandAlonePlane${pl}/RPC_w2_Merge_${a1}.root
rfcp /tmp/${me}/RPC_w0_Merge_${a1}.root /castor/cern.ch/user/c/ccmuon/RPC/GlobalRuns/${GRN}/${prefix}/${a1}/StandAlonePlane${pl}/RPC_w0_Merge_${a1}.root
rfcp /tmp/${me}/RPC_wm1_Merge_${a1}.root /castor/cern.ch/user/c/ccmuon/RPC/GlobalRuns/${GRN}/${prefix}/${a1}/StandAlonePlane${pl}/RPC_w-1_Merge_${a1}.root
rfcp /tmp/${me}/RPC_wm2_Merge_${a1}.root /castor/cern.ch/user/c/ccmuon/RPC/GlobalRuns/${GRN}/${prefix}/${a1}/StandAlonePlane${pl}/RPC_w-2_Merge_${a1}.root
rm /tmp/${me}/RPC_w1_Merge_${a1}.root
rm /tmp/${me}/RPC_w2_Merge_${a1}.root
rm /tmp/${me}/RPC_w0_Merge_${a1}.root
rm /tmp/${me}/RPC_wm2_Merge_${a1}.root
rm /tmp/${me}/RPC_wm1_Merge_${a1}.root
rm /tmp/${me}/Merge_${a1}.root
