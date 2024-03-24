# nsum_opti_recur .sh
#!/bin/sh
# PBS -N nsum_opti_recur

pssh -h $PBS_NODEFILE mkdir -p /home/s2212138 1>&2
scp master:/home/s2212138/nsum_opti_recur /home/s2212138
pscp -h $PBS_NODEFILE master::/home/s2212138/nsum_opti_recur /home/s2212138 1>&2
/home/s2212138/nsum_opti_recur
