#!/bin/tcsh
set a1 = "578"
#set a1 = `tail -100 /afs/cern.ch/user/a/aocampor/scratch0/CMSSW_2_0_10/src/GlobalRuns/merger/lista.dat`


set piani = "5"
set casa = /afs/cern.ch/user/a/aocampor/scratch0/CMSSW_2_0_10/src/GlobalRuns/merger/
set me = `whoami`
set GRN = "Cruzet3MW32"
set prefix = "054"
set castorh = "/castor/cern.ch/user/c/ccmuon/RPC/GlobalRuns/${GRN}/${prefix}"
set cmsversio = "CMSSW_2_0_10"

foreach fls ( $a1[*] )

	set p1 = `rfdir $castorh/$fls/StandAlonePlane${piani} | awk '{print $9}' | grep RPC_EfficRun`
	set p2 = `rfdir $castorh/$fls/StandAlonePlane${piani} | awk '{print $9}' | grep GRPC_EfficW`

	cd ~/scratch0/${cmsversio}/src
	eval `scramv1 runtime -csh`
	setenv CORAL_AUTH_USER ""
	setenv CORAL_AUTH_PASSWORD ""
	cd $casa


	if(!(-d /tmp/${me}/MergeStandAlone${piani}))then 
	    mkdir /tmp/${me}/MergeStandAlone${piani}
	endif

	if(!(-d /tmp/${me}/MergeStandAlone${piani}/${prefix}))then 
	    mkdir /tmp/${me}/MergeStandAlone${piani}/${prefix}
	endif


	if(!(-d /tmp/${me}/MergeStandAlone${piani}/${prefix}/$fls))then 
	    mkdir /tmp/${me}/MergeStandAlone${piani}/${prefix}/$fls
	endif

	rm -f /tmp/${me}/MergeStandAlone${piani}/${prefix}/$fls/*

	cd /tmp/${me}/MergeStandAlone${piani}/${prefix}/$fls/
	foreach flist ( $p1[*] )
	    hadd -f MergeStandAlone${piani}_${flist}.root rfio:${castorh}/${fls}/StandAlonePlane${piani}/${flist}
	end

	foreach flist ( $p2[*] )
            hadd -f MergeStandAlone_2_${piani}_${flist}.root rfio:${castorh}/${fls}/StandAlonePlane${piani}/${flist}
        end


	hadd Merge_Detailed_$fls.root MergeStandAlone${piani}_*.root
	rm -f MergeStandAlone${piani}_*.root

	hadd Merge_sum_$fls.root MergeStandAlone_2_${piani}_*.root
	rm -f MergeStandAlone_2_${piani}_*.root

        rfcp Merge_Detailed_$fls.root ${castorh}/${fls}/StandAlonePlane${piani}/Merge_$fls.root
	rfcp Merge_sum_$fls.root ${castorh}/${fls}/StandAlonePlane${piani}/

	cd $casa       

        cp effStandAlone.csh effStandAlone_t.csh
	replace "wheel_t" "w0" -- effStandAlone_t.csh
	replace "prefix_t" "$prefix" -- effStandAlone_t.csh
	replace "GRN_t" "$GRN" -- effStandAlone_t.csh
	replace "cmsversion_t" "${cmsversio}" -- effStandAlone_t.csh
	replace "a1_t" "$fls" -- effStandAlone_t.csh

	chmod a+x effStandAlone_t.csh
	./effStandAlone_t.csh
	rm effStandAlone_t.csh

end
