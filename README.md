# ED_UL_Maps

## This repo is to produce UL maps using EventDisplay (ED). The general ideal is the current ED can only produce UL on a single point by giving the coordinate in the ANASUM parameter file. Therefore, this repo will try to generate coordiant files contains a Healpix-based, equal-area circular sky grid (a disk) centered on the source, with user input radius. Here are the general steps to use these scripts.

### packages: python2,  healpy, numpy and pylab
### Use generate_parameter_files.ipynb, first generate coordinates files. Change name, coordinate and  radius of the UL maps (defaults +-1.5deg)
### In the same notebook, run the "generate parameter files" block. It will use the ANASUM.template to create multiple ED parameter files. Each file contains different coordiante to produce UL. 
### Submit the jobs to your cluster. The script for this task is not provided, so you will need to create your own. The basic idea is to submit a large number of jobs to the cluster, with each job using a separate parameter file. Since this will involve a substantial number of jobs, please be mindful to limit your core usage to avoid interfering with other users’ workloads. Don’t ask me how I know this…
### Use combine_anasum.sh as the standard ED process, to combine all runs with same parameter files. 
### Once you have the anasum.root file, modify the printresults.C
#### Set source name
#### Set E_th, alpha,iUpperLimit
#### Set the file name, I'm using the loop value "i" to name all anasum.root files. 
#### Set for loop range
#### Set significance to 20 to produce UL in all points
#### Run ./get_all_UL.sh This script will save the output 
#### The save file for UL will be in 4 columns: #     RA        Dec        Flux_UL
### Use plot_UL.ipynb and saved UL files to plot the UL map. 


