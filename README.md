# ED_UL_Maps

## Overview

This repo is to produce UL maps using EventDisplay (ED). The general ideal is the current ED can only produce UL on a single point by giving the coordinate in the ANASUM parameter file. Therefore, this repo will try to generate coordiant files contains a Healpix-based, equal-area circular sky grid (a disk) centered on the source, with user input radius.

Below are the general steps to use these scripts.

---

## Requirements

- python2  
- healpy  
- numpy  
- pylab  

---

## Workflow

1. **Generate coordinates**
   - Use `generate_parameter_files.ipynb`
   - First generate coordinates files
   - Change name, coordinate, and radius of the UL maps (default ±1.5 deg)

2. **Generate parameter files**
   - In the same notebook, run the *Generate parameter files* block
   - It will use `ANASUM.template` to create multiple ED parameter files
   - Each file contains a different coordinate to produce UL

3. **Submit jobs to the cluster**
   - The script for this task is not provided; you need to create your own
   - Submit a large number of jobs, one per parameter file
   - Since this involves many jobs, limit core usage to avoid interfering with other users’ workloads  
     *Don’t ask me how I know this…*

4. **Combine runs**
   - Use `combine_anasum.sh` as the standard ED process
   - This combines all runs with the same parameter files

5. **Extract upper limits**
   - Once you have the `anasum.root` file, modify `printresults.C`:
     - Set source name
     - Set `E_th`, `alpha`, `iUpperLimit`
     - Set the file name (using loop index `i` for all `anasum.root` files)
     - Set the for-loop range
     - Set significance to 20 to produce UL at all points
   - Run:
     ```bash
     ./get_all_UL.sh
     ```
   - The saved UL file will contain four columns:
     ```
     #     RA        Dec        Flux_UL
     ```

6. **Plot UL map**
   - Use `plot_UL.ipynb` together with the saved UL files to plot the UL map
