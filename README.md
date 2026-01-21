# icarus_CosmicMuonTrackComparisons

### Description of output files (Olivia, Jan. 2026)

# /JAN_2026

*'FullSet_TEST25_1D2D_AUG24_E_MConly_tpc0.C': 1D and 2D plots in pdf format for MC files in East cryostat, logical tpc0
*'FullSet_TEST25_1D2D_AUG24_E_DATAonly_tpc0.C': 1D and 2D plots in pdf format for DATA files in East cryostat, logical tpc0
*'FullSet_TEST25_1D2D_FEB25_E_MCDATA_tpc0.C': 1D and 2D plots in pdf format for MC and DATA overlaid in East cryostat, logical tpc0
* note that changing the caloskim from E to W accesses the West cryostat
* note that changing the tpc_num variable accesses logical tpcs 1-3

* There are now file paths saved for both MC and data, along with the sam2xrootd.sh script that can pull any new set and form a new .txt file from which to run the above macros.



# /AUG_2023

* `Sept_angle_E_MAY2023_MConly.C`: combining the above files to run together
* `FullSet_1D2D_Oct23_E_MConly_Etpc0.C`: Latest to combine for running together (will use the updated MC files) (sim. files also for logical tpc 1-3)


* `April_2023_1Ddis.C (was Nov1D.C)` : up-to-date 1D plots

* `April_2023_2DComp.C (was Nov2D.C)` : up-to-date 2D plots (or, will be up to date soon)

* `Sept_angle*.C`: how to get the extracted x,y,z coordinates
* `Between2_hor.C`: calculation of the angles, using the `Sept_angle` output as input. Horizontal only
* `P_M_60angles.C`: calculation of the angles, using the `Sept_angle` output as input, +/-60 degree angles relatively to horizontal

