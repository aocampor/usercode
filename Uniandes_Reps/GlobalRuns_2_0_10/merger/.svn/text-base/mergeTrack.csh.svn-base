#!/bin/tcsh
set a1 = "696"
#set a1 = `tail -100 lista.dat`

set piani = "5"
set casa = `pwd`
set me = `whoami`
set GRN = "Cruzet3MW32"
set prefix = "054"
set castorh = "/castor/cern.ch/user/c/ccmuon/RPC/GlobalRuns/${GRN}/${prefix}"
set cmsversio = "CMSSW_2_1_6"

foreach fls ( $a1[*] )

	set p1 = `rfdir $castorh/$fls | awk '{print $9}' | grep SumEff`
	set p2 = `rfdir $castorh/$fls | awk '{print $9}' | grep RpcEff_track`

	cd ~/scratch0/${cmsversio}/src
	eval `scramv1 runtime -csh`
	setenv CORAL_AUTH_USER ""
	setenv CORAL_AUTH_PASSWORD ""
	cd $casa


	if(!(-d /tmp/${me}/MergeTrack${piani}))then 
	    mkdir /tmp/${me}/MergeTrack${piani}
	endif

	if(!(-d /tmp/${me}/MergeTrack${piani}/${prefix}))then 
	    mkdir /tmp/${me}/MergeTrack${piani}/${prefix}
	endif


	if(!(-d /tmp/${me}/MergeTrack${piani}/${prefix}/$fls))then 
	    mkdir /tmp/${me}/MergeTrack${piani}/${prefix}/$fls
	endif

	rm -f /tmp/${me}/MergeTrack${piani}/${prefix}/$fls/*

	cd /tmp/${me}/MergeTrack${piani}/${prefix}/$fls/
	foreach flist ( $p1[*] )
	    hadd -f MergeTrackSumEff${piani}_${flist}.root rfio:${castorh}/${fls}/${flist}
	end

	foreach flist ( $p2[*] )
	    hadd -f MergeTrackRPCEff${piani}_${flist}.root rfio:${castorh}/${fls}/${flist}
	end

	hadd MergeTrackSumEff_$fls.root MergeTrackSumEff${piani}_*.root
	rm -f MergeTrackSumEff${piani}_*.root

	hadd MergeTrackRPCEff_$fls.root MergeTrackRPCEff${piani}_*.root
	rm -f MergeTrackRPCEff${piani}_*.root

	rfcp MergeTrackSumEff_$fls.root ${castorh}/${fls}/
	rfcp MergeTrackRPCEff_$fls.root ${castorh}/${fls}/
	rm MergeTrackSumEff_$fls.root
	rm MergeTrackRPCEff_$fls.root
	cd $casa       


end
