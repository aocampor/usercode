#!/bin/tcsh

set a1 = "485"
#set a1 = `tail -100 lista.dat`

set pl = "5"
set place = "/StandAlonePlane${pl}"
set string1 = "cazzo"
set casa = `pwd`
set GRN = "Cruzet3"
set prefix = "051"
set CASTOR_HOME_A = "/castor/cern.ch/user/c/ccmuon/RPC/GlobalRuns"
set cmsversion = "CMSSW_2_0_10"

if(!(-d ${GRN})) then
mkdir $GRN
endif

rm -Rf ${GRN}/${prefix}
mkdir ${GRN}/${prefix}

foreach fls ( $a1[*] )
	cd ~/scratch0/${cmsversion}/src
        eval `scramv1 runtime -csh`
        setenv CORAL_AUTH_USER ""
        setenv CORAL_AUTH_PASSWORD ""
	    
        cd $casa

	if(!(-d ${GRN}/${prefix}/)) then 
	mkdir $casa/${GRN}/${prefix}/
	endif

	rfmkdir $CASTOR_HOME_A/${GRN}
	rfchmod +777 $CASTOR_HOME_A/${GRN}

	rfmkdir $CASTOR_HOME_A/${GRN}/${prefix}
	rfchmod +777 $CASTOR_HOME_A/${GRN}/${prefix}


	if(!(-d ${GRN}/${prefix}/$fls)) then 
	mkdir $casa/${GRN}/${prefix}/$fls
	endif

	rfmkdir $CASTOR_HOME_A/${GRN}/${prefix}/$fls
	rfchmod +777 $CASTOR_HOME_A/${GRN}/${prefix}/$fls

	rfmkdir $CASTOR_HOME_A/${GRN}/${prefix}/$fls/${place}
	rfchmod +777 $CASTOR_HOME_A/${GRN}/${prefix}/$fls/${place}

	cd $casa/${GRN}/${prefix}/$fls

	set rootfile = `rfdir /castor/cern.ch/cms/store/data/Global${GRN}/A/000/${prefix}/$fls | awk '{print $9}'`
	touch file_$fls.dat
	foreach fls2 ( $rootfile[*] )	    
	    echo "\042""rfio:/castor/cern.ch/cms/store/data/Global${GRN}/A/000/${prefix}/"$fls"/"$fls2"\042""," >> file_$fls.dat
	end

	cp $casa/source/createpath.cc  $casa/${GRN}/${prefix}/$fls/createpath.cc
        cp $casa/source/Makefile  $casa/${GRN}/${prefix}/$fls/Makefile
	replace "PENE" "file_${fls}.dat" -- $casa/${GRN}/${prefix}/$fls/createpath.cc

	cd $casa/${GRN}/${prefix}/$fls
	make
	./createpath
	rm -f createpath*

	set lista = `ls -1 file_*_*.dat`
	foreach flist ( $lista[*] )
            set nr = `echo $flist | awk -F"_" '{print $2}'`  
	    set flag1 = "RPC_EfficRun${prefix}${fls}_${nr}.root"
	    set flag2 = "GRPC_EfficWheelRun${prefix}${fls}_${nr}.root"
			
	    cp $casa/source/batchStandAlone_RUN.job $casa/${GRN}/${prefix}/$fls/batchStandAlone_$flist.job 
	    cp $casa/source/StandAloneEfficiencyFromDat_RUN.cfg $casa/${GRN}/${prefix}/$fls/StandAloneEfficiencyFromDat_$flist.cfg 

	    replace "RUN" "$fls" -- $casa/${GRN}/${prefix}/$fls/batchStandAlone_$flist.job 
	    replace "/StandAlone" "$place" -- $casa/${GRN}/${prefix}/$fls/batchStandAlone_$flist.job 
	    replace "input" "StandAloneEfficiencyFromDat_${flist}.cfg" -- $casa/${GRN}/${prefix}/$fls/batchStandAlone_$flist.job
	    replace "file1" "${flag1}" -- $casa/${GRN}/${prefix}/$fls/batchStandAlone_$flist.job
	    replace "file2" "${flag2}" -- $casa/${GRN}/${prefix}/$fls/batchStandAlone_$flist.job
	    replace "CMSVER" "${cmsversion}" -- $casa/${GRN}/${prefix}/$fls/batchStandAlone_$flist.job
	    replace "GRN" "${GRN}" -- $casa/${GRN}/${prefix}/$fls/batchStandAlone_$flist.job
  	    replace "PREFIX" "${prefix}" -- $casa/${GRN}/${prefix}/$fls/batchStandAlone_$flist.job

	    replace "RUN" "$flist" -- $casa/${GRN}/${prefix}/$fls/StandAloneEfficiencyFromDat_$flist.cfg 
	    replace "piani" "$pl" -- $casa/${GRN}/${prefix}/$fls/StandAloneEfficiencyFromDat_$flist.cfg 

	    replace "file1" "${flag1}" -- $casa/${GRN}/${prefix}/$fls/StandAloneEfficiencyFromDat_$flist.cfg 
	    replace "file2" "${flag2}" -- $casa/${GRN}/${prefix}/$fls/StandAloneEfficiencyFromDat_$flist.cfg 


	    set list = `grep rfio $flist`
	    
	    foreach fls3 ( $list[*] )    
		replace "cazzo" "${fls3}cazzo" -- StandAloneEfficiencyFromDat_$flist.cfg 
	    end
	    
	    replace ",cazzo" " " -- StandAloneEfficiencyFromDat_$flist.cfg
	    chmod a+x batchStandAlone_$flist.job
	    bsub  -q cmscaf batchStandAlone_$flist.job

	end

	rm -f file_*_*.dat

	cd $casa

end
