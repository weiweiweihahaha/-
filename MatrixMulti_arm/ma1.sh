# ma1.sh
#!/bin/sh
# PBS -N ma1

pssh -h $PBS_NODEFILE mkdir -p /home/s2212138 1>&2
scp master:/home/s2113619/ma1/home/s2212138
pscp -h $PBS_NODEFILE master:/home/s2212138/ma1 /home/s2212138 1>&2
/home/s2212138/ma1
