root -b -q "printresults.C" | grep RUN\ -1  -A 6 | grep Flux| grep cm^-2| grep  s^-1 | awk '{print $12}' > myfluxes.dat;
echo "#       RA        Dec        Flux_UL" >myfluxes_IC171106.dat;
paste -d  "          " coord_IC171106A  myfluxes.dat >> myfluxes_IC171106.dat;
rm -rf myfluxes.dat;
