set breakpoint pending on
exec-file /home/kks/omnetpp/bin/opp_run
set args -l /home/kks/tools/omnetpp/inet-hnrl/src/inet -n /home/kks/tools/omnetpp/inet-hnrl/examples:/home/kks/tools/omnetpp/inet-hnrl/src -u Cmdenv -f Shared.ini -c N64_nh1_nf1_nv1_tbf-test -r 0
tbreak main
tbreak MACRelayUnitNPWithVLAN::initialize
#display state->snd_nxt
#display state->snd_una
#display state->snd_mss
#display state->snd_max
#display bytes
run
