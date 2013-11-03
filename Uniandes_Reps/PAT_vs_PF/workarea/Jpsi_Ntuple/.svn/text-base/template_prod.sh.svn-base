cat IsoOpt.Ccopy | sed -e 's#Gamma1#Gamma2#g' > tmp1
cat tmp1 | sed -e 's#NHad1#NHad2#g' > tmp2
cat tmp2 | sed -e 's#ChHad1#ChHad2#g' > tmp3
cp IsoOpt.Ccopy IsoOpt.C_1
mv tmp3 IsoOpt.C_2
rm tmp1 tmp2 
cat IsoOpt.C | sed -e 's#Gamma1#Gamma3#g' > tmp1
cat tmp1 | sed -e 's#NHad1#NHad3#g' > tmp2
cat tmp2 | sed -e 's#ChHad1#ChHad3#g' > tmp3
mv tmp3 IsoOpt.C_3
rm tmp1 tmp2 
cat IsoOpt.C | sed -e 's#Gamma1#Gamma4#g' > tmp1
cat tmp1 | sed -e 's#NHad1#NHad4#g' > tmp2
cat tmp2 | sed -e 's#ChHad1#ChHad4#g' > tmp3
mv tmp3 IsoOpt.C_4
rm tmp1 tmp2 
cat IsoOpt.C | sed -e 's#Gamma1#Gamma5#g' > tmp1
cat tmp1 | sed -e 's#NHad1#NHad5#g' > tmp2
cat tmp2 | sed -e 's#ChHad1#ChHad5#g' > tmp3
mv tmp3 IsoOpt.C_5
rm tmp1 tmp2 

