# nsum_opti_circulation .sh
#!/bin/sh
# PBS -N nsum_opti_circulation

pssh -h $PBS_NODEFILE mkdir -p /home/s2212138 1>&2
scp master:/home/s2212138/nsum_opti_circulation /home/s2212138
pscp -h $PBS_NODEFILE master::/home/s2212138/nsum_opti_circulation /home/s2212138 1>&2
/home/s2212138/nsum_opti_circulation
