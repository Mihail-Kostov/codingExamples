TTP = [130,170,210,250]
D3T = [10,30,50]
TTM = [1,2]

fOut = open('code.txt','w')
fOut2 = open('bits.txt','w')

def snippet(i,ttp,d3t,ttm):
    txt = '''
BNBHeavySterile%i_FEMBeamTriggerAlgo:{
\t@table::BNB_FEMBeamTriggerAlgo_Base
\tTriggerThresPHMAX : %i
\tDiscr3threshold : %i
\tTriggerThresMult : %i
}
''' %(i,ttp,d3t,ttm)
    return txt

bit1 = 'swtrg_algonames : ['
bit2 = 'swtrg_algotype : ['
bit3 = 'swtrg_bits : ['
i = 0
for ttm in TTM:
    for d3t in D3T:
        for ttp in TTP:
            i += 1
            fOut.write(snippet(i,ttp,d3t,ttm))
            bit1 += '"BNBHeavySterile%i",' %i
            bit2 += '"FEMBeamTriggerAlgo",'
            bit3 += '0x800,'
bit1 = bit1[:-1]
bit2 = bit2[:-1]
bit3 = bit3[:-1]
bit1 += ']'
bit2 += ']'
bit3 += ']'

fOut2.write(bit1+'\n'+bit2+'\n'+bit3)
