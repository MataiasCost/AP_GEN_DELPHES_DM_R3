analysis = "AP_DELPHES_DM_R3"
nano_version = 'v12'

#--------------------------------------------------------------------------------------------------
# Production ID:
# 00-09(Data), 10-19(MC-signal), 20-98(MC-bkg), 99(private sample)
#
# Data taking interval (DTI):
# 2022 DTIs = 0(preEE), 1(postEE)
# 2023 DTIs = 0(preBPix), 1(postBPix)
#--------------------------------------------------------------------------------------------------

paths = {}
#paths["0_22"] = analysis+'/Datasets/Files/bkg_22/dti_0/'+nano_version+'/'
#paths["1_22"] = analysis+'/Datasets/Files/bkg_22/dti_1/'+nano_version+'/'
#paths["0_23"] = analysis+'/Datasets/Files/bkg_23/dti_0/'+nano_version+'/'
paths["0_24"] = analysis+'/Datasets/Files/bkg_24/v15/'


# https://xsecdb-xsdb-official.app.cern.ch/
b_ds_info = { # [DatasetName, Production ID, PROC_XSEC[pb], XSEC_UNC[pb], XSEC_Accuracy]
"QCD": [
    ["QCD",                       '99',       185400000,              310600,		        'NO'],
],

"ZZ": [
    ["ZZ",                       '99',       2.145,              0.004,		        'NO'],
],

"Zto2Nu": [
    ["Zto2Nu",                       '99',       1020,              2.383,		        'NO'],
],

"ZH": [
    ["ZHTo2B",                       '99',       0.1036,              0.0002,		        'NO'],
    ["ZHTo2C",                       '99',       0.125,              0.00019,		        'NO'],

],
# NEW
"WplusH": [
    ["WplusHTo2B",                       '99',       0.1305,              0.0002,		        'NO'],
    ["WplusHTo2C",                       '99',       0.158,              0.00031,		        'NO'],

],

"WminusH": [
    ["WminusHTo2B",                       '99',       0.08045,              0.0001353,		        'NO'],
    ["WminusHTo2C",                       '99',       0.09742,              0.0001,		        'NO'],

],

"WZ": [
    ["WZ",                       '99',       3.083,              0.006347,		        'NO'],
],

"WW": [
    ["WW",                       '99',       19.67,              0.03612,		        'NO'],
],

"TT": [
    ["TTToLNu2Q",                       '99',       407.4,              2.383,		        'NO'],
    ["TTTo2L2Nu",                       '99',       98.88,              0.0001,		        'NO'],
],
    
"TT_v2": [
    ["TTToLNu2Q_powheg",                       '99',       407.4,              2.383,		        'NO'],
    ["TTTo2L2Nu_powheg",                       '99',       98.88,              0.0001,		        'NO'],
],

"WToLNu": [
    ["WToLNu",                       '99',       3573.72,              39.84,		        'NO'],
],
    

    

#"Zto2Nu": [
#    ["Zto2Nu_PTNuNu-40to100_1J",        '26',       929.8,	            5.481,		        'LO'],
#    ["Zto2Nu_PTNuNu-40to100_2J",        '26',       335.5,	            3.49,		        'LO'],
#    ["Zto2Nu_PTNuNu-100to200_1J",       '26',       86.38,	            0.441,		        'LO'],
#    ["Zto2Nu_PTNuNu-100to200_2J",       '26',       100.4,	            0.8555,		        'LO'],
#    ["Zto2Nu_PTNuNu-200to400_1J",       '26',       6.354,	            0.03067,		    'LO'],
#    ["Zto2Nu_PTNuNu-200to400_2J",       '26',       13.86,	            0.09802,		    'LO'],
#    ["Zto2Nu_PTNuNu-400to600_1J",       '26',       0.2188,	            0.0009573,		    'LO'],
#    ["Zto2Nu_PTNuNu-400to600_2J",       '26',       0.7816,	            0.005088,		    'LO'],
#    ["Zto2Nu_PTNuNu-600_1J",            '26',       0.02583,	        0.000108,		    'LO'],
#    ["Zto2Nu_PTNuNu-600_2J",            '26',       0.1311,	            0.0007098,		    'LO'],
#],

}


#----------------------------------------------------------------------------------------
# [DO NOT TOUCH THIS PART]
#----------------------------------------------------------------------------------------
b_ds = {}
for period in paths.keys():

    dti = period[0]
    year = period[-2:]

    for key in b_ds_info.keys():
        b_ds[key+"_"+period] = []
        for ds in b_ds_info[key]:
            list_temp = []
            list_temp.append(ds[0]+"_"+period)
            list_temp.append(ds[1]+year+dti)
            list_temp.append(paths[period]+ds[0]+".txt")
            list_temp.append(ds[2])
            list_temp.append(ds[3])
            b_ds[key+"_"+period].append(list_temp)

