#!/bin/tcsh
#set echo on


set cas = /castor/cern.ch/user/c/ccmuon/RPC/GlobalRuns/
set GLO = MagFieldPreBeam
set pre = 061
set RUN = 204
set method = 

set a1 = `rfdir $cas/$GLO/$pre/$RUN/$method/ | grep -v Merge | awk '{print $9}'`

foreach fls ($a1[*])
    echo $fls
    rfrm $cas/$GLO/$pre/$RUN/$method/$fls
end
rfdir $cas/$GLO/$pre/$RUN/$method
