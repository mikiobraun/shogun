kernel_arg1_degree = 20;
kernel_alphabet = 'DNA';
kernel_arg0_size = 10;
init_random = 42;
kernel_feature_type = 'Char';
kernel_accuracy = 1e-09;
kernel_data_train = {'TTGCCCCAGCGCCATGAGTTGAGTGTCATGACTAACTTGGCATACGAGGGACGTATGTAC', 'ACTAGAGAACTAAATGGGAGACGGAATGAATTTCCAGAAAGCGTGCTCATAGCGGAGTCC', 'CTGTAAAAGTCTATATATACCCGTGGAGCTCGACCCCATATAAGGCGCGGCTGCTTGATA', 'ACGTGTAAGTGAAACATGGAAGTGTTAAGCCCCTACGGGTTGACGTTGGAAAACCGGGCC', 'TATCGAACGCGCCTTGAATATCTCCGTTGTGTTCGGGTCACACTGTATGAGTAGTAGCCG', 'ATACGCCTTTGTTCCACTGGAACTCTAGGTAAATAAGGTTGTGCTGCGCAGTGATACCAC', 'GTTTCGTCTCCGGGCGTTAAGCACTTCCGAGACCGGCACGAAGTCCTTCTGTCTTCTCAC', 'TGGGACGTACAACGAATTCGCTGTAGGCCGGAGAAGCCCGCTCGCGGCCCAAGTCCAATG', 'ACTACGGCTAGAGTCGTAGTGAACAGAACCGGAAACAGATCCTGGTCTCTCCGAACGTGT', 'GAAGCACGCTGGTCGTGTCGATTTGAATCCGCGCGTACCTCCGCTTGGAGGCATCGACTC', 'GACTGTTTTATAAACGCACCTCACCGCCCCTATGATTGCGCATTATGACCTTAGTTAGTC'};
kernel_matrix_train = [1, 0.0511398573, 0.0688458477, 0.0776387675, 0.0859725327, 0.061676703, 0.0556251767, 0.0606066447, 0.0630581731, 0.0541736882, 0.0555326259;0.0511398573, 1, 0.0662033003, 0.0739674963, 0.0708898969, 0.0519929312, 0.0546573362, 0.0450821613, 0.0759676437, 0.0544168454, 0.0618068276;0.0688458477, 0.0662033003, 1, 0.0766812832, 0.0575393851, 0.0525616596, 0.0608966297, 0.0703875195, 0.0589568146, 0.053950233, 0.0492681143;0.0776387675, 0.0739674963, 0.0766812832, 1, 0.0534138071, 0.0830165675, 0.0447511376, 0.0528773663, 0.058498855, 0.0714558382, 0.0596709114;0.0859725327, 0.0708898969, 0.0575393851, 0.0534138071, 1, 0.0680770662, 0.0668060995, 0.0403363101, 0.0457866075, 0.0678754931, 0.0683081585;0.061676703, 0.0519929312, 0.0525616596, 0.0830165675, 0.0680770662, 1, 0.0639334606, 0.0521181249, 0.0706156445, 0.069273471, 0.0587408692;0.0556251767, 0.0546573362, 0.0608966297, 0.0447511376, 0.0668060995, 0.0639334606, 1, 0.0619550863, 0.0663587, 0.0557603418, 0.0644391418;0.0606066447, 0.0450821613, 0.0703875195, 0.0528773663, 0.0403363101, 0.0521181249, 0.0619550863, 1, 0.0727062115, 0.0747773677, 0.0707806295;0.0630581731, 0.0759676437, 0.0589568146, 0.058498855, 0.0457866075, 0.0706156445, 0.0663587, 0.0727062115, 1, 0.0761577896, 0.0630784185;0.0541736882, 0.0544168454, 0.053950233, 0.0714558382, 0.0678754931, 0.069273471, 0.0557603418, 0.0747773677, 0.0761577896, 1, 0.0529531259;0.0555326259, 0.0618068276, 0.0492681143, 0.0596709114, 0.0683081585, 0.0587408692, 0.0644391418, 0.0707806295, 0.0630784185, 0.0529531259, 1];
kernel_name = 'WeightedDegreePositionString';
kernel_seqlen = 60;
kernel_feature_class = 'string';
kernel_matrix_test = [0.0677878173, 0.0506319432, 0.0542292667, 0.0792268617, 0.0653821776, 0.0600270544, 0.0850661567, 0.0687162512, 0.0478615025, 0.0723128398, 0.0683486548, 0.0763690882, 0.0628480967, 0.0668947439, 0.0776287995, 0.0652293284, 0.0676954408;0.0558335213, 0.0512874725, 0.046760747, 0.0518624015, 0.0632075637, 0.0581767265, 0.0468227812, 0.0735684051, 0.0486400712, 0.0629679306, 0.0544024973, 0.0819571248, 0.0518325085, 0.0841817692, 0.0417435179, 0.0681459838, 0.0589083945;0.0901975082, 0.0609400331, 0.070138787, 0.07465951, 0.0886757746, 0.0636640408, 0.059347829, 0.0777900385, 0.0510563924, 0.0616475388, 0.084170847, 0.0884754003, 0.0737654438, 0.070889254, 0.0626178219, 0.0897980217, 0.0732428363;0.0692320177, 0.0721161973, 0.0360816853, 0.0709156609, 0.0768064295, 0.0593566802, 0.0659757042, 0.0532333076, 0.0634342589, 0.0660247677, 0.0854798043, 0.0953043096, 0.0713392344, 0.0833097806, 0.0661568253, 0.0509002276, 0.0969421815;0.0639778021, 0.117596014, 0.078077254, 0.0534670026, 0.0483927355, 0.0844023422, 0.0594018923, 0.0702464297, 0.0590943218, 0.0658466135, 0.0690502564, 0.0558216228, 0.088173937, 0.0568761978, 0.0641635429, 0.0782342432, 0.0642230002;0.0616740367, 0.0388640702, 0.0711750004, 0.0579216993, 0.0674858275, 0.0810101846, 0.100671284, 0.0672205593, 0.0580659876, 0.0533676407, 0.076982823, 0.0647259442, 0.0681328283, 0.0492644698, 0.0788836352, 0.0611183967, 0.0658097974;0.0664538936, 0.0558710317, 0.0655377986, 0.0728119721, 0.0474507026, 0.0608675015, 0.0706496742, 0.0972431837, 0.0717882745, 0.0683731451, 0.068953662, 0.0604211354, 0.0572598037, 0.0652298655, 0.072161823, 0.0880452814, 0.0764379549;0.0771754377, 0.0620464334, 0.0574998703, 0.0709147179, 0.087529139, 0.0947163608, 0.0566765239, 0.0598363671, 0.078732837, 0.0683279996, 0.0796841412, 0.0924790016, 0.0645926281, 0.0807758894, 0.0681253996, 0.0921519478, 0.0650688231;0.067562503, 0.0759441713, 0.0504411867, 0.0748059823, 0.0782923982, 0.0619107617, 0.0613774818, 0.0901515197, 0.06392718, 0.0671206226, 0.0554169671, 0.0770667307, 0.0599719277, 0.0623288943, 0.0400943, 0.0755592712, 0.0640368407;0.0763599296, 0.0699606912, 0.0622438213, 0.0741161288, 0.0682828087, 0.0849806665, 0.0641379589, 0.0708798419, 0.0630627151, 0.0743780668, 0.0653591687, 0.0828702055, 0.0583709455, 0.0797809847, 0.0547524312, 0.0657724652, 0.0633851768;0.0875933428, 0.0621222138, 0.080698909, 0.0724792781, 0.0672886559, 0.0645030705, 0.0584763135, 0.0529048812, 0.0966654383, 0.0843275522, 0.0712942136, 0.0586146625, 0.0873286, 0.0997146451, 0.06520439, 0.0831594883, 0.0662237222];
kernel_data_test = {'CTATCAAAAGATGCCGCATCAGGCTGGCTCGCGAATCCGGAATGCTGAACTAATAGAGCA', 'GGGGGGGGGGAACTTGCATTATCCGGTACCCGCCCGGGACAACAGTATAGGTACACTTGG', 'TCATCAAGGCGTTGTTCCCACCAACGTGCCAATCTGAGCCGTTTAAACCGGTTATCCTAT', 'GTTGAACATCTGACCCGAGCTTAAGTCCACCCGCACTCTGCAGGGTGATGCGGACCCAAA', 'CTACCTAAATGACAATCGCGCCGAGTATACGGATTATGTATATGCATGCCTCATCCATAG', 'TATCGCGCATATACTATCCGCCGCATTCGGGCTAGTGTCCTCGATGCCGAGGATCCCGTA', 'CATCGCTGTAGTGATCACGTCCGCTTCATAAAATGTACTTGATCGGGGGACGCCACTCGG', 'ATCTAACCTAGATTCAGAAGTTGGTGCTAAGACCGTACAGGCAGGACCTTGTGTACGGAC', 'CCCGTGTTCCATAGCTCTCCGTGTTTCCATTGCATATCCTACTGTTAACCCTAGAACTAG', 'GAGTGAGGAAAACCCTGTGACTAACCCACGCGGGAGACGACAACTCCGGTTTTAGTGTAC', 'TCGAGTCAATGAATTACTGTCGGTCACTCCGAACGGTTCGAAACACGCGCAAAAGTCCTA', 'AGGGGACATTCACACGTCAAAATATGGCGCCCTCCCAAAGCTGAGGGGGAGCGATCGTTG', 'ATGGTAAGTCGCGTAGTCCATCCCCGTCGGCATGGATGTTTTATATCGATACTGACAGTG', 'ACTAGCTTCGGCCGATAACACCGTTATCCCCTCGATTCGGGGGAGCCTACAACTCGAGTC', 'TTGCGTACCCTCCGAAGCCAGTTAGTCTTACAATTAGGCGTAAACCCGTCCTTACTACCA', 'ACTTTAATGCACCATATTCGGACGGGCCCCGTGGGGGATACAATCTCCCGTCCTACCACA', 'TGTGGGTACGTTGAATCATAGGACAGCATCCAATCCTGCTGAGTCGTGAAGCTCCGGCAG'};